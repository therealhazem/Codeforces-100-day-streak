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
        int x;
        cin>>x;

        vector<int> a(x);
        for (int i=0; i<x; i++) cin>>a[i];

        int ans=0;
        int mx=0;

        for(int i=0; i<x; i++) {
            mx = max(mx, a[i]);
            if(a[i]==mx) ans++;
        }
        cout<<ans<<"\n";
    }

    return 0;
}
