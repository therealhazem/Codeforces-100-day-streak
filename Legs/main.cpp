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
        int t;
        cin>>t;
        int num = 0;
        num += t/4;
        t -= (num*4);
        num += t/2;
        cout<<num<<"\n";
    }

    return 0;
}

