#include "SceneMainMenu.h"
#include "SceneMainMenu/UIbuttons.cpp"
#include "../global_variables.h"
#include "../TextRect.h"
UIMenuButtons current_button;
SDL_Texture* text;

SceneMainMenu::SceneMainMenu(SDL_Renderer* renderer)
	: BaseScene(renderer)
{
	const auto bg = new Sprite(renderer, "assets/homeVN/sis_room/bg/sister_room_night_fine.png");
	const auto new_button_ptr = new UIButtonNew(renderer, "assets/MainMenu/buttons/NEW_.png", 0, 0, 1920 * 80/100, 1080 * 63/100);
	const auto exit_button_ptr = new UIButtonExit(renderer, "assets/MainMenu/buttons/EXIT_.png", 0, 0, 1920 * 80/100, 1080 * 91/100);
	all_sprites.push_back(bg); // всегда вначале отрисовывается, поэтому добавляется первым

	all_sprites.push_back(new_button_ptr);
	all_sprites.push_back(new UIButtonLoad(renderer, "assets/MainMenu/buttons/LOAD_.png", 0, 0,        1920 * 80/100, 1080 * 70/100));
	all_sprites.push_back(new UIButtonSettings(renderer, "assets/MainMenu/buttons/SETTING_.png", 0, 0, 1920 * 80/100, 1080 * 77/100));
	all_sprites.push_back(new UIButtonSupport(renderer, "assets/MainMenu/buttons/SUPPORT_.png", 0, 0,  1920 * 80/100, 1080 * 84/100));



	all_sprites.push_back(exit_button_ptr);

	current_button.init(std::ranges::find(all_sprites, new_button_ptr), all_sprites.end());
	(*current_button)->on_mouse_enter();
	SDL_Log("\tWelcome to SceneMainMenu");
}


EventType SceneMainMenu::event(SDL_Event* event) {
	switch (event->type)
	{
	case SDL_EVENT_MOUSE_MOTION:
		UIMENUBUTTONMOUSEMOTION(current_button)
		break;
	case SDL_EVENT_MOUSE_BUTTON_UP:
		if (event->button.button == SDL_BUTTON_LEFT)
			(*current_button)->on_mouse_clicked();

		break;
	case SDL_EVENT_KEY_DOWN:
		switch (event->key.scancode)
		{
			UIMENUBUTTONSSWTICH(current_button)
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