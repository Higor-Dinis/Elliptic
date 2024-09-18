all:
	echo "Building main"
	g++ -g $(shell find . -type f -iregex ".*\.cc") $(shell find . -type f -iregex ".*\.h") -o build/main

clean:
	rm -r build
	