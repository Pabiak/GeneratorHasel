#include <stdio.h>
#include <stdlib.h>
#include <time.h> //potrzebne do time() w srand
#include <string.h> //potrzebne do pobrania dlugości tablicy -> funkcja strlen();
#include <windows.h> //potrzebne do sleep i handle

void printMenu();

char *generatePassword(int choice, int length);

char *drawCharacters(int length, char *array);

void controlLoop();

int getInt();

void savePasswordToFile(char *password);

void setColor(char *color);

void animation(char *text);

int main() {
    controlLoop(); //głowna funkcja programu
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
    animation("========Generator hasel========\n");
    setColor("gray");
    animation("Wybierz z czego ma sie skladac twoje haslo\n");
    animation("0.Wyjscie\n");
    animation("1.Litery\n");
    animation("2.Cyfry\n");
    animation("3.Litery i cyfry\n");
    animation("4.Litery, cyfry i znaki specjalne\n");
}

void animation(char *text) {
    for (int i = 0; i < strlen(text); ++i) {
        printf("%c", text[i]);
        Sleep(30);
    }
}

void savePasswordToFile(char *password) {
    printf("Czy chcesz zapisac haslo? t/n: ");
    char choice, temp;
    temp = getchar(); //taki bufor dla entera
    scanf("%c", &choice);
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
    if (color == "green")
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    else if (color == "red")
        SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
    else if (color == "blue")
        SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    else if (color == "gray")
        SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}
