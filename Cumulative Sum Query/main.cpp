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

    int n;
    cin>>n;
    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
        if(i>0) a[i] += a[i-1];
    }

    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;
        if(l==0)cout<<a[r]<<"\n";
        else cout<<a[r]-a[l-1]<<"\n";
    }

    return 0;
}

