#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    for (int i = 0; i <= n / 2; i++) {
        int j = n - 1 - i;

        if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
            cout << -1;
            return 0;
        }

        if (s[i] == '?' && s[j] == '?') {
            s[i] = s[j] = 'a';
        } else if (s[i] == '?') {
            s[i] = s[j];
        } else if (s[j] == '?') {
            s[j] = s[i];
        }
    }

    cout << s;
    return 0;
}
