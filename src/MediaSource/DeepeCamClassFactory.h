#pragma once

#include <windows.h>
#include <unknwn.h>

class DeepeCamClassFactory : public IClassFactory
{
public:
    DeepeCamClassFactory();

    STDMETHODIMP QueryInterface(REFIID riid, void** ppv) override;
    STDMETHODIMP_(ULONG) AddRef() override;
    STDMETHODIMP_(ULONG) Release() override;

    STDMETHODIMP CreateInstance(
        IUnknown* outer,
        REFIID riid,
        void** ppv) override;

    STDMETHODIMP LockServer(BOOL lock) override;

private:
    long m_refCount = 1;
};
