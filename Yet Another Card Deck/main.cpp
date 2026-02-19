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

    int n,q;
    cin>>n>>q;

    deque<int> colors;
    int queries[q];
    int res[q];

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        colors.push_back(x);
    }

    for(int i=0; i<q; i++) cin>>queries[i];

    for(int i=0; i<q; i++){
        auto found = find(colors.begin(), colors.end(), queries[i]);
            int val = queries[i];
            res[i] = distance(colors.begin(), found)+1;
            colors.erase(found);
            colors.push_front(val);
    }


    for(auto x:res){
        cout<<x<<"\n";
    }


    return 0;
}

