#pragma once

#include "IOS/IOSPlatformUtils.h"

#import <Reachability/Reachability.h>
#import <SAMKeychain/SAMKeychain.h>

void FIOSPlatformUtils::Init()
{

}
void FIOSPlatformUtils::Shutdown()
{

}

bool FIOSPlatformUtils::HasInternetConnected()
{
	Reachability *reachability = [Reachability reachabilityForInternetConnection];
	NetworkStatus networkStatus = [reachability currentReachabilityStatus];
	return networkStatus != NotReachable;
}


FString FIOSPlatformUtils::GetPersistentUniqueDeviceId()
{
	NSString *AppName = [[[NSBundle mainBundle] infoDictionary] objectForKey:(NSString*)kCFBundleNameKey];
	NSString *PersistentUUID = [SAMKeychain passwordForService : AppName account : @"incoding"];

	if (PersistentUUID == nil)
	{
		PersistentUUID = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
		[SAMKeychain setPassword : PersistentUUID forService : AppName account : @"incoding"];
	}

	return FString(PersistentUUID);
}

FString FIOSPlatformUtils::GetDeviceId()
{
	return FPlatformUtilsMisc::GetPersistentUniqueDeviceId();
}
