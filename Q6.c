#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stu {
    int id;
    char name[100];
    char batch[20];
    char type[10];
    char reg[20];
    char dob[20];
    char interest[20];
};

struct Stu arr[500];
int n = 0;

void load() {
    FILE *f = fopen("members.dat", "rb");
    if (!f) return;
    n = fread(arr, sizeof(struct Stu), 500, f);
    fclose(f);
}

void save() {
    FILE *f = fopen("members.dat", "wb");
    fwrite(arr, sizeof(struct Stu), n, f);
    fclose(f);
}

int find(int id) {
    int i;
    for (i = 0; i < n; i++)
        if (arr[i].id == id) return i;
    return -1;
}

void add() {
    struct Stu s;
    scanf("%d %s %s %s %s %s %s", &s.id, s.name, s.batch, s.type, s.reg, s.dob, s.interest);
    if (find(s.id) != -1) return;
    arr[n++] = s;
    save();
}

void update() {
    int id;
    scanf("%d", &id);
    int i = find(id);
    if (i == -1) return;
    scanf("%s %s", arr[i].batch, arr[i].type);
    save();
}

void del() {
    int id;
    scanf("%d", &id);
    int i = find(id);
    if (i == -1) return;
    int j;
    for (j = i; j < n - 1; j++)
        arr[j] = arr[j + 1];
    n--;
    save();
}

void list() {
    int i;
    for (i = 0; i < n; i++)
        printf("%d %s %s %s %s %s %s\n",
               arr[i].id, arr[i].name, arr[i].batch, arr[i].type,
               arr[i].reg, arr[i].dob, arr[i].interest);
}

void report() {
    char b[20];
    scanf("%s", b);
    int i;
    for (i = 0; i < n; i++)
        if (strcmp(arr[i].batch, b) == 0)
            printf("%d %s\n", arr[i].id, arr[i].name);
}

int main() {
    load();
    int c;
    while (1) {
        scanf("%d", &c);
        if (c == 1) add();
        else if (c == 2) update();
        else if (c == 3) del();
        else if (c == 4) list();
        else if (c == 5) report();
        else break;
    }
    return 0;
}
