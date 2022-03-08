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
CFLAGS = -Wall -pedantic -O -fPIC
LFLAGS = -Wall -pedantic -O

#REGULA WZORCOWA
%.o: %.c
	$(CO) $(CFLAGS) -c $<

#REGULY ZALEZNOSCI
$(EXEC1): $(OBJS1)
	$(LD) -o $@ $(LFLAGS) $^

#URUCHAMIANIE PROGRAMOW
run: $(EXEC1)
	./$(EXEC1) in.txt out.txt

#POROWNYWANIE ZAWARTOSCI PLIKOW
diff: 
	diff -s in.txt out.txt

#CLEANER
.PHONY: clean tar
clean: 
	rm -f *.o  *~ *.a *.so *.x core core* a.out;

#ARCHIWIZACJA I KOMPRESJA
tar: clean
	(cd ../; tar -cvzf $(DIR).tar.gz  $(DIR) )