morpiondir = src/core/morpion/
iadir = src/core/ia/
affConsoledir = src/affConsole/
affGraphicdir = src/affGraphic/
objectdir = obj/

CC = gcc
CFLAGS = -std=c11 -Wall -Wconversion -Werror -Wextra -Wpedantic -I$(morpiondir) -I$(iadir)
LINKER_FLAGS = -lSDL -lm
objects = $(objectdir)morpion.o $(objectdir)ia.o
executable = bin/morpionExe

$(objectdir)affConsole.o: $(affConsoledir)affConsole.c $(affConsoledir)affConsole.h
	$(CC) -o $(objectdir)affConsole.o -c $(affConsoledir)affConsole.c

$(objectdir)affGraphic.o: $(affGraphicdir)affGraphic.c $(affGraphicdir)affGraphic.h
	$(CC) -o $(objectdir)affGraphic.o -c $(affGraphicdir)affGraphic.c

$(objectdir)morpion.o: $(morpiondir)morpion.c $(morpiondir)morpion.h
	$(CC) -o $(objectdir)morpion.o -c $(morpiondir)morpion.c

$(objectdir)ia.o: $(iadir)ia.c $(iadir)ia.h
	$(CC) -o $(objectdir)ia.o -c $(iadir)ia.c

$(objectdir)mainConsole.o: $(affConsoledir)mainConsole.c
	${CC} -o $(objectdir)mainConsole.o -c $(affConsoledir)mainConsole.c

$(objectdir)mainGraphic.o: $(affGraphicdir)mainGraphic.c
	${CC} -o $(objectdir)mainGraphic.o -c $(affGraphicdir)mainGraphic.c

# ------------ CONSOLE DISPLAY ------------

console: $(objects) $(objectdir)mainConsole.o $(objectdir)affConsole.o
	$(CC) $(CFLAGS) -I$(affConsoledir) -o $(executable) $(objects) $(objectdir)affConsole.o $(objectdir)mainConsole.o

# ------------ GRAPHIC DISPLAY ------------

graphic: $(objects) $(objectdir)mainGraphic.o $(objectdir)affGraphic.o
	$(CC) $(CFLAGS) -I$(affGraphicdir) -o $(executable) $(objects) $(objectdir)mainGraphic.o $(objectdir)affGraphic.o $(LINKER_FLAGS)

clean:
	rm obj/*.o ; rm $(executable)
