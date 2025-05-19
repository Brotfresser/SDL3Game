#include "../global_variables.h"
#include <SwitchSceneFabric.h>


struct SceneGameStart final : BaseScene {
	explicit SceneGameStart(SDL_Renderer* renderer)
		: BaseScene(renderer)
	{
		Global::player = new Player(renderer, "assets/hero/hero.png", 32, 32);
		Global::player->rect_w_k = 10;
		Global::player->rect_h_k = 10;
		all_sprites.push_back(Global::player);

		SDL_Log("Welcome to SceneGameStart");
	}

	EventType event(SDL_Event* event) override {
		switch (event->key.scancode)
		{
			case SDL_SCANCODE_ESCAPE:
				SceneFabric::SwitchScene(0);
			default:
				break;
		}
		return Global::event;
	}

	EventType draw() override {
		for (auto& sprite : all_sprites)
			sprite->draw();
		return EventType::NONE;
	}


	EventType update() override {
		for (auto& sprite : all_sprites)
			sprite->update();
		/*Global::player->rect_w *= 1.001;
		Global::player->rect_h *= 1.001;*/
		return EventType::NONE;
	}
};