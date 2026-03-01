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
    cin.ignore();
    while(n--){

    string s;
    getline(cin,s);

    for(char c:s){
        if(c == '1')cout<<"l";
        else if( c=='2')cout<<"z";
        else if( c=='4')cout<<"y";
        else cout<<(char)tolower(c);
    }
    cout<<endl;

    }
    return 0;
}

