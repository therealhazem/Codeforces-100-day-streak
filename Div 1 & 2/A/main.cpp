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

        vector<int> p(n);
        for(int i=0; i<n; i++) cin>>p[i];

        if(n==1){
            cout<<1<<"\n";
        }else{
            for(int i=0; i<n; i++){
                cout<<2;
                if(i+1<n) cout<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
