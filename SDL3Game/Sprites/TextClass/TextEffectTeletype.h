#pragma once
#include "BaseTextEffect.h"


struct TextEffectTeletype: BaseTextEffect {
protected:
    Timer timer;
    std::string buffer_text;
    int last_char_id = 0;
    float timeDelay = 0.1;
public:
    TextEffectTeletype(TextRect* text, float timeDelay = 0.1);

    void update() override;
    void effect_on() override;
};
