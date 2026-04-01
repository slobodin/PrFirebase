// Copyright 2020-2024 Nikolay Prudnikov. All Rights Reserved.

#pragma once

#include "PrFirebasePerformanceModule.h"

#include "PrFirebasePerformanceModule_iOS.generated.h"

UCLASS()
class UPrFirebasePerformanceModule_iOS : public UPrFirebasePerformanceModule
{
	GENERATED_BODY()

#if WITH_FIREBASE_PERFORMANCE && PLATFORM_IOS
protected:
	virtual void SetPerformanceCollectionEnabled(bool enabled) override;

#endif // WITH_FIREBASE_PERFORMANCE && PLATFORM_IOS
};
