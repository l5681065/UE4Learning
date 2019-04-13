// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "DynamicLoadAssetBPFLibrary.generated.h"

class UParticleSystem;
class UMaterialInterface;

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UDynamicLoadAssetBPFLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:			
	static  FName GetObjPath(const UObject* Obj);

	template <typename ObjClass>
	static FORCEINLINE ObjClass* LoadObjFromPath(const FName& Path)
	{
		if (Path == NAME_None) return NULL;
		//~

		return Cast<ObjClass>(StaticLoadObject(ObjClass::StaticClass(), NULL, *Path.ToString()));
	}
	UFUNCTION(BlueprintCallable)
	static  UParticleSystem* LoadPSFromPath(const FName& Path);
	UFUNCTION(BlueprintCallable)
	static  UMaterialInterface* LoadMatFromPath(const FName& Path);
	UFUNCTION(BlueprintCallable)
	static  UStaticMesh* LoadMeshFromPath(const FName& Path);
};
