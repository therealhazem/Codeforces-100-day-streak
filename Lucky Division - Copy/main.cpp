#include <iostream>

using namespace std;

int r,c;
bool rightside = true;

int main(){
    cin>>r>>c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(i%2!=0){
                cout<<"#";
            }else{
                if(rightside){
                    while(j<c){
                        cout<<".";
                        j++;
                    }
                    cout<<"#";
                    rightside = !rightside;
                }else if(!rightside){
                    cout<<"#";
                    rightside = !rightside;
                    while(j<c){
                        cout<<".";
                        j++;
                    }
                }
            }
        }
        cout<<"\n";
    }

    return 0;
}

