// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ForsakenSociety : ModuleRules
{
	public ForsakenSociety(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
