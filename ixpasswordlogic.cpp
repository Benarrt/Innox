#include "ixpasswordlogic.h"
#include "QRegularExpression"

IXPasswordLogic::IXPasswordLogic()
{

}

std::list<int> IXPasswordLogic::isPasswordValid(const QString& password)
{
    std::list<int> errors;
    errors.clear();
    if(password.length() < 8)
    {
        errors.push_back(PW_ERRORS::TOO_SHORT);
    }

    if(password.toLower() == password)
    {
        errors.push_back(PW_ERRORS::NO_UPPER_CASE);
    }

    if(!password.contains(QRegularExpression("\\d")))
    {
        errors.push_back(PW_ERRORS::NO_NUMBER);
    }

    if(!password.contains(QRegularExpression("[\\[\\]\\\\|@$!%*#?&]")))
    {
        errors.push_back(PW_ERRORS::NO_SPECIAL_CHAR);
    }

    return errors;
}


