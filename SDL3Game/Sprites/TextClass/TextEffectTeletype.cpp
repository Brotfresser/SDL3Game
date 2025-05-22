#include "TextEffectTeletype.h"

TextEffectTeletype::TextEffectTeletype(TextRect* text, float timeDelay)
    : BaseTextEffect(text), timeDelay(timeDelay)
{

}

void TextEffectTeletype::update() {
    if (!finished && timer) {
        if (text_rect->get_text() == buffer_text)
            finished = true;
        else {
            auto text = text_rect->get_text();
            text[last_char_id] = buffer_text[last_char_id];
            text_rect->change_text(text);
            ++last_char_id;
            timer(timeDelay);
        }
    }
}


void TextEffectTeletype::effect_on() {
    finished = false;
    buffer_text = text_rect->get_text();

    auto text = text_rect->get_text();
    for (auto& ch : text)
        if (ch != '\n')
            ch = ' ';

    text_rect->change_text(text);
    last_char_id = 0;
    load_texture();
    timer(timeDelay);
}
