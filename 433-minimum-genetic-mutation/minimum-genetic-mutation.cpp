class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        q.push(startGene);
        int level = 0;
        unordered_set<string> visited;
        unordered_set<string> bankset(bank.begin(), bank.end());
        visited.insert(startGene);
        string gene = "ACGT";
        while (!q.empty()){
            int n = q.size();
            while(n--){
                string s = q.front();
                q.pop();
                if (s == endGene) return level;
                for (int i = 0; i < 4; i++){
                    char c = gene[i];
                    for (int j = 0; j < s.size(); j++){
                        string temp = s;
                        temp[j] = c;
                        if (visited.find(temp) != visited.end()) continue;
                        if (bankset.find(temp) != bankset.end()) {
                            visited.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna