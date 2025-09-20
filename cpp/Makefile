app: ${wildcard *.cpp}
	g++ ${wildcard *.cpp} -Os -Wall -Wextra -Wpedantic -o app

run: app
	./app

clean:
	rm app
