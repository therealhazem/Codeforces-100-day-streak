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

    long long t;
    cin>>t;

    vector<long long> ans(t, 1);
    long long last=0;

    for(long long i=0; i<t; i++){
        long long x;
        cin>>x;
        if(x>last){
            (i>0) ? ans[i] += ans[i-1]: ans[i]=1;
        }
        last = x;
    }

    long long value = *max_element(ans.begin(), ans.end());
    cout<<value;

    return 0;
}

