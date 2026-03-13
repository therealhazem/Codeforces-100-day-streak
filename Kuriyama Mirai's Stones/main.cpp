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
    vector<long long> nums(n);
    vector<long long> pre1(n);
    vector<long long> pre2(n);

    for(long long i=0; i<n; i++){
        cin>>nums[i];
        if(i==0) pre1[i] = nums[i];
        else pre1[i] = nums[i]+pre1[i-1];
    }

    sort(nums.begin(), nums.end());
    for(long long i=0; i<n; i++){
        if(i==0) pre2[i] = nums[i];
        else pre2[i] = nums[i]+pre2[i-1];
    }

    long long t;
    cin>>t;

    while(t--){
        long long c,l,r;
        cin>>c>>l>>r;
        l--;
        r--;

        if(c==1){
            if(l==0)cout<<pre1[r]<<"\n";
            else cout<<pre1[r]-pre1[l-1]<<"\n";
        }else{
            if(l==0)cout<<pre2[r]<<"\n";
            else cout<<pre2[r]-pre2[l-1]<<"\n";
        }

    }

    return 0;
}

