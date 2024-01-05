all: buggy

buggy: buggy.cpp
	g++ -g -std=c++17 -pedantic -Wall -Wextra -fsanitize=address,undefined -o buggy buggy.cpp

clean:
	rm buggy

test: all
	chmod u+x tests.sh
	./tests.sh
