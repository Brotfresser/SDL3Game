#include "BaseScene.h"


BaseScene::BaseScene(SDL_Renderer* renderer) {
	this->renderer = renderer;
}

EventType BaseScene::draw() {
	for (auto sprite : all_sprites)
		sprite->draw();
	return EventType::NONE;
}

EventType BaseScene::update() {
	for (auto& sprite : all_sprites)
		sprite->update();
	return EventType::NONE;
}


BaseScene::~BaseScene() {
	for (auto& sprite : all_sprites)
		delete sprite;
}