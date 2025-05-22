#include "UIMenuButtons.h"

using iter = UIMenuButtons::iter;

void UIMenuButtons::init() {
    if (all_buttons != nullptr)
        delete all_buttons;
    all_buttons = new all_sprites_container();
    this->current = all_buttons->begin();
}

void UIMenuButtons::init(iter begin, iter end) {
    if (all_buttons != nullptr)
        delete all_buttons;
    all_buttons = new all_sprites_container(begin, end);
    this->current = all_buttons->begin();
}

iter UIMenuButtons::operator++() {
    if (current == --all_buttons->end())
        current = all_buttons->begin();
    else
        ++current;
    return current;
}

iter UIMenuButtons::operator--() {
    if (current == all_buttons->begin())
        current = --all_buttons->end();
    else
        --current;
    return current;
}

iter UIMenuButtons::operator++(int) {
    iter to_return = current;
    if (current == --all_buttons->end())
        current = all_buttons->begin();
    else
        ++current;
    return to_return;
}

iter UIMenuButtons::operator--(int) {
    iter to_return = current;
    if (current == all_buttons->begin())
        current = --all_buttons->end();
    else
        --current;
    return to_return;
}

UIMenuButtons::~UIMenuButtons() {
    delete all_buttons;
}



BaseSpriteInterface* UIMenuButtons::operator*() const {
    return *current;
}