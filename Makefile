console: morpionExeC affConsole/affConsole.o morpion/morpion.o ia/ia.o

graphic: morpionExeG affGraphic/affGraphic.o morpion/morpion.o ia/ia.o

affConsole.o: affConsole/affConsole.c affConsole/affConsole.h
	gcc -c affConsole/affConsole.c

morpion.o: morpion/morpion.c morpion/morpion.h
	gcc -c morpion/morpion.c

ia.o: ia/ia.c ia/ia.h
	gcc -c ia/ia.c

# ------------ CONSOLE DISPLAY ------------

morpionExeC: affConsole/mainConsole.c affConsole/affConsole.c affConsole/affConsole.h morpion/morpion.c morpion/morpion.h ia/ia.c ia/ia.h
	gcc -o morpionExe affConsole/mainConsole.c affConsole/affConsole.c morpion/morpion.c ia/ia.c

# ------------ GRAPHIC DISPLAY ------------

morpionExeG: affGraphic/mainGraphic.c affGraphic/affGraphic.c affGraphic/affGraphic.h morpion/morpion.c morpion/morpion.h ia/ia.c ia/ia.h
	gcc -o morpionExe affGraphic/mainGraphic.c affGraphic/affGraphic.c morpion/morpion.c ia/ia.c

clean:
	find . -name "*.o" -type f -delete ; rm -f morpionExe
