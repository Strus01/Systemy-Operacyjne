#ROZSZEZENIA
.SUFFIXES: .c .o .x

#KATALOG
DIR = `basename $(CURDIR)`

#NAZWY PLIKOW
NAME1 = main
NAME2 = producent
NAME3 = konsument

#PROGRAMY WYKONAWCZE
EXEC1 = $(NAME1).x
EXEC2 = $(NAME2).x
EXEC3 = $(NAME3).x


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
$(EXEC2): $(OBJS2)
	$(LD) -o $@ $(LFLAGS) $^
$(EXEC3): $(OBJS3)
	$(LD) -o $@ $(LFLAGS) $^

.PHONY: run runt diff 
#URUCHAMIANIE PROGRAMOW
run: $(EXEC1)
	./$(EXEC1) in.txt out.txt

runt: $(EXEC2) $(EXEC3)
	mkfifo fifo -m 0777 
	xterm -hold -title Producent -e ./$(EXEC2) in.txt fifo &
	xterm -hold -title Konsument -e ./$(EXEC3) out.txt fifo 
	rm fifo
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