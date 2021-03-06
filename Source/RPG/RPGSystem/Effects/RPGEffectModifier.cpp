// Copyright 1998-2013 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "RPG.h"
#include "../Components/RPGAttributeComponent.h"
#include "../Structs/RPGSystemSructs.h"
#include "GameplayTagsManager.h"
#include "GameplayTagsModule.h"
#include "RPGEffectModifier.h"


URPGEffectModifier::URPGEffectModifier(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{

}

void URPGEffectModifier::PreInitialize()
{

}


//Modifier effect is always initialized.
//Because it's only task is to modify other effects, it doesn't care about actors.
bool URPGEffectModifier::Initialize()
{
	IsInitialized = true;
	OnEffectAppiled();
	return true;
}

void URPGEffectModifier::Deinitialize()
{
	OnEffectEnd();
}

void URPGEffectModifier::StoreAttributeSpec(TArray<FModdableAttributes> ModdableAttributes)
{
	AttributesToChange = ModdableAttributes;
}