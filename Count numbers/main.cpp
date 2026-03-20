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

    int n,q;
    cin>>n>>q;

    vector<int> nums (n+1);

    while(q--){
        int x,z;
        cin>>x>>z;
        if(x == 1) nums[z]++;
        else cout<<nums[z]<<endl;
    }
    return 0;
}

