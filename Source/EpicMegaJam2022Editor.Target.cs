// EpicMagaJam2022

using UnrealBuildTool;
using System.Collections.Generic;

public class EpicMegaJam2022EditorTarget : TargetRules
{
	public EpicMegaJam2022EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "EpicMegaJam2022" } );
	}
}
