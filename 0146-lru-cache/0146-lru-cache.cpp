class LRUCache {
public:

    class Node
    {
        public:
        int key, val;
        Node *next;
        Node *prev;
        
        Node(int k, int v)
        {
            key = k;
            val = v;
            prev = NULL;
            next = NULL;
        }

    };

    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    

    unordered_map<int, Node*> m;
    int cap;


    void addNode(Node *newNode)
    {
        Node *oldnext = head->next;
        head->next = newNode;
        oldnext->prev = newNode;
        newNode->prev = head;
        newNode->next = oldnext;
    }

    void deleteNode(Node *oldNode)
    {
        Node *oldNodePrev = oldNode->prev;
        Node *oldNodeNext = oldNode->next;
        oldNodePrev->next = oldNodeNext;
        oldNodeNext->prev = oldNodePrev;
    }



    LRUCache(int capacity) {
        
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(m.contains(key))
        {
            Node *oldNode = m[key];
            int target = oldNode->val;
            deleteNode(oldNode);
            addNode(oldNode);

            return target;
        }

        return -1;

        
    }
    
    void put(int key, int value) {
        
        if(m.contains(key))
        {
            Node *oldNode = m[key];
            m.erase(key);
            deleteNode(oldNode);
        }

        if(m.size() == cap)
        {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }


        Node *newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */