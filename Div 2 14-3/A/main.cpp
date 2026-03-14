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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int m=n*n;

        unordered_map<int, int> nums;

        while(m--){
            int x;
            cin >> x;
            nums[x]++;
        }
        bool ok=true;
        for(auto it : nums){
            if(it.second > n*(n-1)){
                ok = false;
                break;
            }
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
