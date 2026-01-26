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
        int nums;
        cin>>nums;
        int arr[nums];
        int ops=0;
        int lastbig;
        for(int i=0; i<nums; i++){
            int x;
            cin>>x;
            if(i==0){lastbig=x;}
            else if(x<lastbig){
                ops++;
            }else{
                lastbig = x;
            }
        }

        cout<<ops<<"\n";
        }




    return 0;
}

