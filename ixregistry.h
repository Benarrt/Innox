#ifndef IXREGISTRY_H
#define IXREGISTRY_H

class IXWindow;
class IXWindowPage;
class IXHandleBackPopup;
class IXWindowPageHeader;

class IXRegistry
{
public:

    static IXRegistry& inst()
    {
        static IXRegistry instance;
        return instance;
    }

    static const IXRegistry& cinst()
    {
        return inst();
    }

    void addToRegistry(IXWindow*);
    void addToRegistry(IXWindowPage*);
    void addToRegistry(IXHandleBackPopup*);
    void addToRegistry(IXWindowPageHeader*);

    template <class T>
    T* get();

private:
    IXRegistry();

    IXWindow* _ixWindow;
    IXWindowPage* _ixWindowPage;
    IXHandleBackPopup* _ixHandleBackPopup;
    IXWindowPageHeader* _ixWindowPageHeader;
};

#endif // IXREGISTRY_H
