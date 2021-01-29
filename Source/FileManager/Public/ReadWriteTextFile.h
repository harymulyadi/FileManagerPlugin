// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Runtime/Core/Public/Misc/Paths.h"
#include "Runtime/Core/Public/HAL/PlatformFilemanager.h"
#include "Runtime/Core/Public/GenericPlatform/GenericPlatformFile.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "Runtime/Json/Public/Dom/JsonObject.h"
#include "Runtime/Json/Public/Serialization/JsonReader.h"
#include "Runtime/Json/Public/Serialization/JsonWriter.h"
#include "Runtime/Json/Public/Serialization/JsonSerializer.h"
#include "Runtime/Core/Public/Templates/SharedPointer.h"

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ReadWriteTextFile.generated.h"

/**
 * 
 */
UCLASS()
class FILEMANAGER_API UReadWriteTextFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "WriteFile", Keywords = "WriteFile"), Category = "File Manager|Read Write File")
		static void WriteFile(FString filePath, FString content, bool append, bool &Success, FString& output);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "ReadFile", Keywords = "ReadFile"), Category = "File Manager|Read Write File")
		static void ReadFile(FString filePath, bool &Success, FString& content, FString& output);

private:
	static bool CreateDirectory(FString directory);
	static bool IsAbsolutePathExist(FString absolutePath);
	
};
