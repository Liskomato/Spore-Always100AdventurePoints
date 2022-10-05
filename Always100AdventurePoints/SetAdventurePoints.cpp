#include "stdafx.h"
#include "SetAdventurePoints.h"
#include "AdventureScore.h"

SetAdventurePoints::SetAdventurePoints()
{
}


SetAdventurePoints::~SetAdventurePoints()
{
}


void SetAdventurePoints::ParseLine(const ArgScript::Line& line)
{
	// This method is called when your cheat is invoked.
	// Put your cheat code here.

	
		int points;

		try {
			points = mpFormatParser->ParseInt(line.GetArgumentAt(1));
		}
		catch (...) {
			App::ConsolePrintF("Please input a positive number.");
			return;
		}
		if (points > 0) 
		{
			if (Simulator::IsScenarioMode() && ScenarioMode.GetPlayMode()) {

				App::ConsolePrintF("Old points: %i", ScenarioMode.GetPlayMode()->field_C4);
				ScenarioMode.GetPlayMode()->field_C4 = points;
				App::ConsolePrintF("New points: %i", points);
				return;
			}
			else {
				App::ConsolePrintF("Old points: %i", AdventureScore::points);
				AdventureScore::points = points;
				App::ConsolePrintF("New points: %i", points);
				return;
			}
		}
		App::ConsolePrintF("Please input a positive number.");
	

}

const char* SetAdventurePoints::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Sets the amount of points the current adventure rewards.";
	}
	else {
		return "SetAdventurePoints: If used outside adventures, sets the amount of points all adventures reward. If used inside adventure play mode, sets the amount of points that adventure will reward in the current playthrough.";
	}
}
