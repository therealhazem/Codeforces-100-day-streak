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
    cin >> n;

    stack<int> nums;
    stack<int> maxx;

    while(n--){

        int op;
        cin>>op;

        if(op == 1){
            int x;
            cin>>x;
            nums.push(x);
            if(maxx.empty() || x >= maxx.top()) maxx.push(x);
        }
        else if(op == 2){
            if(nums.top() == maxx.top()) maxx.pop();
            nums.pop();
        }
        else{
            cout<<maxx.top()<<"\n";
        }

    }

    return 0;
}

