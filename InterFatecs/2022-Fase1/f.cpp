#include <bits/stdc++.h>

using namespace std;

int main() {

    int ql, qc;

    cin >> ql >> qc;

    unsigned long long int retangulo[ql][qc];

    for (int i = 0; i < qc; i++) {
        retangulo[0][i] = 0;
    }
    for (int i = 1; i < ql; i++) {
        retangulo[i][qc - 1] = 1;
    }
    for (int i = 0; i < qc - 1; i++) {
        retangulo[ql - 1][i] = 2;
    }
    for (int i = 1; i < ql - 1; i++) {
        retangulo[i][0] = 3;
    }

    for (int i = 1; i < ql - 1; i++) {
        for (int j = 1; j < qc - 1; j++) {
            retangulo[i][j] = retangulo[i-1][j] + retangulo[i-1][j-1] + retangulo[i][j-1];
        }
    }

    int l, c;

    cin >> l >> c;

    cout << retangulo[l-1][c-1] << endl;

    return 0;
}