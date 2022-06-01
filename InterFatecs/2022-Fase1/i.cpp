#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, maior = 0;

    cin >> n;

    vector<int> recitou(201, 0);

    for (int i = 0; i < n; i++) {
        int num;

        cin >> num;

        recitou[num] = 1;
        
        if (num > maior) maior = num;
    }

    int tudo = 1;

    for (int i = 1; i < maior; i++) {
        if (!recitou[i]) {
            printf("%d\n", i);
            tudo = 0;
        }
    }

    if (tudo) printf("bom trabalho\n");

    return 0;
}