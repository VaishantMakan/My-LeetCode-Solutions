class LRUCache {
public:
    
    class node{
      public: 
        int k;
        int v;
        
        node* next;
        node* prev;
        
        node(int key, int val)
        {
            k = key;
            v = val;
        }
        
    };
    
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    
    int cap;
    
    unordered_map<int, node*>mp;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node* newNode)
    {
        node* nextNode = head->next;
        
        head->next = newNode;
        newNode->prev = head;
        
        newNode->next = nextNode;
        nextNode->prev = newNode;
    }
    
    void deleteNode(node* delNode)
    {
        node* prevNode = delNode->prev;
        node* nextNode = delNode->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    
    int get(int key) {
        //if it doesn't exist in the map
        if(mp.find(key) == mp.end())
        {
            return -1;
        }
        
        // if exists
        node* resNode = mp[key];
        int res = resNode->v;
        
        //delete 
        mp.erase(key);
        deleteNode(resNode);
        
        //add
        addNode(resNode);
        mp[key] = head->next;
        
        return res;
    }
    
    void put(int key, int value) {
        //check if already exists in the map
        if(mp.find(key) != mp.end())
        {
            //update 
            node* resNode = mp[key];
            resNode->v = value;
            
            //delete
            mp.erase(key);
            deleteNode(resNode);
            
            //add
            addNode(resNode);
            mp[key] = head->next;
        }
        
        //check if capacity full
        else if(mp.size() == cap)
        {
            //delete LRU 
            node* lruNode = tail->prev;
            mp.erase(tail->prev->k);
            deleteNode(lruNode);
            
            //make new Node
            node* newNode = new node(key, value);
            
            //add
            addNode(newNode);
            mp[key] = head->next;
        }
        else
        {
            //make new Node
            node* newNode = new node(key, value);
            
            //add
            addNode(newNode);
            mp[key] = head->next;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */