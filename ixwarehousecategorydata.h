#ifndef IXWAREHOUSECATEGORYDATA_H
#define IXWAREHOUSECATEGORYDATA_H

#include "string"
#include "unordered_map"
#include "list"

#include "QString"

#include "ixwarehousecategoryreqdefs.h"

class IXWarehouseCategoryData
{
    using callbackT = std::function<void()>;
    using childCategoriesCbT = std::function<void(std::vector<uint32_t>t)>;

public:
    struct CategoryData
    {
        uint32_t id;
        uint32_t parentId;
        std::vector<std::string> tags;
    };

    static IXWarehouseCategoryData& inst()
    {
        static IXWarehouseCategoryData instance;
        return instance;
    }

    void parseData(const QString& data);

    template<class T, class ...argsT>
    void request(typename T::callbackT callback, argsT ...args)
    {
        auto& requests = T::requests();
        T req(callback, args...);
        requests.push_back(std::move(req));

        parseRequests();
    }

private:
    IXWarehouseCategoryData();

    void loadData();

    struct JSON_DATA
    {
        static constexpr char categories[] = "categories";
        static constexpr char id[] = "id";
        static constexpr char parentId[] = "parentId";
        static constexpr char tags[] = "tags";
    };

protected:
    template <class T>
    void callRequests()
    {
        auto& requests = T::requests();
        auto it = requests.begin();
        while(it != requests.end())
        {
            callRequest(*it);
            it = requests.erase(it);
        }
    }

    void parseRequests();

    void callRequest(const CHILD_CATEGORIES_REQUEST&);
    void callRequest(const CATEGORY_NAME_REQUEST&);

    bool _dataReady;
    std::vector <CategoryData> _categories;
    std::unordered_map <uint32_t, std::vector<uint32_t>> _parentToChilds;
};

#endif // IXWAREHOUSECATEGORYDATA_H
