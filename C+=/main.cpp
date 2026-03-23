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
        long long a,b,sum;
        cin>>a>>b>>sum;
        long long steps = 0;

        while(a<=sum && b<=sum){
            if(a>=b){
                b+=a;
                steps++;
            }else{
                a+=b;
                steps++;
            }
        }
        cout<<steps<<endl;
    }

    return 0;
}

