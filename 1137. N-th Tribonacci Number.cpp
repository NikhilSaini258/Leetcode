class Solution {
public:
    int tribonacci(int n) {
        if (n < 2) return n;
        int t1, t2, t3;
        t1 = 0;
        t2 = t3 = 1;
        int ans = t1 + t2 + t3;
        for (int i = 2; i < n; i++) {
            ans = t1 + t2 + t3;
            t1 = t2;
            t2 = t3;
            t3 = ans;
        }
        return t3;
    }
};
