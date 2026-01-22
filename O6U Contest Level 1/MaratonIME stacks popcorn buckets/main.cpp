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

long long summition(long long x){
    if (x==0) return 0;
    return (x + summition(x-1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin>>n;

    long long sum = n*(n+1)/2;
    cout<<sum-n + 1<<"\n";

    return 0;
}
