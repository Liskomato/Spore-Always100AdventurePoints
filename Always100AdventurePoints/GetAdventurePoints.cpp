#include "stdafx.h"
#include "GetAdventurePoints.h"
#include "AdventureScore.h"

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
		uint32_t points = ScenarioMode.GetPlayMode()->mAdventurePoints;
		App::ConsolePrintF("Adventure points: %i",points);
	}
	else {
		App::ConsolePrintF("Global adventure point reward: %i", AdventureScore::points);
	}

}

const char* GetAdventurePoints::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Gives you the amount of points the adventure rewards.";
	}
	else {
		return "GetAdventurePoints: Returns the points the current adventure rewards. Outside adventure mode, returns the point amount all adventures reward with the Always 100 Adventure Points mod enabled.";
	}
}
