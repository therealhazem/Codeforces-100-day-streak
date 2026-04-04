#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int x, y;
        cin>>x>>y;

        int n = x + y;

        if(y < x){
            cout<<"NO\n";
            continue;
        }

        if(x == 0){
            if(y % 2 == 0){
                cout<<"NO\n";
                continue;
            }

            cout<<"YES\n";
            for(int i=2; i<=n; i++){
                cout<<1<<" "<<i<<"\n";
            }
            continue;
        }

        cout<<"YES\n";

        vector<pair<int,int>> ans;

        int s = y - x + 1;

        int cur = 2;

        int center = cur;
        cur++;
        ans.push_back({1, center});

        for(int i=0; i<s-1; i++){
            ans.push_back({center, cur});
            cur++;
        }

        for(int i=0; i<x-1; i++){
            int u = cur;
            int v = cur + 1;
            cur += 2;

            ans.push_back({1, u});
            ans.push_back({u, v});
        }

        for(auto e : ans){
            cout<<e.first<<" "<<e.second<<"\n";
        }
    }

    return 0;
}
