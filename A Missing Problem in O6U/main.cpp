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

    while(n--){
        int x;
        cin>>x;
        int miss = x;
        for(int i=1; i<x; i++){
            int z;
            cin>>z;
            if(z!=i && miss == x){
               miss = i;
            }
        }
        cout<<miss<<"\n";
    }

    return 0;
}

