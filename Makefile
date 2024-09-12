all:
	echo "Building main"
	g++ -g main.cpp -o build/main

clean:
	rm -r build
	