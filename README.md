# Spore-Always100AdventurePoints
 A Spore ModAPI mod that makes it that all adventures always give out 100 points, regardless whether they're shared or not. The mod also allows for editing said point data to the amount designated by the player.

![Example of edited points](Always100AdventurePoints.png)

 This mod adds two new cheats to the game:
 * `getAdventurePoints` - Returns the amount of points your captain will be rewarded in their next adventure.
 * `setAdventurePoints` - Inside adventures, temporarily edits the amount of Spore points the current adventure will reward you. Outside adventures, allows for editing and saving the global adventure point reward this mod will set up. Said data will be saved to `%APPDATA%\Spore\Preferences\AdventureScore.prop`.

**Requires the following to...**
### Compile
* Visual Studio 2022
* Spore ModAPI Development Kit
* A zip file manager (for packing the .sporemod file ~by renaming a .zip file~)

### Install and play
* Spore and Galactic Adventures expansion pack, preferably from Origin or GoG
* Spore ModAPI Launcher Kit, preferably a version from after 2019

## Special thanks
* emd4600, for helping out with debugging and overall research.
* VanillaCold & Rosalie, for their work in ModAPI mods regarding save data.