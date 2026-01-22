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
    int n;
    string s;
    cin>>n>>s;

    if (n<26) {
        cout<<"NO";
        return 0;
    }

    for (int i=0; i<26; i++) {
        char upper = 'A'+i;
        char lower = 'a'+i;

        if (s.find(upper) == -1 && s.find(lower) == -1) {
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES";
    return 0;
}
