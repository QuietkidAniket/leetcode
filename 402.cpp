#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution{
    public:
    string removeKdigits(string num, int k){
        // Base Cases:
        // 1. number of deletions if greater than equals to length, then we end up with 0
        if(num.length() == k) return "0";

        // 2. if no digits are to be deleted then return the original number
        if(k==0)return num;

        // storing the size of the number (which is in the form of a string)
        int n = num.size();

        // stores the digits in ascii numerics
        stack<char> s;

        // we iterate through the digits from left to right,
        // and push all the digits into stack except those which are less than current topmost 
        // element in stack -> which we shall pop out
        for(auto&& c : num){
            // if the topmost in the stack is more than the current digit, 
            // given that stack is not empty and we need to remove more digits,
            // we pop the topmost digit out of the stack

            while(!s.empty() && k > 0 && s.top() > c) s.pop(), k--;

            // if c is non zero and stack is not empty, we push c into top of stack
            if(!s.empty() || c  != '0')s.push(c);
        }

        // if there are still digits to be removed
        while(!s.empty() && k--)s.pop();

        // if the stack becomes empty of digits after deletions, then just simply return 0 as
        // no digits imply 0
        if(s.empty()) return "0";

        // placing the digits in the stack into num's back
        while(!s.empty()){
            num[n-1] = s.top();
            s.pop(), n--;
        }

        // returning those digits which we just placed into num's back
        return num.substr(n);
    }
};



int main()
{
    Solution obj;
    cout << obj.removeKdigits("1432219", 3) << '\n';

    return 0;
}