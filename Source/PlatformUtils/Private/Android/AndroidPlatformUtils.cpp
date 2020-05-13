#pragma once

#include "Android/AndroidPlatformUtils.h"
#include "Kismet/KismetSystemLibrary.h"

jmethodID FAndroidPlatformUtils::HasInternetConnectedMethod;
jmethodID FAndroidPlatformUtils::CheckGooglePlayServicesMethod;
jmethodID FAndroidPlatformUtils::GetPersistentUniqueDeviceIdMethod;
jmethodID FAndroidPlatformUtils::GetDeviceIdMethod;

void FAndroidPlatformUtils::Init()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		HasInternetConnectedMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_HasInternetConnected", "()Z", false);
		CheckGooglePlayServicesMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_CheckGooglePlayServices", "()Z", false);
		GetPersistentUniqueDeviceIdMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GetPersistentUniqueDeviceId", "()Ljava/lang/String;", false);
		GetDeviceIdMethod = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GetDeviceId", "()Ljava/lang/String;", false);
	}
}
void FAndroidPlatformUtils::Shutdown()
{

}

bool FAndroidPlatformUtils::HasNetworkConnected()
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
	FString ResultDeviceId = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring ResultDeviceIdString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, FAndroidPlatformUtils::GetPersistentUniqueDeviceIdMethod);
		const char *nativeDeviceIdString = Env->GetStringUTFChars(ResultDeviceIdString, 0);
		ResultDeviceId = FString(nativeDeviceIdString);
		Env->ReleaseStringUTFChars(ResultDeviceIdString, nativeDeviceIdString);
		Env->DeleteLocalRef(ResultDeviceIdString);
	}
	return ResultDeviceId;
}

FString FAndroidPlatformUtils::GetDeviceId()
{
	FString ResultDeviceId = FString("");
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		jstring ResultDeviceIdString = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GameActivityThis, FAndroidPlatformUtils::GetDeviceIdMethod);
		const char *nativeDeviceIdString = Env->GetStringUTFChars(ResultDeviceIdString, 0);
		ResultDeviceId = FString(nativeDeviceIdString);
		Env->ReleaseStringUTFChars(ResultDeviceIdString, nativeDeviceIdString);
		Env->DeleteLocalRef(ResultDeviceIdString);
	}
	return ResultDeviceId;
}
