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

    string brackets;
    cin>>brackets;

    long long open = 0;
    long long ans = 0;

    for(char c:brackets){
        if(c == '('){
            open++;
        }else if(open>0){
            open--;
            ans+=2;
        }
    }

    cout<<ans;

    return 0;
}

