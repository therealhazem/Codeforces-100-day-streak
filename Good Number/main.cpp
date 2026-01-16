#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int ans = 0;

    while (n--) {
        string s;
        cin >> s;

        bool seen[10] = {false};

        for (char c : s) {
            seen[c - '0'] = true;
        }

        bool good = true;
        for (int i = 0; i <= k; i++) {
            if (!seen[i]) {
                good = false;
                break;
            }
        }

        if (good) ans++;
    }

    cout << ans;
}
