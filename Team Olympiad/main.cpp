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
    stack<int> prog, math, PE;

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        if(x==1)prog.push(i);
        else if(x==2)math.push(i);
        else PE.push(i);
    }

    int ans = min(min(prog.size(), math.size()), PE.size());
    cout<<ans<<endl;
    while(ans--){
        cout<<prog.top()<<" "<<math.top()<<" "<<PE.top()<<endl;
        prog.pop();
        math.pop();
        PE.pop();
    }

    return 0;
}

