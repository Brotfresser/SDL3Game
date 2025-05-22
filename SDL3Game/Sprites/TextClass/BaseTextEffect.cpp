#include "BaseTextEffect.h"

BaseTextEffect::BaseTextEffect(TextRect* text) : text_rect(text) {}
BaseTextEffect::~BaseTextEffect() {delete text_rect;}

bool BaseTextEffect::is_finished() const { return finished;}


void BaseTextEffect::load_texture(float w, float h) {text_rect->load_texture(w, h);}
void BaseTextEffect::load_texture(const char* path_to_file, float w, float h) {text_rect->load_texture(path_to_file, w, h);}
void BaseTextEffect::draw() {text_rect->draw();}
void BaseTextEffect::update() {text_rect->update();}
void BaseTextEffect::handleEvents(SDL_Event* event) {text_rect->handleEvents(event);}
void BaseTextEffect::on_mouse_clicked() {text_rect->on_mouse_clicked();}
void BaseTextEffect::on_mouse_enter() {text_rect->on_mouse_enter();}
void BaseTextEffect::on_mouse_exit() {text_rect->on_mouse_exit();}
bool BaseTextEffect::is_in_rect(float x, float y) const {return text_rect->is_in_rect(x, y);}
void BaseTextEffect::activate() {text_rect->activate();}
void BaseTextEffect::deactivate() {text_rect->deactivate();}

const char* BaseTextEffect::get_path_to_file() const {return text_rect->get_path_to_file();}
SDL_Texture* BaseTextEffect::get_texture() const {return text_rect->get_texture();}
float BaseTextEffect::get_rect_w_original() const {return text_rect->get_rect_w_original();}
float BaseTextEffect::get_rect_h_original() const {return text_rect->get_rect_h_original();}
