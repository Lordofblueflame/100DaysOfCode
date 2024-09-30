#include <vector>
#include <algorithm>

class CustomStack {
public:
    CustomStack(int maxSize) {
        top = 0;
        m_stack.resize(maxSize);
    }
    
    void push(int x) {
        if(top == m_stack.size())
            return;
        
        m_stack[top] = x;
        top++;
    }
    
    int pop() {
        if (top == 0) {
            return -1;
        }
        top--;
        return m_stack[top];
    }
    
    void increment(int k, int val) {
        if (val == 0 || k <= 0) {
            return;
        }

        k = std::min(k, top);

        for (int i = 0; i < k; i++) {
            m_stack[i] += val;
        }
    }

private:
    int top;
    std::vector<int> m_stack;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */