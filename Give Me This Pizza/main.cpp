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
    int arr[n];
    int ans[n];

    for(int i=0; i<n; i++) ans[i]=-1;
    for(int i=0; i<n; i++) cin>>arr[i];

    stack<int> nobig;

    for(int i=0; i<n; i++){
        while(!nobig.empty() && arr[i] > arr[nobig.top()]){
            ans[nobig.top()] = arr[i];
            nobig.pop();
        }
        nobig.push(i);
    }


    for(int n:ans) cout<<n<<" ";

    return 0;
}

