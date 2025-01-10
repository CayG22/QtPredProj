#include "murdock.h"
Murdock::Murdock() {
    setStats();
    setBasic();
    setAlternate();
    setPrimary();
    setSecondary();
    setUltimate();
}
void Murdock::setStats() {
    name = "Murdock";
    m_attack_power = 62.0;
    m_attack_speed = .125;
    m_basic_attack_time = 1.4;
    m_actual_attack_time = 1.12;
    m_attack_range = 1300;
    m_cleave = 0.0;
    m_physical_armor = 22.0;
    m_magical_armor = 25.0;
    m_max_health = 745.0;
    m_max_mana = 310.0;
    m_health_regeneration = 1.5;
    m_mana_regeneration = 1.4;
    m_movement_speed = 645.0;
}
void Murdock::setBasic(){
    m_basic.setName("The Enforcer");
    m_basic.setDescription("Ranged Basic Attack dealing physical Damage");
    m_basic.setPhysicalDamage(62);
    m_basic.setPhysicalScale(.90);
    m_basic.setLevel(1);
}
void Murdock::setAlternate() {
    m_alternate.setName("Buckshot");
    m_alternate.setDescription("Discharge a shotgun blast, dealing physical damage");
    m_alternate.setPhysicalDamage(85);
    m_alternate.setPhysicalScale(.1);
    m_alternate.setLevel(1);
}
void Murdock::setPrimary() {
    m_primary.setName("Static Trap");
    m_primary.setDescription("Place a trap that arms after a short delay dealing magical damage");
    m_primary.setMagicaldamage(140);
    m_primary.setPhysicalScale(.12);
    m_primary.setLevel(1);
}
void Murdock::setSecondary() {
    m_secondary.setName("Hot Pursuit");
    m_secondary.setDescription("Murdock actiavtes his sirens, granting him 35% bonus movement speed for 2s");
    m_secondary.setLevel(1);
}
void Murdock::setUltimate() {
    m_ultimate.setName("The Long Arm of \nthe Law");
    m_ultimate.setDescription("An energized sniper shot that travels through anything dealing physical damage");
    m_ultimate.setPhysicalDamage(240);
    m_ultimate.setPhysicalScale(.12);
    m_ultimate.setLevel(1);
}
void Murdock::setPassive() {}
void Murdock::levelUp(int level){

    switch (level) {
    case 1:
        m_attack_power = 62.0;
        m_attack_speed = .125;
        m_basic_attack_time = 1.4;
        m_actual_attack_time = 1.12;
        m_attack_range = 1300;
        m_cleave = 0.0;
        m_physical_armor = 22.0;
        m_magical_armor = 25.0;
        m_max_health = 745.0;
        m_max_mana = 310.0;
        m_health_regeneration = 1.5;
        m_mana_regeneration = 1.4;
        m_movement_speed = 645.0;
        break;
    case 2:
        m_attack_power = 64.8;
        m_attack_speed = .126;
        m_basic_attack_time = 1.4;
        m_actual_attack_time = 1.11;
        m_attack_range = 1300;
        m_cleave = 0.0;
        m_physical_armor = 24.5;
        m_magical_armor = 25.6;
        m_max_health = 845.8;
        m_max_mana = 338.0;
        m_health_regeneration = 1.6;
        m_mana_regeneration = 1.5;
        m_movement_speed = 645.0;
        break;
    case 3:
        m_attack_power = 67.7;
        m_attack_speed = .128;
        m_basic_attack_time = 1.4;
        m_actual_attack_time = 1.09;
        m_attack_range = 1300;
        m_cleave = 0.0;
        m_physical_armor = 27.1;
        m_magical_armor = 26.1;
        m_max_health = 949.8;
        m_max_mana = 366.9;
        m_health_regeneration = 1.7;
        m_mana_regeneration = 1.6;
        m_movement_speed = 645.0;
        break;
    case 4:
        m_attack_power = 70.7;
        m_attack_speed = .129;
        m_basic_attack_time = 1.4;
        m_actual_attack_time = 1.08;
        m_attack_range = 1300;
        m_cleave = 0.0;
        m_physical_armor = 29.8;
        m_magical_armor = 26.7;
        m_max_health = 1056.9;
        m_max_mana = 396.6;
        m_health_regeneration = 1.9;
        m_mana_regeneration = 1.7;
        m_movement_speed = 645.0;
        break;
    case 5:
        m_attack_power = 73.7;
        m_attack_speed = .131;
        m_actual_attack_time = 1.07;
        m_physical_armor = 32.6;
        m_magical_armor = 27.3;
        m_max_health = 1167.1;
        m_max_mana = 427.3;
        m_health_regeneration = 2.0;
        m_mana_regeneration = 1.7;
        break;
    case 6:
        m_attack_power = 76.9;
        m_attack_speed = .133;
        m_actual_attack_time = 1.06;
        m_physical_armor = 35.4;
        m_magical_armor = 28.0;
        m_max_health = 1280.5;
        m_max_mana = 2.1;
        m_health_regeneration = 2.1;
        m_mana_regeneration = 1.8;
        break;
    case 7:
        m_attack_power = 80.1;
        m_attack_speed = .134;
        m_actual_attack_time = 1.04;
        m_physical_armor = 38.3;
        m_magical_armor = 28.6;
        m_max_health = 1397.1;
        m_max_mana = 491.1;
        m_health_regeneration = 2.3;
        m_mana_regeneration = 1.9;
        break;
    case 8:
        m_attack_power = 83.4;
        m_attack_speed = .136;
        m_actual_attack_time = 1.03;
        m_physical_armor = 41.3;
        m_magical_armor = 29.3;
        m_max_health = 1516.8;
        m_max_mana = 524.4;
        m_health_regeneration = 2.4;
        m_mana_regeneration = 2.0;
        break;
    case 9:
        m_attack_power = 86.9;
        m_attack_speed = .138;
        m_actual_attack_time = 1.02;
        m_physical_armor = 44.4;
        m_magical_armor = 30.0;
        m_max_health = 1639.6;
        m_max_mana = 558.3;
        m_health_regeneration = 2.6;
        m_mana_regeneration = 2.1;
        break;
    case 10:
        m_attack_power = 90.4;
        m_attack_speed = .140;
        m_actual_attack_time = 1.0;
        m_physical_armor = 47.5;
        m_magical_armor = 30.7;
        m_max_health = 1765.6;
        m_max_mana = 593.5;
        m_health_regeneration = 2.7;
        m_mana_regeneration = 2.2;
        break;
    case 11:
        m_attack_power = 93.9;
        m_attack_speed = .141;
        m_actual_attack_time = .99;
        m_physical_armor = 50.7;
        m_magical_armor = 31.4;
        m_max_health = 1894.8;
        m_max_mana = 629.4;
        m_health_regeneration = 2.9;
        m_mana_regeneration = 2.3;
        break;
    case 12:
        m_attack_power = 97.6;
        m_attack_speed = .143;
        m_actual_attack_time = .98;
        m_physical_armor = 54.1;
        m_magical_armor = 32.1;
        m_max_health = 2027.1;
        m_max_mana = 666.1;
        m_health_regeneration = 3.0;
        m_mana_regeneration = 2.4;
        break;
    case 13:
        m_attack_power = 101.4;
        m_attack_speed = .145;
        m_actual_attack_time = .96;
        m_physical_armor = 57.4;
        m_magical_armor = 32.9;
        m_max_health = 2162.5;
        m_max_mana = 703.8;
        m_health_regeneration = 3.2;
        m_mana_regeneration = 2.5;
        break;
    case 14:
        m_attack_power = 105.2;
        m_attack_speed = .147;
        m_actual_attack_time = .95;
        m_physical_armor = 60.9;
        m_magical_armor = 33.7;
        m_max_health = 2301.1;
        m_max_mana = 742.3;
        m_health_regeneration = 3.4;
        m_mana_regeneration = 2.6;
        break;
    case 15:
        m_attack_power = 109.2;
        m_attack_speed = .149;
        m_actual_attack_time = .94;
        m_physical_armor = 64.5;
        m_magical_armor = 34.4;
        m_max_health = 2442.9;
        m_max_mana = 781.6;
        m_health_regeneration = 3.5;
        m_mana_regeneration = 2.8;
        break;
    case 16:
        m_attack_power = 113.2;
        m_attack_speed = .151;
        m_actual_attack_time = .93;
        m_physical_armor = 68.1;
        m_magical_armor = 35.2;
        m_max_health = 2587.8;
        m_max_mana = 821.9;
        m_health_regeneration = 3.7;
        m_mana_regeneration = 2.9;
        break;
    case 17:
        m_attack_power = 117.3;
        m_attack_speed = .153;
        m_actual_attack_time = .91;
        m_physical_armor = 71.8;
        m_magical_armor = 36.1;
        m_max_health = 2735.8;
        m_max_mana = 863;
        m_health_regeneration = 3.9;
        m_mana_regeneration = 3;
        break;
    case 18:
        m_attack_power = 121.5;
        m_attack_speed = .156;
        m_actual_attack_time = .9;
        m_physical_armor = 75.6;
        m_magical_armor = 36.9;
        m_max_health = 2887;
        m_max_mana = 905;
        m_health_regeneration = 4.1;
        m_mana_regeneration = 3.1;
        break;
    default:
        m_attack_power = 62.0;
        m_attack_speed = .125;
        m_basic_attack_time = 1.4;
        m_actual_attack_time = 1.12;
        m_attack_range = 1300;
        m_cleave = 0.0;
        m_physical_armor = 22.0;
        m_magical_armor = 25.0;
        m_max_health = 745.0;
        m_max_mana = 310.0;
        m_health_regeneration = 1.5;
        m_mana_regeneration = 1.4;
        m_movement_speed = 645.0;
        break;
    }

}
void Murdock::levelUpBasic(int level){
    switch(level){
    case 1:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 2:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 3:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 4:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 5:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 6:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 7:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 8:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 9:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 10:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 11:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 12:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 13:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 14:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 15:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 16:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 17:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    case 18:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    default:
        m_basic.setPhysicalDamage(m_attack_power);
        break;
    }
}
void Murdock::levelUpAlternate(int level){
    switch(level){
    case 1:
        m_alternate.setPhysicalDamage(85);
        m_alternate.setPhysicalScale(.1);
        break;
    case 2:
        m_alternate.setPhysicalDamage(115);
        m_alternate.setPhysicalScale(.11);
        break;
    case 3:
        m_alternate.setPhysicalDamage(145);
        m_alternate.setPhysicalScale(.13);
        break;
    case 4:
        m_alternate.setPhysicalDamage(175);
        m_alternate.setPhysicalScale(.145);
        break;
    case 5:
        m_alternate.setPhysicalDamage(205);
        m_alternate.setPhysicalScale(.16);
        break;
    default:
        m_alternate.setPhysicalDamage(85);
        m_alternate.setPhysicalScale(.1);
        break;
    }
}
void Murdock::levelUpPrimary(int level){
    switch(level){
    case 1:
        m_primary.setMagicaldamage(90);
        break;
    case 2:
        m_primary.setMagicaldamage(140);
        break;
    case 3:
        m_primary.setMagicaldamage(190);
        break;
    case 4:
        m_primary.setMagicaldamage(240);
        break;
    case 5:
        m_primary.setMagicaldamage(290);
        break;
    default:
        m_primary.setMagicaldamage(90);
        break;
    }
}
void Murdock::levelUpSecondary(int level){}
void Murdock::levelUpUltimate(int level){
    switch(level){
    case 1:
        m_ultimate.setPhysicalDamage(240);
        break;
    case 2:
        m_ultimate.setPhysicalDamage(380);
        break;
    case 3:
        m_ultimate.setPhysicalDamage(520);
        break;
    case 4:
        m_ultimate.setPhysicalDamage(240);
        break;
    }
}






