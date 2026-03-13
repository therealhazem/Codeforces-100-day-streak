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
    int n;
    cin>>s>>n;
    int l=s.size();

    vector<int> prefix(l,0);
    for(int i=1; i<l; i++){
        prefix[i] = prefix[i-1];
        if(s[i] == s[i-1]) prefix[i]++;
    }

    while(n--){
        int l,r;
        cin>>l>>r;
        cout<<prefix[r-1]-prefix[l-1]<<"\n";
    }

    return 0;
}

