CC      ?= gcc
CFLAGS  ?= -std=c11 -Wall -Wextra -O2 -D_GNU_SOURCE

.PHONY: all records game clean

all: records

## records — Tri d'étudiants (CSV sort). Requires only a C11 compiler.
records: main.c eleve.c eleve.h
	$(CC) $(CFLAGS) -o tri_eleves main.c eleve.c

## game — SDL2 game (icone.c). Requires SDL2 dev headers (libsdl2-dev).
## Not built by default: see docs/BUILD.md — assets live in quiz/ and snack/
## folders that must be recreated, and the source has not been re-verified
## on a clean machine.
game: icone.c
	$(CC) $(CFLAGS) -o prog icone.c $(shell sdl2-config --cflags --libs)

clean:
	rm -f tri_eleves prog *.o
