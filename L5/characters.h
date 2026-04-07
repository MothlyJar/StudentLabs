#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <QString>

struct Armor {
    int helmet;
    int chestplate;
    int boots;
};

class Characters {
protected:
    QString name_;
    int health_;
    Armor armor_;
public:
    Characters(QString& name, int health, Armor armor) {
        name_ = name;
        health_ = health;
        armor_ = armor;
    };
    virtual ~Characters() = default;
    QString get_name() {return name_;}
    virtual int Craft() = 0;
};

class MageChara : public Characters {
private:
    QString element_;
    int mana_;
public:
    MageChara(QString& name, int health, Armor armor, QString& element, int mana) : Characters(name, health, armor) {
        name_ = name;
        health_ = health;
        armor_ = armor;
        element_ = element;
        mana_ = mana;
    };
    ~MageChara() = default;
    int Craft() override;
};
class EnemyChara : public Characters {
private:
    QString rareness_;
    int damage_;
public:
    EnemyChara(QString& name, int health, Armor armor, QString& rareness, int damage) : Characters(name, health, armor) {
        name_ = name;
        health_ = health;
        armor_ = armor;
        rareness_ = rareness;
        damage_ = damage;
    };
    ~EnemyChara() = default;
    int Craft() override;
};

#endif // CHARACTERS_H
