#include <unordered_map>
#include <limits>
#include <string>

class AllOne {
public:
    AllOne() {
        maxCount = 0;
        minCount = std::numeric_limits<int>::max();
    }

private:
    std::unordered_map<std::string, int> stringCount;
    std::string maxKey;
    std::string minKey;
    int maxCount;
    int minCount;

public:
    void inc(const std::string& key) {
        int newCount = ++stringCount[key];

        if (newCount >= maxCount) {
            maxCount = newCount;
            maxKey = key;
        }

        if (newCount == 1 || newCount < minCount) {
            minCount = newCount;
            minKey = key;
        }
        recalculateMaxMin();
    }

    void dec(const std::string& key) {
        int newCount = --stringCount[key];

        if (newCount == 0) {
            stringCount.erase(key);

            recalculateMaxMin();
        } else {
            if (newCount < minCount) {
                minCount = newCount;
                minKey = key;
            }
            if (newCount >= maxCount) {
                maxCount = newCount;
                maxKey = key;
            }
            recalculateMaxMin();
        }
    }

    std::string getMaxKey() const {
        return maxCount > 0 ? maxKey : "";
    }

    std::string getMinKey() const {
        return minCount < std::numeric_limits<int>::max() ? minKey : "";
    }

private:

    void recalculateMaxMin() {
        maxCount = 0;
        minCount = std::numeric_limits<int>::max();
        maxKey = "";
        minKey = "";

        for (const auto& pair : stringCount) {
            if (pair.second > maxCount) {
                maxCount = pair.second;
                maxKey = pair.first;
            }
            if (pair.second < minCount) {
                minCount = pair.second;
                minKey = pair.first;
            }
        }
    }
};
