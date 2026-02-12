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
    int sum=0;
    int nn=n;

    while(true){

        while(n>0){
            sum += n%10;
            n/=10;
        }

        if(sum%4==0){
            cout<<nn;
            return 0;
        }

        nn++;
        n=nn;
        sum=0;
    }

    return 0;
}

