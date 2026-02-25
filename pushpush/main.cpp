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

    deque<int> ans;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(i%2==0){
            ans.push_front(x);
        }else{
            ans.push_back(x);
        }
    }

    if(n%2==0)reverse(ans.begin(), ans.end());

    for(int c:ans)cout<<c<<" ";

    return 0;
}

