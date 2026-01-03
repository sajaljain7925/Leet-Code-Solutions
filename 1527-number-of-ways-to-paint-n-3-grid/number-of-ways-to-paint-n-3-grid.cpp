class Solution {
public:
    int numOfWays(int n) {
        const long MOD = 1000000007;

        long same = 6; // ABA type
        long diff = 6; // ABC type

        for (int i = 2; i <= n; i++) {
            long newDiff = (2 * diff + 2 * same) % MOD;
            long newSame = (2 * diff + 3 * same) % MOD;

            diff = newDiff;
            same = newSame;
        }

        return (same + diff) % MOD;
    }
};
