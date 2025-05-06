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
	TTF_CloseFont(font);
	BaseSprite::~BaseSprite();
}


void TextRect::load_texture(float w, float h) {
	w = h = 0;  // не нужны
	this->font = TTF_OpenFont(path_to_file, text_size);

	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), text.size(), text_color);
	this->texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	SDL_DestroySurface(text_surface);
	SDL_GetTextureSize(texture, &rect_w, &rect_h);
	srcrect.w = rect_w; srcrect.h = rect_h;
}


void TextRect::draw() {
	SDL_RenderTexture(renderer, texture, NULL, &dstrect);
}


void TextRect::change_font(std::string path_to_file) {
	this->path_to_file = path_to_file.c_str();
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
	load_texture();
}


void TextRect::change_text_color(SDL_Color new_color) {
	this->text_color = new_color;
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
	load_texture();
}


void TextRect::change_text_size(float new_text_size) {
	text_size = new_text_size;
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
	load_texture();
}


void TextRect::change_text(std::string new_text) {
	text = new_text;
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);
	load_texture();
}

void update() {

}


std::string TextRect::get_text() {
	return text;
}