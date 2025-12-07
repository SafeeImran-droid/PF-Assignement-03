#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **lines;
int n = 0;
int cap = 2;

void grow() {
    cap *= 2;
    lines = realloc(lines, cap * sizeof(char*));
}

void insertLine(int idx, char *txt) {
    if (n == cap) grow();
    int i;
    for (i = n; i > idx; i--)
        lines[i] = lines[i - 1];
    lines[idx] = malloc(strlen(txt) + 1);
    strcpy(lines[idx], txt);
    n++;
}

void deleteLine(int idx) {
    int i;
    free(lines[idx]);
    for (i = idx; i < n - 1; i++)
        lines[i] = lines[i + 1];
    n--;
}

void printAll() {
    int i;
    for (i = 0; i < n; i++)
        printf("%s\n", lines[i]);
}

void shrink() {
    cap = n;
    lines = realloc(lines, cap * sizeof(char*));
}

void save() {
    FILE *f = fopen("file.txt", "w");
    int i;
    for (i = 0; i < n; i++)
        fprintf(f, "%s\n", lines[i]);
    fclose(f);
}

void load() {
    FILE *f = fopen("file.txt", "r");
    if (!f) return;
    char temp[500];
    while (fgets(temp, 500, f)) {
        temp[strcspn(temp, "\n")] = 0;
        insertLine(n, temp);
    }
    fclose(f);
}

int main() {
    lines = malloc(cap * sizeof(char*));

    insertLine(0, "hello");
    insertLine(1, "world");
    insertLine(1, "middle");
    deleteLine(0);
    printAll();
    shrink();
    save();
    return 0;
}
