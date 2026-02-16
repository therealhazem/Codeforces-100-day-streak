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

    string n;
    cin>>n;

    int spell=0;

    while(n.length()>1){
        int sum=0;

        for(char c:n) {
            sum +=c-'0';
        }

        n=to_string(sum);
        spell++;
    }

    cout<<spell;
    return 0;
}

