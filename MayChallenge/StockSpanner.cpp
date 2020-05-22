class StockSpanner {
    stack<int> *p;
    stack<int> *s;
public:
    StockSpanner() {
        p = new stack<int>();
        s = new stack<int>();
    }
    
    int next(int price) {
        int ans = 1;
        while(!p->empty() && price >= p->top())
        {
            ans += s->top();
            s->pop();
            p->pop();
        }
        s->push(ans);
        p->push(price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
