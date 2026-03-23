class Solution {
public:
    int MOD = 1e9 + 7;
    typedef long long ll;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<ll,ll>>> t(m,vector<pair<ll,ll>>(n));
        ll p = 1;
        for (int i = 0; i < m; i++){
            p = p*grid[i][0];
            t[i][0] = {p,p};
        }
        p = 1;
        for (int i = 0; i < n; i++){
            p = p*grid[0][i];
            t[0][i] = {p,p};
        }

        for (int i = 1; i < m; i++){
            for (int j = 1; j  < n; j++){
                ll upmax = t[i-1][j].first;
                ll upmin = t[i-1][j].second;
                ll leftmax = t[i][j-1].first;
                ll leftmin = t[i][j-1].second;

                t[i][j].first = max({grid[i][j]*upmax, grid[i][j]*upmin, grid[i][j]*leftmax, grid[i][j]*leftmin});
                t[i][j].second = min({grid[i][j]*upmax, grid[i][j]*upmin, grid[i][j]*leftmax, grid[i][j]*leftmin});
            }
        }
        if (t[m-1][n-1].first < 0) return -1;
        return t[m-1][n-1].first % MOD;
    }
};