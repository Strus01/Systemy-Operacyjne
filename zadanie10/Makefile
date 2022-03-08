#ROZSZEZENIA
.SUFFIXES: .c .o .x

#KATALOG
DIR = `basename $(CURDIR)`

#NAZWY PLIKOW
NAME1 = main

#PROGRAMY WYKONAWCZE
EXEC1 = $(NAME1).x

#PLIKI PO KOMPILACJI
OBJS1 = $(NAME1).o
 
# KOMPILATOR I LINKER 
CO = gcc
LD = $(CO)

#FLAGI KOMPILATORA I LINKERA
CFLAGS = -Wall -std=c99 -pedantic -fPIC
LFLAGS = -Wall -std=c99 -pedantic -lpthread

#REGULA WZORCOWA
%.o: %.c
	$(CO) $(CFLAGS) -c $<

#REGULY ZALEZNOSCI
.PHONY: compile

$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^ 

#URUCHAMIANIE PROGRAMOW
compile: $(EXEC1)

#CLEANER
.PHONY: clean tar
clean: 
	rm -f *.o  *~ *.a *.so *.x core core* a.out;

#ARCHIWIZACJA I KOMPRESJA
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )