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
	static FString GetPersistentUniqueDeviceId(){ return TEXT(""); }

	/**
	* Return Device ID. Should be unique but not guaranteed.
	*
	* @return - Device ID
	*/
	static FString GetDeviceId() { return TEXT(""); }
};