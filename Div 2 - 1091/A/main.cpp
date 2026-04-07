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

    int n;
    cin>>n;

    while(n--){
        int x,k;
        cin>>x>>k;

        int sum = 0;
        int sum2 = x*k;

        for(int i=0; i<x; i++){
            int z;
            cin>>z;
            sum += z;
        }

        if(sum%2==1 || sum2%2==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}
