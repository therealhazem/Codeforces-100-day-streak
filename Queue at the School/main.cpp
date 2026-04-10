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

    int n, t;
    cin>>n>>t;
    string s;
    cin>>s;
    char arr[n];
    for(int i=0; i<n; i++){
        arr[i] = s[i];
    }

    while(t--){
        for(int i=0; i<n-1; i++){
            if(arr[i]=='B' && arr[i+1] == 'G'){
                swap(arr[i], arr[i+1]);
                i++;
            }
        }
    }

    for(int i=0; i<n; i++) cout<<arr[i];

    return 0;
}

