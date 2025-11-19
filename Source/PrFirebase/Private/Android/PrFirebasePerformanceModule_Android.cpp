// Copyright 2020-2024 Nikolay Prudnikov. All Rights Reserved.

#include "Android/PrFirebasePerformanceModule_Android.h"

#if WITH_FIREBASE_PERFORMANCE && PLATFORM_ANDROID
#include "PrFirebaseDefines.h"

#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include <android_native_app_glue.h>

void UPrFirebasePerformanceModule_Android::SetPerformanceCollectionEnabled(bool enabled)
{
	if (auto Env = FAndroidApplication::GetJavaEnv())
	{
		static auto Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID,
			"AndroidThunkJava_FirebasePerformance_SetPerformanceCollectionEnabled", "(Z)V", false);

		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, enabled);
	}
}

#endif // WITH_FIREBASE_PERFORMANCE && PLATFORM_ANDROID
