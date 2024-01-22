//here's a frog looking over a river that's x feet wide, and there are x-1 stones placed in the river one foot apart. (From the beginning to the first stone is one foot, 
//from the last stone to the end is one foot, etc.) This frog is able to jump either 1 foot or 2 feet. (After the first jump the frog could either be on the first or 
//the second stone and again jump 1 or 2 feet from where he was initially.) The question is, how many ways are there for the frog to get to the end?
//__________________________________________________________________CODE_________________________________________________________________________________________________
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
