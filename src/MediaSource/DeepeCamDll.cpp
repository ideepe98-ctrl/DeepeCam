#include <windows.h>
#include "DeepeCamClassFactory.h"

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

    // Our CLSID will be connected here in the next step.
    return CLASS_E_CLASSNOTAVAILABLE;
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
