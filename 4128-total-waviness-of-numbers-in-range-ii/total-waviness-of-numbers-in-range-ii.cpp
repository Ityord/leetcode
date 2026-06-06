class Solution {
public:
    typedef long long ll;
    string s;
    int n;
    ll dpTotalNumbers[16][10][10];
    ll dpTotalWaviness[16][10][10];
    pair<ll,ll> solve(int curr, int prevPrev, int prev, bool isLWAN, bool isLZ){
        if (curr == n){
            return {1,0};
        }

        if (!isLWAN && !isLZ && prevPrev >= 0 && prev >= 0){
            if (dpTotalNumbers[curr][prevPrev][prev] != -1 && dpTotalWaviness[curr][prevPrev][prev] != -1){
                return {dpTotalNumbers[curr][prevPrev][prev], dpTotalWaviness[curr][prevPrev][prev]};
            }
        }

        ll totalNumbers = 0;
        ll totalWaveScore = 0;

        int limitDigit = isLWAN ? (s[curr] - '0') : 9;
        for (int digit = 0; digit <= limitDigit; digit++){
            bool newIsLeadingZero = isLZ && (digit == 0);
            int newPrevPrev = prev;
            int newPrev = newIsLeadingZero ? -1 : digit;

            auto [remainTotalNumbers, remainTotalWaveScore] = solve(curr + 1, newPrevPrev, newPrev, isLWAN && (digit == limitDigit), newIsLeadingZero);

            if (!newIsLeadingZero && prevPrev >= 0 && prev >= 0){
                bool isPeak = (prevPrev < prev && prev > digit);
                bool isValley = (prevPrev > prev && prev < digit);

                if (isPeak || isValley) {
                    totalWaveScore += remainTotalNumbers;
                }
            }
            totalNumbers += remainTotalNumbers;
            totalWaveScore += remainTotalWaveScore;
        }
        if (!isLWAN && !isLZ && prevPrev >= 0 && prev >= 0) {
            dpTotalNumbers[curr][prevPrev][prev] = totalNumbers;
            dpTotalWaviness[curr][prevPrev][prev] = totalWaveScore;
        }
        return {totalNumbers, totalWaveScore};
    }

    ll func(ll num){
        if (num < 100){
            return 0;
        }

        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWaviness, -2, sizeof(dpTotalWaviness));
        s = to_string(num);
        n = s.length();

        auto [totalNumbers, totalWaveScore] = solve(0,-1,-1, true, true);
        return totalWaveScore;
    }
    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1-1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/leethub-v4/bcilpkkbokcopmabingnndookdogmbna