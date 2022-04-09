#include "ixwarehousecategorydata.h"

#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten.h>
#include </home/lqony/Documents/projects/emsdk/upstream/emscripten/system/include/emscripten/html5.h>

#include <utility>

#include "QJsonDocument"
#include "QJsonArray"
#include "QJsonObject"

#include "ixwarehousecategoryreqdefs.h"

extern "C"
{
    void EMSCRIPTEN_KEEPALIVE IXWarehouseCategoryDataCallback(const QChar* data)
    {
        IXWarehouseCategoryData::inst().parseData(QString(data));
    }
}

IXWarehouseCategoryData::IXWarehouseCategoryData() : _dataReady(false)
{
    loadData();
}

void IXWarehouseCategoryData::loadData()
{
    EM_ASM({
               fetch('./resources/json/categories.json')
               .then(response => response.text())
               .then(data=> {
                   var heapPtr = Module._malloc((data.length+1)*2);
                   Module.stringToUTF16(data, heapPtr, (data.length+1)*2);
                   Module._IXWarehouseCategoryDataCallback(heapPtr);
               })
               .catch(error => console.log(error));
           });
}

void IXWarehouseCategoryData::callRequest(const CHILD_CATEGORIES_REQUEST& req)
{

    std::vector<uint32_t> ids;
    ids.clear();
    auto it = _parentToChilds.find(req.parentId);
    if(it != _parentToChilds.end())
    {
        for(const auto& catId : it->second)
        {
            ids.push_back(catId);
        }
    }

    req.callback(ids);
}

void IXWarehouseCategoryData::callRequest(const CATEGORY_NAME_REQUEST& req)
{
    std::string catName("error");
    if(req.categoryId < _categories.size() && _categories[req.categoryId].tags.size() > 0)
        catName = _categories[req.categoryId].tags[0];

    req.callback(catName);
}

void IXWarehouseCategoryData::parseRequests()
{
    if(_dataReady)
    {
        callRequests<CHILD_CATEGORIES_REQUEST>();
        callRequests<CATEGORY_NAME_REQUEST>();
    }
}

void IXWarehouseCategoryData::parseData(const QString& data)
{
    auto dataJSON = QJsonDocument::fromJson(data.toUtf8());

    if(dataJSON[JSON_DATA::categories] == QJsonValue::Undefined)
        return;

    auto catArray = dataJSON[JSON_DATA::categories].toArray();

    _categories.reserve(catArray.size());

    for(const auto& category : catArray)
    {
        auto categoryJSON = category.toObject();
        if(categoryJSON[JSON_DATA::id]== QJsonValue::Undefined)
            continue;

        if(categoryJSON[JSON_DATA::parentId]== QJsonValue::Undefined)
            continue;

        if(categoryJSON[JSON_DATA::tags] == QJsonValue::Undefined)
            continue;

        auto tagsArray = categoryJSON[JSON_DATA::tags].toArray();


        uint32_t catId = categoryJSON[JSON_DATA::id].toInt();
        uint32_t catParentId = categoryJSON[JSON_DATA::parentId].toInt();

        if(catId != _categories.size())
        {
            qDebug("Error - warehouse categories must be sortead before loadign into IXWarehouseCategoryData");
            qDebug(QString("Category ID %1 Parent ID %2").arg(QString::number((int)catId),
                   QString::number((int)catParentId)).toLocal8Bit());
        }

        CategoryData catData = {catId, catParentId,  {}};

        for(const auto& tag : tagsArray)
        {
            catData.tags.push_back(tag.toString().toStdString());
        }

        _categories.push_back(catData);

        if(catId > 0)
        {
            auto it = _parentToChilds.find(catParentId);
            if(it == _parentToChilds.end())
            {
                auto record = std::make_pair<uint32_t, std::vector<uint32_t>>((uint32_t)catParentId, {(uint32_t)catId});
                _parentToChilds.emplace(std::move(record));
                continue;
            }
            it->second.push_back(catId);
        }
    }

    _dataReady = true;
    parseRequests();
}
