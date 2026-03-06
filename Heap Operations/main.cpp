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
    priority_queue<int, vector<int>, greater<int>> heap;
    int op=0;
    cin>>n;

    vector<string> ans;

    while(n--){
        string s;
        int n;
        cin>>s;

        if(s=="removeMin"){
            if(heap.empty()){
                heap.push(0);
                ans.push_back("insert 0");
            }
            heap.pop();
            ans.push_back("removeMin");

        }else if(s=="insert"){
            cin>>n;
            heap.push(n);
            ans.push_back("insert "+to_string(n));

        }else if(s=="getMin"){
            cin>>n;

            while(!heap.empty() && heap.top()<n){
                heap.pop();
                ans.push_back("removeMin");
            }

            if(heap.empty() || heap.top()>n){
                heap.push(n);
                ans.push_back("insert " + to_string(n));
            }
            ans.push_back("getMin " + to_string(n));
        }
    }

    cout<<ans.size()<<"\n";
    for(string x : ans) cout<<x<<"\n";
    return 0;
}

