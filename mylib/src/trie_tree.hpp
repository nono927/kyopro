#include <vector>
#include <string>

class TrieTree {
    struct Node {
        char c;
        std::vector<int> nexts;
        bool is_string;

        Node(): c('\0'), nexts(std::vector<int>(26)), is_string(false) {}
        Node(char c): c(c), nexts(std::vector<int>(26)), is_string(false) {}
    };
    std::vector<Node> nodes;

public:
    TrieTree() : nodes(std::vector<Node>(1)) {}

    void add(std::string &s) {
        int index = 0;
        for (auto &c : s) {
            Node &node = this->nodes[index];
            if (node.nexts[c-'a']) {
                index = node.nexts[c-'a'];
            } else {
                index = this->nodes.size();
                node.nexts[c-'a'] = index;
                this->nodes.emplace_back(c);
            }
        }
        this->nodes[index].is_string = true;
    }

    bool find(std::string &s) {
        int index = 0;
        for (auto &c : s) {
            index = this->nodes[index].nexts[c-'a'];
            if (!index) return false;
        }
        return this->nodes[index].is_string;
    }
};
