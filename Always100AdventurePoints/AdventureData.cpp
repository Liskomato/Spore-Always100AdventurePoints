#include "stdafx.h"
#include "AdventureData.h"

AdventureData::AdventureData()
{
}


AdventureData::~AdventureData()
{
}


void AdventureData::ParseLine(const ArgScript::Line& line)
{
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
	if (Simulator::IsScenarioMode()) {

		const char16_t* path = u"C:\\Users\\tende\\Documents\\scenarioprops.prop";
		
		auto output = new IO::FileStream(path);

		auto data = ScenarioMode.GetResource();

		output->Open(IO::kAccessFlagReadWrite, IO::kCDCreateAlways);

		if (data->mpPropList.Write(output)) {
			App::ConsolePrintF("Prop data successfully saved to %s44",path);
		}
		else {
			App::ConsolePrintF("Failed to write prop data for adventure.");
		}
		output->Close();

		delete output;
	}
	else {
		App::ConsolePrintF("You have to be in an adventure to use this cheat.");
	}
}

const char* AdventureData::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "Saves adventure property list data.";
	}
	else {
		return "GetAdventureProp: Saves a prop file of the adventure's property list.";
	}
}
