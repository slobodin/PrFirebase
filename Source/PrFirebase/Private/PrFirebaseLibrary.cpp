// Copyright 2020-2024 Nikolay Prudnikov. All Rights Reserved.

#include "PrFirebaseLibrary.h"

#include "PrFirebase.h"

UPrFirebaseProxy* UPrFirebaseLibrary::GetFirebaseProxy()
{
	return IPrFirebase::Get().FirebaseProxy;
}
