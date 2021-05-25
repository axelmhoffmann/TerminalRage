#ifndef PROJECTILE
#define PROJECTILE
class Weapon;
class Player;
class Game;
#include "Point.h"
#include "Entity.h"
#include "Player.h"
#include "Game.h"

// [ Axel Hoffmann a1832087 | UofA OOP 2021 ]
//-----------------------------------
// A type of Entity that represents an autonomous object moving in the game space
//-----------------------------------
class Projectile : public Entity{
public:
    Projectile(Point _position, std::string _sprite, int _colour);

    // Called when the projectile hitbox interacts with the player hitbox
    virtual void OnHitPlayer(Player * p);
    // Called every game loop
    virtual void Update(double deltaTime) override;
    // Called when the proj moves
    virtual void OnMove();

    void Setup();
    Player * GetOwner();
    void SetOwner(Player * _owner);

    void SetLifeTime(double _time);
    double GetLifeTime();
    void SetMaxMoveTimer(double max);
    void SetDamage(int dmg);

    ~Projectile();
private:
    int size;

    void CheckCollisions();
protected:
    double moveTimer;
    double maxMoveTimer;
    Player * owner;
    double lifeTime;
    int damage;
};
#endif