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

    while(n--){
        string s;
        cin>>s;
        string ans= s.substr(0, (s.size()-2));
        cout<<ans<<"i\n";
    }

    return 0;
}

