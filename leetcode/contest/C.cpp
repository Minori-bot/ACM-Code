class BinaryIndexTree{

private:
    vector<int> c;
    int n;

    inline int lowbit(int x){
        return x & (-x);
    }

public:
    explicit BinaryIndexTree(int n){
        c.resize(n + 1);
        this->n = n;
    }

    inline void add(int k, int val){
        for(; k <= n; k += lowbit(k)) c[k] += val;
    }

    inline int query(int k){
        int res = 0;
        for(; k; k -= lowbit(k)) res += c[k];
        return res;
    }
};

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {

        int n = grid.size();
        vector<int> zeros(n);
        auto bit = BinaryIndexTree(n);

        for(int i = 0; i < n; i ++){
            auto vec = grid[i];
            for(int j = vec.size() - 1; j >= 0; j --){
                if(vec[j]) break;
                zeros[i] ++;
            }
        }

        int limit = n - 1;
        vector<int> used(n, 0);
        while(limit > 0){
            bool ok = false;
            for(int i = 0; i < n; i ++){
                if(zeros[i] >= limit && !used[i]){
                    used[i] = 1;
                    ok = true;
                    limit --;
                    break;
                }
            }
            if(!ok) return -1;
        }

        int res = 0;
        limit = n - 1;
        used.clear();
        used.resize(n);
        while(limit > 0){
            for(int i = 0; i < n; i ++){
                if(zeros[i] >= limit && !used[i]){
                    used[i] = 1;
                    int left = bit.query(i);
                    res += max(0, i - left);
                    limit --;
                    bit.add(i + 1, 1);
                    break;
                }
            }
        }
        return res;
    }
};