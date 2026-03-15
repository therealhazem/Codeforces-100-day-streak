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

    int n,m;
    cin>>n>>m;

    vector<int> dist(n,0);
    vector<int> nums(n);

    for(int i=0; i<n; i++) cin>>nums[i];

    set<int> diff;

    for(int i=n-1;i>=0;i--){
        diff.insert(nums[i]);
        dist[i] = diff.size();
    }

    while(m--){
        int x;
        cin>>x;
        cout<<dist[x-1]<<"\n";
    }

    return 0;
}

