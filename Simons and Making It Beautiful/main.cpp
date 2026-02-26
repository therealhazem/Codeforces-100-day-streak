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
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];

        vector<int> ugly;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, p[i]);
            if (mx == i) ugly.push_back(i);
        }

        if (ugly.size() > 1) {
            swap(p[ugly.front()], p[ugly.back()]);
        }

        for (int i = 1; i <= n; i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

