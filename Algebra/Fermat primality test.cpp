#include <bits/stdc++.h>
using namespace std;

int binPower(int a, int p, int m) {
    if (p == 0)
        return 1;
        
    int val = binPower(a, p / 2, m) % m;

    if (p % 2 == 0)
        return (val * val) % m;

    return ((a * val) % m * val) % m;

}

int fermatPrimeTest(int n, int iter = 5) {
    
    if (n == 2 || n == 3)
        return true;

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);

        if (binPower(a, n - 1, n) % n != 1)
            return false;
    }

    return true;
}

int main() {
    // your code goes here
    cout << "Check : " << fermatPrimeTest(7, 5) << endl;
    return 0;
}
