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

    string top,low;
    getline(cin, top);
    getline(cin, low);

    unordered_map<char, int> topL;
    unordered_map<char, int> lowL;

    for(char c:top) if(c != ' ') topL[c]++;
    for(char c:low) if(c != ' ') lowL[c]++;

    bool can = true;

    for(auto ele:lowL){
        char c = ele.first;
        int len = ele.second;
        if(topL[c]<len) can = false;
    }
    can?cout<<"YES":cout<<"NO";

    return 0;
}

