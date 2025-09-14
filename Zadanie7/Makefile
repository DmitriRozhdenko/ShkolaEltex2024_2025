BIN := CalculStatic
TARGET :=CalculStatic.c
SOURCES :=  mul.c sub.c dive.c add.c
OBJ := mul.o sub.o dive.o add.o
HDR := libcalc.h
LIB =calc
  

.PHONY:clean


$(BIN): $(TARGET) $(LIB)
		gcc $(TARGET) -o $(BIN) -L. -l$(LIB) 

$(LIB):$(OBJ)
		ar rc lib$(LIB).a  $(OBJ)
				
%.O: %.c
		gcc $^ -c
		
		

clean:
		rm -f $(BIN) *.o lib$(LIB).a
		



