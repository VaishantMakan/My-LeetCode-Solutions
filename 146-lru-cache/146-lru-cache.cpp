class LRUCache {
public:
    
    class node 
    {  
        public:
        int NodeKey;
        int NodeVal;
        node* next;
        node* prev;
        
        node(int _key, int _val) {
            NodeKey = _key;
            NodeVal = _val;
        }
    };
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    int cap;
    unordered_map<int, node*> m;
    
    LRUCache(int capacity) 
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* newNode)
    {
        node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(node* delNode)
    {
        node* delPrev = delNode->prev;
        node* delNext = delNode->next;
        
        delPrev->next = delNext;
        delNext->prev = delPrev;
        
        // Can't write delete(delNode) as this same node is later getting added.
        // see get function
    }
    
    int get(int key) {
        
        if(m.find(key) != m.end())
        {
            node* resNode = m[key];
            int res = resNode->NodeVal;
            
            deleteNode(resNode);
            addNode(resNode);
            
            m[key] = head->next;
            
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(m.find(key) != m.end())
        {
            // hence updating the value
            node* existingNode = m[key];
            m.erase(key);
            
            deleteNode(existingNode);
        }
        
        if(m.size() == cap)
        {
            // deleting the least recently used node 
            // it would always be present just before tail node
            // most recently used node would always be just after head node
            
            m.erase(tail->prev->NodeKey);
            deleteNode(tail->prev);
        }
        
        addNode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */