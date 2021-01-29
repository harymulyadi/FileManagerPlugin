// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine.h"
#include "Json.h"
#include "JsonUtilities.h"
#include "JsonObjectConverter.h"
#include "JsonFunctionLibrary.generated.h"

/**
 * 
 */


USTRUCT(BlueprintType)
struct FVectorStruct
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		float X;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		float Y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		float Z;
	FVectorStruct() {}
};

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		FVectorStruct Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		FVectorStruct Rotation;
	FTransformStruct() {}
};

USTRUCT(BlueprintType)
struct FAssetStruct
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		FString Guid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		FTransformStruct Position;
	FAssetStruct() {}
};

USTRUCT(BlueprintType)
struct FRecordMicroStruct
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		FTransformStruct Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		TArray<FAssetStruct> Assets;
	FRecordMicroStruct() {}
};

USTRUCT(BlueprintType)
struct FRecordDataStruct
{
	GENERATED_USTRUCT_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		FString Guid;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		float Deltatime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RecordData)
		TArray<FRecordMicroStruct> RecordMicros;
	FRecordDataStruct() {}
};


USTRUCT(BlueprintType)
struct FArrayVectorStruct
{
	GENERATED_USTRUCT_BODY()
 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	TArray<FVectorStruct> points;
	FArrayVectorStruct() {}
};


UCLASS()
class FILEMANAGER_API UJsonFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Json To Record Struct", Keywords = "Json Record Struct"), Category = "File Manager|Json Function")
		static void JsonToRecordStruct(FString Json, FRecordDataStruct& RecordData);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "JsonToArrayVector", Keywords = "JsonToArrayVector"), Category = "File Manager|Json Function")
		static void JsonToArrayVector(FString Json, TArray<FVectorStruct>& vectors);

	
};
