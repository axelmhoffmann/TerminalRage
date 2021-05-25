compiler = g++

all: tests game

#- Run this to skip tests -#
game: Point.o Entity.o Projectile.o Combo.o Weapon.o SwordCombos.o Sword.o StaffCombos.o Staff.o Player.o AutoPlayer.o Menu.o Game.o Renderer.o main.cpp
	g++ -g Point.o Entity.o Projectile.o Combo.o Weapon.o SwordCombos.o Sword.o StaffCombos.o Staff.o Player.o AutoPlayer.o Menu.o Game.o Renderer.o main.cpp -lncurses -o build

##############
##  ENGINE  ##
##############
Point.o: Point.h Point.cpp
	g++ -c Point.cpp -o Point.o

Game.o: Game.h Game.cpp
	g++ -c Game.cpp -o Game.o

Renderer.o: Renderer.h Renderer.cpp
	g++ -c Renderer.cpp -o Renderer.o

Menu.o: Menu.h Menu.cpp
	g++ -c Menu.cpp

################
##  ENTITIES  ##
################
Entity.o: Entity.h Entity.cpp
	g++ -c Entity.cpp -o Entity.o

Player.o: Entity.o Player.h Player.cpp
	g++ -c Player.cpp -o Player.o

AutoPlayer.o: Entity.o Player.o AutoPlayer.h AutoPlayer.cpp
	g++ -c AutoPlayer.cpp

Projectile.o: Entity.o Projectile.h Projectile.cpp
	g++ -c Projectile.cpp -o Projectile.o

##############
##	WEAPONS ##
##############
Combo.o: Combo.h Combo.cpp
	g++ -c Combo.cpp -o Combo.o

Weapon.o: Weapon.h Weapon.cpp
	g++ -c Weapon.cpp -o Weapon.o

#- Sword Weapon -#
SwordCombos.o: SwordCombos.h SwordCombos.cpp
	g++ -c SwordCombos.cpp

Sword.o: Sword.h Sword.cpp
	g++ -c Sword.cpp

#- Staff Weapon -#
StaffCombos.o: StaffCombos.h StaffCombos.cpp
	g++ -c StaffCombos.cpp

Staff.o: Staff.h Staff.cpp
	g++ -c Staff.cpp -o Staff.o

#############
##  TESTS  ##
#############
tests: point_test entity_test io_test player_test game_test
	./point_test
	./entity_test
	./player_test
	./game_test
	./io_test < IO_Test_Input.txt | diff - IO_Test_ExpectedOut.txt

#- UNIT TESTS -#
point_test: Point.o Point_Test.cpp
	g++ -o point_test Point.o Point_Test.cpp

entity_test: Point.o point_test Entity_Test.cpp Entity.o
	g++ Point.o Entity.o Entity_Test.cpp -o entity_test

player_test: Point.o Combo.o Weapon.o Entity.o Player_Test.cpp Player.o
	g++ Point.o Combo.o Weapon.o Entity.o Player.o Player_Test.cpp -o player_test

game_test: Point.o Entity.o Player.o Projectile.o entity_test Game.o
	g++ Point.o Entity.o Player.o Projectile.o Game.o Game_Test.cpp -o game_test

#-- IO TEST --#
io_test: Point.o Entity.o Projectile.o Player.o Combo.o SwordCombos.o StaffCombos.o Weapon.o Staff.o Sword.o Game.o Menu.o IO_Test.cpp
	g++ Point.o Entity.o Projectile.o Player.o Combo.o SwordCombos.o StaffCombos.o Weapon.o Staff.o Sword.o Game.o Menu.o IO_Test.cpp -lncurses -o io_test


clean:
	rm -f *.o build