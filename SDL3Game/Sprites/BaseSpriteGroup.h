#pragma once
#include "BaseSprite.h"
#include <list>

// костыль, знаю, потом исправлю
template <typename value_type = BaseSprite>
struct BaseSpriteGroup: BaseSprite
{
    float prev_x, prev_y;
    BaseSpriteGroup();
    std::list<value_type*> baseSprites;
    using iterator = decltype(baseSprites.begin());

    void push_back(BaseSprite* sprite);
    iterator begin();
    iterator end();

    void load_texture(float w, float h) override;
    void update() override;
    void draw() override;
    bool is_in_rect(float x, float y) const override;
};

