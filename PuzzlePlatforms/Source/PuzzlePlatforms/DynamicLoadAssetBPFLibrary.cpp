// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicLoadAssetBPFLibrary.h"
#include "Particles/ParticleSystem.h"
#include "Materials/MaterialInterface.h"


FName UDynamicLoadAssetBPFLibrary::GetObjPath(const UObject* Obj)
{
	if (!Obj)
	{
		return NAME_None;
	}
	//~

	FStringAssetReference ThePath = FStringAssetReference(Obj);

	if (!ThePath.IsValid()) return NAME_None;

	//The Class FString Name For This Object
	FString Str = Obj->GetClass()->GetDescription();

	Str += "'";
	Str += ThePath.ToString();
	Str += "'";

	return FName(*Str);
}

UParticleSystem* UDynamicLoadAssetBPFLibrary::LoadPSFromPath(const FName& Path)
{
	if (Path == NAME_None) return NULL;
	//~

	return LoadObjFromPath<UParticleSystem>(Path);
}

UMaterialInterface* UDynamicLoadAssetBPFLibrary::LoadMatFromPath(const FName& Path)
{
	if (Path == NAME_None) return NULL;
	//~

	return LoadObjFromPath<UMaterialInterface>(Path);
}

UStaticMesh* UDynamicLoadAssetBPFLibrary::LoadMeshFromPath(const FName& Path)
{
	if (Path == NAME_None) return NULL;
	//~

	return LoadObjFromPath<UStaticMesh>(Path);
}
