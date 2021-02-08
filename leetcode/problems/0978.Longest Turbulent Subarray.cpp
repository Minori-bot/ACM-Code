class Solution {
private:
    vector<int> up;
    vector<int> down;

public:
    int maxTurbulenceSize(vector<int>& arr) {

        int n = arr.size();
        up = vector<int>(n, 1);
        down = vector<int>(n, 1);

        for(int i = 1; i < n; i ++){
            if(arr[i] > arr[i - 1]){
                up[i] = max(up[i], down[i - 1] + 1);
            }
            else if(arr[i] < arr[i - 1]){
                down[i] = max(down[i], up[i - 1] + 1);
            }
        }
        int res = max(*max_element(up.begin(), up.end()), *max_element(down.begin(), down.end()));
        
        return res;
    }
};