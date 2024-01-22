// Cherry's Birthday is coming this month: She want to plan a birthday party and is preparing a invite list with her friend Aashi.She ask to tell her name to add in the list.

// Aashi is a random guy and keeps coming with names of people randomly to add in the invite list, even if the name is already in the list.
// Cherry hates redudancy and hence, enlist the names only once.

// find the final invite list, that contains names without any repetition.

// Input:
// First Line of each Test Contains an integer N, the number of names that aashi pops up.

// Output:
// Output the final invite list with each name in the final invite list are lexicographically.
//________________________________________________________CODE___________________________________________________________________________________________________________
#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    set<string>inviteList;
    int n;
    cin>>n;
    while(n--){
        string name;
        cin>>name;
        inviteList.insert(name);
    }
    for(auto name: inviteList){
        cout<<name<<endl;
    }
    return 0;
}
