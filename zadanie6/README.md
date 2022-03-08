# Zawartość

----------------------------------------------------------------

I. Program main.c tworzy semafor i wypisuje jego nazwę, wartość i adres.
Potem tworzy plik numer.txt i wpisuje do niego liczbę 0.
Następnie uruchamia w swoim procesie potomnym program wykluczenia.c. 
Na koniec usuwa utworzony semafor.

II. Program wykluczenia jest odpowiedzialny za operacje w sekcji prywatnej
oraz krytycznej procesu. W sekcji krytycznej odczytuje on wartość z pliku 
numer.txt, zwiększa ją o 1 i zapisuje do pliku.

III. Biblioteka semafory.c zawiera fukcje do tworzenia, otwierania,
uzyskiwania wartości, podnoszenia, opuszczania, zamykania i niszczenia 
semafora.

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