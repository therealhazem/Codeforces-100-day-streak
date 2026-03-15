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

        deque<int> h;
        deque<int> v;
        for(int i=0; i<x; i++){
            int s;
            cin>>s;
            h.push_back(s);
            v.push_front(s);
        }

        vector<pair<int,int>> diffs(x-1);
        for(int i=0;i<x-1;i++){
            diffs[i].first = h[i] - h[i+1];
            diffs[i].second = v[i] - v[i+1];
        }



        for(int i=0; i<x-1; i++){
            cout<<"("<<diffs[i].first<<" "<<diffs[i].second<<")";
        }
        cout<<"\n";

    }
    return 0;
}

