#include "BaseSpriteGroup.h"

template <typename value_type>
BaseSpriteGroup<value_type>::BaseSpriteGroup()
    :BaseSprite(nullptr, nullptr) {prev_x = x; prev_y = y;}


template <typename value_type>
void BaseSpriteGroup<value_type>::load_texture(float w, float h) {

}


template <typename value_type>
void BaseSpriteGroup<value_type>::push_back(BaseSprite* sprite) {
    baseSprites.push_back(sprite);
}

template <typename value_type>
BaseSpriteGroup<value_type>::iterator BaseSpriteGroup<value_type>::begin() {
    return baseSprites.begin();
}

template <typename value_type>
BaseSpriteGroup<value_type>::iterator BaseSpriteGroup<value_type>::end() {
    return baseSprites.end();
}

template <typename value_type>
void BaseSpriteGroup<value_type>::update() {
    for (auto& sprite : baseSprites)
        sprite->update();
}

template <typename value_type>
void BaseSpriteGroup<value_type>::draw() {
    float mod_x = 0, mod_y = 0;
    if (prev_x != x || prev_y != y) {
        mod_x = x - prev_x;
        mod_y = y - prev_y;
    }
    for (auto& sprite : baseSprites) {
        sprite->x += mod_x;
        sprite->y += mod_y;
        sprite->draw();
    }
    prev_x = x; prev_y = y;
}

template <typename value_type>
bool BaseSpriteGroup<value_type>::is_in_rect(float x, float y) const {
    for (auto& sprite : baseSprites)
        if (sprite->is_in_rect(x, y))
            return true;
    return false;
}
