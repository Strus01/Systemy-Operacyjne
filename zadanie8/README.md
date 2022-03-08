#Zawartość

----------------------------------------------------------------

I. Program serwer.c tworzy kolejkę komunikatów w trybie do otwierania.
Działa on w petli nieskończonej. Odczytuje on działanie wysłane przez
klienta i następnie odsyła wynik.

II. Program klient.c tworzy kolejkę komunikatów w trybie do czytania.
Wpisujemy w nim działanie, które chcemy wysłać do serwera. Potem klient 
wysyła działanie do serwera i odbiera jego wynik.

III. Biblioteka komunikaty służy do obsługi funkcji kolejki komunikatów POSIX.

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
Aby zakończyć proces SERWER należy użyć sekwencji klawiszy

    Ctrl C
-----------------------------------------------------------------
Aby zakończyć proces SERWER należy użyć sekwencji klawiszy
    
    Ctrl D
-----------------------------------------------------------------
Usuwanie zbędnych plików z katalogu
    
    make clean
-----------------------------------------------------------------
Archiwizacja i kompresja kalatogu
    
    make tar
-----------------------------------------------------------------