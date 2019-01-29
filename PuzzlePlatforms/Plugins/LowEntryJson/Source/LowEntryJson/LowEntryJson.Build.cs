using System.IO;

namespace UnrealBuildTool.Rules
{
	public class LowEntryJson : ModuleRules
	{
		public LowEntryJson(ReadOnlyTargetRules Target) : base(Target)
        {
            PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

            PublicIncludePaths.AddRange(
				new string[] {
                    Path.Combine(ModuleDirectory, "Public/Module"),
                    Path.Combine(ModuleDirectory, "Public/Classes"),
                    Path.Combine(ModuleDirectory, "Public/Enums"),
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
					"Json",
				}
			);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
				}
			);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
				}
			);
		}
	}
}
