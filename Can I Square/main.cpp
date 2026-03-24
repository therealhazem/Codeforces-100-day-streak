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
        long long x;
        cin>>x;
        long long sum=0;
        for(long long i=0; i<x; i++){
            long long z;
            cin>>z;
            sum+=z;
        }
        (sqrt(sum) == (long long)sqrt(sum))?cout<<"YES\n":cout<<"NO\n";
    }
    return 0;
}

