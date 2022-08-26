// EpicMagaJam2022

using UnrealBuildTool;
using System.Collections.Generic;

public class EpicMegaJam2022Target : TargetRules
{
	public EpicMegaJam2022Target(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "EpicMegaJam2022" } );
	}
}
