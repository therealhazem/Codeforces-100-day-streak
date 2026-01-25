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
        int water;
        cin>>water;
        int cm=1;
        int days[water];
        for(int i=0; i<water; i++) cin>>days[i];

        for(int i=0; i<water; i++){
            if(i>0 && days[i]==0 && days[i-1]==0){
                cm=-1;
                break;
            }
            if(days[i]==1){
                cm+=1;
                if(days[i-1]==1 && i>0)cm+=4;
            }
        }
        cout<<cm<<"\n";

    }

    return 0;
}

