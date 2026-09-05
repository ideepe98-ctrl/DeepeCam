#include <windows.h>
#include "DeepeCamClassFactory.h"
#include <new>

static long g_objectCount = 0;

extern "C" HRESULT __declspec(dllexport)
DllGetClassObject(
    REFCLSID rclsid,
    REFIID riid,
    void** ppv)
{
    if (!ppv)
        return E_POINTER;

    *ppv = nullptr;

    static const CLSID CLSID_DeepeCamMediaSource =
{ 0x8a5e5c91, 0x4d7b, 0x4e35,
  { 0x9f, 0x3b, 0x1c, 0x8a, 0x9b, 0x7d, 0x21, 0xf4 } };

if (rclsid != CLSID_DeepeCamMediaSource)
    return CLASS_E_CLASSNOTAVAILABLE;

DeepeCamClassFactory* factory = new (std::nothrow) DeepeCamClassFactory();

if (!factory)
    return E_OUTOFMEMORY;

HRESULT hr = factory->QueryInterface(riid, ppv);
factory->Release();

return hr;
}

extern "C" HRESULT __declspec(dllexport)
DllCanUnloadNow()
{
    return g_objectCount == 0 ? S_OK : S_FALSE;
}

BOOL APIENTRY DllMain(
    HMODULE,
    DWORD,
    LPVOID)
{
    return TRUE;
}
