#include "../global_variables.h"
#include <SwitchSceneFabric.h>

#include "Sprites/SpriteWithAnimation.h"
#include "Sprites/AnimationClass/AnimationByFile.h"


struct SceneGameStart : BaseScene {
	explicit SceneGameStart(SDL_Renderer* renderer)
		: BaseScene(renderer)
	{
		all_sprites.push_back(new Sprite(renderer, "assets/homeVN/sis_room/bg/sister_room_BW.png"));
		auto anim = new SpriteWithAnimation(renderer, "assets/animations/pipofm-fullscreeneffect_023/pipofm-fullscreeneffect_023_1.png");
		anim->change_animation(new AnimationByFile(anim, "assets/animations/pipofm-fullscreeneffect_023/pipofm-fullscreeneffect_023_", new int[1]{31}, 0.1));
		all_sprites.push_back(anim);
		SDL_Log("Welcome to SceneGameStart");
	}

	EventType event(SDL_Event* event) override {
		switch (event->key.scancode)
		{
			case SDL_SCANCODE_ESCAPE:
				SceneFabric::SwitchScene(0);
				break;
			default:
				break;
		}
		return Global::event;
	}
};
