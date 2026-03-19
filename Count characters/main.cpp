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

    string n;
    cin>>n;
    vector<int> letters('z',0);

    for(char i:n){
        letters[i]++;
    }

    for(int i=0; i<letters.size(); i++){
        if(letters[i]!=0){
            cout<<char(i)<<" "<<letters[i]<<"\n";
        }
    }


    return 0;
}

