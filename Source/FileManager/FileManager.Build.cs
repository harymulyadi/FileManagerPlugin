// Some copyright should be here...

using UnrealBuildTool;

public class FileManager : ModuleRules
{
	public FileManager(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] { 
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] { 
			}
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
            { }
            );
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "Core", "CoreUObject", "Engine", "" +
				"Slate",
				"SlateCore", 	
                "InputCore", "Json", "JsonUtilities", 
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{ 
			}
			);
	}
}
