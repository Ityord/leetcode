class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<bool> arrA(50,false);
        vector<bool> arrB(50,false);
        int i = 0;
        int n = A.size();
        vector<int> c(n);
        while (i < A.size()){
            arrA[A[i]] = true;
            arrB[B[i]] = true;
            int cnt = 0;
            for (int j = 0; j <= 50; j++){
                if (arrA[j] && arrB[j]){
                    cnt++;
                }
            }
            c[i] = cnt;
            i++;
        }
        return c;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna