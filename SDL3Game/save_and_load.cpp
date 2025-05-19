#include "save_and_load.h"

#include "global_options.h"
#include <SDL3/SDL.h>
#include <fstream>
#include <nlohmann/json.hpp>


void load_options() {
	std::filesystem::create_directory("save");
    std::ifstream out_options("save/options.json");

    if (!out_options.is_open()) {
        out_options.close();
    	SDL_Log("Could not open options.json");
        save_options();
        return;
    }
	SDL_Log("opening options.json for loading");
	nlohmann::json load_json;
	try { // sometimes it skip (!out_options) for some reason
    out_options >> load_json;
    out_options.close();
		// load option vars here begin
	GameOptions::Fullscreen = load_json["Fullscreen"];
	GameOptions::Main_Volume = load_json["Main_Volume"];
	GameOptions::BGM_Volume = load_json["BGM_Volume"];
	GameOptions::BGS_Volume = load_json["BGS_Volume"];
	GameOptions::SE_Volume = load_json["SE_Volume"];
	GameOptions::Sister_Volume = load_json["Sister_Volume"];
	GameOptions::Max_Player_Msgs = load_json["Max_Player_Msgs"];
	GameOptions::Show_Weapon_Durability = load_json["Show_Weapon_Durability"];
		// load option vars here end
	}
	catch (const nlohmann::json_abi_v3_12_0::detail::parse_error &e) {
		SDL_LogWarn(SDL_LOG_PRIORITY_ERROR , "|Parsing error| %s", e.what());
		SDL_LogWarn(SDL_LOG_PRIORITY_ERROR , "position: %s", e.byte);
		SDL_LogWarn(SDL_LOG_PRIORITY_ERROR , "BLABLABLA, seems like program can't find options.json or you're version of options.json is corrupted");
	}
	load_json.clear();
}


void load_game_file(const char* path_to_file) {
	std::filesystem::create_directory("save");
	std::ifstream out_file(path_to_file);

	if (!out_file.is_open()) {
		out_file.close();
		SDL_Log("Could not open %s", path_to_file);
		save_game_file(path_to_file);
		return;
	}
	SDL_Log("opening %s for loading", path_to_file);
	nlohmann::json load_json;
	try { // sometimes it skip (!out_options) for some reason
		out_file >> load_json;
		out_file.close();
		//load game vars here begin
		//load game vars here end
	}
	catch (const nlohmann::json_abi_v3_12_0::detail::parse_error &e) {
		SDL_LogWarn(SDL_LOG_PRIORITY_ERROR , "|Parsing error| %s", e.what());
		SDL_LogWarn(SDL_LOG_PRIORITY_ERROR , "position: %s", e.byte);
		SDL_LogWarn(SDL_LOG_PRIORITY_ERROR , "BLABLABLA, seems like program can't find save/options.json or it's corrupted, try delete it");
	}
	load_json.clear();
}


void save_options() {
	std::filesystem::create_directory("save");
	nlohmann::json save_json;
	SDL_Log("saving options.json");
// save option vars here begin
	save_json["Fullscreen"] = GameOptions::Fullscreen;
	save_json["Main_Volume"] = GameOptions::Main_Volume;
	save_json["BGM_Volume"] = GameOptions::BGM_Volume;
	save_json["BGS_Volume"] = GameOptions::BGS_Volume;
	save_json["SE_Volume"] = GameOptions::SE_Volume;
	save_json["Sister_Volume"] = GameOptions::Sister_Volume;
	save_json["Max_Player_Msgs"] = GameOptions::Max_Player_Msgs;
	save_json["Show_Weapon_Durability"] = GameOptions::Show_Weapon_Durability;
// save option vars here end
    std::ofstream out("save/options.json");
    out << save_json.dump(2);
    out.close();
    save_json.clear();
}


void save_game_file(const char* path_to_file) {
	std::filesystem::create_directory("save");
	nlohmann::json save_json;
	SDL_Log("saving %s", path_to_file);
	//save game vars here begin
	//save game vars here end
	std::ofstream out(path_to_file);
	out << save_json.dump(2);
	out.close();
	save_json.clear();
}