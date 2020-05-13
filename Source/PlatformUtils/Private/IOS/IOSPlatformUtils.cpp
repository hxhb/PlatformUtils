#pragma once

#include "IOS/IOSPlatformUtils.h"


void FIOSPlatformUtils::Init()
{

}
void FIOSPlatformUtils::Shutdown()
{

}
bool FIOSPlatformUtils::HasNetworkConnected()
{
	return true;
}

FString FIOSPlatformUtils::GetPersistentUniqueDeviceId()
{
	return TEXT("");
}

FString FIOSPlatformUtils::GetDeviceId()
{
	return TEXT("");
}
