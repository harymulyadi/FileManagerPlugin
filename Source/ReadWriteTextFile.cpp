// Fill out your copyright notice in the Description page of Project Settings.

#include "ReadWriteTextFile.h"

void UReadWriteTextFile::WriteFile(FString fileName, FString content, bool append, bool &Success, FString& output)
{
	TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	JsonObject->SetStringField("Name", "Super Sword");
	JsonObject->SetNumberField("Damage", 15);
	JsonObject->SetNumberField("Weight", 3);

	FString OutputString;
	TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), Writer);

	FString FilePath = FPaths::Combine(FPaths::ProjectSavedDir(), fileName);
	if (IsAbsolutePathExist(fileName))
	{
		FilePath = fileName;
	}
	FFileHelper::SaveStringToFile(content, *FilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(),
		append ? EFileWrite::FILEWRITE_Append : EFileWrite::FILEWRITE_None);
}

void UReadWriteTextFile::ReadFile(FString fileName, bool & Success, FString & content, FString & output)
{
	FString FilePath = FPaths::Combine(FPaths::ProjectSavedDir(), fileName);
	FFileHelper::LoadFileToString(content, *FilePath);
}

bool UReadWriteTextFile::CreateDirectory(FString directory)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	// CreateDirectoryTree returns true if the destination
	// directory existed prior to call or has been created
	// during the call.
	return PlatformFile.CreateDirectoryTree(*directory);
}

bool UReadWriteTextFile::IsAbsolutePathExist(FString absolutePath)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	return PlatformFile.FileExists(*absolutePath);
}



