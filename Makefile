# Makefile -- gum project
# author - vooop binary 
# licence - GPL licence

exec = gum.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g


$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	cp ./gum.out /usr/local/bin/gum

clean:
	-rm *.out
	-rm *.o
	-rm src/*.o
