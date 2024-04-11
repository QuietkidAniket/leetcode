#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // intuition : 
        /*
        no matter in what order the students stand in line,
        if none of the students in the line do not prefer the current type of sandwich 
        then the remaining sandwiches cannot be catered to the 
        students, or conversely the remaining students will get stranded in a *deadlock*
        and hence they will stay hungry.

        so we need to check for the top most sandwich and then 
        try decreasing the count of students who prefer that type;
        if the number of students who like that sandwich is 0, then all the remaining students
        will have to stay hungry.

        Similar thing happens in terms of computer threads and processes.
        A *deadlock* occurs in a system if or when the processes keeps waiting for 
        one or more resources it needs, but the resources will never be available.
        , i.e., the current resource doesnt satisfy them and they wait till 
        the next resource which never comes on top unless the current resource is used.

        */

        //keeps track of 1s and 0s as preferences
        vector<int> counts(2,0);

        // keeps track of 1s and 0s occuring in students
        for(auto student : students){
            counts[student]++;
        }

        // keeps track of how many sandwiches have been catered
        int remaining = sandwiches.size();

        // selects the top most sandwich from the queue at each iteration
        for(auto sandwich : sandwiches){
            // if none of the students like the sandwich then the current remaining students will have to starve
            if(counts[sandwich] == 0){
                break;
            }

            // if remaining number of sandwiches are 0, then there is no more sanwiches left to be catered
            if(remaining == 0){
                break;
            }
            // decreasing the count of students who love this specific type of sandwich
            counts[sandwich]--;
            // decreasing the number of sandwiches as they are catered to the person
            remaining--;
        }
        return remaining;
    }
};



int main(){
    vector<int> sandwiches{1,0,0,0,1,1};
    vector<int> students{1,1,1,0,0,1};
    Solution obj;
    cout << obj.countStudents(students, sandwiches) << '\n' ;
    return 0;

}