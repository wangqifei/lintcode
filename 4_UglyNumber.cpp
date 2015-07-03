// Ugly Number Show result 

// 20% Accepted
// Ugly number is a number that only have factors 3, 5 and 7.

// Design an algorithm to find the Kth ugly number. The first 5 ugly numbers are 3, 5, 7, 9, 15 ...

// Example
// If K=4, return 9.

// Challenge
// O(K log K) or O(K) time.
#include <iostream>
#include <queue>
using namespace::std;
class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        queue<long long> q3, q5, q7;
        int i = 0;
        q3.push(3);
        q5.push(5);
        q7.push(7);
        while(i < k)
        {
            long long a3 = q3.front();
            long long a5 = q5.front();
            long long a7 = q7.front();
            long long a = min(a3, min(a5, a7));
            if(i == k-1) return a;
            else i++;
            if(a == a3)
            {
                q3.pop();
                q3.push(a*3);
                q5.push(a*5);
                q7.push(a*7);
                continue;
            }
            if(a == a5)
            {
                q5.pop();
                q5.push(a*5);
                q7.push(a*7);
                continue;
            }
            if(a == a7)
            {
                q7.pop();
                q7.push(a*7);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    long long res = solution.kthPrimeNumber(12);
    cout<<"result is "<<res<<endl;
    return 0;
}