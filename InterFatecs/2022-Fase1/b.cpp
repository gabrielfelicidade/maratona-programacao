#include <bits/stdc++.h>

using namespace std;

int main(){

    int p, e;

    cin >> p >> e;

    int pessoas[p+1];
    int grupos[p+1];
    int ni = 0;
    int ns = p;
    int n = p;

    for (int i = 1; i <= p; i++) pessoas[i] = i;
    for (int i = 1; i <= p; i++) grupos[i] = 0;

    while (e--) {
        string s;

        cin >> s;

        if (s == "c") {
            int a, b;
            cin >> a >> b;
            if (pessoas[a] != pessoas[b]) {
                n--;
                if (grupos[pessoas[a]] && !grupos[pessoas[b]]) {
                    ns--;
                } else if (!grupos[pessoas[a]] && grupos[pessoas[b]]) {
                    ns--;
                    ni++;
                } else if (grupos[pessoas[a]] && grupos[pessoas[b]]) {
                    ni--;
                } else {
                    ns--;
                }
                int grupo = pessoas[b];
                for (int i = 1; i <= p; i++) if (pessoas[i] == grupo) pessoas[i] = pessoas[a];
            }
        } else if (s == "p") {
            int a;
            cin >> a;

            if (!grupos[pessoas[a]]) {
                grupos[pessoas[a]] = 1;
                ni++;
                ns--;
            }
        } else if (s == "n") {
            printf("%d\n", n);
        } else if (s == "ns") {
            printf("%d\n", ns);
        } else if (s == "ni") {
            printf("%d\n", ni);
        } else {
            if (ni == 0) printf("vazio\n"); else {
                int primeiro = 1;
                for (int i = 1; i <= p; i++) {
                    if (grupos[pessoas[i]]) {
                        if (primeiro) {
                            printf("%d", i);
                            primeiro = 0;
                        } else {
                            printf(" %d", i);
                        }
                    }
                }
                printf("\n");
            }
        }
    }

    return 0;
}