class MyStack {
public:
    queue<int> q;
     queue<int> temp;
    MyStack() {
       
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        
        int n = q.size();
        int i = 0;
        while(i < n-1)
        {
            temp.push(q.front());
            q.pop();
            i++;
        }

        int val =  q.front();
        q.pop();
        q = temp;

        while(!temp.empty())   
            temp.pop();
        return val;

    }
    
    int top() { 

        int n = q.size();
        int val;

        for(int i = 0; i < n; i++) {
            val = q.front();
            q.pop();
            q.push(val);
        }

        return val;
    }
    
    bool empty() {
        
        if(q.size() == 0)
            return true;
        else
            return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */