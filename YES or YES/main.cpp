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
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s=="yes" ? cout<<"YES\n": cout<<"NO\n";
    }

    return 0;
}
