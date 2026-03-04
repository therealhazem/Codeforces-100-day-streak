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

    int arr[4];
    int sum = 0;

    for(int i=0; i<4; i++){
        int x;
        cin>>x;
        arr[i]= x;
        sum+=x;
    }

    if(sum%2!=0){
        cout<<"NO";
        return 0;
    }


    int target = sum/2;

    for(int i=0; i<4; i++){
        if(arr[i] == target){
            cout<<"YES";
            return 0;
        }
    }

    for(int i=0; i<4; i++){
        for(int j=i+1; j<4; j++){
            if(arr[i]+arr[j] == target){
                cout<<"YES";
                return 0;
            }
        }
    }

    cout<<"NO";
    return 0;
}

