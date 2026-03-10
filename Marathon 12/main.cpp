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

    long long n;
    cin>>n;
    deque<long long> nums;
    while(n--){
        long long x;
        cin>>x;
        nums.push_front(x);
    }

    for(long long i:nums) cout<<i<<" ";

    return 0;
}

