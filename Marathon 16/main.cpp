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

    vector<long long> worm(n);
    long long total = 0;

    for(long long i=0; i<n; i++){
        cin>>worm[i];
        total += worm[i];
    }

    vector<long long> place(total+1);

    long long now=1;
    for(long long i=0; i<n; i++){
        for(long long j=0; j<worm[i]; j++){
            place[now] = i+1;
            now++;
        }
    }

    long long x;
    cin>>x;

    while(x--){
        long long q;
        cin>>q;
        cout<<place[q]<<"\n";
    }

    return 0;
}
