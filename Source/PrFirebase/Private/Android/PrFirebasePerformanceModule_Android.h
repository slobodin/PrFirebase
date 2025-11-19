// Copyright 2020-2024 Nikolay Prudnikov. All Rights Reserved.

#pragma once

#include "PrFirebasePerformanceModule.h"

#include "PrFirebasePerformanceModule_Android.generated.h"

UCLASS()
class UPrFirebasePerformanceModule_Android : public UPrFirebasePerformanceModule
{
	GENERATED_BODY()

#if WITH_FIREBASE_PERFORMANCE && PLATFORM_ANDROID
protected:
	virtual void SetPerformanceCollectionEnabled(bool enabled) override;

#endif // WITH_FIREBASE_PERFORMANCE && PLATFORM_ANDROID
};
