#include <stdio.h>

int calcFuel(int fuel, int cons, int reg, int solar, int p, int total) {
    if (fuel <= 0) {
        printf("Planet %d: Fuel Remaining = 0\n", p);
        return 0;
    }
    if (p > total) return 1;

    fuel -= cons;
    if (p % 3 == 0) fuel += reg;
    if (p % 4 == 0) fuel += solar;

    if (fuel < 0) fuel = 0;

    printf("Planet %d: Fuel Remaining = %d\n", p, fuel);

    return calcFuel(fuel, cons, reg, solar, p + 1, total);
}

int main() {
    int fuel = 200;
    int cons = 40;
    int reg = 20;
    int solar = 50;
    int planets = 7;

    int ok = calcFuel(fuel, cons, reg, solar, 1, planets);
    if (ok) printf("Journey Completed\n");
    else printf("Journey Failed\n");
}
