#ifndef IXWAREHOUSECATEGORYLOGIC_H
#define IXWAREHOUSECATEGORYLOGIC_H

#include <vector>
#include <string>

#include "ixwarehousecategoryreqdefs.h"
#include "ixsafecallback.h"

class IXWarehouseCategoryLogic : public IXSafeCallback
{
public:
    IXWarehouseCategoryLogic();

    void getChildCategories(uint32_t parentId, CHILD_CATEGORIES_REQUEST::callbackT callback);
    void getCategoryName(uint32_t categoryId, CATEGORY_NAME_REQUEST::callbackT callback);

protected:
};

#endif // IXWAREHOUSECATEGORYLOGIC_H
