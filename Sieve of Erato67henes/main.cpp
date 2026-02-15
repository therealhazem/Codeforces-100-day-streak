#include <string>
#include <utility>
#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        bool found67 = false;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 67) {
                found67 = true;
            }
        }

        cout << (found67 ? "YES\n" : "NO\n");
    }

    return 0;
}

