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

    long long n;
    cin>>n;
    if(n >=0){
        cout<<n;
    }else{
        int last = n/10;
        int before = n/10;
        before -= before%10;
        before += n%10;

        last >= before ? cout<<last: cout<<before;
    }
    return 0;
}

