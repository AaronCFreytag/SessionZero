#include "Window.h"

#include "ErrorFormatter.h"
#include <stdexcept>

namespace SessionZero {
	bool Window::windowClassSet = false;

	Window::Window(HINSTANCE instance, const std::wstring title, int width, int height, int windowDisplayState) noexcept {
		if (!windowClassSet) {
			setupWindowClass(instance);
		}
		handle = CreateWindowEx(
			0,
			L"DefaultWindow",
			static_cast<const LPCWSTR>(title.c_str()),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			width,
			height,
			NULL,
			NULL,
			instance,
			NULL
		);

		if (handle == NULL) {
			throw std::runtime_error(
				ErrorFormatter::formatWindowsError("Window Creation", GetLastError())
			);
		}

		ShowWindow(handle, windowDisplayState);
	}

	void Window::setupWindowClass(HINSTANCE instance) {
		wchar_t exePath[MAX_PATH];
		GetModuleFileName(NULL, exePath, MAX_PATH);
		HICON icon = ExtractIcon(instance, exePath, 0);

		WNDCLASS windowClass = {
			.lpfnWndProc = WindowProc,
			.hInstance = instance,
			.hIcon = icon,
			.lpszClassName = L"DefaultWindow"
		};

		if (!RegisterClass(&windowClass)) {
			throw std::runtime_error(
				ErrorFormatter::formatWindowsError("Window Class Registration", GetLastError())
			);
		}
		windowClassSet = true;
	}

	LRESULT CALLBACK Window::WindowProc(HWND window, UINT uMsg, WPARAM wParam, LPARAM lParam) noexcept {
		switch (uMsg)
		{
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		}
		return DefWindowProc(window, uMsg, wParam, lParam);
	}
}