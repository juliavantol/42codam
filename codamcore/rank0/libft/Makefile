CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)

run: $(SRC)
	gcc -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
