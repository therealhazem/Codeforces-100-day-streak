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

    while(n--){
        long long cok, mini, larg;
        cin>>cok>>mini>>larg;
        long long avil= cok-mini;

        if(avil >= larg){
            cout<<larg<<"\n";
        }else{
            cout<<avil<<"\n";
        }
    }

    return 0;
}
