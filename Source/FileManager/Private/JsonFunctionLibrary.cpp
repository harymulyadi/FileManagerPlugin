// Fill out your copyright notice in the Description page of Project Settings.

#include "JsonFunctionLibrary.h"

void UJsonFunctionLibrary::JsonToRecordStruct(FString Json, FRecordDataStruct& RecordData) {
	FJsonObjectConverter::JsonObjectStringToUStruct(Json, &RecordData, 0, 0);
}

void UJsonFunctionLibrary::JsonToArrayVector(FString Json, TArray<FVectorStruct>& vectors) {
	FJsonObjectConverter::JsonArrayStringToUStruct(Json, &vectors, 0, 0);
}

