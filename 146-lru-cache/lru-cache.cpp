class LRUCache {
public:
    int c;
    list<int>s;
    int l;
    unordered_map<int,pair< list<int>::iterator ,int>>mp;
    LRUCache(int capacity) {
       c=capacity;  
       l=0;  
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        s.push_front(key);
        s.erase(mp[key].first);
        mp[key].first = s.begin();
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Key exists: erase old position and update
            s.erase(mp[key].first);
        } 
        else if (s.size() == c) {
            // Cache is full: remove least recently used (back)
            int oldKey = s.back();
            s.pop_back();
            mp.erase(oldKey);
        }

        // Insert the new key at front
        s.push_front(key);
        mp[key] = {s.begin(), value};
    }
};
