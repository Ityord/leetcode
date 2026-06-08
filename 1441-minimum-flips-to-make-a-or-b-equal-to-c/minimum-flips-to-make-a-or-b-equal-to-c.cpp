class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        while (c > 0 || b > 0 || a > 0){
            if ((c&1) == 1){
                if ((a&1) == 0 && (b&1)== 0){
                    flips++;
                }
            } else {
                if ((a&1)==1 || (b&1)==1){
                    if ((a&1)==1 && (b&1)==1){
                        flips += 2;
                    } else {
                        flips++;
                    }
                }
            }
            c = c >> 1;
            a = a >> 1;
            b = b >> 1;
        }
        return flips;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna