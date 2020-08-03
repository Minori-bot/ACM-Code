class Solution {
public:
    int climbStairs(int n) {
        
        int a = 1, b = 1;
        
        if(n == 0 || n == 1) return 1;
        
        for(int i = 2; i <= n; i ++){
            int cur = a + b;
            a = b, b = cur;
        }
        return b;
    }
};

// 1 1 2 3 5 8