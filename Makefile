#Allows for removal of files in Windows OS
ifeq ($(OS),Windows_NT) 
RM = del /Q /F
#CP = copy /Y
else
RM = rm -rf
#CP = cp -f
endif

animal:	init.o animals.o main.o
	gcc -o animal init.o animals.o main.o

init.o: init.c defs.h
	gcc -c init.c

animals.o: animals.c
	gcc -c animals.c

main.o: main.c
	gcc -c main.c

clean:
	$(RM) -f *.o animal.*