class Solution {
public:
    int reverse(int x) {
        string s;
        if (0 == x) return x;
        if (x < 0) s = '-';

        for (int i=0 ; x ; ++i) {
            int n = x % 10;
            x /= 10;
            if (0 == i && 0 == n) continue;
            if (n < 0) n = -n;
            s += ('0' + n);
        }

        int ans = 0;
        string sm;
        if ('-' == s[0]) sm = to_string(INT_MIN);
        else sm = to_string(INT_MAX);

        if (s.length() > sm.length()) return 0;
        if (s.length() == sm.length()) {
            for (int i=0 ; i<s.length() ; ++i) {
                if (s[i] < sm[i]) break;
                if (s[i] > sm[i]) return 0;
            }
        }

        ans = stoi(s);
        return ans;
    }
};