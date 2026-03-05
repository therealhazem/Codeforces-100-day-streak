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
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        if(i%2==1) cout << "I hate";
        else cout<<"I love";

        if(i==n) cout<<" it";
        else cout<<" that ";
    }

    return 0;
}

