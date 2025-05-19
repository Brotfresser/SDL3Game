#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "Sprites/BaseSprite.h"

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
	explicit TextRect(SDL_Renderer* renderer, std::string text = "Sample text", float x = 200, float y = 200,
		SDL_Color text_color = SDL_TEXT_COLOR_WHITE,
		float text_size = 16, const char* file = "assets/fonts/FOT-NewCinemaAStd-D.otf");

	~TextRect() override;
	void load_texture(float w = 0, float h = 0) override;
	void draw() override;

	virtual void change_font(std::string path_to_file);
	virtual void change_text_color(SDL_Color new_color);
	virtual void change_text_size(float new_text_size);
	virtual void change_text(std::string new_text);

	std::string get_text();
};

