#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int strength;
int dragons;

priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> dragon;

int main(){
    cin>>strength>>dragons;
    for(int i=0; i<dragons; i++){
        int heal,bonus;
        cin>>heal>>bonus;
        dragon.push({heal,bonus});
    }

    for(int i=0; i<dragons; i++){
        int heal = dragon.top().first;
        int bonus = dragon.top().second;
        if(strength > heal){
            strength += bonus;
            dragon.pop();
        }else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

    return 0;
}

