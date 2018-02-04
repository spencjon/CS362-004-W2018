CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	g++ -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	g++ -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	g++ -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	g++  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	g++ -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	g++ -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testDiscardCard: unittest1.c assertDominionTest.c dominion.o rngs.o
	g++ -o testDiscardCard -g unittest1.c assertDominionTest.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	g++ -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	g++ -c interface.c -g  $(CFLAGS)

runtests: testDrawCard
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	g++ -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard testDiscardCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
