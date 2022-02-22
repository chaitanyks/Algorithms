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
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int rangeMinimumQueries(int L, int R) {
        int index = log2(R - L + 1);
        int ans = min(st[L][index], st[R - (1 << index) + 1][index]);
        return ans;
    }
};

int main() {
	  // your code goes here
	  SparseTable sparseTable;
    vector<int> arr = {1, 5, 8, 6, 3, 2, 1, 4, 1};
	  sparseTable.sparseTable(arr);
  
    // Minimum Queries
    cout<<"Minimum Queries : "<<endl;
    cout<<sparseTable.rangeMinimumQueries(2,5)<<endl;
    cout<<sparseTable.rangeMinimumQueries(4,8)<<endl;
    cout<<sparseTable.rangeMinimumQueries(1,7)<<endl;

	  return 0;
}
