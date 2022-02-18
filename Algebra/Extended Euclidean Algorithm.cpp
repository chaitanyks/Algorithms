// https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
// Calculate GCD coefficients x and y using Extended Euclidean Algorithm
// Time Complexity O(log min(a,b)) and Space Complexity O(1) 
// Consecutive Fibonacci numbers are the worst case input for Extended Euclidean Algorithm.

#include <iostream>
using namespace std;

class Solution {
public:
    long long gcd(long long a, long long b, int & x, int & y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        
        int x1, y1;
        int d = gcd(b, a%b, x1, y1);
        x = y1;
        y = x1 - a/b * y1;
        
        return d;
    }
};

int main() {
    // your code goes here
    Solution solution;
    int a = 12, b = 18;
    int x, y;
    cout << "GCD : " << solution.gcd(a, b, x, y) << endl;
    cout << "GCD coefficients x : " << x << endl;
    cout << "GCD coefficients y : " << y << endl;
    return 0;
}
