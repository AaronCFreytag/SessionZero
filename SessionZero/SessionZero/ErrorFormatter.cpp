#include "ErrorFormatter.h"

namespace SessionZero {
	std::string ErrorFormatter::formatWindowsError(const std::string location, DWORD errorCode) {
		const auto errorMessageSize = 512;
		char errorMessage[errorMessageSize];
		if (FormatMessageA(
			FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			errorCode,
			0,
			errorMessage,
			errorMessageSize,
			NULL
		)) {
			return "Encountered error during " + location + ": " + std::string(errorMessage);
		}
		return "Encountered error during " + location + " (Error Code " + std::to_string(errorCode) + ". More information could not be retrieved.)";
	}
}