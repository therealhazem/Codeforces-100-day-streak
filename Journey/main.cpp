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
        long long kilos,a,b,c;
        cin>>kilos>>a>>b>>c;
        long long days=0;

        if( (a+b+c) <= kilos){
            long long cycle = kilos/(a+b+c);
            days += cycle*3;
            kilos -= (a+b+c)*cycle;
        }

        while(kilos>0){
            kilos -=a;
            days++;
            if(kilos<=0) break;
            kilos -=b;
            days++;
            if(kilos<=0) break;
            kilos -=c;
            days++;
            if(kilos<=0) break;
        }
        cout<<days<<"\n";
    }
    return 0;
}

