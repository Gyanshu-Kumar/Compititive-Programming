// You Have 'n' (n <= 10^5) boxes of chocolates.Each boxes contain a[i](a[i] <= 10000) chocolates.You Need to distribute these boxes among 'm' students such that the maximum number of chocolates allocated to a student is minimum.
// a> One box will be allocated to exactly one Student.
// b> All boxes Should be allocated.
// c> Each Student ha to be allocated at least One Box.
// d> Allotment Should be in contigious order, for instance, a student cannot be allocated box 1 and box 3, skipping box 2.
// . Calculate and return that Minimum possible Number.
// . Assume that it is always possible to Distribute the Chocolated.
// . The first line of Input will contain the value of n, the number of boxes.
// . The Second line of Input will contain the n number of denoting the number of chocolates in each boxes 
// . The Third line will contain the m, number students.
__________________________________________________________________________________________________________________
// INPUT-
// 4
// 12 34 67 90
// 2
// OUTPUT-
// 113
// ___________________________________________________CODE___________________________________________________

#include<iostream>
#include<vector>
using namespace std;
bool canDistChoco(vector<int>&arr, int mid,int s){
    int n = arr.size();
    int studReqd = 1;
    int currSum = 0;
    for(int i = 0;i < n;i++){
        if(arr[i] > mid){
            return false;
        }
        if(currSum + arr[i] > mid){
            studReqd++;
            currSum = arr[i];
            if(studReqd > s) return false;
        }
        else{
            currSum += arr[i];
        }
    }
    return true;
}
int distChoco(vector<int> &arr, int s){
    int n = arr.size();
    int lo = arr[0];
    int hi = 0;
    for(int i = 0;i < arr.size();i++){
        hi += arr[i];
    }
    int ans = -1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(canDistChoco(arr, mid, s)){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int s;
    cin>>s;
    cout<<distChoco(v, s)<<endl;
    return 0;
}
