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
        int x;
        cin>>x;
        deque<int>  ans;

        for(int i=0; i<x; i++){
            int num;
            cin >> num;
            if(ans.empty()) ans.push_front(num);
            else if(num >= ans.back()) ans.push_back(num);
            else if(num <= ans.front()) ans.push_front(num);
            else ans.push_back(num);
        }
        for(int c:ans) cout<<c<<" ";
        cout<<"\n";
    }

    return 0;
}

