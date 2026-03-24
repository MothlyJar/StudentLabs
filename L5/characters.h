#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <string>

struct Armor {
    int helmet;
    int chestplate;
    int boots;
};

class Characters {
protected:
    std::string name_;
    int health_;
    Armor armor_;
public:
    Characters(const std::string& name, int health, Armor armor) {
        name_ = name;
        health_ = health;
        armor_ = armor;
    };
    virtual void Craft() = 0;
};

class MageChara : public Characters {
private:
    std::string element_;
    int mana_;
public:
    MageChara(const std::string& name, int health, Armor armor, std::string element, int mana) : Characters(name, health, armor) {
        element_ = element;
        mana_ = mana;
    };
    void Craft() override;
};
class EnemyChara : public Characters {
private:
    std::string rareness_;
    int damage_;
public:
    EnemyChara(const std::string& name, int health, Armor armor, std::string rareness, int damage) : Characters(name, health, armor) {
        rareness_ = rareness;
        damage_ = damage;
    };
    void Craft() override;
};

#endif // CHARACTERS_H
