# ĆWICZENIE 2: Uruchamianie Programów: exec

## Treść zadania

Zmodyfikować program z ćwiczenia 1b, tak aby komunikaty procesów potomnych były wypisywane przez program uruchamiany przez funkcję `exec`.

Nazwę programu do uruchomienia przekazywać przez argumenty programu procesu macierzystego.

> Ile procesów powstanie przy n-krotnym wywołaniu funkcji fork-exec jak wyżej i dlaczego?

## Zawartość

Pliki `.c`

- exec.c (główny program, zmodyfikowane ćwiczenie 1B, wypisywanie identyfikatorów procesów z użyciem funkcji exec)
- id.c (program z ćwiczenia 1A wypisujący identyfikatory procesów)

## Jak uruchomić programy

Aby uruchomić program, należy wykonać komendę:

```bash
make run
```

Aby wyczyścić zawartość katalogu (usunać zbędne pliki), należy wykonać:

```bash
make clean
```

W celu archiwizacji oraz kompresji katalogu należy wykonać:

```bash
make tar
```