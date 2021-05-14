#include <stdio.h>
#include <stdlib.h>
#include <time.h> //potrzebne do time() w srand
#include <string.h> //potrzebne do pobrania dlugości tablicy -> funkcja strlen();

void printMenu();

char *generatePassword(int choice, int length);

char *drawCharacters(int length, char *array);

void controlLoop();

int getInt();

int main() {
    controlLoop(); //głowna funkcja programu
    return 0;
}

void controlLoop(){
    srand(time(NULL)); // Punkt startowy, potrzebny generowania serii pseudolosowych liczb
    while (1) { //nieskończona pętla, program ma się zapętlać
        printMenu();
        int choice = getInt();
        if (choice == 0) break; //w przypadku wyboru 0 program ma się zakończyć
        const char *constant = "Podaj dlugosc hasla:";
        printf("%s", constant);
        int passwordLength = getInt();
        char *password = generatePassword(choice, passwordLength); //funkcja generatePassword zwraca haslo do password
        printf("%s\n", password);
        free(password); //zwalniamy pamięc po dynamicznym zaalokowaniu jej
        system("pause");
    }
}

int getInt() {
    int choice,temp,status;
    status = scanf("%d", &choice); //scanf zwróci 1 - true lub 0 - false do status
    while(status != 1){ //dopóki status nie będzie równy true
        temp = getchar();
        status = scanf("%d", &choice);
    }
    return choice;
}

char *generatePassword(int choice, int passwordLength) {
    char *lettersArray = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *numbersArray = "1234567890";
    char *lettersNumbersArray = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    char *everythingArray = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+?;:<>,.|`~";

    //do losowania znaków używam jednej funkcji, zmieniam jedynie ciągu znaków, z których są losowane
    switch (choice) {
        case 1:
            return drawCharacters(passwordLength, lettersArray);
        case 2:
            return drawCharacters(passwordLength, numbersArray);
        case 3:
            return drawCharacters(passwordLength, lettersNumbersArray);
        case 4:
        default:
            return drawCharacters(passwordLength, everythingArray);
    }
}

char *drawCharacters(int passwordLength, char *array) {
    char *password = malloc(passwordLength); //dynamiczne zaalakowanie pamięci.
    unsigned int arrayLength = strlen(array); //pobieramy dlugosc łańcucha znaków

    for (int i = 0; i < passwordLength; i++)
        password[i] = array[rand()%arrayLength]; //do indexu i przypisujemy znak z array o wylosowanym indexie 0 - dlugosc łańcucha

    password[passwordLength] = '\0'; //przypisanie nulla, potrzebny do poprawnego wyświetlania
    return password;
}

void printMenu() {
    system("cls");
    printf("Generator hasel!\n");
    printf("Wybierz z czego ma sie skladac twoje haslo\n");
    printf("0.Wyjscie\n");
    printf("1.Litery\n");
    printf("2.Cyfry\n");
    printf("3.Litery i cyfry\n");
    printf("4.Litery, cyfry i znaki specjalne\n");
}