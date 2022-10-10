#pragma once
struct AdventureScore {
	static uint32_t points;
	static string16 path;
	static bool Initialize();
	static bool SetScoreValue(App::PropertyList* propList, IO::FileStream* stream,uint32_t points);
	static string16 GetPath();
};