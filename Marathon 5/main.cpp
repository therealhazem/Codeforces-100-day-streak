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

    long long n;
    cin>>n;

    vector<long long> ans(100001, 0);
    for(long long i=0; i<n; i++){
        long long x;
        cin>>x;
        ans[x]++;
    }

    for(long long i=1; i<=100000; i++) ans[i] += ans[i-1];

    long long prices;
    cin>>prices;

    while(prices--){
        long long m;
        cin>>m;

        if(m >= 100000) cout<<ans[100000]<<"\n";
        else cout<<ans[m]<<"\n";
    }
}

