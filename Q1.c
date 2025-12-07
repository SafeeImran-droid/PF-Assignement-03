#include <stdio.h>

double calc(double loan, double r, int y, double inst, int yr) {
    if (loan <= 0 || y == 0) {
        printf("Year %d: Remaining loan = %.2f\n", yr, loan);
        return 0;
    }
    double inter = loan * r;
    double after = loan + inter;
    double pay = inst;
    if (pay > after) pay = after;
    double rem = after - pay;
    printf("Year %d: Remaining loan = %.2f\n", yr, rem);
    return pay + calc(rem, r, y - 1, inst, yr + 1);
}

int main() {
    double loan = 100000;
    double r = 0.05;
    int years = 3;
    double inst = loan / years;
    double total = calc(loan, r, years, inst, 1);
    printf("Total repayment = %.2f\n", total);
    return 0;
}
