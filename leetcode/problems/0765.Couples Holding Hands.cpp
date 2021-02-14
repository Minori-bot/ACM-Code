class Solution {
public:
    int minSwapsCouples(vector<int>& row) {

        int n = row.size();
        int *pos = new int[n];
        fill(pos, pos + n, 0);

        for(int i = 0; i < n; i ++){
            pos[row[i]] = i;
        }

        int ret = 0;
        for(int i = 0; i < n; i += 2){
            int cp = row[i] ^ 1;
            if(row[i + 1] == cp) continue;
            else{
                int prior = row[i + 1];
                swap(row[pos[prior]], row[pos[cp]]);
                swap(pos[prior], pos[cp]);
                ret ++;
            }
        }

        return ret;
    }
};

// 0 1 4 6 7 2 3 5
// 0 1 4 5 7 2 3 6
// 0 1 4 5 7 6 3 2