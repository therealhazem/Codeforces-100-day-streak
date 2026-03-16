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

    long long t;
    cin>>t;
    while(t--){
        long long a, b, c, m;
        cin>>a>>b>>c>>m;
        long long aL=0;
        long long bL=0;
        long long cL=0;
        long long liters = 6;
        for(long long i=1; i<=m && liters!=0; i++){
            if(i%a==0){
                aL+=2;
                liters --;
            }
            if(i%b==0){
                bL+=2;
                liters --;
            }
            if(i%c==0){
                cL+=2;
                liters --;
            }
            if(liters>0) i--;
            else liters = 6;
        }
        cout<<aL/2<<" "<<bL/2<<" "<<cL/2<<"\n";

    }
    return 0;

}
