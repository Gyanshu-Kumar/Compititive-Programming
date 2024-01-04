// A new Racing Track for kids is being built in New York with 'n' Starting Spots.The Spots are located along a starting line at a position x1,x2,.......xn(xi = 10^9).For Eack 'i'xi + 1 > xi.At a time only m childrens are allowed to Enter the race. Since the Race track is For kids,they may run into each other while running.To prevent this, we want to choose the starting spot such that the minimum distance between between any Two of them is as Possible.What is the Largest minimum Distance ?.

// The First Line of the input will contain the value of n.
// The Numbers of the starting spots.
// The Second line of the input will contain the n numbers of denoting the locations of each spot.
// The third line will contain the value of m,numbers of denoting the location of each spot.
// The Third line will contain the value the value of m,numbers of the childrens.
// Input:-
// 5
// 1 2 4 8 9
// 3
// Output:
// 3

// Hint:- we have to write a program to find the minimum distance is Maximum Between Two Students.
//_______________________________________________________________________________________________________________________________________________________________
//___________________________________________________________________________CDOE________________________________________________________________________________
#include<iostream>
#include<vector>
using namespace std;
bool canPlaceStudents(vector<int>&pos, int s, int mid){
    int studReqd = 1;
    int lastPlaced = pos[0];
    for(int i = 1;i < pos.size();i++){
        if(pos[i] - lastPlaced >= mid){
            studReqd++;
            lastPlaced = pos[i];
            if(studReqd == s){
                return true;
            }
        }
    }
    return false;
}
int race(vector<int> &pos, int s){
    int n = pos.size();
    int lo = 1;
    int hi = pos[n - 1] - pos[0];
    int ans = -1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(canPlaceStudents(pos, s, mid)){
            ans = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>pos;
    while(n--){
        int x;
        cin>>x;
        pos.push_back(x);
    }
    int s;
    cin>>s;
    cout<<race(pos, s)<<"\n";
    return 0;
}
