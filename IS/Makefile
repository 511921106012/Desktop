OBJ := $(patsubst %.c, %.o, $(wildcard *.c))

a.out : $(OBJ)
	gcc $(OBJ) -o a.out

clean:	
		rm *.o a.out