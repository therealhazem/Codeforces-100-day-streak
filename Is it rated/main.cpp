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

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    bool changed = false;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] != b[i]) {
            changed = true;
        }
    }

    if (changed) {
        cout << "rated\n";
        return 0;
    }

    for (int i = 0; i + 1 < n; i++) {
        if (a[i] < a[i + 1]) {
            cout << "unrated\n";
            return 0;
        }
    }

    cout << "maybe\n";
    return 0;
}

