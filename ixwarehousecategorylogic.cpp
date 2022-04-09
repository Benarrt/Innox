#include "ixwarehousecategorylogic.h"
#include "ixwarehousecategorydata.h"

IXWarehouseCategoryLogic::IXWarehouseCategoryLogic()
{
    IXWarehouseCategoryData::inst();
}

void IXWarehouseCategoryLogic::getChildCategories(uint32_t parentId,
                                                  CHILD_CATEGORIES_REQUEST::callbackT callback)
{
    std::function<void(const std::vector<uint32_t>&)> innerCallback =
    [callback](const std::vector<uint32_t>& ids)
    {
        callback(ids);
    };

    IXWarehouseCategoryData::inst().request<CHILD_CATEGORIES_REQUEST>(safeCallbackLambda(innerCallback), parentId);
}

void IXWarehouseCategoryLogic::getCategoryName(uint32_t categoryId, CATEGORY_NAME_REQUEST::callbackT callback)
{
    std::function<void(const std::string&)> innerCallback =
    [callback](const std::string& name)
    {
        callback(name);
    };

    IXWarehouseCategoryData::inst().request<CATEGORY_NAME_REQUEST>(safeCallbackLambda(innerCallback), categoryId);
}
