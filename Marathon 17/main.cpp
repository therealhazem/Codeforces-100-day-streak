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

    long long books;
    long long n;
    cin>>books>>n;

    vector<long long> booktime;
    for(long long i=0; i<books; i++){
        long long x;
        cin>>x;
        booktime.push_back(x);
    }

    long long ans=0;

    long long sum=0;
    long long l=0;

    for(long long i=0; i<books; i++){
        sum+=booktime[i];
        while(sum>n){
            sum -= booktime[l];
            l +=1;
        }
        ans = max(ans, i-l+1);
    }
    cout<<ans;

    return 0;
}
