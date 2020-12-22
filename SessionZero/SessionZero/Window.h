#pragma once

#include <string>
#include <windows.h>

namespace SessionZero {
	class Window
	{
	public:
		Window(HINSTANCE instance, const std::wstring title, int width = CW_USEDEFAULT, int height = CW_USEDEFAULT, int windowDisplayState = SW_SHOW) noexcept;
	private:
		static void setupWindowClass(HINSTANCE instance);
		static bool windowClassSet;
		bool exists = true;
		static LRESULT CALLBACK WindowProc(HWND window, UINT uMsg, WPARAM wParam, LPARAM lParam) noexcept;
		HWND handle;
	};
}

