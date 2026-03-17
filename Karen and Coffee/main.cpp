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

    int degrees, appr, tests;
    cin>>degrees>>appr>>tests;

    vector<int> freq(200001,0);

    for(int i=0; i<degrees; i++){
        int li, ri;
        cin>>li>>ri;
        freq[li]++;
        freq[ri+1]--;
    }

    for(int i=1; i<=200000; i++){
        freq[i]+=freq[i-1];
    }

    vector<int> ok(200001,0);
    for(int i=1; i<=200000; i++){
        if(freq[i]>=appr) ok[i]=1;
    }

    vector<int> pref(200001,0);
    for(int i=1; i<=200000; i++){
        pref[i]=pref[i-1]+ok[i];
    }

    while(tests--){
        int a,b;
        cin>>a>>b;
        cout<<pref[b]-pref[a-1]<<"\n";
    }

    return 0;
}
