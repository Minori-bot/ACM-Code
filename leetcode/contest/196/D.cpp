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
    string minInteger(string num, int k) {

        vector<priority_queue<int, vector<int>, greater<int>>> pqs;
        pqs.resize(10);

        for(int i = 0; i < num.size(); i ++){
            pqs[num[i] - '0'].push(i);
        }

        string res;
        BinaryIndexTree bit = BinaryIndexTree(num.size());

        for(int i = 0; i < num.size(); i ++){

            for(int digit = 0; digit < 10; digit ++){

                if(!pqs[digit].empty()){
                    int pos = pqs[digit].top();
                    int leftUsed = bit.query(pos);

                    if(pos - leftUsed <= k){
                        k -= pos - leftUsed;
                        res.push_back(digit + '0');
                        pqs[digit].pop();
                        bit.add(pos + 1, 1);
                        break;
                    }
                }
            }
        }

        return res;
    }
};