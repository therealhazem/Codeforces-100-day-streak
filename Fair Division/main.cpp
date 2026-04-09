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
        int sum =0;
        int ones =0;
        int twos =0;

        int x;
        cin>>x;
        for(int i=0; i<x; i++){
            int z;
            cin>>z;
            sum+=z;
            if(z==1)ones++;
            else twos++;
        }

        if(sum%2 != 0) cout<<"NO\n";
        else{
            if(ones==0 && twos%2 == 1) cout<<"NO\n";
            else cout<<"YES\n";
        }
    }

    return 0;
}

