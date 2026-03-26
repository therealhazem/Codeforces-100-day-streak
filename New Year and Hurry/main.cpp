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

    int n, mins;
    cin>>n>>mins;

    int mytime = (60*4)-mins;

    int i=1;
    while(mytime>0){
        if(i>n) break;

        int neww = 5*i;
        if(mytime-neww >=0){
            mytime -=neww;
            i++;
        }
        else break;
    }

    cout<<i-1;

    return 0;
}

