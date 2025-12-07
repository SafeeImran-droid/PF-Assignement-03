#include <stdio.h>

struct Book {
    int id;
    int pop;
    int used;
};

int main() {
    int cap, q;
    scanf("%d %d", &cap, &q);

    struct Book s[100];
    int n = 0;
    int t = 1;

    while (q--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'A' && op[1] == 'D') {
            int x, y;
            scanf("%d %d", &x, &y);
            int i, ok = 0;
            for (i = 0; i < n; i++)
                if (s[i].id == x) {
                    s[i].pop = y;
                    s[i].used = t++;
                    ok = 1;
                    break;
                }
            if (!ok) {
                if (n < cap) {
                    s[n].id = x;
                    s[n].pop = y;
                    s[n].used = t++;
                    n++;
                } else {
                    int j = 0;
                    for (i = 1; i < n; i++)
                        if (s[i].used < s[j].used) j = i;
                    s[j].id = x;
                    s[j].pop = y;
                    s[j].used = t++;
                }
            }

        } else {
            int x;
            scanf("%d", &x);
            int i, f = -1;
            for (i = 0; i < n; i++)
                if (s[i].id == x) {
                    f = s[i].pop;
                    s[i].used = t++;
                    break;
                }
            printf("%d\n", f);
        }
    }
}
