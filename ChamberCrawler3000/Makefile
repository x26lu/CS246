cc3k : Potion.o Player.o Item.o Gold.o Floor.o Enemy.o Character.o ChamberCrawler3000.o
	g++ Potion.o Player.o Item.o Gold.o Floor.o Enemy.o Character.o ChamberCrawler3000.o -o cc3k
Potion.o : Potion.h Potion.cc Item.h
	g++ -g -Wall -c Potion.c
Player.o : Player.h Player.c Character.h
	g++ -g -Wall -c Player.c
Item.o : Item.c Item.h
	g++ -g -Wall -c Item.c
Gold.o : Gold.h Gold.c Item.h
	g++ -g -Wall -c Gold.c
Floor.o : Floor.h Floor.cpp Enemy.h Potion.h Gold.h
	g++ -g -Wall -c Floor.cpp
Enemy.o : Enemy.c Enemy.h Character.h
	g++ -g -Wall -c Enenmy.c
Character.o : Character.c Character.h
	g++ -g -Wall -c Character.c
ChamberCrawler3000.o : ChamberCrawler3000.h ChamberCrawler3000.cpp Floor.h Player.h
	g++ -g -Wall -c ChamberCrawler3000.cpp