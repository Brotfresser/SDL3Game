#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "BaseSprite.h"

#include <string>
#define STDSTRING

#define SDL_TEXT_COLOR_BLACK {0, 0, 0, 255}
#define SDL_TEXT_COLOR_WHITE {255, 255, 255, 255}

class TextRect: public BaseSprite
{
protected:
	TTF_Font* font;
	std::string text;
	SDL_Color text_color;
	int text_size;	

public:
	TextRect(SDL_Renderer* renderer, std::string text = "Sample text", float x = 0, float y = 0, 
		SDL_Color text_color = SDL_TEXT_COLOR_WHITE,
		float text_size = 16, const char* file = "assets/fonts/PixelifySans-Regular.ttf");

	virtual ~TextRect() override;
	virtual void load_texture(float w = 0, float h = 0) override;
	virtual void draw() override;

	void change_font(std::string path_to_file);
	void change_text_color(SDL_Color new_color);
	void change_text_size(int new_text_size);
	void change_text(std::string new_text);

	std::string get_text();
};

