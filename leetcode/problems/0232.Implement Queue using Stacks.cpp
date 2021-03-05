class MyQueue {

private:
    bool isPop;
    stack<int> p, q;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        isPop = false;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {         
        if(!isPop){
            p.push(x);
        }
        else{
            while(!q.empty()){
                int k = q.top(); q.pop();
                p.push(k);
            }
            p.push(x);
        }
        isPop = false;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(q.empty() && p.empty()) return -1;
        
        if(isPop){
            int k = q.top(); q.pop();
            return k;
        }
        else{
            isPop = true;
            while(!p.empty()){
                int k = p.top(); p.pop();
                q.push(k);
            }
            int k = q.top(); q.pop();
            return k;
        }
    
    }
    
    /** Get the front element. */
    int peek() {
        if(q.empty() && p.empty()) return -1;
        
        if(isPop){
            return q.top();
        }
        else{
            isPop = true;
            while(!p.empty()){
                int k = p.top(); p.pop();
                q.push(k);
            }
            return q.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q.empty() && p.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */