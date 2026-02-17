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

    vector<int> cnt(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (cnt[i] == 0) {
            for (int j = i; j <= n; j += i) {
                cnt[j]++;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 2) {
            result++;
        }
    }

    cout << result << "\n";
    return 0;
}

