#pragma once

#include "CoreMinimal.h"

struct PLATFORMUTILS_API FGenericPlatformUtils
{
public:
	
	/**
	* Return persistent Unique Device ID without reset after app reinstall
	*
	* @return - Unique Device ID
	*/
	virtual FString GetPersistentUniqueDeviceId()=0;

	/**
	* Return Device ID. Should be unique but not guaranteed.
	*
	* @return - Device ID
	*/
	virtual FString GetDeviceId()=0;
};