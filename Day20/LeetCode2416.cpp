#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int count = 0;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count += 1;
        }
    }

    int calculatePrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            node = node->children[c];
            score += node->count;
        }
        return score;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        for (const string& word : words) {
            trie.insert(word);
        }  

        vector<int> result;
        for (const string& word : words) {
            result.push_back(trie.calculatePrefixScore(word));
        }

        return result; 
    }
};