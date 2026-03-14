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

    int n,need;
    int sum=0;
    int mine=0;
    int mini=0;
    priority_queue<int> coins;
    cin>>n;

    while(n--){
        int x;
        cin>>x;
        sum+=x;
        coins.push(x);
    }

    need = sum/2;
    while(mine<=need){
        mine+=coins.top();
        mini++;
        coins.pop();
    }

    cout<<mini;

    return 0;
}

