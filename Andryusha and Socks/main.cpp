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
    int socks = n*2;
    int ans=0;
    set<int> pairs;

    while(socks--){
        int x;
        cin>>x;
        if(pairs.empty()){
            pairs.insert(x);
            int p = pairs.size();
            ans = max(p, ans);
        }else{
            auto i = pairs.find(x);
            if(i != pairs.end()){
                pairs.erase(x);
                int p = pairs.size();
                ans = max(p, ans);
            }else{
                pairs.insert(x);
                int p = pairs.size();
                ans = max(p, ans);
            }
        }
    }
    cout<<ans;

    return 0;
}

