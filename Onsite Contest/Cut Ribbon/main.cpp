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

    float h,l;
    cin>>h>>l;

    double result = ((l*l)-(h*h))/(2*h);
    printf("%.13f", result);
    return 0;

}

