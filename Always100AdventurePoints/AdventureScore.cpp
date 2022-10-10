#include "stdafx.h"
#include "stdio.h"
#include "shlobj.h"
#include "AdventureScore.h"
#include <Spore\Properties.h>
#include <string>

uint32_t AdventureScore::points = 100;

string16 AdventureScore::path = AdventureScore::GetPath();


string16 AdventureScore::GetPath() {

	// Get %APPDATA%
	PWSTR appdata;
/*	size_t len;
	errno_t err = getenv_s(&appdata, &len, u"APPDATA");*/

	if (SHGetKnownFolderPath(FOLDERID_RoamingAppData, KF_FLAG_CREATE, NULL, &appdata) != S_OK) {
		// This shouldn't happen.
		return NULL;
	}
	

	// Add rest of the filepath.

	string16 path = (char16_t*)appdata;

	path += u"\\Spore\\Preferences\\AdventureScore.prop";

	return path;
}


bool AdventureScore::Initialize() {
//	ManualBreakpoint();
	string str;
	// Initialize filestream and prop list.
	FileStreamPtr stream = new IO::FileStream(AdventureScore::path.c_str());
	PropertyListPtr propList = new App::PropertyList();
//	PropManager.SetPropertyList(propList.get(), );
	
	// Read prop list (if it exists).
	if (stream->Open(IO::kAccessFlagRead, IO::kCDOpenExisting)) {
		propList->Read(stream.get());
		stream->Close();
	}
	// Check if property already exists.
	if (propList->HasProperty(id("AdventureScore"))) {
		App::Property::GetUInt32(propList.get(), id("AdventureScore"), points);
		str.assign_convert(path);
		App::ConsolePrintF("Always 100 Adventure Points: Loaded adventure point data from %s", str);
		return true;
	}
	else {

		// Otherwise initialize value and save it to the filepath. 

		bool check = SetScoreValue(propList.get(), stream.get(), points);
		str.assign_convert(path);

		// Boolean value check determines if writing was successful or not.
		if (check) {
			App::ConsolePrintF("Always 100 Adventure Points: Initialized save file data for the mod to %s", str);
		}
		else {
			App::ConsolePrintF("Always 100 Adventure Points ERROR: Failed to initialize save file data.");
		}
		return check;
	}
	App::ConsolePrintF("Always 100 Adventure Points ERROR: Failed to read adventure point data.");
	return false;
}

bool AdventureScore::SetScoreValue(App::PropertyList* propList, IO::FileStream* stream,uint32_t points) {
	
	propList->SetProperty(id("AdventureScore"), &App::Property().SetValueUInt32(points));

	stream->Open(IO::kAccessFlagReadWrite, IO::kCDCreateAlways);
	bool check = propList->Write(stream);
	stream->Close();
	return check;
}