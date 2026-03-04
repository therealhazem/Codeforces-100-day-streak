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

    stack<string> names;
    unordered_map<string, int> nlist;

    while(n--){
        string name;
        cin>>name;
        nlist[name]++;
        names.push(name);
    }

    while(!names.empty()){
        if(nlist[names.top()] > 0){
            cout<<names.top()<<"\n";
            nlist[names.top()] = 0;
        }
        names.pop();
    }
    return 0;
}

