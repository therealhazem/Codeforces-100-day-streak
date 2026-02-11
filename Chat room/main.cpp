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

    string s;
    cin>>s;

    string target="hello";
    int j=0;

    for (char c : s) {
        if (c == target[j]) {
            j++;
        }
        if (j == target.size()) {
            break;
        }
    }

    if (j == target.size()) cout << "YES";
    else cout << "NO";

    return 0;

}

