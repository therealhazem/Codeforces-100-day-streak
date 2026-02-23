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

        string brackets;
        cin>>brackets;

        if(brackets.size()%2 == 1 || brackets[0]==')' || brackets.back() == '('){
            cout<<"NO\n";
        }else{

            long long open = 0;
            long long quesion = 0;
            long long closed = 0;

            for(char c:brackets){
                if(c == '('){
                    if(closed >= 1) closed--;
                    else open++;
                }else if(c== ')'){
                    if(open >= 1) open--;
                    else closed++;
                }else quesion ++;
            }
            if((open+closed) <= quesion){
                quesion -= (open+closed);
                if(quesion%2 == 0){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
            }else{
                cout<<"NO\n";
            }
        }
    }


    return 0;
}

