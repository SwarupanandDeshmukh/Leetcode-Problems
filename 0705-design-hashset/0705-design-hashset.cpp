class MyHashSet {
public:
    int s = 10;
    vector<list<int>> table;
    MyHashSet() {
        table.resize(s);
    }
    
    void add(int key) {
        int idx = key % s;
        auto it = table[idx].begin();
        while(it != table[idx].end())
        {
            if(key == *it)
                return;
            it++;
        }

        table[idx].push_back(key);
    }   
    
    void remove(int key) {
         int idx = key % s;
        auto it = table[idx].begin();
        while(it != table[idx].end())
        {
            if(key == *it)
            {
                table[idx].erase(it);
                return;
            }
            it++;
        }
        return;
    
    }
    
    bool contains(int key) {
        
        int idx = key % s;
        auto it = table[idx].begin();
        while(it != table[idx].end())
        {
            if(key == *it)
                return true;
            it++;
        }
        return false;

    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */