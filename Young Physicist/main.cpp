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

    int xs=0;
    int ys=0;
    int zs=0;
    while(n--){
        int x,y,z;
        cin>>x>>y>>z;
        xs+=x;
        ys+=y;
        zs+=z;
    }

    if(xs==0 && ys==0 && zs==0)cout<<"YES";
    else cout<<"NO";

    return 0;
}

