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
        int x;
        cin>>x;
        int arr[x];
        int index = 0;
        for(int i=0; i<x; i++){
            int v;
            cin>>v;
            arr[i] = v;
        }

        if(arr[0] != arr[1] && arr[0] != arr[2]) index = 1;
        else if(arr[1] != arr[0] && arr[1] != arr[2]) index = 2;
        else{
            for(int i=2; i<x; i++){
                if(arr[i] != arr[0]){
                    index = i + 1;
                    break;
                }
            }
        }

        cout<<index<<"\n";
    }

    return 0;
}

