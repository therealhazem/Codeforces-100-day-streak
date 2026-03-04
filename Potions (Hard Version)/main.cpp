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
    long long health=0;
    long long ans=0;
    priority_queue<long long, vector<long long>, greater<long long>> negative;
    while(n--){
        long long x;
        cin>>x;
        if(x>=0){
            ans++;
            health+=x;
        }else{
            negative.push(x);
        }
    }

    while(health>=0){
        health +=negative.top();
        negative.pop();
        ans++;
    }

    cout<<ans;
    if(health>=0)cout<<ans;
    else cout<<ans+1;

    return 0;
}

