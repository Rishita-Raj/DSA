class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* node = root;

        for (int bit = 31; bit >= 0; bit--) {
            int currentBit = (num >> bit) & 1;

            if (!node->child[currentBit]) {
                node->child[currentBit] = new TrieNode();
            }

            node = node->child[currentBit];
        }
    }

    int getMaxXor(int num) {
        TrieNode* node = root;
        int xorValue = 0;

        for (int bit = 31; bit >= 0; bit--) {

            int currentBit = (num >> bit) & 1;
            int oppositeBit = 1 - currentBit;

            if (node->child[oppositeBit]) {
                xorValue |= (1 << bit);
                node = node->child[oppositeBit];
            } else {
                node = node->child[currentBit];
            }
        }

        return xorValue;
    }

    int findMaximumXOR(vector<int>& nums) {

        for (int num : nums) {
            insert(num);
        }

        int answer = 0;

        for (int num : nums) {
            answer = max(answer, getMaxXor(num));
        }

        return answer;
    }
};