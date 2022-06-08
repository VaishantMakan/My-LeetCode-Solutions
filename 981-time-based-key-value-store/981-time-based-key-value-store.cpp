class TimeMap {
public:
    
    unordered_map<string, vector<pair<int, string>>>m;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        if(!m.count(key))
            return "";
        
        int start=0, end=m[key].size()-1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            if(m[key][mid].first > timestamp)
                end = mid-1;
            else if(m[key][mid].first < timestamp)
                start = mid+1;
            else
                return m[key][mid].second;
        }
        
        return end >=0 ? m[key][end].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */