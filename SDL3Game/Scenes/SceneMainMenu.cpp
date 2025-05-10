#include "SceneMainMenu.h"
#include "SceneMainMenu_obj/UIbuttons.cpp"
#include "../global_variables.h"


Sprite* bg;

SceneMainMenu::SceneMainMenu(SDL_Renderer* renderer)
	: BaseScene(renderer)
{
	bg = new Sprite(renderer, "assets/homeVN/sis_room/bg/sister_room_night_fine.png");

	all_sprites.push_back(bg);
	all_sprites.push_back(new UIButtonNew(renderer, "assets/MainMenu/buttons/NEW_.png", 0, 0,          1920 * 80/100, 1080 * 63/100));
	all_sprites.push_back(new UIButtonLoad(renderer, "assets/MainMenu/buttons/LOAD_.png", 0, 0,        1920 * 80/100, 1080 * 70/100));
	all_sprites.push_back(new UIButtonSettings(renderer, "assets/MainMenu/buttons/SETTING_.png", 0, 0, 1920 * 80/100, 1080 * 77/100));
	all_sprites.push_back(new UIButtonSupport(renderer, "assets/MainMenu/buttons/SUPPORT_.png", 0, 0,  1920 * 80/100, 1080 * 84/100));
	all_sprites.push_back(new UIButtonExit(renderer, "assets/MainMenu/buttons/EXIT_.png", 0, 0,        1920 * 80/100, 1080 * 91/100));
	SDL_Log("\n\n\tWelcome to SceneMainMenu");
}

EventType SceneMainMenu::event(SDL_Event* event) {
	switch (event->type)
	{
	case SDL_EVENT_MOUSE_BUTTON_UP: 
		if (event->button.button == SDL_BUTTON_LEFT)
			for (auto& sprite : all_sprites) // почему-то в main.cpp оно ведёт себя странно (будто-бы неправильно определяет виртуальные функции)
				if (sprite->is_in_rect(Global::MouseX, Global::MouseY))
					sprite->on_mouse_clicked();
		break;
	case SDL_EVENT_KEY_DOWN:
		switch (event->key.scancode)
		{
		case SDL_SCANCODE_F1:
			new_scene_ptr = new SceneGameStart(renderer);

			return EventType::SCENE_SWITCH_REQUEST;
		}
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