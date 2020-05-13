#pragma once

#include "Windows/WindowsPlatformUtils.h"

bool FWindowsPlatformUtils::HasInternetConnected()
{
	return true;
}
FString FWindowsPlatformUtils::GetPersistentUniqueDeviceId()
{
	return FWindowsPlatformUtils::GetDeviceId();
}

FString FWindowsPlatformUtils::GetDeviceId()
{
	return FGenericPlatformMisc::GetDeviceId();
}
