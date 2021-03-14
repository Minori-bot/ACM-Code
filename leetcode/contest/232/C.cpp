class Class{

private:
    double rate;
    double up;
    int pass;
    int total;
    
public:
    Class(int pass, int total): pass(pass), total(total){
        rate = pass * 1.0 / total;
        up = (pass + 1) * 1.0 / (total + 1) - rate;
    }
    bool operator < (const Class& rhs) const {
        return up < rhs.up;
    }
    void add(){
        pass ++, total ++;
        rate = pass * 1.0 / total;
        up = (pass + 1) * 1.0 / (total + 1) - rate;
    }
    double getRate(){
        return rate;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<Class> pq;
        for(auto& e: classes){
            pq.emplace(Class(e[0], e[1]));
        }
        while(extraStudents --){
            auto prior = pq.top();
            pq.pop();
            prior.add();
            pq.emplace(prior);
        }
        double rate = 0;
        while(!pq.empty()){
            auto prior = pq.top();
            pq.pop();
            rate += prior.getRate();
        }
        return rate / classes.size();
    }
};