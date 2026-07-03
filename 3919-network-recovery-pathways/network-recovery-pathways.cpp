class Solution {
public:
    typedef long long ll;
    bool check(int mid, int n, ll k, unordered_map<int,vector<vector<int>>>& mp){
        vector<ll> result(n,LLONG_MAX);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
        pq.push({0,0});
        result[0] = 0;
        while (!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if (d > k){
                return false;
            }
            if (node == n-1) return true;
            if (result[node] < d){
                continue;
            }
            for (auto &nd : mp[node]){
                int cost = nd[0];
                int neighbour = nd[1];
                if (cost < mid) continue;
                if (result[neighbour] > cost+d){
                    result[neighbour] = cost+d;
                    pq.push({cost+d,neighbour});
                }
            }
        }
        return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        unordered_map<int,vector<vector<int>>> mp;
        int n = online.size();
        int l = INT_MAX;
        int r = 0;
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int cost = edges[i][2];
            if (!online[u] || !online[v]) continue;
            l = min(l,cost);
            r = max(r,cost);
            mp[u].push_back({cost,v});
        }
        int ans = -1;
        while (l<=r){
            int mid = l + (r-l)/2;
            if (check(mid, n, k ,mp)){
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna