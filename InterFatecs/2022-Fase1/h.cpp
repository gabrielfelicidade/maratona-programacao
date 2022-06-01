#include <bits/stdc++.h>

using namespace std;

int main() {

    int inimigos, q1=0, q2=0, q3=0, q4=0;

    cin >> inimigos;

    while(inimigos--) {
        long long int x, y;

        cin >> x >> y;

        if (x > 0 && y > 0) q1++;
        else if (x > 0 && y < 0) q2++;
        else if (x < 0 && y < 0) q3++;
        else q4++;
    }

    printf("I = %d\n", q1);

    printf("II = %d\n", q2);

    printf("III = %d\n", q3);

    printf("IV = %d\n", q4);

    return 0;
}