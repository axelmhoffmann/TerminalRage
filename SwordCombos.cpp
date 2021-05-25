#include "SwordCombos.h"
#include "Projectile.h"
#include "Sword.h"
#include "Player.h"

///////////////////////
// SwordStab methods //
///////////////////////
void SwordStab::Perform(Player * player){
    Game * game = player->GetGame();
    // Spawn a projectile to the right of the player
    Point pos = player->GetPosition();
    SwordProjectile * proj;
    std::string sprite;
    Point direction = Point::right;
    if(player->GetDirection().equal(Point::left)){
        sprite = "<====|-";
        pos = pos.add(Point::right.multiply(-7));
        direction = Point::left;
    }
    else{
        sprite = "-|====>";
        pos = pos.add(Point::right.multiply(3));
    }
    proj = new SwordProjectile(pos, sprite, 1, 4);
    proj->SetDirection(direction);
    // Set owner, so that the sword projectile can give energy back to the owner
    proj->SetOwner(player);
    // Set values
    proj->SetLifeTime(0.4);
    proj->SetMaxMoveTimer(0.15);
    proj->SetDamage(3);
    game->SpawnEntity(proj);
}
string SwordStab::GetDescription(){
    return "A ranged thrust that generates 4 energy";
}
////////////////////////
// SwordSlash methods //
////////////////////////
void SwordSlash::Perform(Player * player){
    Game * game = player->GetGame();
    // Spawn the slash 1 tile up and 3 to the right
    Point pos = player->GetPosition().add(Point::right.multiply(3)).add(Point::up);
    SwordProjectile * proj = new SwordProjectile(pos, "-|______)", 1, 3);
    // Slash moves downwards
    proj->SetDirection(Point::down);
    
    proj->SetOwner(player);
    proj->SetDamage(2);
    proj->SetLifeTime(0.5);
    proj->SetMaxMoveTimer(0.2);
    game->SpawnEntity(proj);
}
string SwordSlash::GetDescription(){
    return "An attack that hits a huge area and generates 3 energy";
}

///////////////////////////
// SwordUltimate methods //
///////////////////////////
void SwordUltimate::Perform(Player * player){
    Game * game = player->GetGame();
    // Spawn the slash 1 tile up and 3 to the right
    Point pos = player->GetPosition().add(Point::right.multiply(3)).add(Point::up);
    UltimateSwordProjectile * proj = new UltimateSwordProjectile(pos, "-|,_,_,_,_,_)", 1);
    // Slash moves downwards
    proj->SetDirection(Point::down);
    proj->SetOwner(player);
    proj->SetLifeTime(0.3);
    proj->SetMaxMoveTimer(0.12);
    proj->SetDamage(8);
    game->SpawnEntity(proj);
}
string SwordUltimate::GetDescription(){
    return "An ultimate ability that consumes your energy to create a massive beam slash";
}

///////////////////////
// SwordProj methods //
///////////////////////
SwordProjectile::SwordProjectile(Point _position, std::string _sprite, int _colour, int _energy) : Projectile(_position, _sprite, _colour){
    energy = _energy;
}
void SwordProjectile::OnHitPlayer(Player * p){
    if(GetOwner()->GetWeapon() == nullptr)
        return;
    Sword * sw = (Sword *)GetOwner()->GetWeapon();
    sw->ChangeEnergy(energy);
    // Projectiles can only grant energy once
    energy = 0;
}

///////////////////////////////
// UltimateSwordProj methods //
///////////////////////////////
UltimateSwordProjectile::UltimateSwordProjectile(Point _position, std::string _sprite, int _colour) : Projectile(_position, _sprite, _colour){ }

void UltimateSwordProjectile::OnMove(){
    Game * game = GetOwner()->GetGame();
    // Spawn the slash 1 tile up and 3 to the right
    Point pos = GetPosition().add(Point(10,0));
    Projectile * proj = new Projectile(pos, "--==>>>>)", 1);

    proj->SetDirection(Point::right);
    proj->SetOwner(GetOwner());
    proj->SetLifeTime(3);
    proj->SetDamage(5);
    proj->SetMaxMoveTimer(0.08);
    game->SpawnEntity(proj);
}