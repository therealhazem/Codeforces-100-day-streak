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

    queue<long long> ans;

    while(n--){
        int c;
        cin>>c;

        if(c == 1){
            long long value;
            cin>>value;
            ans.push(value);
        }
        else if (c == 2) {
            if (!ans.empty()) ans.pop();
        }
        else if (c == 3) {
            if (!ans.empty()) cout<<ans.front()<<"\n";
            else cout << "Empty!\n";
        }
    }

    return 0;
}
