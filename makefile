default: debug

debug:
	g++ -std=c++11 Menu.cpp Exit.cpp Space.cpp Key.cpp KeyChest.cpp inputValid.cpp Blank.cpp Board.cpp Character.cpp Chest.cpp Game.cpp HealthPotion.cpp Inventory.cpp Line.cpp Player.cpp Trap.cpp Troll.cpp Wall.cpp main.cpp -o FP 
clean:
	-rm FP 
