#include "SceneGameStart.h"
#include "../global_variables.h"
#include "../global_functions.h"



SceneGameStart::SceneGameStart(SDL_Renderer* renderer)
	: BaseScene(renderer)
{
	Global::player = new Player(renderer, "assets/hero/hero.png", 32, 32);
	Global::player->rect_w_k = 10;
	Global::player->rect_h_k = 10;
	all_sprites.push_back(Global::player);

	SDL_Log("Welcome to SceneGameStart");
}

EventType SceneGameStart::event(SDL_Event* event) {
	switch (event->key.scancode)
	{
	case SDL_SCANCODE_ESCAPE:
		new_scene_ptr = new SceneMainMenu(renderer);
		return EventType::SCENE_SWITCH_REQUEST;
	default:
		break;
	}
	return EventType::EVENT_NONE;
}

EventType SceneGameStart::draw() {
	for (auto& sprite : all_sprites)
		sprite->draw();
	return EventType::EVENT_NONE;
}


EventType SceneGameStart::update() {
	for (auto& sprite : all_sprites)
		sprite->update();
	/*Global::player->rect_w *= 1.001;
	Global::player->rect_h *= 1.001;*/
	return EventType::EVENT_NONE;
}

SceneGameStart::~SceneGameStart() {
	for (auto& sprite : all_sprites)
		delete sprite;
}
