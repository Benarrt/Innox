#include "ixpasswordlogic.h"
#include "QRegularExpression"

IXPasswordLogic::IXPasswordLogic()
{

}

QList<int> IXPasswordLogic::isPasswordValid(const QString& password)
{
    QList<int> error;
    if(password.length() < 8)
    {
        error.append(0);
    }

    if(password.toLower() == password)
    {
        error.append(1);
    }

    if(!password.contains(QRegularExpression("\\d")))
    {
        error.append(2);
    }

    if(!password.contains(QRegularExpression("[\\[\\]\\\\|@$!%*#?&]")))
    {
        error.append(3);
    }

    return error;
}
