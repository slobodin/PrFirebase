// Copyright 2020-2024 Nikolay Prudnikov. All Rights Reserved.

#include "iOS/PrFirebaseCrashlyticsModule_iOS.h"

#include "PrFirebaseDefines.h"

#if WITH_FIREBASE_CRASHLYTICS && PLATFORM_IOS
#import <Firebase.h>

void UPrFirebaseCrashlyticsModule_iOS::Crash()
{
	UE_LOG(LogFirebase, Fatal, TEXT("Crash"));
}

void UPrFirebaseCrashlyticsModule_iOS::SetUserIdentifier(const FString& UserIdentifier)
{
	const FString userId = UserIdentifier;

	dispatch_async(dispatch_get_main_queue(), ^{
	  [[FIRCrashlytics crashlytics] setUserID:userId.GetNSString()];
	});
}

void UPrFirebaseCrashlyticsModule_iOS::WriteLog(const FString& Log)
{
	const FString logCopy = Log;
	dispatch_async(dispatch_get_main_queue(), ^{
	  [[FIRCrashlytics crashlytics] log:logCopy.GetNSString()];
	});
}

void UPrFirebaseCrashlyticsModule_iOS::AddAttribute(const FString& Key, const FString& Value)
{
	// disabled for now
	//[[FIRCrashlytics crashlytics] setCustomValue:Value.GetNSString() forKey:Key.GetNSString()];
}

void UPrFirebaseCrashlyticsModule_iOS::Initialize_AnyThread()
{
	CatchEngineLogs();
}

void UPrFirebaseCrashlyticsModule_iOS::SetCrashlyticsCollectionEnabled(bool bEnabled)
{
	dispatch_async(dispatch_get_main_queue(), ^{
	  [[FIRCrashlytics crashlytics] setCrashlyticsCollectionEnabled:bEnabled];
	});
}

#endif // WITH_FIREBASE_CRASHLYTICS && PLATFORM_IOS
