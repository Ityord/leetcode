class Solution {
public:
    long long sum(vector<int>& arr){
        long long res = 0;
        for (int i = 0; i < arr.size(); i++){
            res += arr[i];
        }
        return res;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> sumst(n);
        for (int i = 0; i < n; i++) {
            sumst[i] = sum(grid[i]);
        }

        vector<long long> presum(n);
        presum[0] = sumst[0];
        for (int i = 1; i < n; i++){
            presum[i] = presum[i-1] + sumst[i];
        }
        long long p = 0;
        for (int i = n-1; i > 0; i--){
            p += sumst[i];
            if (p == presum[i-1]) return true;
        }
        vector<long long> sumst2(m);
        for (int i = 0; i < m; i++) {
            long long s = 0;
            for (int j = 0; j < n; j++){
                s += grid[j][i];
            }
            sumst2[i] = s;
        }
        vector<long long> presum2(m);
        presum2[0] = sumst2[0];
        for (int i = 1; i < m; i++){
            presum2[i] = presum2[i-1] + sumst2[i];
        }
        long long k = 0;
        for (int i = m-1; i > 0; i--){
            k += sumst2[i];
            if (k == presum2[i-1]) return true;
        }
        return false;
    }
};