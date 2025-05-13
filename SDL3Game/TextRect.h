#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "BaseSprite.h"

#include <string>

#define SDL_TEXT_COLOR_BLACK {0, 0, 0, 255}
#define SDL_TEXT_COLOR_WHITE {255, 255, 255, 255}

class TextRect: public BaseSprite
{
protected:
	TTF_Font* font = nullptr;
	std::string text;
	SDL_Color text_color;
	float text_size;

public:
	TextRect(SDL_Renderer* renderer, std::string text = "Sample text", float x = 200, float y = 200,
		SDL_Color text_color = SDL_TEXT_COLOR_WHITE,
		float text_size = 16, const char* file = "assets/fonts/PixelifySans-Regular.ttf", int text_len = 0);

	~TextRect() override;
	void load_texture(float w = 0, float h = 0) override;
	void draw() override;

	void change_font(std::string path_to_file);
	void change_text_color(SDL_Color new_color);
	void change_text_size(float new_text_size);
	void change_text(std::string new_text);

	std::string get_text();
};

