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

    string st1, st2;
    cin>>st1>>st2;
    string S = st1+st1;

    if(S.find(st2) != string::npos) cout<<"Yes";
    else cout<<"No";


    return 0;
}

