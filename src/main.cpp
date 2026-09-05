#include <windows.h>

int WINAPI wWinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PWSTR pCmdLine,
    int nCmdShow)
{
    (void)hInstance;
    (void)hPrevInstance;
    (void)pCmdLine;
    (void)nCmdShow;

    MessageBoxW(
        nullptr,
        L"DeepeCamTest is running successfully.",
        L"DeepeCam Test",
        MB_OK | MB_ICONINFORMATION
    );

    return 0;
}
