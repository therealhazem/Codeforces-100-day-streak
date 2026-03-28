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
        int n, k;
        cin>>n>>k;

        vector<int> a(n+1), b(n+1), pos(n+1);
        for(int i=1; i<=n; i++){
            cin>>a[i];
            pos[a[i]] = i;
        }

        for(int i=1; i<=n; i++) cin>>b[i];

        vector<int> L(n+1), R(n+1);
        for(int i=1; i<=n; i++){
            L[i] = max(1, i-k+1);
            R[i] = min(i, n-k+1);
        }
        vector<int> used(n+1, 0);
        bool ok = true;

        for(int i=1; i<=n; i++){
            if(b[i] == -1) continue;
            if(used[b[i]]){
                ok = false;
                break;
            }
            used[b[i]] = 1;
            int p = pos[b[i]];
            if(L[i] != L[p] || R[i] != R[p]){
                ok = false;
                break;
            }
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
