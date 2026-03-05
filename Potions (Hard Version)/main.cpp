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

    int n;
    cin>>n;

    long long health = 0;
    priority_queue<long long, vector<long long>, greater<long long>> po;

    for(int i=0; i<n; i++){
        long long x;
        cin>>x;

        health += x;
        po.push(x);

        if(health < 0) {
            health -= po.top();
            po.pop();
        }
    }

    cout<<po.size();
}

