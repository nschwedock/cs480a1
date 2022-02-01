#ifndef dicctree_H
#define dicttree_H

#define NUM_CHARS 27

#include <string>


class Node{
    public:
        bool isWord;
        Node *children[NUM_CHARS];

        //Node constructor
        Node(){
            isWord = false;
            for (int i = 0; i < NUM_CHARS; i++){
                children[i] = NULL;
            }
        }
};

class Trie{
    private:
        Node root;
    public:
        //Trie constructor which holds a root node
        Trie(){
            root = *(new Node());
        }

        bool addWord(std::string word);

        Node* findEndingNode(std::string word);

        int countWords(Node* node);

};

#endif