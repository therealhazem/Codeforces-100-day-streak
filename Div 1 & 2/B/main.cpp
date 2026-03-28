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
        int x,y;
        cin>>x>>y;

        long long d=abs(x-y);
        long long ans=0;

        if(d==0){
            ans=1;
        }else{
            for(long long i=1; i*i<=d; i++){
                if(d%i == 0){
                    ans++;
                    if(i*i != d)ans++;
                }
            }
        }

        cout<<ans<<"\n";

        if(x >= y){
            for(int i=0; i<x; i++) cout<<1<<" ";
            for(int i=0; i<y; i++) cout<<-1<<" ";
        }else{
            for(int i=0; i<y; i++) cout<<-1<<" ";
            for(int i=0; i<x; i++) cout<<1<<" ";
        }

        cout<<"\n";
    }

    return 0;
}
