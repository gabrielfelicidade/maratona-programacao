#include <bits/stdc++.h>

using namespace std;

double f(double x, int g, double* coef) {

    double ret = 0;

    for (int i = g, j = 0; j <= g; j++, i--) {
        ret = ret + coef[j] * pow(x, i);
    }

    return ret;
}

int main(){

    double b, h;

    cin >> b >> h;

    int g;

    cin >> g;

    double coef[g+1];

    for (int i = 0; i <= g; i++) cin >> coef[i];

    int pontos;

    cin >> pontos;

    double espcX = b / (2 * (pontos - 1));

    double polinomio = 0;

    for (int i = 0; i < pontos; i++) {
        if (i == 0 || i == pontos - 1) {
            polinomio = polinomio + f(espcX * i, g, coef);
        } else if (i % 2 == 0) {
            polinomio = polinomio + 2 * f(espcX * i, g, coef);
        } else if (i % 2 == 1) {
            polinomio = polinomio + 4 * f(espcX * i, g, coef);
        }
    }

    double acinza = 2 * espcX / 3 * polinomio;

    double ams = b * h - acinza;

    double cm = ams / (b * h);

    printf("%.4lf\n", cm);

    return 0;
}