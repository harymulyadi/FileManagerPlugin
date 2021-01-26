// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileOperation.generated.h"

/**
 * 
 */
UCLASS()
class FILEMANAGER_API UFileOperation : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Does File Exist", Keywords = "Does File Exist"), Category = "File Manager|File Operation")
		static void DoesFileExist(FString filePath, bool &exist);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Copy File", Keywords = "Copy File"), Category = "File Manager|File Operation")
		static void CopyAFile(FString from, FString to, bool &success);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Delete File", Keywords = "Delete File"), Category = "File Manager|File Operation")
		static void DeleteAFile(FString Path, bool &success);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get System Save Game Directory", Keywords = "Get Save Directory"), Category = "File Manager|File Operation")
		static void GetSystemSaveGameDirectory(FString &Path);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Files on Directory", Keywords = "Get Files on Directory"), Category = "File Manager|File Operation")
		static void GetFilesOnDir(FString dirPath, FString ext, TArray<FString>& fileNames);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Does Directory Exist", Keywords = "Does Directory Exist"), Category = "File Manager|File Operation")
		static void DoesDirExist(FString dirPath, bool &exist);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Computer Name", Keywords = "Get Computer Name"), Category = "File Manager|File Operation")
		static void GetMyComputerName(FString &Name);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Open Folder Dialog", Keywords = "Open Folder Dialog"), Category = "File Manager|File Operation")
		static void OpenFolderDialog(FString DialogTitle, FString DefaultPath, FString &FolderLocation);

	/*UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get File Extention", Keywords = "Get File Extention"), Category = "File Manager")
	static void GetFileExt(FString filePath, FString &ext);*/


	/*UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Filename", Keywords = "Get Filename"), Category = "File Manager")
	static void GetFilenameFromPath(FString path, FString &fullFilename, FString &filename, FString &ext);*/

	/*UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get System Save Directory", Keywords = "Get Save Directory"), Category = "File Manager")
	static void GetSystemSaveDirectory(FString &Path);*/
 
};
