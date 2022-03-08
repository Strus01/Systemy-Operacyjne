# Zawartość

----------------------------------------------------------------

I.   Pierwszy program odpowiada za obsługę sygnałów.

II.  Drugi program uruchamia pierwszy program funkcją exec.
Następnie wysyła do procesu potomnego sygnał poprzez funkcję kill.

III. Trzeci program tworzy proces potomny. Potem sprawia, że staje się
on liderem swojej grupy i uruchamia w nim kilka procesów potomnych.
Następnie z pierwszego procesu macierzystego wysyłany jest sygnał do
całej grupy procesów potomnych. Lider grupy ignoruje ten sygnał i czeka na
zakończenie wszystkich swoich procesów potomnych i zwraca ich status zakończenia.

-----------------------------------------------------------------
Uruchamianie
-----------------------------------------------------------------

Za uruchamianie programu odpowiedzialny jest plik Makefile.
Służy on też do archiwizacji i czyszczenia zbędnych plików
po kompilacji.

Przy uruchamianiu programu należy podać nr_sygnalu i nr_obslugi.

nr_sygnalu to dowolna liczba naturalna z wyjątkiem 9 i 19.

nr_obslugi to obsługa naszego sygnału

nr_obslugi:
1) Operacja domyślna.
2) Zignorowanie sygnału.
3) Własna obsługa (przechwycenie sygnału).
4) 
-----------------------------------------------------------------
Aby skompilować należy wpisać komendę
    
    make compile1 (dla programu a)
    make compile2 (dla programu b)
    make compile3 (dla programu c)
-----------------------------------------------------------------
Aby uruchomić program a) należy wpisać komendę

    ./a.x nr_sygnalu nr_obslugi

Analogicznie dla pozostałych programów.

    Aby uruchomić programy b) i c) należy najpierw skompilować program a) (make compile1).
-----------------------------------------------------------------
Usuwanie zbędnych plików z katalogu
    
    make clean
-----------------------------------------------------------------
Archiwizacja i kompresja kalatogu

    make tar
-----------------------------------------------------------------
