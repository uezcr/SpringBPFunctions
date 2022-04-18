// Copyright Epic Games, Inc. All Rights Reserved.

#include "MoreBPFunctionBPLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "MoreBPFunction.h"

UMoreBPFunctionBPLibrary::UMoreBPFunctionBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UMoreBPFunctionBPLibrary::MoreBPFunctionSampleFunction(float Param)
{
	return -1;
}

FVector UMoreBPFunctionBPLibrary::Spring_ByteToVector(const uint8 input)
{
	float nums = UKismetMathLibrary::Conv_ByteToFloat(input);
	return UKismetMathLibrary::Conv_FloatToVector(nums);
}

TArray<FVector> UMoreBPFunctionBPLibrary::Spring_GetActorsLocation(const TArray<AActor*>& input)
{
	TArray<FVector> Locations;
	if (input.Num()<=0)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Red,
				"ActorArrayIsEmpty"
			);
		}
		return Locations;
	}
	for (auto i : input)
	{
		if (i)
		{
			Locations.Add(i->GetActorLocation());
		}
	}
	return Locations;
}

FVector UMoreBPFunctionBPLibrary::Spring_IntToVector(const int32 input)
{
	return UKismetMathLibrary::Conv_IntToVector(input);
}

TArray<FVector> UMoreBPFunctionBPLibrary::Spring_FloatArrayToVectorArray(const TArray<float> input)
{
	TArray<FVector> Vectors;
	if (input.Num() <= 0)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Red,
				"FloatArrayIsEmpty"
			);
		}
		return Vectors;
	}
	for (float i : input)
	{
		Vectors.Add(UKismetMathLibrary::Conv_FloatToVector(i));
	}
	return Vectors;
}

TArray<FVector> UMoreBPFunctionBPLibrary::Spring_IntArrayToVectorArray(const TArray<int32> input)
{
	TArray<FVector> Vectors;
	if (input.Num() <= 0)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Red,
				"IntArrayIsEmpty"
			);
		}
		return Vectors;
	}
	for (int32 i : input)
	{
		Vectors.Add(UKismetMathLibrary::Conv_IntToVector(i));
	}
	return Vectors;
}
