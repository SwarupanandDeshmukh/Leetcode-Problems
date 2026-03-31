class MyCircularQueue {
public:
    vector<int> arr;
    int f,r;
    int s  = 0;
    MyCircularQueue(int k) {
        arr.resize(k);
        f = r = -1;
        s = k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        if(f == -1)
            f = 0;
        r = (r+1) % s;
        arr[r] = value;
        return true;

    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        
        if(f == r)
        {
            f = r = -1;
            return true;
        }
        else 
        {
            f = (f + 1) % s;
            return true;
        }
    }
    
    int Front() {
        if(f == -1)
            return -1;
        else
            return arr[f];
    }
    
    int Rear() {
        if(r == -1)
            return -1;
        else
            return arr[r];
    }
    
    bool isEmpty() {
        if(f == -1 && r == -1)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if((f == 0 && r == s-1) || (r == f-1))
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */