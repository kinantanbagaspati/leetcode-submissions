class CustomStack {
public:
    int isi[1024], curn, n;
    CustomStack(int maxSize) {
        n = maxSize;
        curn = 0;
    }
    
    void push(int x) {
        if(curn < n){
            isi[curn] = x; curn++;
        }
    }
    
    int pop() {
        if(!curn) return -1;
        curn--; 
        return isi[curn];
    }
    
    void increment(int k, int val) {
        for(int i=0; i<k && i<curn; i++) isi[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */