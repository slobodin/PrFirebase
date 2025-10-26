// Copyright 2020-2024 Nikolay Prudnikov. All Rights Reserved.

#include "Android/PrFirebase_Android.h"

#include "PrFirebaseDefines.h"

#if WITH_FIREBASE && PLATFORM_ANDROID
#include "Android/PrFirebaseAnalyticsModule_Android.h"
#include "Android/PrFirebaseCrashlyticsModule_Android.h"
#include "Android/PrFirebasePerformanceModule_Android.h"
#include "Android/PrFirebaseRemoteConfigModule_Android.h"
#include "PrFirebaseAppDistributionModule.h"
#include "PrFirebaseAuthModule.h"
#include "PrFirebasePerformanceModule.h"
#include "PrFirebaseRemoteConfigModule.h"

#include "Modules/ModuleManager.h"
#include "PrFirebase.h"

#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#include <android_native_app_glue.h>

extern "C" {

	JNI_METHOD void Java_com_pr_firebase_PrFirebase_onApplicationDestroyed(JNIEnv*, jobject)
	{
		if (auto prFirebaseModule = static_cast<IPrFirebase*>(FModuleManager::Get().GetModule("PrFirebase")))
		{
			if (auto prAnalytics = prFirebaseModule->FirebaseProxy->GetAnalyticsModule())
			{
				prAnalytics->AppBeingDestroyedAnyThread.ExecuteIfBound();
			}
		}
	}
}

void UPrFirebase_Android::InitializeModuleList()
{
	ModuleClasses.Add(UPrFirebaseRemoteConfigModule::StaticClass(), UPrFirebaseRemoteConfigModule_Android::StaticClass());
	ModuleClasses.Add(UPrFirebaseCrashlyticsModule::StaticClass(), UPrFirebaseCrashlyticsModule_Android::StaticClass());
	ModuleClasses.Add(UPrFirebasePerformanceModule::StaticClass(), UPrFirebasePerformanceModule_Android::StaticClass());
	ModuleClasses.Add(UPrFirebaseAuthModule::StaticClass(), UPrFirebaseAuthModule::StaticClass());
	ModuleClasses.Add(UPrFirebaseAppDistributionModule::StaticClass(), UPrFirebaseAppDistributionModule::StaticClass());
	ModuleClasses.Add(UPrFirebaseAnalyticsModule::StaticClass(), UPrFirebaseAnalyticsModule_Android::StaticClass());
}

void UPrFirebase_Android::Initialize()
{
	PreInitializeModules_AnyThread();

	if (auto Env = FAndroidApplication::GetJavaEnv())
	{
		static auto Method = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_Firebase_Initialize", "()V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
	}

	InitializeModules_AnyThread();
}

#endif // WITH_FIREBASE && PLATFORM_ANDROID
