CFLAGS = -Wall -fpic -coverage -lm



rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)


random1: randomtestcard1.c dominion.o rngs.o
	gcc -o random1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

random2: randomtestcard2.c dominion.o rngs.o
	gcc -o random2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

randomA: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomA -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)


card1: cardtest1.c dominion.o rngs.o
	gcc -o card1 -g cardtest1.c dominion.o rngs.o $(CFLAGS)

card2: cardtest2.c dominion.o rngs.o
	gcc -o card2 -g cardtest2.c dominion.o rngs.o $(CFLAGS)

card3: cardtest3.c dominion.o rngs.o
	gcc -o card3 -g cardtest3.c dominion.o rngs.o $(CFLAGS)

card4: cardtest4.c dominion.o rngs.o
	gcc -o card4 -g cardtest4.c dominion.o rngs.o $(CFLAGS)


test1: unittest1.c dominion.o rngs.o
	gcc -o test1 -g unittest1.c dominion.o rngs.o $(CFLAGS)

test2: unittest2.c dominion.o rngs.o
	gcc -o test2 -g unittest2.c dominion.o rngs.o $(CFLAGS)

test3: unittest3.c dominion.o rngs.o
	gcc -o test3 -g unittest3.c dominion.o rngs.o $(CFLAGS)

test4: unittest4.c dominion.o rngs.o
	gcc -o test4 -g unittest4.c dominion.o rngs.o $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randTests:
	gcov -b -c randomtestcard1.c &> randomtestresult.out
	./random1 >> randomtestresult.out
	gcov -b -c randomtestcard2.c >> randomtestresult.out
	./random2 >> randomtestresult.out
	gcov -b -c randomtestadventurer.c >> randomtestresult.out
	./randomA >> randomtestresult.out

mytests:
	gcov -b -c unittest1.c &> unittestresult.out
	./test1 >> unittestresult.out
	gcov -b -c unittest2.c >> unittestresult.out
	./test2 >> unittestresult.out
	gcov -b -c unittest3.c >> unittestresult.out	
	./test3 >> unittestresult.out
	gcov -b -c unittest4.c >> unittestresult.out
	./test4 >> unittestresult.out	
	gcov -b -c cardtest1.c >> unittestresult.out
	./card1 >> unittestresult.out
	gcov -b -c cardtest2.c >> unittestresult.out
	./card2 >> unittestresult.out
	gcov -b -c cardtest3.c >> unittestresult.out	
	./card3 >> unittestresult.out
	gcov -b -c cardtest4.c >> unittestresult.out	
	./card4 >> unittestresult.out
	gcov -b -c dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

	

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe

