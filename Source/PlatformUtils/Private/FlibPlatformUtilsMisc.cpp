// Fill out your copyright notice in the Description page of Project Settings.


#include "FlibPlatformUtilsMisc.h"
#include "PlatformUtilsMisc.h"

bool UFlibPlatformUtilsMisc::HasInternetConnected()
{
	return FPlatformUtilsMisc::HasInternetConnected();
}

FString UFlibPlatformUtilsMisc::GetPersistentUniqueDeviceId()
{
	return FPlatformUtilsMisc::GetPersistentUniqueDeviceId();
}

FString UFlibPlatformUtilsMisc::GetDeviceId()
{
	return FPlatformUtilsMisc::GetDeviceId();
}
