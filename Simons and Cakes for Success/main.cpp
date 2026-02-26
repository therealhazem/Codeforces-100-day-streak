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
    cin >>t;

    while (t--) {
        long long n;
        cin>>n;

        long long temp = n;
        long long k=1;

        for (long long p = 2; p * p <= temp; p++) {
            if (temp % p == 0) {
                int cnt = 0;
                while (temp % p == 0) {
                    temp /= p;
                    cnt++;
                }
                int need = (cnt+n-1)/n;
                while (need--) k *= p;
            }
        }

        if (temp > 1) {
            k *= temp;
        }

        cout << k << "\n";
    }

    return 0;
}

