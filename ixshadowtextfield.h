#ifndef IXSHADOWTEXTFIELD_H
#define IXSHADOWTEXTFIELD_H

#include <QObject>


class IXTextField;

class IXShadowTextField : public QObject
{

public:
    static IXShadowTextField& inst()
    {
        static IXShadowTextField instance;
        return instance;
    }

    static const IXShadowTextField& cinst()
    {
        return inst();
    }

    void shadowTextFieldData(const QString& data);
    void addTextField(IXTextField* textField);
    void removeTextField(IXTextField* textField);

private:
    IXShadowTextField();
    IXTextField* _textField;
};

#endif // IXSHADOWTEXTFIELD_H
