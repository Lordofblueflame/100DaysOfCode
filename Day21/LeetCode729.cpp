#include <set>
#include <utility>

class MyCalendar {
private:
    std::set<std::pair<int,int>> bookedTime; 
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (const auto& [bookedStart, bookedEnd] : bookedTime) {
            if (!(end <= bookedStart || start >= bookedEnd)) {
                return false;  
            }
        }

        bookedTime.insert(std::make_pair(start, end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */