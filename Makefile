salida_out = lab1
	
salida_headers = funciones.h
salida_source = $(salida_headers:.h=.c) lab1.c funciones.c
salida_objects = $(salida_source:.c=.o)

CC     = gcc 
CFLAGS =  -Wall -lm -lniceprint -L  .

depends = .depends


$(salida_out) : $(salida_objects)
	$(CC) $(CFLAGS) -o $@ $^ -lm -lniceprint -L  .
$(objetcs) :
	$(CC) $(CFLAGS) -c -o $@ $*.c

$(depends) : $(salida_source) $(salida_headers)
	@$(CC) -MM $(salida_source) > $@

clean :
	$(RM) $(salida_out) $(salida_objects) $(zipfile)
.PHONY : build zip clean

sinclude : $(depends)

run :
	./lab1 -N 35 -i test1_35.txt -o out1_35.txt -D
	./lab1 -N 35 -i test2_35.txt -o out2_35.txt -D
	./lab1 -N 30000 -i test3_30000.txt -o out1_30000.txt -D
	./lab1 -N 1000000 -i test4_1M.txt -o out1_1M.txt -D
