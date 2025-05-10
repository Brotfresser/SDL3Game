#include <SDL3/SDL.h>
#include "../../Sprite.h"
#include "../../global_functions.h"
//#include <string>


struct UIButtonNew : Sprite {
	UIButtonNew(SDL_Renderer* renderer, const char* file, float w = 0, float h = 0, 
		float x = 0, float y = 0)
		: Sprite(renderer, file, w, h, x, y)
	{
		SDL_Log("new");
		SDL_SetTextureAlphaMod(texture, 128);
	}

	void on_mouse_clicked() override {
		SDL_Log("game new");
		SDL_SetTextureAlphaMod(texture, 255);
	}
};


struct UIButtonLoad : Sprite {
	UIButtonLoad(SDL_Renderer* renderer, const char* file, float w = 0, float h = 0,
		float x = 0, float y = 0)
		: Sprite(renderer, file, w, h, x, y)
	{
		SDL_Log("load");
		SDL_SetTextureAlphaMod(texture, 128);
	}

	void on_mouse_clicked() override {
		SDL_Log("game load");
		SDL_SetTextureAlphaMod(texture, 255);
	}
};


struct UIButtonSettings : Sprite {
	UIButtonSettings(SDL_Renderer* renderer, const char* file, float w = 0, float h = 0, float x = 0, float y = 0)
		: Sprite(renderer, file, w, h, x, y)
	{
		SDL_Log("settings");
		SDL_SetTextureAlphaMod(texture, 128);
	}

	void on_mouse_clicked() override {
		SDL_Log("open settings");
		SDL_SetTextureAlphaMod(texture, 255);
	}
};


struct UIButtonSupport : public Sprite { 
	UIButtonSupport(SDL_Renderer* renderer, const char* file, float w = 0, float h = 0, float x = 0, float y = 0)
		: Sprite(renderer, file, w, h, x, y)
	{
		SDL_Log("suppotr");
		SDL_SetTextureAlphaMod(texture, 128);
	}

	void on_mouse_clicked() override {
		SDL_SetTextureAlphaMod(texture, 255);
		SDL_Log("open url");
		Global::openWebsite("https://nlch.itch.io/sister");
	}
};


struct UIButtonExit : Sprite {
	UIButtonExit(SDL_Renderer* renderer, const char* file, float w = 0, float h = 0, float x = 0, float y = 0)
		: Sprite(renderer, file, w, h, x, y)
	{
		SDL_Log("exit");
		SDL_SetTextureAlphaMod(texture, 128);
	}

	void on_mouse_clicked() override {
		SDL_Log("close game");
		SDL_SetTextureAlphaMod(texture, 255);
	}
};