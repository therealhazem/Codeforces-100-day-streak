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
        long long sum = (x*(x+1))/2;
        cout<<sum/x<<endl;
    }
    return 0;
}

