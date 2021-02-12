class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if(rowIndex == 0) return vector<int>({1});
        
        rowIndex ++;
        vector<int> row[2];
        row[0].resize(rowIndex + 1);
        row[1].resize(rowIndex + 1);

        for(int i = 1; i <= rowIndex; i ++){
            row[i % 2][1] = row[i % 2][i] = 1;
            for(int j = 2; j < i; j ++){
                row[i % 2][j] = row[(i % 2) ^ 1][j - 1] + row[(i % 2) ^ 1][j];
            }
        }

        return vector<int>(row[rowIndex % 2].begin() + 1, row[rowIndex % 2].end());
    }
};