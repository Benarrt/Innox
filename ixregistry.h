#ifndef IXREGISTRY_H
#define IXREGISTRY_H

class IXWindow;
class IXPage;
class IXHandleBackPopup;
class IXPageHeader;

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
    void addToRegistry(IXPage*);
    void addToRegistry(IXHandleBackPopup*);
    void addToRegistry(IXPageHeader*);

    template <class T>
    T* get();

private:
    IXRegistry();

    IXWindow* _ixWindow;
    IXPage* _ixPage;
    IXHandleBackPopup* _ixHandleBackPopup;
    IXPageHeader* _ixPageHeader;
};

#endif // IXREGISTRY_H
