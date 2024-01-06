#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int f(int *h, int n, int i){
    if(i == n - 1) return 0;
    if(i == n - 2) return f(h,n,i + 1) + abs(h[i] - h[i + 1]);
    return min(f(h,n, i + 1) + abs(h[i] - h[i + 1]), f(h,n,i+2) + abs(h[i] - h[i + 2]));
    // int oneStep = f(h, n, i + 1) + abs(h[i] - h[i + 1]);
    // int twoSteps = f(h, n, i + 2) + abs(h[i] - h[i + 2]);

    // return min(oneStep, twoSteps);

}
int main(){
    int arr[] = {10,30,40,20};
    int n = 4;
    cout<<f(arr, n,0);
    return 0;
}