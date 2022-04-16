#include <stdio.h>
#include "dialog.h"

int dialog(const char *msgs[], int n) {
    char *error = "";
    int choice;
    do {
        puts(error);
        error = "\nThere's no such option -_- \nTry again!\n";
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
        }
        puts("Make your choice now: ");
        choice = getchar() - '0';
        while (getchar() != '\n') {}
    } while (choice < 0 || choice >= n);
    return choice;
}
