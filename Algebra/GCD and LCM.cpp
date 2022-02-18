// https://cp-algorithms.com/algebra/euclid-algorithm.html
// calculate GCD and LCM using Euclidean algorithm
// Time Complexity O(log min(a,b)) and Space Complexity O(1) 
// Consecutive Fibonacci numbers are the worst case input for Euclid's algorithm.

#include <iostream>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a%b);
    }
    
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
};

int main() {
    // your code goes here
    Solution solution;
    int a = 12, b = 18;
    cout << "GCD : " << solution.gcd(a, b) << endl;
    cout << "LCM : " << solution.lcm(a, b) << endl;
    return 0;
}
