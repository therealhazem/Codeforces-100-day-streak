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
        long long x;
        cin>>x;
        long long root=sqrt(x);

        bool prime=true;
        if(root<2) prime=false;
        else{
            for(long long i=2; i*i<=root; i++){
                if(root%i == 0){
                    prime = false;
                    break;
                }
            }
        }
        if(root*root==x && prime) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}

