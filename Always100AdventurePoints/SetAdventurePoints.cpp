#include "stdafx.h"
#include "SetAdventurePoints.h"
#include "AdventureScore.h"
#include <string>

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

	
		uint32_t points;
		string str;

		try {
			points = mpFormatParser->ParseInt(line.GetArgumentAt(1));
		}
		catch (...) {
			App::ConsolePrintF("Please input a positive number.");
			return;
		}
		if (points >= 0) 
		{
			if (points > 100) App::ConsolePrintF("WARNING: Setting point reward over 100 is not recommended! Levelling up twice may cause a softlock.");
			
			if (Simulator::IsScenarioMode() && ScenarioMode.GetPlayMode()) {

				App::ConsolePrintF("Old points: %i", ScenarioMode.GetPlayMode()->mAdventurePoints);
				ScenarioMode.GetPlayMode()->mAdventurePoints = points;
				App::ConsolePrintF("New points: %i", points);
				return;
			}
			else {
				App::ConsolePrintF("Old points: %i", AdventureScore::points);
				AdventureScore::points = points;
				App::ConsolePrintF("New points: %i", points);

				FileStreamPtr stream = new IO::FileStream(AdventureScore::path.c_str());
				PropertyListPtr propList = new App::PropertyList();

				str.assign_convert(AdventureScore::path);

				if (AdventureScore::SetScoreValue(propList.get(), stream.get(), points)) {
					App::ConsolePrintF("Saved new adventure point data to %s",str);
				}
				else {
					App::ConsolePrintF("Always 100 Adventure Points ERROR: Failed to write adventure point data.");
				}
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
