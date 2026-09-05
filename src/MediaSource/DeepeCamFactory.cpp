#include "DeepeCamFactory.h"

HRESULT DeepeCamFactory::CreateInstance(
    REFIID riid,
    void** ppv)
{
    if (!ppv)
        return E_POINTER;

    *ppv = nullptr;

    DeepeCamMediaSource* source = new (std::nothrow) DeepeCamMediaSource();

    if (!source)
        return E_OUTOFMEMORY;

    HRESULT hr = source->QueryInterface(riid, ppv);

    source->Release();

    return hr;
}
