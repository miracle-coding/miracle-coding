#define ull unsigned long long

class Solution {
public:
    int countPrimes(int n) {
        if (n<=2) return 0;
        
        vector<bool> sieve(n+1, true);
        for (ull i=2 ; i*i<n ; ++i) {
            if (!sieve[i]) continue;
            for (ull j=i*i ; j<n ; j+=i) {
                sieve[j] = false;
            }                
        }
        
        int cnt = 0;
        for (int i=2 ; i<n ; ++i) {
            if (sieve[i]) ++cnt;
        }
        return cnt;
    }
};