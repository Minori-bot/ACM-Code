class Solution {

private:

    double euclidean(double a, double b, double c, double d){
        return sqrt(pow(a - c, 2) + pow(b - d, 2));
    }

    double sum(double x, double y, vector<vector<int>>& positions){

        double res = 0;
        for(auto& p: positions){
            res += euclidean(x, y, p[0], p[1]);
        }
        return res;
    }

public:
    double getMinDistSum(vector<vector<int>>& positions) {

        int n = (int)positions.size();
        double x = 50, y = 50;
        double res = INT_MAX;

        double delta = 50;

        while(delta >= 1e-5){

            double curx = x, cury = y;

            for(double i = x - delta; i <= x + delta; i += delta / 10){
                for(double j = y - delta; j <= y + delta; j += delta / 10){

                    double d = sum(i, j, positions);

                    if(d < res){
                        res = d;
                        curx = i;
                        cury = j;
                    }
                }
            }
            x = curx, y = cury;
            delta /= 10;
        }

        return res;
    }
};