class MyHashMap {
public:
    int s = 1000;
    vector<list<pair<int,int>>> table;
    MyHashMap() {
        table.resize(s);
    }

    int hash(int key)
    {
        return key % s;
    }
    
    void put(int key, int value) {
        
        int idx = hash(key);

        for(auto &p : table[idx])
        {
            if(p.first == key)
            {
                p.second = value;
                return;
            }
        }

        table[idx].push_back({key,value});

    }
    
    int get(int key) {

        int idx = hash(key);

        for(auto &p : table[idx])
        {
            if(p.first == key)
                return p.second;
        }
        return -1;   
    }
    
    void remove(int key) {
        
        int idx = hash(key);

        auto it = table[idx].begin();
        while(it != table[idx].end())
        {
            if(it->first == key)
            {
                table[idx].erase(it);
                return;
            }
            it++;
        }

        return;
         

    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */