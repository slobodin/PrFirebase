// Copyright 2020-2024 Nikolay Prudnikov. All Rights Reserved.

#pragma once

#include "PrFirebaseModule.h"

#include "PrFirebaseDefines.h"

#include "PrFirebasePerformanceModule.generated.h"

UCLASS()
class PRFIREBASE_API UPrFirebasePerformanceModule : public UPrFirebaseModule
{
	GENERATED_BODY()

public:
	virtual bool IsAvailable() const final override { return WITH_FIREBASE_PERFORMANCE; }

	virtual void SetPerformanceCollectionEnabled(bool enabled) { Firebase_NotImplemented(); }
};
