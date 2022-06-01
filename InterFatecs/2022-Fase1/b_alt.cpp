#include <bits/stdc++.h>

using namespace std;

struct sPessoa {
    int id;
    struct sPessoa* next;
};

typedef struct {
    bool infectado;
    struct sPessoa* pessoas;
    struct sPessoa* ultima;
} sGrupo;

int main(){

    int p, e;

    cin >> p >> e;
    int ni = 0;
    int ns = p;
    int n = p;

    sGrupo* grupos[p+1];

    for (int i = 1; i <= p; i++) {
        struct sPessoa* pessoa = (struct sPessoa*) malloc(sizeof(struct sPessoa));
        sGrupo* grupo = (sGrupo*) malloc(sizeof(sGrupo));

        pessoa->id = i;
        pessoa->next = NULL;

        grupo->infectado = false;
        grupo->pessoas = pessoa;
        grupo->ultima = pessoa;
        grupos[i] = grupo;
    }

    while (e--) {
        string s;

        cin >> s;

        if (s == "c") {
            int a, b;
            cin >> a >> b;
            if (grupos[a] != grupos[b]) {
                n--;
                if (grupos[a]->infectado && !grupos[b]->infectado) {
                    ns--;
                } else if (!grupos[a]->infectado && grupos[b]->infectado) {
                    ns--;
                    ni++;
                } else if (grupos[a]->infectado && grupos[b]->infectado) {
                    ni--;
                } else {
                    ns--;
                }
                grupos[a]->ultima->next = grupos[b]->pessoas;
                grupos[a]->ultima = grupos[b]->ultima;
                grupos[b]->infectado = false;
                grupos[b]->pessoas = NULL;
                grupos[b]->ultima = NULL;
                grupos[b] = grupos[a];
            }
        } else if (s == "p") {
            int a;
            cin >> a;

            if (!grupos[a]->infectado) {
                grupos[a]->infectado = true;
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
                vector<int> infectados(p + 1, 0);
                for (int i = 1; i <= p; i++) {
                    if (grupos[i]->infectado) {
                        struct sPessoa* pessoa = grupos[i]->pessoas;
                        while(pessoa != NULL) {
                            infectados[pessoa->id] = 1;
                            pessoa = pessoa->next;
                        }
                    }
                }
                int primeiro = 1;
                for (int i = 0; i <= p; i++) {
                    if (infectados[i]) {
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