class AllOne {
public:
    map<string, int> cnt;
    set<pair<int, string>> pos, neg;
    AllOne() {
        cnt.clear(); pos.clear(); neg.clear();
    }
    
    void inc(string key) {
        pos.erase({cnt[key], key});
        neg.erase({-cnt[key], key});
        cnt[key]++;
        pos.insert({cnt[key], key});
        neg.insert({-cnt[key], key});
    }
    
    void dec(string key) {
        pos.erase({cnt[key], key});
        neg.erase({-cnt[key], key});
        cnt[key]--;
        if(cnt[key] == 0) return;
        pos.insert({cnt[key], key});
        neg.insert({-cnt[key], key});
    }
    
    string getMaxKey() {
        if(neg.size() == 0) return "";
        return neg.begin()->second;
    }
    
    string getMinKey() {
        if(pos.size() == 0) return "";
        return pos.begin()->second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */