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
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    string s;
    cin>>s;

    deque<char> letters;
    bool rev = false;

    for(char c:s){
        if(c=='R') rev = !rev;
        else{
            if(!rev) letters.push_back(c);
            else letters.push_front(c);
        }
    }
    if(rev) reverse(letters.begin(), letters.end());
    for(char c:letters)cout<<c;

    return 0;
}

