class MyCalendar {
public:
    set<pair<int, int>> s, t;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        set<pair<int, int>>::iterator p = s.lower_bound({start, -1e9});
        if(p != s.end() && p->first < end){
            return false;
        }
        p = t.lower_bound({-start, -1e9});
        if(p != t.end() && p->second > start){
            return false;
        }
        s.insert({start, end}); t.insert({-start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */