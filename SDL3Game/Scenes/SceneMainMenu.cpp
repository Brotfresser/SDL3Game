#include "SceneMainMenu/UIbuttons.cpp"
#include <global_variables.h>
#include <Sprites/TextClass/TextRect.h>

#include "Sprites/TextClass/TextEffectTeletype.h"
#include "Sprites/TextClass/TextRectWithShadow.h"
static UIMenuButtons current_button;

static float a, b;
struct SceneMainMenu final : BaseScene {
	explicit SceneMainMenu(SDL_Renderer* renderer)
		: BaseScene(renderer)
	{
		const auto bg = new Sprite(renderer, "assets/homeVN/sis_room/bg/sister_room_night_fine.png");
		const auto new_button_ptr = new UIButtonNew(renderer);
		const auto exit_button_ptr = new UIButtonExit(renderer);
		all_sprites.push_back(bg); // всегда вначале отрисовывается, поэтому добавляется первым

		all_sprites.push_back(new_button_ptr);
		all_sprites.push_back(new UIButtonLoadGame(renderer));
		all_sprites.push_back(new UIButtonSettings(renderer));
		all_sprites.push_back(new UIButtonSupport(renderer));

		all_sprites.push_back(exit_button_ptr);

		current_button.init(std::ranges::find(all_sprites, new_button_ptr), all_sprites.end());
		(*current_button)->on_mouse_enter();

		auto text = new TextEffectTeletype(new TextRectWithShadow(renderer, "Big rEal TEXT", 200, 200, SDL_TEXT_COLOR_WHITE, 50));
		text->effect_on();
		all_sprites.push_back(text);
		SDL_Log("\tWelcome to SceneMainMenu");
	}


	EventType event(SDL_Event* event) override {
		switch (event->type)
		{
			case SDL_EVENT_MOUSE_MOTION:
				UI_MENU_BUTTON_MOUSE_MOTION_ITER(current_button)
				break;
			case SDL_EVENT_MOUSE_BUTTON_UP:
				UI_MENU_BUTTON_MOUSE_PRESSED(current_button, all_sprites)

				break;
			case SDL_EVENT_KEY_DOWN:
				switch (event->key.scancode)
				{
					UI_MENU_BUTTON_SWITCH_ITER(current_button)
					default: ;
				}
		}

		return Global::event;
	}


	EventType update() override {
		for (auto& sprite : all_sprites)
			sprite->update();
		return EventType::NONE;
	}
};