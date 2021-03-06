#pragma once

#include <algorithm>
#include <iostream>
#include <type_traits>
#include <array>

#include "./enum.h"
#include "./util.h"

#pragma pack(1)
struct MonsterData {
    explicit MonsterData(const unsigned char* raw);
    MonsterData() = default;

    char name[97];
    Element element;
    uint8_t rare;
    uint16_t no;
    uint16_t cost;
    uint8_t unknown1[2];
    uint8_t max_lv;
    uint32_t compose_exp;  // Lv4合成exp(?)
    uint8_t unknown2[4];
    uint32_t sell_value;  // Lv10賣價(?)

    float hp_1;
    float hp_max;
    float hp_grow;
    uint8_t unknown3[4];
    float atk_1;
    float atk_max;
    float atk_grow;
    uint8_t unknown4[4];
    float heal_1;
    float heal_max;
    float heal_grow;
    uint8_t unknown5[4];

    float exp_type;
    uint8_t unknown6[8];
    Type type;
    Type sub_type;

    uint16_t skill;
    uint8_t unknown7[4];
    uint16_t leader_skill;

    uint8_t unknown8[4];
    uint16_t dungeon_turn;

    float dungeon_hp_1;
    float dungeon_hp_max;
    float dungeon_hp_grow;
    uint8_t unknown9[4];
    float dungeon_atk_1;
    float dungeon_atk_max;
    float dungeon_atk_grow;
    uint8_t unknown10[4];
    float dungeon_def_1;
    float dungeon_def_max;
    float dungeon_def_grow;
    uint8_t unknown11[4];
    
    uint8_t unknown12[4];
    uint16_t dungeon_exp;  // Lv2關卡exp (maybe 4 byte?)

    uint16_t base_monster;  // 進化前
    std::array<uint16_t, 5> base_material;  // 進化素材

    uint8_t unknown13[142];  // lots of zeros?

    Element sub_element;

    uint8_t unknown14[11];  // 究極退化?
    std::array<Awoken, 9> awoken;
    uint8_t unknown15[6];

    float plus() const;
    int count_awoken(Awoken x) const;
    bool has_type(Type t) const;
};

static_assert(std::is_pod<MonsterData>::value, "MonsterData is not pod");
static_assert(sizeof(MonsterData) == 438, "Incorrect MonsterData struct size");

std::ostream& operator<<(std::ostream& os, const MonsterData& m);
