class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int,int> map;
    vector<int> value;
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val) == map.end()) //not present
        {
            int index = value.size();
            value.push_back(val);
            map[val] = index;
            return true;
        }
        return false; 
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val) != map.end()) //already present
        {
            int remIndex = map[val];
            swap(value[remIndex],value[value.size()-1]);
            value.pop_back();
            map[value[remIndex]] = remIndex;
            map.erase(val);
            return true;
        }   
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        
        return value[rand()%value.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
