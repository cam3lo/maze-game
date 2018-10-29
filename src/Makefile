GCC = g++
CFLAGS = -g -Wall

OBJ = main.o node.o
authen: $(OBJ)
	$(GCC) $(CFLAGS) -o maze $(OBJ)

main.o: node.h

node.o: node.h

clean:
	-rm *.o 
