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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    int c = 0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i) c++;
    }

    cout<<c;

    return 0;
}

