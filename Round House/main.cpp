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

    int n,a,b;
    cin>>n>>a>>b;

    if(n+b==0){cout<<a; return 0;}
    int pos=a+b;
    while(b<0 && pos<0){pos+=n;}

    if(pos==0)cout<<n;
    else{
        pos%=n;
        if(pos==0)cout<<n;
        else cout<<pos;
    }

    return 0;
}

