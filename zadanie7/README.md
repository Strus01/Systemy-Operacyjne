#Zawartość

----------------------------------------------------------------
###Katalog zawiera 3 programy, 2 biblioteki z funkcjmi oraz pliki Readme i Makefile.

I. Program main.c tworzy semafory i pamięć dzieloną,
a następnie wypisuje ich nazwę, wartość i adres.
Potem uruchamia programy producenta i konsumenta.
Na koniec usuwa utworzony semafory i pamięć dzieloną.

II. Producent otwiera pamięć dzieloną i ją mapuje. Otwiera on też 
semafory. Następnie w swojej sekcji krytycznej zapisuje zawartość 
pliku in.txt do wspólnego bufora.

III. Konsument otwiera pamięć dzieloną i ją mapuje. Otwiera on też 
semafory. Następnie w swojej sekcji krytycznej zapisuje zawartość
wspólnego bufora do pliku out.txt.

IV. Biblioteka semafory.c zawiera fukcje do tworzenia, otwierania,
uzyskiwania wartości, podnoszenia, opuszczania, zamykania i niszczenia 
semafora.

V. Biblioteka pamiec.c zawiera funkcje do tworzenia, otwierania,
zamykania, mapowania, odmapowania, usuwania pamięci dzielonej.
-----------------------------------------------------------------
Uruchamianie
-----------------------------------------------------------------
Za uruchamianie programu odpowiedzialny jest plik Makefile.
Służy on też do archiwizacji i czyszczenia zbędnych plików 
po kompilacji.
-----------------------------------------------------------------
Aby uruchomić program z wykorzystaniem biblioteki statycznej należy 
wpisać komendę 

    make run1 
-----------------------------------------------------------------
Aby uruchomić program z wykorzystaniem 1 sposobu tworzenia biblioteki dzielonej 
należy wpisać komendę 
    
    make run2
-----------------------------------------------------------------
Aby uruchomić program z wykorzystaniem 2 sposobu tworzenia biblioteki dzielonej 
należy wpisać komendę 
    
    make run3
-----------------------------------------------------------------
Aby porównac zawarotść plików in.txt i out.txt należy wpisać komendę

    make diff
-----------------------------------------------------------------
Usuwanie zbędnych plików z katalogu
    
    make clean
-----------------------------------------------------------------
Archiwizacja i kompresja kalatogu

    make tar
-----------------------------------------------------------------


Przykład pseudokodu dla ćwiczenia 7:

```cpp
// Pseudokod dla problemu Producenta i Konsumenta z buforem cyklicznym.
// Wspolny bufor do przesylania danych znajduje sie w pamieci dzielonej.
// Dostep do bufora jest synchronizowany semaforami.

#define N ? // Rozmiar bufora

typdef struct { ... } Towar; // Definicja typu dla jednostek towaru
Towar bufor[N]; // Bufor mogacy pomiescic N jednostek towaru
int wstaw = 0, wyjmij = 0; // Pozycje wstawiania oraz wyjmowania towaru
    // z bufora (mozna umieścic w pamieci dzielonej)

semaphore PROD = N; // Semafor do wstrzymywania Producenta
semaphore KONS = 0; // Semafor do wstrzymywania Konsumenta

// Proces Producent
// ----------------
Towar towarProd;
while (1) {
    // Produkcja towaru
    P(PROD); // Opusc semafor Producenta
    bufor[wstaw] = towarProd; // Umiesc towar w buforze
    wstaw = (wstaw + 1) % N; // Przesun pozycje wstawiania o 1 dalej
    V(KONS); // Podniesc semafor Konsumenta
}

// Proces Konsument
// ----------------
Towar towarKons;
while (1) {
    P(KONS); // Opusc semafor Konsumenta
    towarKons = bufor[wyjmij]; // Umiesc towar w buforze
    wyjmij = (wyjmij + 1) % N; // Przesun pozycje wstawiania o 1 dalej
    V(PROD); // Podniesc semafor Producenta
    // Konsumpcja towaru
}
```