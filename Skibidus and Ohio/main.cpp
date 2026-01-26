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
    cin>>n;

    while (n--) {
        string s;
        cin >> s;
        bool rem = false;
        for (int i=0; i+1 < s.size(); i++) {
            if (s[i] == s[i+1]) {
                rem = true;
                break;
            }
        }
        if (rem)cout<< 1<<"\n";
        else cout<<s.size()<<"\n";
    }
    return 0;
}

