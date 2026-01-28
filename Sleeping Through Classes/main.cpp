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
        int classes,must;
        int slept=0;
        string clas;
        cin>>classes>>must;
        cin>>clas;
        int awake=-1;
        for(int i=0; i<classes; i++){
            if(clas[i]=='1'){
                awake = max(awake, i + must);
            }else if(i > awake){
                slept++;
            }
        }
        cout<<slept<<"\n";
    }

    return 0;
}
