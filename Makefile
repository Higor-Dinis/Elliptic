all:
	echo "Building main"
	g++ -g main.cpp lexer.h tokens.h -o build/main

clean:
	rm -r build
	