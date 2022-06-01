#include <bits/stdc++.h>

using namespace std;

class Person {
    public:
        int id;
        Person *next = nullptr;
        Person(int i) {
            id = i;
        }
};

class Group {
    public:
        bool infected = false;
        Person* people;
        Person* tail;
        Group(Person* person) {
            people = person;
            tail = person;
        }
};

int main(){

    int p, e;

    cin >> p >> e;
    int ni = 0;
    int ns = p;
    int n = p;

    Group* groups[p+1];

    for (int i = 1; i <= p; i++) {
        Person *person = new Person(i);
        Group *group = new Group(person);

        groups[i] = group;
    }

    while (e--) {
        string s;

        cin >> s;

        if (s == "c") {
            int a, b;
            cin >> a >> b;
            if (groups[a] != groups[b]) {
                n--;
                if (groups[a]->infected && !groups[b]->infected) {
                    ns--;
                } else if (!groups[a]->infected && groups[b]->infected) {
                    ns--;
                    ni++;
                } else if (groups[a]->infected && groups[b]->infected) {
                    ni--;
                } else {
                    ns--;
                }

                groups[a]->tail->next = groups[b]->people;
                groups[a]->tail = groups[b]->tail;
                groups[b] = groups[a];
            }
        } else if (s == "p") {
            int a;
            cin >> a;

            if (!groups[a]->infected) {
                groups[a]->infected = true;
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
                    if (groups[i]->infected) {
                        Person* person = groups[i]->people;
                        while(person != nullptr) {
                            infectados[person->id] = 1;
                            person = person->next;
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