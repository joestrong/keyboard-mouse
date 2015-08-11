all:
	gcc -Wall mousemove.c -o bin/mousemove -lX11 `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
