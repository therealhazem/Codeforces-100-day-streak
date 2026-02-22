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

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long mn = *min_element(a.begin(), a.end());
        long long eaten = 0;

        for (int i = 0; i < n; i++) {
            eaten += (a[i] - mn);
        }

        cout << eaten << '\n';
    }

    return 0;
}

