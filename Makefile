# Set a variable LDFLAGS. Use the variable as $(LDFLAGS)
# On cisc210.cis.udel.edu, add -lcurses to the below line
LDFLAGS := -L ~/lib -lsense -lm

run:
        make all
        ./scroll
all: main.o display.o input.o
        cc -o scroll main.o display.o input.o $(LDFLAGS) -lcurses

%.o: %.c scroll.h
        cc -g -c $< -I ~/include

clean:
        rm -f *.o scroll
display.o: display.c
        cc -g -c display.c -I ~/include
input.o: input.c
        cc -g -c input.c -I ~/include
main.o: main.c
        cc -g -c main.c -I ~/include
