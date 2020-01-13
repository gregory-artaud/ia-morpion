console: morpionExeC affConsole/affConsole.o morpion/morpion.o

graphic: morpionExeG affGraphic/affGraphic.o morpion/morpion.o

affConsole.o: affConsole/affConsole.c affConsole/affConsole.h
	gcc -c affConsole/affConsole.c

morpion.o: morpion/morpion.c morpion/morpion.h
	gcc -c morpion/morpion.c

# ------------ CONSOLE DISPLAY ------------

morpionExeC: affConsole/mainConsole.c affConsole/affConsole.c affConsole/affConsole.h morpion/morpion.c morpion/morpion.h
	gcc -o morpionExe affConsole/mainConsole.c affConsole/affConsole.c morpion/morpion.c

# ------------ GRAPHIC DISPLAY ------------

morpionExeG: affGraphic/mainGraphic.c affGraphic/affGraphic.c affGraphic/affGraphic.h morpion/morpion.c morpion/morpion.h
	gcc -o morpionExe affGraphic/mainGraphic.c affGraphic/affGraphic.c morpion/morpion.c

clean:
	find . -name "*.o" -type f -delete ; rm -f morpionExe
