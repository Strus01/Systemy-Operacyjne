#Zawartość

-----------------------------------------------------------------

I. Program main.c implementuje algorytm piekarni. 
Tworzy on wątki i następnie w sekcji krytycznej wątku
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
Aby skompilować program należy wpisać komendę

    make compile
-----------------------------------------------------------------
Aby uruchomić program należy wpisać komendę 

    ./main.x
-----------------------------------------------------------------
Usuwanie zbędnych plików z katalogu

    make clean
-----------------------------------------------------------------
Archiwizacja i kompresja kalatogu

    make tar
-----------------------------------------------------------------