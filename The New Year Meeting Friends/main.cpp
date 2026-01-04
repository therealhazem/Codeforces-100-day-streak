#include <iostream>
#include <queue>
using namespace std;

int main(){

    priority_queue<int> points;
    int arranged[3];
    for(int i=0; i<3; i++){
        int x;
        cin>>x;
        points.push(x);
    }
    for(int i=0; i<3; i++){
        arranged[i] = points.top();
        points.pop();
    }

    cout<<arranged[0]-arranged[1] + arranged[1]-arranged[2];
    return 0;
}

