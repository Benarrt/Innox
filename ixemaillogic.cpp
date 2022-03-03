#include "ixemaillogic.h"
#include "QRegularExpression"

IXEmailLogic::IXEmailLogic()
{

}

bool IXEmailLogic::isEmailValid(const QString& email)
{
   return email.contains(QRegularExpression("(^.+@.+$)"));
}
