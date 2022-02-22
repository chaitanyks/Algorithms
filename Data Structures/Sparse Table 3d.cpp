static auto _speedupMagic = [] {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class NumMatrix {
public:
    vector<vector<vector<int>>> st;
    int k;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        
        int n = matrix[0].size();
        k = log2(n);
        
        st.resize(m,vector<vector<int>>(n,vector<int>(k+1)));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                st[i][j][0] = matrix[i][j];
            }
        }
        
        for(int row = 0;row<m;row++)
        {
            for(int j = 1;j<=k;j++)
            {
                for(int i=0;i+(1<<j)<=n;i++)
                {
                    st[row][i][j] = st[row][i][j-1] + st[row][i+(1<<(j-1))][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans = 0;
        // for(int row = row1;row<=row2;row++)
        // {
            int l = col1;
            // cout<<row<<" ";
            for(int j=k;j>=0;j--)
            {
                // cout<<j<<" ";
                if(l + (1<<j) -1<=col2)
                {
                    // cout<<j<<" ";
                    for(int row = row1;row<=row2;row++)
                        ans = ans + st[row][l][j];
                    l = l + (1<<j);                    
                }                
            }
            // cout<<ans<<" ";
        // }
        // cout<<endl;
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
