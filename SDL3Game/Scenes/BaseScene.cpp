#include "BaseScene.h"

#include <filesystem>
#include <bits/ios_base.h>


using iter = UIMenuButtons::iter;

void UIMenuButtons::init() {
	all_buttons = new all_sprites_container();
}

void UIMenuButtons::init(iter begin, iter end) {
	all_buttons = new all_sprites_container(begin, end);
	this->current = all_buttons->begin();
}

iter UIMenuButtons::operator++() {
	if (current == --all_buttons->end())
		current = all_buttons->begin();
	else
		++current;
	return current;
}

iter UIMenuButtons::operator--() {
	if (current == all_buttons->begin())
		current = --all_buttons->end();
	else
		--current;
	return current;
}

iter UIMenuButtons::operator++(int) {
	iter to_return = current;
	if (current == --all_buttons->end())
		current = all_buttons->begin();
	else
		++current;
	return to_return;
}

iter UIMenuButtons::operator--(int) {
	iter to_return = current;
	if (current == all_buttons->begin())
		current = --all_buttons->end();
	else
		--current;
	return to_return;
}

UIMenuButtons::~UIMenuButtons() {
	delete all_buttons;
}



BaseSprite* UIMenuButtons::operator*() const {
	return *current;
	}


BaseScene::BaseScene(SDL_Renderer* renderer) {
	this->renderer = renderer;
}

EventType BaseScene::draw() {
	for (auto sprite : all_sprites)
		sprite->draw();
	return EventType::NONE;
}

BaseScene::~BaseScene() {
	for (auto& sprite : all_sprites)
		delete sprite;
}