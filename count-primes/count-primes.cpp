#define ull unsigned long long

class Solution {
public:
    vector<bool> sieve;
    
    void e_sieve(ull n) {
        sieve.resize(n+1, true);
        for (ull i=2 ; i*i<n ; ++i) {
            if (!sieve[i]) continue;
            for (ull j=i*i ; j<n ; j+=i) {
                sieve[j] = false;
            }                
        }
    }

    int countPrimes(int n) {
        e_sieve(n);
        int cnt = 0;
        for (int i=2 ; i<n ; ++i) {
            if(sieve[i]) ++cnt;
        }
        return cnt;
    }
};