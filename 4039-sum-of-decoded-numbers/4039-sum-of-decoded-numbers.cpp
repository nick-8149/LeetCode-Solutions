class Solution {
public:

    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;

        base %= mod;

        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % mod;

            base = (base * base) % mod;
            exp /= 2;
        }

        return result;
    }

    int sumDecoded(vector<long long>& nums) {
        const long long mod = 1000000007;
        long long sum = 0;

        for (long long num : nums) {
            int width = num % 10;
            long long d = num / 10;

            int size = 0;
            long long temp = d;

            while (temp != 0) {
                temp /= 10;
                size++;
            }

            long long i = d;
            long long mul = 1;

            for (int j = 0; j < size - width; j++) {
                i /= 10;
                mul *= 10;
            }

            long long exponent = d - i * mul;

            long long value = modPow(i, exponent, mod);

            sum = (sum + value) % mod;
        }

        return (int)sum;
    }
};