#include <stdio.h>
#include <stdlib.h>
#include <time.h> //potrzebne do time() w srand
#include <string.h> //potrzebne do pobrania dlugości tablicy -> funkcja strlen(), strcmp() -> porównanie stringów;
#include <windows.h> //potrzebne do sleep i handle

void printMenu();

char *generatePassword(int choice, int length);

char *drawCharacters(int length, char *array);

void controlLoop();

int getInt();

void savePasswordToFile(char *password);

void setColor(char *color);

void animation(char *text, int delay);

int main() {
    controlLoop(); //góowna funkcja programu
    return 0;
}

void controlLoop() {
    srand(time(NULL)); // Punkt startowy, potrzebny generowania serii pseudolosowych liczb
    while (1) { //nieskończona pętla, program ma się zapętlać
        printMenu();
        int choice = getInt();
        if (choice == 0) break; //w przypadku wyboru 0 program ma się zakończyć
        const char *constant = "Podaj dlugosc hasla:";
        printf("%s", constant);
        int passwordLength = getInt();
        char *password = generatePassword(choice, passwordLength); //funkcja generatePassword zwraca haslo do password
        setColor("red");
        printf("%s\n", password);
        setColor("gray");
        savePasswordToFile(password);
        free(password); //zwalniamy pamięc po dynamicznym zaalokowaniu jej
    }
}

int getInt() {
    int integer, temp, status;
    status = scanf("%d", &integer); //scanf zwróci 1 - true lub 0 - false do status
    while (status != 1) { //dopóki status nie będzie równy true
        temp = getchar();
        status = scanf("%d", &integer);
    }
    return integer;
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
    int arrayLength = strlen(array); //pobieramy dlugosc łańcucha znaków

    for (int i = 0; i < passwordLength; i++)
        password[i] = array[rand() %
                            arrayLength]; //do indexu i przypisujemy znak z array o wylosowanym indexie 0 - dlugosc łańcucha

    password[passwordLength] = '\0'; //przypisanie nulla, potrzebny do poprawnego wyświetlania
    return password;
}

void printMenu() {
    system("cls");
    setColor("green");
    animation("========Generator hasel========\n",30);
    setColor("gray");
    animation("Wybierz z czego ma sie skladac twoje haslo\n",30);
    animation("0.Wyjscie\n",25);
    animation("1.Litery\n",25);
    animation("2.Cyfry\n",25);
    animation("3.Litery i cyfry\n",25);
    animation("4.Litery, cyfry i znaki specjalne\n",25);
}

void animation(char *text, int delay) {
    for (int i = 0; i < strlen(text); ++i) {
        printf("%c", text[i]);
        Sleep(delay);
    }
}

void savePasswordToFile(char *password) {
    printf("Czy chcesz zapisac haslo? t/n: ");
    char choice, temp;
    temp = getchar(); //taki bufor dla entera
    choice = getchar();
    if (choice == 'T' || choice == 't') {
        FILE *file = fopen("password.txt", "w"); //pierwszy parametr to nazwa pliku, drugi to tryb - w oznacza write
        if (file == NULL) {
            setColor("red");
            printf("Nie udalo sie zapisac pliku\n");
            setColor("gray");
        }
        fputs(password, file); //zapis
        fclose(file); //zamknięcie pliku
    }
}

void setColor(char *color) {
    HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (strcmp(color,"green") == 0)
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    else if (strcmp(color,"red") == 0)
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    else if (strcmp(color,"gray") == 0)
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}
