#include <iostream>

using namespace std;

int n;

int main(){
    cin>>n;
    int arr[n]={0};
    int recived[n]={0};
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr[i] = x;
    }

    for (int i=0; i<n; i++){
        int rec = arr[i];
        recived[rec-1] = i+1;
    }

    for(int i=0; i<n; i++){
        cout<<recived[i]<<" ";
    }

    return 0;
}

