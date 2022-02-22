#include <bits/stdc++.h>
using namespace std;

class SparseTable {
public:
    vector<vector<int>> st;
    int k,n;

    void sparseTable(vector<int> &arr) {
        n = arr.size();
        k = log2(n);
        st.resize(n, vector < int>(k + 1));

        for (int i = 0; i < n; i++)
            st[i][0] = arr[i];

        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = st[i][j - 1] + st[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int rangeSumQueries(int L, int R) {
        int ans = 0;

        for (int i = k; i >= 0; i--) {
            if (L + (1 << i) - 1 <= R) {
                ans = ans + st[L][i];
                L = L + (1 << i);
            }
        }
        return ans;
    }
};

int main() {
	// your code goes here
	  SparseTable sparseTable;
    vector<int> arr = {1, 5, 8, 6, 3, 2, 1, 4, 1};
	  sparseTable.sparseTable(arr);
  
    // Sum Queries
    cout<<"Sum Queries : "<<endl;
    cout<<sparseTable.rangeSumQueries(2,5)<<endl;
    cout<<sparseTable.rangeSumQueries(4,8)<<endl;
    cout<<sparseTable.rangeSumQueries(1,7)<<endl;

	  return 0;
}
