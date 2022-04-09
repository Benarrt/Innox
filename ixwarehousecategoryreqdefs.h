#ifndef IXWAREHOUSECATEGORYREQDEFS_H
#define IXWAREHOUSECATEGORYREQDEFS_H

#include <vector>
#include <list>
#include <functional>

#include "QString"

template <class T>
struct REQUEST_LIST
{
    static std::list<T>& requests()
    {
        static std::list<T> _requests;
        return _requests;
    }
};

struct CHILD_CATEGORIES_REQUEST : public REQUEST_LIST<CHILD_CATEGORIES_REQUEST>
{
    static constexpr const uint32_t ID = 1;
    using callbackT = std::function<void(const std::vector<uint32_t>& t)>;

    CHILD_CATEGORIES_REQUEST(callbackT cb, uint32_t parentId) : callback(cb), parentId(parentId)
    {}

    callbackT callback;
    uint32_t parentId;
};

struct CATEGORY_NAME_REQUEST : public REQUEST_LIST<CATEGORY_NAME_REQUEST>
{
    static constexpr const uint32_t ID = 2;
    using callbackT = std::function<void(const std::string&)>;

    CATEGORY_NAME_REQUEST(callbackT cb, uint32_t categoryId) : callback(cb), categoryId(categoryId)
    {}

    callbackT callback;
    int categoryId;
};

#endif // IXWAREHOUSECATEGORYREQDEFS_H
