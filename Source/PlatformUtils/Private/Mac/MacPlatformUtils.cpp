#pragma once

#include "Mac/MacPlatformUtils.h"


bool FMacPlatformUtils::HasNetworkConnected()
{
	return true;
}
FString FMacPlatformUtils::GetPersistentUniqueDeviceId()
{
	return FGenericPlatformMisc::GetUniqueDeviceId();
}

FString FMacPlatformUtils::GetDeviceId()
{
	return FGenericPlatformMisc::GetDeviceId();
}
