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

    string s;
    cin>>s;

    priority_queue<char, vector<char>, greater<char>> corrected;

    for(char c:s) if(c!='+')corrected.push(c);

    int cou = corrected.size();
    for(int i=0; i<cou; i++){
        cout<<corrected.top();
        corrected.pop();
        if(!corrected.empty())cout<<"+";
    }


    return 0;
}

