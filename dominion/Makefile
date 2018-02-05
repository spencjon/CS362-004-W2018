CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

assertDominionTest.o: assertDominionTest.h assertDominionTest.c dominion.o rngs.o
	gcc -c assertDominionTest.c -g $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 1o*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testDiscardCard: unittest1.c assertDominionTest.o dominion.o rngs.o
	gcc -o testDiscardCard -g  unittest1.c assertDominionTest.o dominion.o rngs.o $(CFLAGS)

testNumHandCards: unittest1.c assertDominionTest.o dominion.o rngs.o
	gcc -o testNumHandCards -g  unittest2.c assertDominionTest.o dominion.o rngs.o $(CFLAGS)

testSupplyCount: unittest1.c assertDominionTest.o dominion.o rngs.o
	gcc -o testSupplyCount -g unittest3.c assertDominionTest.o dominion.o rngs.o $(CFLAGS)

testIsGameOver: unittest1.c assertDominionTest.o dominion.o rngs.o
	gcc -o testIsGameOver -g unittest4.c assertDominionTest.o dominion.o rngs.o $(CFLAGS)

testSmithyCard: cardtest1.c assertDominionTest.o dominion.o rngs.o
	gcc -o testSmithyCard -g cardtest1.c assertDominionTest.o dominion.o rngs.o $(CFLAGS)

testAdventurerCard: cardtest1.c assertDominionTest.o dominion.o rngs.o
	gcc -o testAdventurerCard -g cardtest2.c assertDominionTest.o dominion.o rngs.o $(CFLAGS)

testGreatHallCard: cardtest1.c assertDominionTest.o dominion.o rngs.o
	gcc -o testGreatHallCard -g cardtest3.c assertDominionTest.o dominion.o rngs.o $(CFLAGS)

testVillageCard: cardtest1.c assertDominionTest.o dominion.o rngs.o
	gcc -o testVillageCard -g cardtest4.c assertDominionTest.o dominion.o rngs.o $(CFLAGS)

#testAll: dominion.o testSuite.c
#	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard testDiscardCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe testDiscardCard testNumHandCards testSupplyCount testIsGameOver 
