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

// selection
void selection(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int index = i;
        for(int j=i+1; j<n; j++){
            if(arr[index]>arr[j]) index = j;
        }
        swap(arr[index], arr[i]);
    }
    for(int i=0; i<n; i++)cout<<arr[i]<<" ";
}

// bubble
void bubble(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i; j<n-1-i; j++){
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
     for(int i=0; i<n; i++)cout<<arr[i]<<" ";
}


void insertion(int arr[], int n){
    for(int i=1; i<n; i++){
        int key=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
     for(int i=0; i<n; i++)cout<<arr[i]<<" ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)cin>>arr[i];
    selection(arr, n);
    cout<<"\n";
    selection(arr, n);
    cout<<"\n";
    insertion(arr, n);

    return 0;
}

