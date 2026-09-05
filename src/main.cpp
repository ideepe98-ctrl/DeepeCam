#include <windows.h>
#include <mfapi.h>
#include <mfvirtualcamera.h>

#pragma comment(lib, "mfsensorgroup.lib")

int main()
{
    HRESULT hr = MFStartup(MF_VERSION);
    if (FAILED(hr))
        return 1;

    IMFVirtualCamera* camera = nullptr;

    hr = MFCreateVirtualCamera(
        MFVirtualCameraType_SoftwareCameraSource,
        MFVirtualCameraLifetime_Session,
        MFVirtualCameraAccess_CurrentUser,
        L"DeepeCam",
        L"{8A5E5C91-4D7B-4E35-9F3B-1C8A9B7D21F4}",
        nullptr,
        0,
        &camera
    );

    if (camera)
        camera->Release();

    MFShutdown();

    return SUCCEEDED(hr) ? 0 : 2;
}
