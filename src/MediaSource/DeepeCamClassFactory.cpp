#include "DeepeCamClassFactory.h"
#include "DeepeCamFactory.h"

DeepeCamClassFactory::DeepeCamClassFactory()
{
}

STDMETHODIMP DeepeCamClassFactory::QueryInterface(
    REFIID riid,
    void** ppv)
{
    if (!ppv)
        return E_POINTER;

    *ppv = nullptr;

    if (riid == IID_IUnknown || riid == IID_IClassFactory)
    {
        *ppv = static_cast<IClassFactory*>(this);
        AddRef();
        return S_OK;
    }

    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) DeepeCamClassFactory::AddRef()
{
    return static_cast<ULONG>(
        InterlockedIncrement(&m_refCount));
}

STDMETHODIMP_(ULONG) DeepeCamClassFactory::Release()
{
    ULONG count = static_cast<ULONG>(
        InterlockedDecrement(&m_refCount));

    if (count == 0)
        delete this;

    return count;
}

STDMETHODIMP DeepeCamClassFactory::CreateInstance(
    IUnknown* outer,
    REFIID riid,
    void** ppv)
{
    if (outer)
        return CLASS_E_NOAGGREGATION;

    return DeepeCamFactory::CreateInstance(riid, ppv);
}

STDMETHODIMP DeepeCamClassFactory::LockServer(BOOL)
{
    return S_OK;
}
