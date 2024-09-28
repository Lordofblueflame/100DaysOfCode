#include <memory>

class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        m_size = k;
        m_item_count = 0;
        m_array = std::make_unique<int[]>(m_size);
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        
        // Shift all elements one place to the right
        for (int i = m_item_count - 1; i >= 0; --i) {
            m_array[i + 1] = m_array[i];
        }

        m_array[0] = value;
        ++m_item_count;
        
        updateFrontAndLast();

        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        m_array[m_item_count] = value;
        ++m_item_count;

        updateFrontAndLast();

        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        // Shift all elements one place to the left
        for (int i = 0; i < m_item_count - 1; ++i) {
            m_array[i] = m_array[i + 1];
        }

        --m_item_count;

        updateFrontAndLast();

        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        --m_item_count;

        updateFrontAndLast();

        return true;
    }
    
    int getFront() {
        if (isEmpty()) {
            return -1;
        }

        return m_array[0];
    }
    
    int getRear() {
        if (isEmpty()) {
            return -1;
        }

        return m_array[m_item_count - 1];
    }
    
    bool isEmpty() {
        return m_item_count == 0;
    }
    
    bool isFull() {
        return m_item_count == m_size;
    }

private:
    int m_item_count;
    int m_size;
    std::unique_ptr<int[]> m_array;
    std::unique_ptr<int> m_front;
    std::unique_ptr<int> m_last;

    void updateFrontAndLast() {
        if (isEmpty()) {
            m_front.reset();
            m_last.reset();
        } else {
            m_front = std::make_unique<int>(m_array[0]);
            m_last = std::make_unique<int>(m_array[m_item_count - 1]);
        }
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