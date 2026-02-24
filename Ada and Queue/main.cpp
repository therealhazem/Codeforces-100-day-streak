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
    bool reversed = false;
    cin>>n;

    deque<int> ada;

    while(n--){
        string command;
        cin>>command;

        if(command == "back" && !ada.empty()){
            if(!reversed){
                cout<<ada.back()<<"\n";
                ada.pop_back();
            }else{
                cout<<ada.front()<<"\n";
                ada.pop_front();
            }

        }else if(command == "front" && !ada.empty()){
            if(!reversed){
                cout<<ada.front()<<"\n";
                ada.pop_front();
            }else{
                cout<<ada.back()<<"\n";
                ada.pop_back();
            }

        }else if(command == "reverse") reversed = !reversed;

        else if(command == "push_back"){
            int x;
            cin>>x;
            if(!reversed)ada.push_back(x);
            else ada.push_front(x);

        }else if(command == "toFront"){
            int x;
            cin>>x;
            if(!reversed)ada.push_front(x);
            else ada.push_back(x);
        }else cout<<"No job for Ada?\n";

    }

    return 0;
}

