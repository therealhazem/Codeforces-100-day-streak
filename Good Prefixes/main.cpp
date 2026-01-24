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
        long long nums;
        long long sum=0;
        long long good=0;
        cin>>nums;
        priority_queue<long long> numQ;
        numQ.push(0);
        while(nums--){
            long long x;
            cin>>x;
            numQ.push(x);
            sum+=x;
            if(sum-numQ.top() == numQ.top())good++;
        }
        cout<<good<<"\n";
    }


    return 0;
}

