#include <stdio.h>
#include <stdlib.h>
#include <time.h> //potrzebne do time() w srand
#include <string.h> //potrzebne do pobrania dlugości tablicy -> funkcja strlen();

void printMenu();

char *generatePassword(int choice, int length);

char *drawCharacters(int length, char *array);

void controlLoop();

int main() {
    controlLoop(); //głowna funkcja programu
    return 0;
}

void controlLoop(){
    srand(time(NULL)); // Punkt startowy, potrzebny generowania serii pseudolosowych liczb
    while (1) { //nieskonczona pętla, program ma chodzic non stop
        printMenu(); //wypisujemy menu
        int choice;
        scanf("%d", &choice);
        if (choice == 0) break; //w przypadku wyboru 0 program ma się zakończyć
        const char *constant = "Podaj dlugosc hasla:";
        printf("%s", constant);
        int passwordLength;
        scanf("%d", &passwordLength);
        char *password = generatePassword(choice, passwordLength); //funkcja generatePassword zwraca haslo do password
        printf("%s\n", password);
        free(password); //zwalniamy pamięc po dynamicznym zaalokowaniu jej
        system("pause"); //pauza
        system("cls");//czyszczenie ekranu
    }
}

char *generatePassword(int choice, int length) {
    //poniżej tablice, z których będą losowane znaki
    char *lettersArray = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *numbersArray = "1234567890";
    char *lettersNumbersArray = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    char *everythingArray = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+?;:<>,.|`~";

    //do losowania znaków używam jednej funkcji, zmieniam jedynie tablice, z której są losowane
    switch (choice) {
        case 1:
            return drawCharacters(length, lettersArray);
        case 2:
            return drawCharacters(length, numbersArray);
        case 3:
            return drawCharacters(length, lettersNumbersArray);
        case 4:
        default:
            return drawCharacters(length, everythingArray);
    }
}

char *drawCharacters(int passwordLength, char *array) {
    char *password = malloc(passwordLength); //dynamiczne przydzielenie pamięci.
    int arrayLength = strlen(array); //pobieramy dlugosc tablicy ze znakami
    for (int i = 0; i < passwordLength; i++) {
        password[i] = array[rand()%arrayLength]; //do indexu i przypisujemy znak z array o wylosowanym indexie 0 - dlugosc tablicy
    }
    password[passwordLength] = '\0';
    return password;
}

void printMenu() {
    printf("Generator hasel!\n");
    printf("Wybierz z czego ma sie skladac twoje haslo\n");
    printf("0.Wyjscie\n");
    printf("1.Litery\n");
    printf("2.Cyfry\n");
    printf("3.Litery i cyfry\n");
    printf("4.Litery, cyfry i znaki specjalne\n");
}