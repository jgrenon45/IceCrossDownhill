// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class IceCrossDownhill : ModuleRules
{
	public IceCrossDownhill(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"IceCrossDownhill",
			"IceCrossDownhill/Variant_Platforming",
			"IceCrossDownhill/Variant_Combat",
			"IceCrossDownhill/Variant_Combat/AI",
			"IceCrossDownhill/Variant_SideScrolling",
			"IceCrossDownhill/Variant_SideScrolling/Gameplay",
			"IceCrossDownhill/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
