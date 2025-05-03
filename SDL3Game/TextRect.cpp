#include "TextRect.h"


TextRect::TextRect(SDL_Renderer* renderer, std::string text, SDL_Color text_color, float font_size, const char* file) :
	Sprite(renderer, "")
{
	this->text = text;
	this->text_color = text_color;
	this->text_size = font_size;
	path_to_file = file;

	//this->font = TTF_OpenFont(path_to_file, text_size);
	update_texture();

	dstrect = { 0, 0, rect_w, rect_h };
	srcrect = dstrect;
}

TextRect::~TextRect() {
	SDL_DestroyTexture(texture);
}


void TextRect::update_texture() {
	this->font = TTF_OpenFont(path_to_file, text_size);
	// если находится здесь, то бесконечно заполняет память

	SDL_Surface* text_surface = TTF_RenderText_Solid(font, text.c_str(), text.size(), text_color);
	this->texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	SDL_DestroySurface(text_surface);

	SDL_GetTextureSize(texture, &rect_w, &rect_h);
}


//void TextRect::change_font(std::string path_to_file) {
//	this->path_to_file = path_to_file.c_str();
//	SDL_DestroyTexture(texture);
//	update_texture();
//}
//
//
//void TextRect::change_text_color(SDL_Color new_color) {
//	this->text_color = new_color;
//	SDL_DestroyTexture(texture);
//	update_texture();
//}
//
//
//void TextRect::change_text_size(int new_text_size) {
//	text_size = new_text_size;
//	SDL_DestroyTexture(texture);
//	update_texture();
//}


void TextRect::change_text(std::string new_text) {
	text = new_text;
	SDL_DestroyTexture(texture);
	update_texture();
}


void TextRect::draw() {
	SDL_RenderTexture(renderer, texture, &srcrect, &dstrect);
}

void update() {

}


