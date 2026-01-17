#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long stock;
    int dis = 0;

    string x;
    getline(cin, x);
    int s = x.find(' ');
    n = stoi(x.substr(0, s));
    stock = stoll(x.substr(s + 1));

    while(n--){
        string came;
        getline(cin, came);

        int z = came.find(' ');
        long long val = stoll(came.substr(z + 1));

        if(came[0] == '+'){
            stock += val;
        }else{
            if(stock >= val) stock -= val;
            else dis++;
        }
    }

    cout << stock << " " << dis << "\n";
}
