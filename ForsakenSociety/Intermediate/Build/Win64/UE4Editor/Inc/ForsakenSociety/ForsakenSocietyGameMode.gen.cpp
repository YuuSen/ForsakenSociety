// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ForsakenSociety/ForsakenSocietyGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeForsakenSocietyGameMode() {}
// Cross Module References
	FORSAKENSOCIETY_API UClass* Z_Construct_UClass_AForsakenSocietyGameMode_NoRegister();
	FORSAKENSOCIETY_API UClass* Z_Construct_UClass_AForsakenSocietyGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_ForsakenSociety();
// End Cross Module References
	void AForsakenSocietyGameMode::StaticRegisterNativesAForsakenSocietyGameMode()
	{
	}
	UClass* Z_Construct_UClass_AForsakenSocietyGameMode_NoRegister()
	{
		return AForsakenSocietyGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AForsakenSocietyGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AForsakenSocietyGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_ForsakenSociety,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AForsakenSocietyGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "ForsakenSocietyGameMode.h" },
		{ "ModuleRelativePath", "ForsakenSocietyGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AForsakenSocietyGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AForsakenSocietyGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AForsakenSocietyGameMode_Statics::ClassParams = {
		&AForsakenSocietyGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AForsakenSocietyGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AForsakenSocietyGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AForsakenSocietyGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AForsakenSocietyGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AForsakenSocietyGameMode, 1243479027);
	template<> FORSAKENSOCIETY_API UClass* StaticClass<AForsakenSocietyGameMode>()
	{
		return AForsakenSocietyGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AForsakenSocietyGameMode(Z_Construct_UClass_AForsakenSocietyGameMode, &AForsakenSocietyGameMode::StaticClass, TEXT("/Script/ForsakenSociety"), TEXT("AForsakenSocietyGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AForsakenSocietyGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
