#ifndef IXSHADOWTEXTFIELD_H
#define IXSHADOWTEXTFIELD_H

#include <QObject>

//TODO REMOVE THIS CLASSH AND REMAKE IT INTO IXTEXTFIELD LOGIC!
//DYNAMICALY CREATE AND REMOVE TEXT INPUT IN JS

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
    void addTextField(IXTextField* textField, const QString& _textValue);
    void removeTextField(IXTextField* textField);
    void setShadowTextFieldSelection(quint16 start, quint16 end);
    void shadowTextFieldCursor(quint16 posBeg, quint16 posEnd);

private:
    IXShadowTextField();
    IXTextField* _textField;
};

#endif // IXSHADOWTEXTFIELD_H
