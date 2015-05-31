#include "ModulePlayer.h"
#include <sstream>
#include "../ElDorito.h"

namespace Modules
{
	ModulePlayer::ModulePlayer() : ModuleBase("Player")
	{
		VarArmorAccessory = AddVariableString("Armor.Accessory", "armor_accessory", "Armor ID for player accessory", "", VariablePlayerArmorAccessoryUpdate);
		VarArmorArms = AddVariableString("Armor.Arms", "armor_arms", "Armor ID for player arms", "", VariablePlayerArmorArmsUpdate);
		VarArmorChest = AddVariableString("Armor.Chest", "armor_chest", "Armor ID for player chest", "", VariablePlayerArmorChestUpdate);
		VarArmorHelmet = AddVariableString("Armor.Helmet", "armor_helmet", "Armor ID for player helmet", "", VariablePlayerArmorHelmetUpdate);
		VarArmorLegs = AddVariableString("Armor.Legs", "armor_legs", "Armor ID for player legs", "", VariablePlayerArmorLegsUpdate);
		VarArmorPelvis = AddVariableString("Armor.Pelvis", "armor_pelvis", "Armor ID for player pelvis", "", VariablePlayerArmorPelvisUpdate);
		VarArmorShoulders = AddVariableString("Armor.Shoulders", "armor_shoulders", "Armor ID for player shoulders", "", VariablePlayerArmorShouldersUpdate);

		VarColorsPrimary = AddVariableString("Colors.Primary", "colors_primary", "The primary colors hex value", "#000000", VariablePlayerColorsPrimaryUpdate);
		VarColorsSecondary = AddVariableString("Colors.Secondary", "colors_secondary", "The secondary colors hex value", "#000000", VariablePlayerColorsSecondaryUpdate);
		VarColorsVisor = AddVariableString("Colors.Visor", "colors_visor", "The visor colors hex value", "#000000", VariablePlayerColorsVisorUpdate);
		VarColorsLights = AddVariableString("Colors.Lights", "colors_lights", "The lights colors hex value", "#000000", VariablePlayerColorsLightsUpdate);
		VarColorsHolo = AddVariableString("Colors.Holo", "colors_holo", "The holo colors hex value", "#000000", VariablePlayerColorsHoloUpdate);

		VarPlayerName = AddVariableString("Name", "name", "The players ingame name", "Jasper", VariablePlayerNameUpdate);
		VarUserID = AddVariableInt64("UserID", "userid", "The players unique user ID", 0xbeefcafe, VariablePlayerUserIDUpdate);

		memset(this->UserName, 0, sizeof(wchar_t)* 17);

		// patch Game_GetPlayerName to get the name from our field
		Pointer::Base(0x42AA1).Write<uint32_t>((uint32_t)&this->UserName);

		// patch BLF save func to get the name from our field
		Pointer::Base(0x124E6A).Write<uint32_t>((uint32_t)&this->UserName);

		char* defaultNames[41] = {
			"Donut", "Penguin", "Stumpy", "Whicker", "Shadow", "Howard", "Wilshire",
			"Darling", "Disco", "Jack", "The Bear", "Sneak", "The Big ", "Whisp",
			"Wheezy", "Crazy", "Goat", "Pirate", "Saucy", "Hambone", "Butcher",
			"Walla Walla", "Snake", "Caboose", "Sleepy", "Killer", "Stompy",
			"Mopey", "Dopey", "Wease", "Ghost", "Dasher", "Grumpy", "Hollywood",
			"Tooth", "Noodle", "King", "Cupid", "Prancer", "Pyong", "Jasper"
		};

		srand((unsigned int)time(0));
		Modules::CommandMap::Instance().SetVariable(VarPlayerName, std::string(defaultNames[rand() % 41]), std::string());
	}
}

namespace
{
	bool VariablePlayerArmorAccessoryUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}

	bool VariablePlayerArmorArmsUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}

	bool VariablePlayerArmorChestUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}

	bool VariablePlayerArmorHelmetUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}

	bool VariablePlayerArmorLegsUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}

	bool VariablePlayerArmorPelvisUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}

	bool VariablePlayerArmorShouldersUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}

	bool VariablePlayerColorsPrimaryUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}

	bool VariablePlayerColorsSecondaryUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}

	bool VariablePlayerColorsVisorUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}

	bool VariablePlayerColorsLightsUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}

	bool VariablePlayerColorsHoloUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}

	bool VariablePlayerNameUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		std::string name = Modules::ModulePlayer::Instance().VarPlayerName->ValueString;

		std::wstring nameStr = Utils::String::WidenString(name);
		wcscpy_s(Modules::ModulePlayer::Instance().UserName, 16, nameStr.c_str());
		std::string actualName = Utils::String::ThinString(Modules::ModulePlayer::Instance().UserName);

		return true;
	}

	bool VariablePlayerUserIDUpdate(const std::vector<std::string>& Arguments, std::string& returnInfo)
	{
		return true;
	}
}
