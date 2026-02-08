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
    string n;
    cin >> n;

    int luckyCount = 0;

    for (char c : n) {
        if (c=='4' || c=='7') {
            luckyCount++;
        }
    }

    if (luckyCount == 0) {
        cout<<"NO";
        return 0;
    }

    while (luckyCount > 0) {
        int digit = luckyCount % 10;
        if (digit != 4 && digit != 7) {
            cout << "NO";
            return 0;
        }
        luckyCount /= 10;
    }

    cout << "YES";
    return 0;
}
