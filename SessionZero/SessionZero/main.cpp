#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include "Window.h"

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
	auto title = L"Session Zero";

	SessionZero::Window w(hInstance, title, 960, 540, nCmdShow);

	MSG msg = {};
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0) {
            // Process message
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            // Render Frame while waiting for messages
        }
    }

	return 0;
}