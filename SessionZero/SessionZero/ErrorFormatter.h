#pragma once

#include <windows.h>
#include <string>

namespace SessionZero {
	class ErrorFormatter
	{
	public:
		static std::string formatWindowsError(const std::string location, DWORD errorCode);
	};
}

