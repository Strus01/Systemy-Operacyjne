#Zawartość

----------------------------------------------------------------
###Katalog zawiera 1 program oraz pliki Readme i Makefile.

I. Program main.c implementuje problem wzajemnego wykluczania 
dla wątkow. Tworzy on wątki i następnie w sekcji krytycznej wątku
pobiera wartość zmiennej globalnej i przypisuje jej wartość
swojemu prywatnemu licznikowi. Potem inkrementuje ją. 
Program używa sekwencji sterujących konsli do wypisywania wiadomości
o sekcjach.
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
Usuwanie zbędnych plików z katalogu

    make clean
-----------------------------------------------------------------
Archiwizacja i kompresja kalatogu

    make tar
-----------------------------------------------------------------