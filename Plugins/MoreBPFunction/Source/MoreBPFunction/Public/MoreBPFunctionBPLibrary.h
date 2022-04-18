// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MoreBPFunctionBPLibrary.generated.h"

/* 
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu. 
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class UMoreBPFunctionBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Execute Sample function", Keywords = "MoreBPFunction sample test testing"), Category = "MoreBPFunctionTesting")
	static float MoreBPFunctionSampleFunction(float Param);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Int to Vector"), Category = "MoreBPFunctions|Vector| Convertation")
	static FVector Spring_IntToVector(const int32 input);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Byte to Vector"), Category = "MoreBPFunctions|Vector| Convertation")
	static FVector Spring_ByteToVector(const uint8 input);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Actors Location"), Category = "MoreBPFunctions|Vector| Convertation")
	static TArray<FVector> Spring_GetActorsLocation(const TArray<AActor*>& input);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Float Array To Vector Array"), Category = "MoreBPFunctions|Vector| Convertation")
	static TArray<FVector> Spring_FloatArrayToVectorArray(const TArray<float> input);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Int Array To Vector Array"), Category = "MoreBPFunctions|Vector| Convertation")
	static TArray<FVector> Spring_IntArrayToVectorArray(const TArray<int32> input);
};
