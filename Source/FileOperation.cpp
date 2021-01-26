// Fill out your copyright notice in the Description page of Project Settings.
 
#include "FileOperation.h"
#include <string>
#include <fstream>
#include <ios>
#include <iostream>
#include "Filemanager.h"
#include "Misc/Paths.h"
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"

#include "Windows/MinWindows.h"
#include <shobjidl.h> 


void UFileOperation::DoesFileExist(FString filePath, bool &exist)
{
	//exist = FPlatformFileManager::Get().GetPlatformFile().FileExists(*filePath);
	exist = FPaths::FileExists(*filePath);
}

void UFileOperation::DoesDirExist(FString filePath, bool &exist)
{
	exist = false;
	std::string dirName_in(TCHAR_TO_UTF8(*filePath));
	unsigned long ftyp = GetFileAttributesA(dirName_in.c_str());
	if ((dirName_in.find('\\') == std::string::npos) && (ftyp & FILE_ATTRIBUTE_DIRECTORY))
	{
		exist = true;
	}
}

void UFileOperation::CopyAFile(FString from, FString to, bool &success)
{
	/*try
	{*/
	std::ifstream src(TCHAR_TO_UTF8(*from), std::ios::binary);
	std::ofstream dst(TCHAR_TO_UTF8(*to), std::ios::binary);
	dst << src.rdbuf();
	success = true;
	/*}
	catch(...)
	{
	success = false;
	}*/
}

void UFileOperation::DeleteAFile(FString path, bool &success)
{
	std::string pathString(TCHAR_TO_UTF8(*path));
	success = std::remove(pathString.c_str()) == 0;
}

void UFileOperation::GetFilesOnDir(FString dirPath, FString ext, TArray<FString> &fileNames)
{
	fileNames.Empty();
	if (FPaths::DirectoryExists(dirPath))
	{
		FString finalPath = dirPath + TEXT("/*.") + ext;
		IFileManager& FileManager = IFileManager::Get();
		FileManager.FindFiles(fileNames, *finalPath, true, false);
		for (int i = 0; i < fileNames.Num(); i++)
		{
			fileNames[i] = dirPath + fileNames[i];
		}
	}
}

void UFileOperation::GetSystemSaveGameDirectory(FString &Path)
{
	Path = FPaths::ProjectSavedDir() + TEXT("SaveGames/");
}

void UFileOperation::GetMyComputerName(FString &Name)
{
	Name = FPlatformProcess::ComputerName();
}

void UFileOperation::OpenFolderDialog(FString DialogTitle, FString DefaultPath, FString &FolderLocation)
{
	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED |
		COINIT_DISABLE_OLE1DDE);
	if (SUCCEEDED(hr))
	{
		IFileOpenDialog *pFileOpen;

		// Create the FileOpenDialog object.
		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
			IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

		if (SUCCEEDED(hr))
		{
			// setting open dialog
			pFileOpen->SetOptions(FOS_PICKFOLDERS);
			// Show the Open dialog box.
			hr = pFileOpen->Show(NULL);

			// Get the file name from the dialog box.
			if (SUCCEEDED(hr))
			{
				IShellItem *pItem;
				hr = pFileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

					// Display the file name to the user.
					if (SUCCEEDED(hr))
					{
						//MessageBox(NULL, pszFilePath, L"File Path", MB_OK);
						FolderLocation = pszFilePath;
						CoTaskMemFree(pszFilePath);
					}
					pItem->Release();
				}
			}
			pFileOpen->Release();
		}
		CoUninitialize();
	}
	//if (GEngine)
	//{
	//	if (GEngine->GameViewport)
	//	{
	//		void* ParentWindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
	//		IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
	//		if (DesktopPlatform)
	//		{
	//			uint32 SelectionFlag = 0; //A value of 0 represents single file selection while a value of 1 represents multiple file selection
	//			DesktopPlatform->OpenDirectoryDialog(ParentWindowHandle, DialogTitle, DefaultPath, FolderLocation);
	//		}
	//	}
	//}
}

