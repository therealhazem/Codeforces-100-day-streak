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
    int space=0;

    while(n--){
        for(int i=0; i<space; i++)cout<<" ";
        for(int i=0; i<=(n*2); i++){
            cout<<"*";
        }
        space++;
        cout<<endl;
    }


    return 0;
}

