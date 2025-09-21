app: ${wildcard src/*.c} ${wildcard include/*.h}
	gcc ${wildcard src/*.c} -I include -Os -Wall -Wextra -Wpedantic -Werror -o app

run: app
	./app

valgrind: app
	valgrind ./app

clean:
	rm app
