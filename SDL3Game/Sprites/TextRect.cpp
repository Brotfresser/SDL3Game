#include "TextRect.h"


TextRect::TextRect(SDL_Renderer* renderer, std::string text, float x, float y, SDL_Color text_color, float text_size, const char* file)
	: BaseSprite(renderer, file, x, y)
{
	this->text = text;
	this->text_color = text_color;
	this->text_size = text_size;
	load_texture();
}

TextRect::~TextRect() {
	if (font)
		TTF_CloseFont(font);
	BaseSprite::~BaseSprite();
}


void TextRect::load_texture(float w, float h) {
	w = h = 0; // не нужны
	if (texture)
		SDL_DestroyTexture(texture);
	if (font)
		TTF_CloseFont(font);

	font = TTF_OpenFont(path_to_file, text_size);
	if (!font)
		SDL_Log("error loading font: %s", SDL_GetError());

	SDL_Surface* text_surface = TTF_RenderText_Blended(font, text.c_str(), text.size(), text_color);
	if (!text_surface)
		SDL_Log("error SDL_Surface text: %s", SDL_GetError());
	texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if (!texture)
		SDL_Log("error creating from SDL_Surface text: %s", SDL_GetError());
	SDL_DestroySurface(text_surface);
	SDL_GetTextureSize(texture, &rect_w, &rect_h);
	dstrect.w = rect_w; dstrect.h = rect_h;
}


void TextRect::draw() {
	SDL_RenderTexture(renderer, texture, NULL, &dstrect);
}


void TextRect::change_font(std::string path_to_file) {
	this->path_to_file = path_to_file.c_str();
	load_texture();
}


void TextRect::change_text_color(SDL_Color new_color) {
	this->text_color = new_color;
	load_texture();
}


void TextRect::change_text_size(float new_text_size) {
	text_size = new_text_size;
	load_texture();
}


void TextRect::change_text(std::string new_text) {
	text = new_text;
	load_texture();
}


std::string TextRect::get_text() {
	return text;
}