class Solution {
public:
    int getWinner(vector<int>& arr, int k) {

        unordered_map<int, int> win;
        deque<int> dq(arr.begin(), arr.end());
        int maxVal = *max_element(arr.begin(), arr.end());

        while(!dq.empty()){
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();

            if(a < b) swap(a, b);
            if(a == maxVal) return a;
            dq.push_back(b);
            dq.push_front(a);
            win[a] += 1;
            if(win[a] == k) return a;
        }
        return arr[0];
    }
};
