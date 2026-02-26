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

    int N;
    string S;
    cin >> N >> S;

    deque<int> dq;
    dq.push_back(0);

    for (int i = N - 1; i >= 0; i--) {
        if (S[i] == 'L') {
            dq.push_back(i + 1);
        } else {
            dq.push_front(i + 1);
        }
    }

    for (int x : dq) {
        cout << x << " ";
    }
    return 0;
}

