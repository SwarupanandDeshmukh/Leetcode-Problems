class MyQueue {
public:
    vector<int> v;
    MyQueue() {

    }
    
    void push(int x) {
        v.push_back(x);
    }
    
    int pop() {
         auto i = v.begin();
         int val = *i;
         v.erase(v.begin());
         return val;

    }
    
    int peek() {
     auto it = v.begin();
     return *(it);   
    }
    
    bool empty() {
        if(v.size() == 0)
            return true;
        else 
            return false;
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