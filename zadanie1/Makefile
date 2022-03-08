#ROZSZEZENIA
.SUFFIXES: .c .o .x

#KATALOG
DIR = `basename $(CURDIR)`

#NAZWY PLIKOW
NAME1 = a
NAME2 = b
NAME3 = c
NAME4 = d
NAME5 = e

#PROGRAMY WYKONAWCZE
EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x
EXEC4 = $(NAME4).x
EXEC5 = $(NAME5).x

#PLIKI PO KOMPILACJI
OBJS1 = $(NAME1).o
OBJS2 = $(NAME2).o
OBJS3 = $(NAME3).o
OBJS4 = $(NAME4).o
OBJS5 = $(NAME5).o
 
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
$(EXEC3): $(OBJS3)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC4): $(OBJS4)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC5): $(OBJS5)
	$(LD) -o $@ $(LFLAGS) $^

#BEZWZGLEDNE WYKONANIE PROGRAMU
.PHONY: run1 run2 run3 run4 run5

#URUCHAMIANIE PROGRAMOW
run1: $(EXEC1)
	./$(EXEC1)
run2: $(EXEC2)
	./$(EXEC2)
run3: $(EXEC3)
	./$(EXEC3)
run4: $(EXEC4)
	./$(EXEC4)
run5: $(EXEC5)
	./$(EXEC5)	

#CLEANER
.PHONY: clean tar
clean: 
	rm -f *.o  *~ *.a *.so *.x core core* a.out;

#ARCHIWIZACJA I KOMPRESJA
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )