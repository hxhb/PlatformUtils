#pragma once

#include "GenericPlatformUtils.h"
#include "CoreMinimal.h"

struct PLATFORMUTILS_API FIOSPlatformUtils:public FGenericPlatformUtils
{
public:
	
	/**
	* Return persistent Unique Device ID without reset after app reinstall
	*
	* @return - Unique Device ID
	*/
	virtual FString GetPersistentUniqueDeviceId()override;

	/**
	* Return Device ID. Should be unique but not guaranteed.
	*
	* @return - Device ID
	*/
	virtual FString GetDeviceId()override;
};

typedef FIOSPlatformUtils FPlatformUtilsMisc;