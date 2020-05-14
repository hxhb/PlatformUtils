#pragma once


#include "Android/AndroidPlatformUtils.h"

// engine header
#include "Kismet/KismetSystemLibrary.h"

jmethodID FAndroidPlatformUtils::HasInternetConnectedMethod;
jmethodID FAndroidPlatformUtils::GetDeviceIdMethod;
jmethodID FAndroidPlatformUtils::GetAndroidDeviceIdMethod;
jmethodID FAndroidPlatformUtils::GetMacAddressMethod;
jmethodID FAndroidPlatformUtils::GetFakeDeviceIDMethod;

void FAndroidPlatformUtils::Init()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		HasInternetConnectedMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_HasInternetConnected", "()Z", false);
		GetDeviceIdMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GetDeviceId", "()Ljava/lang/String;", false);
		GetAndroidDeviceIdMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GetAndroidDeviceId", "()Ljava/lang/String;", false);
		GetMacAddressMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GetMacAddress", "()Ljava/lang/String;", false);
		GetFakeDeviceIDMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GetFakeDeviceID", "()Ljava/lang/String;", false);
	}
}
void FAndroidPlatformUtils::Shutdown()
{

}

bool FAndroidPlatformUtils::HasInternetConnected()
{
	bool bResult = false;
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		bResult = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, FAndroidPlatformUtils::HasInternetConnectedMethod);
	}
	return bResult;
}
FString FAndroidPlatformUtils::GetPersistentUniqueDeviceId()
{
	return FPlatformUtilsMisc::GetDeviceId();
}

FString FAndroidPlatformUtils::GetDeviceId()
{
	FString ResultDeviceId = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		ResultDeviceId = FJavaHelper::FStringFromLocalRef(Env, (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, FAndroidPlatformUtils::GetDeviceIdMethod));
	}
	return ResultDeviceId;
}
