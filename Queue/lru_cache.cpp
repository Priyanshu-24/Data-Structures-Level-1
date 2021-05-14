class LRUCache {
    
public:
    
    list< pair<int,int> > q;         // list for implementing our cache

    unordered_map<int, list< pair<int,int> >::iterator> m;    // hash for lookup table 
    
    int cache_size;       // cache size used in overflow condition
    
    
    
    LRUCache(int capacity) {
        
        cache_size = capacity;
        
    }
    
    int get(int key) {
        
        if(m.find(key) == m.end())          // if not present 
            return -1;
        
        auto temp = *m[key];          // if present delete it from previous position and add it in the 
        q.erase(m[key]);             // front of the cache
        q.push_front(temp);
        m[key] = q.begin();
        
        return temp.second;
        
        return 0;
        
    }
    
    void put(int key, int value) {
        
       if(m.find(key) != m.end())      // if the key is already present then delete it from its position and place it in front
       {                                // ........ placing at front is done in the end 
           q.erase(m[key]);
       }
        
       if(cache_size == q.size())           // if we enter here, means the size if full and we have to delete the least used one
       {                                   // and delete the it from the lookup table as well
           
           int temp = q.back().first;      // because we want to delete the that key from the lookup table
           q.pop_back();
           m.erase(temp);
       }
        
        q.push_front({key, value});     // make a pair and insert in the front of the list
        m[key] = q.begin();                      //save it in the hash for lookup
        
        
        
    }