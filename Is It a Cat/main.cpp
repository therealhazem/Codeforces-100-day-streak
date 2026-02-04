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
        string cat = "MEOW";
        int counter=3;
        int letters;
        string user;
        cin>>letters>>user;

        for(int i=letters-1; i>=0; i--){
            if(user[i]==cat[counter] || user[i]==(cat[counter]+32)){
                while(user[i]==cat[counter] || user[i]==(cat[counter]+32)) i--;
                counter--;
                i++;
            }else{
                counter=5;
                break;
            }
        }

        if(counter<=-1){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}

