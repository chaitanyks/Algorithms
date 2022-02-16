// https://cp-algorithms.com/algebra/binary-exp.html
// calculate a^n using Binary Exponentiation
// Time Complexity O(logN) and Space Complexity O(1)

#include <iostream>
using namespace std;

class Solution {
public:
    long long fastPow(long long a, long long n) {
        if (n == 0)
            return 1;

        long long val = fastPow(a, n / 2);

        if (n % 2 == 0)
            return val * val;
        else
            return a * val * val;
    }
};

int main() {
    // your code goes here
    Solution solution;
    int a = 4, b = 6;
    cout << solution.fastPow(a, b) << endl;
    return 0;
}
