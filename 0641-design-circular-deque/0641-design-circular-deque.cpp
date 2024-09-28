class MyCircularDeque {
public:
    int head, tail, sz, mod, arr[1024];
    MyCircularDeque(int k) {
        head=0; tail=0; sz=0; mod=k;
    }
    
    bool insertFront(int value) {
        if(sz == mod) return false;
        head = (head+mod-1) % mod; sz++;
        arr[head] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(sz == mod) return false;
        arr[tail] = value;
        tail = (tail+1) % mod; sz++;
        return true;
    }
    
    bool deleteFront() {
        if(sz == 0) return false;
        head = (head + 1) % mod; sz--;
        return true; 
    }
    
    bool deleteLast() {
        if(sz == 0) return false;
        tail = (tail + mod - 1) % mod; sz--;
        return true;
    }
    
    int getFront() {
        return (sz ? arr[head] : -1);
    }
    
    int getRear() {
        return (sz ? arr[(tail+mod-1) % mod] : -1);
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz == mod;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */