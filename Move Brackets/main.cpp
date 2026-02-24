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
        int num;
        string brackets;
        cin>>num>>brackets;

        stack<char> open;

        for(char c:brackets){
            if(c == '(') open.push(c);
            else if (c == ')' && !open.empty()) open.pop();
        }

        cout<<open.size()<<"\n";


    }

    return 0;
}

