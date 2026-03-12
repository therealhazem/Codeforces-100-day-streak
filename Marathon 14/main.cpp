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
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> p(n);
        vector<int> a(n);

        for(int i=0; i<n; i++) cin>>p[i];
        for(int i=0; i<n; i++) cin>>a[i];

        vector<int> pos(n+1);
        for(int i=0; i<n; i++) pos[p[i]] = i;

        bool ok = true;

        vector<int> seq;
        seq.push_back(a[0]);
        for(int i=1; i<n; i++){
            if(a[i] != a[i-1]) seq.push_back(a[i]);
        }

        for(int i=1; i<seq.size(); i++){
            if(pos[seq[i]] < pos[seq[i-1]]){
                ok = false;
                break;
            }
        }
        cout<<(ok ? "YES":"NO")<<"\n";
    }

    return 0;
}
