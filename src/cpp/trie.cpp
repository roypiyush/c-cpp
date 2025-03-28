#include <iostream>
#include <string>
#include <vector>

class Trie
{
private:
    struct TrieNode
    {
        std::vector<TrieNode *> children;
        bool isEndOfWord;

        TrieNode() : children(26, nullptr), isEndOfWord(false) {}

        ~TrieNode()
        {
            for (TrieNode *child : children)
            {
                delete child;
            }
        }
    };

    TrieNode *root;

public:
    Trie() : root(new TrieNode()) {}

    ~Trie()
    {
        std::cout << "Deleting Constructor" << std::endl;
        delete root;
    }

    void insert(std::string word)
    {
        TrieNode *current = root;

        for (char c : word)
        {
            int index = c - 'a';
            if (current->children[index] == NULL)
            {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }

        current->isEndOfWord = true;
    }

    bool search(std::string word)
    {
        TrieNode *current = root;
        for (char c : word)
        {

            int index = c - 'a';

            if (current->children[index])
            {
                current = current->children[index];
            }
        }

        return current != NULL && current->isEndOfWord;
    }

    bool startsWith(std::string prefix)
    {
        TrieNode *current = root;
        for (char c : prefix)
        {
            int index = c - 'a';
            if (!current->children[index])
            {
                return false;
            }
            current = current->children[index];
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("banana");
    std::cout << std::boolalpha;
    std::cout << trie.search("banana") << std::endl;
    std::cout << trie.search("bana") << std::endl;
    std::cout << trie.startsWith("ban") << std::endl;
    trie.insert("bangles");
    std::cout << trie.search("bangles") << std::endl;

    return 0;
}