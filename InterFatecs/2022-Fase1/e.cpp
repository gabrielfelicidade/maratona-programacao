#include <bits/stdc++.h>

using namespace std;

int main() {

    double i, a, t;

    cin >> i;
    cin >> a;
    cin >> t;

    if (i >= a) {
        printf("pode comprar agora\n");
    } else {
        int meses = 0;
        do {
            i = i * (t / 100) + i;
            meses++;
        } while(i < a);

        if (meses == 1) {
            printf("possivel em 1 mes\n");
        } else {
            printf("possivel em %d meses\n", meses);
        }
    }

    return 0;
}