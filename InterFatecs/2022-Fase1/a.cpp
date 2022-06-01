#include <bits/stdc++.h>

using namespace std;

bool isMercosul(int* plate) {
    return plate[0] >= 65 && plate[0] <= 90 &&
        plate[1] >= 65 && plate[1] <= 90 &&
        plate[2] >= 65 && plate[2] <= 90 &&
        plate[3] >= 48 && plate[3] <= 57 &&
        plate[4] >= 65 && plate[4] <= 90 &&
        plate[5] >= 48 && plate[5] <= 57 &&
        plate[6] >= 48 && plate[6] <= 57;
}

bool isOld(int* plate) {
    return plate[0] >= 65 && plate[0] <= 90 &&
        plate[1] >= 65 && plate[1] <= 90 &&
        plate[2] >= 65 && plate[2] <= 90 &&
        plate[3] >= 48 && plate[3] <= 57 &&
        plate[4] >= 48 && plate[4] <= 57 &&
        plate[5] >= 48 && plate[5] <= 57 &&
        plate[6] >= 48 && plate[6] <= 57;
}

int main() {

    int plate[7];

    while(scanf("%d %d %d %d %d %d %d", &plate[0], &plate[1], &plate[2], &plate[3], &plate[4], &plate[5], &plate[6]) != EOF) {
        if (isMercosul(plate)) {
            printf("MERCOSUL\n");
        } else if (isOld(plate)) {
            printf("ANTIGA\n");
        } else {
            printf("ERRO\n");
        }
    }

    return 0;
}