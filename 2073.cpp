#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int length {(int)tickets.size()};
        int time {0};

        int i {0};
        while(tickets[k] != 0)
        {
            if(tickets[i] == 0){
                if(i == length -1)i=-1;
                i++;
                continue;
            }
            tickets[i]--;
            time++;
            if(i == length - 1)i=-1;
            i++;
            
        }
        
        return time;

    }
};


int main(){
    vector<int> tickets {2,3,2};
    int k = 2;
    Solution obj;
    cout << obj.timeRequiredToBuy(tickets, k) << '\n'; 
}