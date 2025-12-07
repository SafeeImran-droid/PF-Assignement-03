#include <stdio.h>
#include <string.h>

struct Emp {
    int id;
    char name[50];
    char des[50];
    int sal;
};

void display(struct Emp e[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d %s %s %d\n", e[i].id, e[i].name, e[i].des, e[i].sal);
}

void highest(struct Emp e[], int n) {
    int i, idx = 0;
    for (i = 1; i < n; i++)
        if (e[i].sal > e[idx].sal) idx = i;
    printf("Highest: %d %s %s %d\n", e[idx].id, e[idx].name, e[idx].des, e[idx].sal);
}

void search(struct Emp e[], int n, int id, char name[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (id != -1 && e[i].id == id) {
            printf("%d %s %s %d\n", e[i].id, e[i].name, e[i].des, e[i].sal);
            return;
        }
        if (name != NULL && strcmp(e[i].name, name) == 0) {
            printf("%d %s %s %d\n", e[i].id, e[i].name, e[i].des, e[i].sal);
            return;
        }
    }
    printf("Not found\n");
}

void bonus(struct Emp e[], int n) {
    int i;
    for (i = 0; i < n; i++)
        if (e[i].sal < 50000)
            e[i].sal = e[i].sal + e[i].sal * 0.10;
}

int main() {
    int n, i;
    scanf("%d", &n);
    struct Emp e[n];
    for (i = 0; i < n; i++)
        scanf("%d %s %s %d", &e[i].id, e[i].name, e[i].des, &e[i].sal);
    display(e, n);
    highest(e, n);
    search(e, n, 2, NULL);
    bonus(e, n);
    display(e, n);
}
