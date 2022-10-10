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

		string16 path = u"C:\\Users\\tende\\Documents\\scenarioprops.prop";
		string str;
		
		auto output = new IO::FileStream(path.c_str());

		auto data = ScenarioMode.GetResource();

		output->Open(IO::kAccessFlagReadWrite, IO::kCDCreateAlways);
		str.assign_convert(path);

		if (data->mpPropList.Write(output)) {
			App::ConsolePrintF("Prop data successfully saved to %s",str);
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
