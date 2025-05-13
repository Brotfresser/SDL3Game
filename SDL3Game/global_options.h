#pragma once

#ifdef __MAIN_GLOBAL_DEFINITION__
#define GLOBAL(type, name, value) type name = value
#else
#define GLOBAL(type, name, value) extern type name
#endif


namespace GameOptions {
    GLOBAL(bool, Fullscreen, false);
    GLOBAL(int, Main_Volume, 50);
    GLOBAL(int, BGM_Volume, 100);
    GLOBAL(int, BGS_Volume, 100);
    GLOBAL(int, SE_Volume, 100);
    GLOBAL(int, Sister_Volume, 100);
    GLOBAL(int, Max_Player_Msgs, 3);
    GLOBAL(bool, Show_Weapon_Durability, false);
}
#undef GLOBAL