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

    long long n;
    cin>>n;

    while(n--){
        long long s;
        cin>>s;
        vector<long long> arr(s);
        for(int i=0;i<s; i++){
            cin>>arr[i];
        }
        if(s != arr[0]){
            cout<<"NO\n";
        }else{
            vector<long long> longg(s+1);
            longg[0] = s;

            for(long long i=0; i<s; i++) longg[arr[i]]--;
            for(long long i=1; i<s; i++) longg[i] = longg[i]+longg[i-1];

            bool ok = true;
            for(int i=0; i<s; i++){
                if(longg[i] != arr[i]){
                    ok=false;
                    break;
                }
            }
            (ok)?cout<<"YES\n":cout<<"NO\n";
        }
    }
    return 0;
}
