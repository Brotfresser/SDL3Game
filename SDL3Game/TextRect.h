#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "Sprite.h"

#include <string>
#define STDSTRING

#define SDL_TEXT_COLOR_BLACK {0, 0, 0, 255}
#define SDL_TEXT_COLOR_WHITE {255, 255, 255, 255}

class TextRect: public Sprite
{
protected:
	TTF_Font* font;
	SDL_Color text_color;
	int text_size;
	std::string text;

public:
	TextRect(SDL_Renderer* renderer, std::string text = "Sample text", SDL_Color text_color = SDL_TEXT_COLOR_WHITE, 
		float font_size = 16, const char* file = "assets/fonts/PixelifySans-Regular.ttf");

	~TextRect();
	void update_texture();
	//void change_font(std::string path_to_file);
	//void change_text_color(SDL_Color new_color);
	//void change_text_size(int new_text_size);
	void change_text(std::string new_text);
	void draw();
};

