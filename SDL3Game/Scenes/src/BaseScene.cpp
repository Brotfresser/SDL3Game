#include "../headers/BaseScene.h"

BaseScene* BaseScene::get_new_scene_ptr() {
	return new_scene_ptr;
}

BaseScene::BaseScene(SDL_Renderer* renderer) {
	this->renderer = renderer;
}

BaseScene::~BaseScene() {

}