#include <iostream>

using namespace std;

int n;
int main(){
    cin>>n;
    if(n%4 == 0 || n%7 ==0 || n%44 == 0 || n%47 ==0 || n%444 == 0 || n%447 ==0 || n%477 == 0 || n%77 ==0 || n%74 == 0 || n%744 ==0 || n%774 == 0 || n%777 ==0){
        cout<<"YES";
        return 0;
    }
    else{
        while(n>0){
            if(n%10 != 4 && n%10 != 7){
                cout<<"NO";
                return 0;
            }else{
                n/=10;
            }
        }
        cout<<"YES";
    }
    return 0;
}

