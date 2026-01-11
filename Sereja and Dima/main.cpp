#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int s = 0, d = 0;
    int l = 0, r = n - 1;

    for (int i=0; i<n; i++) {

        int chosen;
        if (nums[l]>nums[r]) {
            chosen=nums[l];
            l++;
        } else {
            chosen=nums[r];
            r--;
        }
        if(i%2 == 0)
            s+=chosen;
        else{
            d+=chosen;
        }
    }

    cout <<s<<" "<<d;
    return 0;
}
