#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

class TrieNode {
public:
    std::unordered_map<std::string, TrieNode*> children;
    bool isEnd;
    TrieNode() : isEnd(false) {}
};

class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        TrieNode* root = new TrieNode();

        for (const std::string& path : folder) {
            insert(root, path);
        }

        std::vector<std::string> result;
        dfs(root, "", result);
        
        return result;
    }

private:
    void insert(TrieNode* root, const std::string& path) {
        TrieNode* current = root;
        std::stringstream ss(path);
        std::string folder;

        while (getline(ss, folder, '/')) {
            if (folder.empty()) continue;
            
            if (current->isEnd) return;
            
            if (!current->children.count(folder)) {
                current->children[folder] = new TrieNode();
            }
            current = current->children[folder];
        }
        current->isEnd = true;
    }

    void dfs(TrieNode* node, std::string path, std::vector<std::string>& result) {
        if (node->isEnd) {
            result.push_back(path);
            return;
        }
        
        for (auto& [name, child] : node->children) {
            dfs(child, path + "/" + name, result);
        }
    }
};
