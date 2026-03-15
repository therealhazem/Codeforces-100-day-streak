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

    int n, op, qu;
    cin>>n>>op>>qu;

    vector<int> arr(n);
    for(int i=0; i<n; i++)cin>>arr[i];

    vector<int>li(op);
    vector<int>ri(op);
    vector<int>di(op);
    for(int i=0; i<op; i++) cin>>li[i]>>ri[i]>>di[i];

    vector<int> xi(qu), yi(qu);
    for(int i=0; i<qu; i++) cin>>xi[i]>>yi[i];



    return 0;
}

