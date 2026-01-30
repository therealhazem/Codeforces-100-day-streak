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
    while(n--){
        int num;
        cin>>num;
        priority_queue<int, vector<int>, greater<int>> odd;
        priority_queue<int, vector<int>, greater<int>> even;
        while(num--){
            int x;
            cin>>x;
            if(x%2==0){
                even.push(x);
            }else{
                odd.push(x);
            }
        }
        if(odd.size()==0 || even.size()==0 || ((!odd.empty() && !even.empty()) && (odd.top() < even.top()))){
                cout<<"YES\n";
        }else{
                cout<<"NO\n";
        }
    }

    return 0;
}

