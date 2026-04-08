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

    long long t;
    cin>>t;

    while(t--){
        long long a, b, c;
        cin>>a>>b>>c;

        if(c%2==0){
            a += c/2;
            b += c/2;
        }
        else{
            a++;
            c--;
            a += c/2;
            b += c/2;
        }

        if(a>b) cout<<"First\n";
        else cout<<"Second\n";

    }
    return 0;
}
