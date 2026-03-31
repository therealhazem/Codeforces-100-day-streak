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

        if (n % 4 != 0) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        vector<int> even, odd;

        int sum_even = 0, sum_odd = 0;

        for (int i = 1; i <= n / 2; i++) {
            even.push_back(2 * i);
            sum_even += 2 * i;
        }

        for (int i = 1; i < n / 2; i++) {
            odd.push_back(2 * i - 1);
            sum_odd += 2 * i - 1;
        }

        odd.push_back(sum_even - sum_odd);

        for (int x : even) cout << x << " ";
        for (int x : odd) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
