#include <bits/stdc++.h>

using namespace std;

int main() {

    string s, c;

    cin >> s;
    cin >> c;

    int index = 0;
    int multiplier = 1;
    int sum[s.size()];

    for (int i = 0; i < c.size(); i++) {
        if (c[i] == '+') {
            multiplier = 1;
        } else if (c[i] == '-') {
            multiplier = -1;
        } else {
            int s = (c[i] - '0') * multiplier;
            sum[index++] = s;
        }
    }

    index = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'w') {
            s[i] = ' ';
        } else {
            if (s[i] + sum[index] > 'z') {
                s[i] = s[i] + sum[index] - 'z' + 'a' - 1;
            } else if (s[i] + sum[index] < 'a') {
                s[i] = s[i] + sum[index] - 'a' + 'z' + 1;
            } else {
                s[i] = s[i] + sum[index];
            }
            index++;
        }
    }

    cout << s << endl;

    return 0;
}