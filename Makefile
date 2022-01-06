CFLAG = -Wall -Wextra

Block.o : Block.cpp Block.h
	g++ $(CFLAG) -c Block.cpp

sha256.o : sha256.cpp sha256.h
	g++ $(CFLAG) -c sha256.cpp

Blockchain.o : Blockchain.cpp Blockchain.h
	g++ $(CFLAG) -c Blockchain.cpp

TestChain : Block.o Blockchain.o sha256.o main.cpp
	g++ -o TestChain Block.o sha256.o Blockchain.o main.cpp

run_TestChain : TestChain
	./TestChain

clean :
	rm Block.o Blockchain.o sha256.o TestChain

