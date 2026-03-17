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

    long long t;
    cin>>t;

while(t--){
        long long n;
        cin>>n;
        string s;
        cin>>s;

        long long ans1=0;
        for (char c:s) if (c=='1') ans1++;
        long long zeros = n-ans1;

        if(zeros==n){
            ans1 = (zeros+2)/3;
            cout<<ans1<<"\n";
            continue;
        }

        long long cycle=0;
        long long zeroslist=0;

        for(int i=0; i<n; i++){
            if(s[i]=='0')zeroslist++;
            else break;
        }

        for(int i=zeroslist; i<n; i++){
            if(s[i]=='0')cycle++;
            else{
                if(cycle>0) ans1+=cycle/3;
                cycle = 0;
            }
        }

        ans1+=(zeroslist+1)/3;
        ans1+=(cycle+1)/3;
        cout<<ans1<<"\n";
    }

    return 0;
}
