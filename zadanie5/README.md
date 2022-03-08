#Zawartość

----------------------------------------------------------------

I. Program implementuje problem producenta i konsumenta za pomocą
   potoków nazwanych.

-----------------------------------------------------------------
Uruchamianie
-----------------------------------------------------------------

Za uruchamianie programu odpowiedzialny jest plik Makefile.
Służy on też do archiwizacji i czyszczenia zbędnych plików 
po kompilacji.

-----------------------------------------------------------------
Aby uruchomić program należy wpisać komendę 
    
    make run 
-----------------------------------------------------------------
Aby sprawdzić czy potoki FIFO działają dla niezależnych procesów 
należy wpisać komendę 
    
    make runt
-----------------------------------------------------------------
Aby porównać zawartość plików in.txt i out.txt  

    make diff
-----------------------------------------------------------------
Usuwanie zbędnych plików z katalogu

    make clean
-----------------------------------------------------------------
Archiwizacja i kompresja kalatogu

    make tar
-----------------------------------------------------------------