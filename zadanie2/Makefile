#ROZSZEZENIA
.SUFFIXES: .c .o .x

#KATALOG
DIR = `basename $(CURDIR)`

#NAZWY PLIKOW
NAME1 = exec
NAME2 = id

#PROGRAMY WYKONAWCZE
EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x

#PLIKI PO KOMPILACJI
OBJS1 = $(NAME1).o
OBJS2 = $(NAME2).o
 
# KOMPILATOR I LINKER 
CO = gcc
LD = $(CO)

#FLAGI KOMPILATORA I LINKERA
CFLAGS = -Wall -pedantic -O -fPIC
LFLAGS = -Wall -pedantic -O

#REGULA WZORCOWA
%.o: %.c
	$(CO) $(CFLAGS) -c $<

#REGULY ZALEZNOSCI
.PHONY: all
all: $(EXEC1) $(EXEC2) $(EXEC3) $(EXEC4) $(EXEC5)

$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $^

#BEZWZGLEDNE WYKONANIE PROGRAMU
.PHONY: run1 run2 run3 run4 run5

#URUCHAMIANIE PROGRAMOW
run: $(EXEC1) $(EXEC2)
	./$(EXEC1) $(EXEC2)
	
#CLEANER
.PHONY: clean tar
clean: 
	rm -f *.o  *~ *.a *.so *.x core core* a.out;

#ARCHIWIZACJA I KOMPRESJA
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )