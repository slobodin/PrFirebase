// Copyright 2020-2024 Nikolay Prudnikov. All Rights Reserved.

#include "iOS/PrFirebasePerformanceModule_iOS.h"

#if WITH_FIREBASE_PERFORMANCE && PLATFORM_IOS
#include "PrFirebaseDefines.h"

#include "Async/Async.h"
#include "Misc/CoreDelegates.h"

#import <Firebase.h>
#import <Foundation/NSProcessInfo.h>

void UPrFirebasePerformanceModule_iOS::SetPerformanceCollectionEnabled(bool enabled)
{
    // todo_ios: implement it
}

#endif // WITH_FIREBASE_PERFORMANCE && PLATFORM_IOS
