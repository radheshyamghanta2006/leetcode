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
        if(mp.find(key)!=mp.end()){
            s.push_front(key);
            s.erase(mp[key].first);
            mp[key].first = s.begin();
            mp[key].second = value;
            return;
        }
        if(l==c){
            s.push_front(key);
            mp[key].first =s.begin();
             mp[key].second =value;
             mp.erase(s.back());
             s.pop_back();
             return;
        }else if(l<c){
             s.push_front(key);
            mp[key].first =s.begin();
             mp[key].second =value;
             l++;
        }
    }
};
