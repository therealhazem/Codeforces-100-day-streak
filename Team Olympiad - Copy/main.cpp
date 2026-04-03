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

    stack<int> P,M,E;

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;

        if(x==1)P.push(i);
        else if(x==2)M.push(i);
        else E.push(i);
    }

    int ans = min(min(P.size(),M.size()), E.size());

    cout<<ans<<endl;

    while(ans--){
        cout<<P.top()<<" "<<M.top()<<" "<<E.top()<<" "<<endl;
        P.pop();
        M.pop();
        E.pop();
    }

    return 0;
}

