#ifndef IXPASSWORDLOGIC_H
#define IXPASSWORDLOGIC_H

#include <list>

#include "QString"

class IXPasswordLogic
{
public:
    IXPasswordLogic();

    struct ERRORS
    {
        static constexpr uint16_t TOO_SHORT = 0;
        static constexpr uint16_t NO_UPPER_CASE = 1;
        static constexpr uint16_t NO_NUMBER = 2;
        static constexpr uint16_t NO_SPECIAL_CHAR = 3;
    }; using PW_ERRORS = IXPasswordLogic::ERRORS;

    virtual std::list<int> isPasswordValid(const QString& password);
};

#endif // IXPASSWORDLOGIC_H
