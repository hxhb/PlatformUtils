#pragma once

#include "HAL/Platform.h"

#if PLATFORM_ANDROID
#include "Andorid/AndroidPlatformUtils.h"
#elif PLATFORM_IOS
#include "IOS/IOSPlatformUtils.h"
#elif PLATFORM_WINDOWS
#include "Windows/WindowsPlatformUtils.h"
#elif PLATYFORM_MAC
#include "Mac/MacPlatformUtils.h"
#endif