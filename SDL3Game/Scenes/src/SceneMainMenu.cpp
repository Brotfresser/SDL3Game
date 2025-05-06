#include "../headers/SceneMainMenu.h"
#include "../../global_variables.h"


Sprite* bg;

SceneMainMenu::SceneMainMenu(SDL_Renderer* renderer)
	: BaseScene(renderer)
{
	bg = new Sprite(renderer, "assets/homeVN/sis_room/bg/sister_room_night_fine.png");
	
	all_sprites.push_back(bg);
}

EventType SceneMainMenu::event(SDL_Event* event) {
	switch (event->key.scancode)
	{
	case SDL_SCANCODE_F1:
		new_scene_ptr = new SceneGameStart(renderer);
		return EventType::SCENE_SWITCH_REQUEST;
	}
	return EventType::EVENT_NONE;
}

EventType SceneMainMenu::draw() {
	for (auto& sprite : all_sprites)
		sprite->draw();
	return EventType::EVENT_NONE;
}


EventType SceneMainMenu::update() {
	for (auto& sprite : all_sprites)
		sprite->update();
	return EventType::EVENT_NONE;
}

SceneMainMenu::~SceneMainMenu() {
	for (auto& sprite : all_sprites)
		delete sprite;
}