class MyCircularDeque {
public:
    vector<int> arr;
    int f,r;
    int s;
    MyCircularDeque(int k) {
        arr.resize(k);
        f = r = -1;
        s = k;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;
        
        if(isEmpty())
            f = r = 0;
        else
            f = (f -1 +s) % s;
        
        arr[f] = value;
        return true;
        
        

    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;
        
        if(f == -1)
            f = 0;
        r = (r+1) % s;
        arr[r] = value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        
        if(f == r)
        {
            f = r = -1;
            return true;
        }
        else
        {
            f = (f+1) % s;
            return true;
        }

    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        
        if(f == r)
            f = r = -1;
        else
            r = (r - 1 + s) % s;
        return true; 
        
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        else
            return arr[f];
    }
    
    int getRear() {
        if(isEmpty())
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */