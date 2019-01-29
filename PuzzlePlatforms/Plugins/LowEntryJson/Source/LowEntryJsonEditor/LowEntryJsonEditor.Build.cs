using System.IO;

namespace UnrealBuildTool.Rules
{
	public class LowEntryJsonEditor : ModuleRules
	{
		public LowEntryJsonEditor(ReadOnlyTargetRules Target) : base(Target)
        {
            PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

            PublicIncludePaths.AddRange(
				new string[] {
                    Path.Combine(ModuleDirectory, "Public/Module"),
                    Path.Combine(ModuleDirectory, "Public/Classes"),
				}
			);

			PrivateIncludePaths.AddRange(
				new string[] {
                    Path.Combine(ModuleDirectory, "Private/Module"),
                    Path.Combine(ModuleDirectory, "Private/Classes"),
				}
			);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Engine",
					"Core",
					"CoreUObject",
					"InputCore",
					"Slate",
					"EditorStyle",
					"AIModule",
					"BlueprintGraph",
					"LowEntryJson",
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"EditorStyle",
					"KismetCompiler",
					"UnrealEd",
					"GraphEditor",
					"SlateCore",
                    "Kismet",
                    "KismetWidgets",
                    "PropertyEditor",
                }
			);
		}
	}
}
