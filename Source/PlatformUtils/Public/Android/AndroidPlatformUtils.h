#pragma once

#include "GenericPlatformUtils.h"
#include "CoreMinimal.h"

struct PLATFORMUTILS_API FAndroidPlatformUtils:public FGenericPlatformUtils
{
public:
	static void Init();
	static void Shutdown();

	/**
	* Return device network connected status
	*
	* @return - has network?
	*/
	static bool HasInternetConnected();

	/**
	* Return persistent Unique Device ID without reset after app reinstall
	*
	* @return - Unique Device ID
	*/
	static FString GetPersistentUniqueDeviceId();

	/**
	* Return Device ID. Should be unique but not guaranteed.
	*
	* @return - Device ID
	*/
	static FString GetDeviceId();

	// JNI Methods
	static jmethodID HasInternetConnectedMethod;
	static jmethodID CheckGooglePlayServicesMethod;
	static jmethodID GetPersistentUniqueDeviceIdMethod;
	static jmethodID GetDeviceIdMethod;
};

typedef FAndroidPlatformUtils FPlatformUtilsMisc;