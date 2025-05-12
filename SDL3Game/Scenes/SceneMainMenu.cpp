#include "SceneMainMenu.h"

//#include <algorithm>

#include "SceneMainMenu/UIbuttons.cpp"
#include "../global_variables.h"

std::list<BaseSprite*>::iterator selected_object;
std::list<BaseSprite*>::iterator new_button_iter;
std::list<BaseSprite*>::iterator exit_button_iter;


SceneMainMenu::SceneMainMenu(SDL_Renderer* renderer)
	: BaseScene(renderer)
{
	Sprite* bg = new Sprite(renderer, "assets/homeVN/sis_room/bg/sister_room_night_fine.png");
	UIButtonNew* new_button_ptr = new UIButtonNew(renderer, "assets/MainMenu/buttons/NEW_.png", 0, 0, 1920 * 80/100, 1080 * 63/100);
	UIButtonExit* exit_button_ptr = new UIButtonExit(renderer, "assets/MainMenu/buttons/EXIT_.png", 0, 0, 1920 * 80/100, 1080 * 91/100);

	all_sprites.push_back(bg); // всегда вначале отрисовывается, поэтому добавляется первым
	all_sprites.push_back(new_button_ptr);
	all_sprites.push_back(new UIButtonLoad(renderer, "assets/MainMenu/buttons/LOAD_.png", 0, 0,        1920 * 80/100, 1080 * 70/100));
	all_sprites.push_back(new UIButtonSettings(renderer, "assets/MainMenu/buttons/SETTING_.png", 0, 0, 1920 * 80/100, 1080 * 77/100));
	all_sprites.push_back(new UIButtonSupport(renderer, "assets/MainMenu/buttons/SUPPORT_.png", 0, 0,  1920 * 80/100, 1080 * 84/100));
	all_sprites.push_back(exit_button_ptr);

	selected_object = all_sprites.begin();
	new_button_iter = std::ranges::find(all_sprites, new_button_ptr);
	exit_button_iter = std::ranges::find(all_sprites, exit_button_ptr);
	SDL_Log("\tWelcome to SceneMainMenu");
}


EventType SceneMainMenu::event(SDL_Event* event) {
	switch (event->type)
	{
	case SDL_EVENT_MOUSE_MOTION:
		for (auto& sprite : all_sprites)
			if (sprite->is_in_rect(Global::MouseX, Global::MouseY)) {
				(*selected_object)->on_mouse_exit();
				selected_object = std::ranges::find(all_sprites, sprite);
				(*selected_object)->on_mouse_enter();
			}
		break;
	case SDL_EVENT_MOUSE_BUTTON_UP:
		if (event->button.button == SDL_BUTTON_LEFT)
			(*selected_object)->on_mouse_clicked();

		break;
	case SDL_EVENT_KEY_DOWN:
		switch (event->key.scancode)
		{
			case SDL_SCANCODE_RETURN:
				(*selected_object)->on_mouse_clicked();
				break;
			case SDL_SCANCODE_UP: {
				(*selected_object)->on_mouse_exit();
				if (selected_object == all_sprites.begin()) //bg
					selected_object = new_button_iter;
				else if (selected_object == new_button_iter)
					selected_object = exit_button_iter;
				else
					--selected_object;

				(*selected_object)->on_mouse_enter();
				break;
			}
			case SDL_SCANCODE_DOWN: {
				(*selected_object)->on_mouse_exit();
				if (selected_object == all_sprites.begin()) //bg
					selected_object = exit_button_iter;
				else if (selected_object == exit_button_iter)
					selected_object = new_button_iter;
				else
					++selected_object;

				(*selected_object)->on_mouse_enter();
				break;
			}
			default: ;
		}
	}
	
	return Global::event;
}

EventType SceneMainMenu::draw() {
	for (auto& sprite : all_sprites)
		sprite->draw();
	return EventType::NONE;
}


EventType SceneMainMenu::update() {
	for (auto& sprite : all_sprites)
		sprite->update();
	return EventType::NONE;
}

SceneMainMenu::~SceneMainMenu() {
	for (auto& sprite : all_sprites)
		delete sprite;
}