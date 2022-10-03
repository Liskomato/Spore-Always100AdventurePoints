#include "stdafx.h"
#include "GetAdventurePoints.h"

GetAdventurePoints::GetAdventurePoints()
{
}


GetAdventurePoints::~GetAdventurePoints()
{
}


void GetAdventurePoints::ParseLine(const ArgScript::Line& line)
{
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
	if (Simulator::IsScenarioMode() && ScenarioMode.GetPlayMode())
	{
		int points = ScenarioMode.GetPlayMode()->field_C4;
		App::ConsolePrintF("Adventure points: %i",points);
	}

}

const char* GetAdventurePoints::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Gives you the amount of points the adventure has..";
	}
	else {
		return "GetAdventurePoints: Returns the points the adventure rewards.";
	}
}
