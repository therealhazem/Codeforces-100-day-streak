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

    unordered_map<string, int> names;

    while(n--){
        string name;
        cin>>name;

        if(names[name] == 0) cout<<"OK\n";
        else cout<<name<<names[name]<<"\n";
        names[name]++;
    }

    return 0;
}

