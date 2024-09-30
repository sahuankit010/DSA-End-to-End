//
// Created by Ankit Sahu on 9/28/24.
//

#include<iostream>


using namespace  std;

class Trie{

    class TrieNode{
    public:
        bool isEndOfWord;
        TrieNode *children[26];


        TrieNode(){
            this->isEndOfWord = false;
            for(int i=0; i<26; i++){
                this->children[i] = nullptr;
            }
        }
    };

public:
    TrieNode *root;

    Trie(){
        this->root = new TrieNode();
    }

    void insert(string str){
        TrieNode *node = root;
        for(char &ch: str){
            int index = ch-'a'; // all are English lowercase letters

            if(node->children[index] == nullptr){
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }

        node->isEndOfWord = true;
    }

    bool search(string &str){
        TrieNode *node = root;

        for(char &ch: str){
            int index = ch-'a';

            if(!node->children[index]) return false;
            node = node->children[index];
        }

        if(node != nullptr && node->isEndOfWord == false) return false;
        return true;
    }

    bool startsWith (string str){
        TrieNode* node = root;

        for(char &ch: str){
            int index = ch-'a';

            if(!node->children[index]) return false;

            node = node->children[index];
        }

        return true;
    }
};

int main(){
    Trie obj;
    cout<<"Hello\n";
    obj.insert("apple");       // Insert a word into the Trie
    bool param_2 = obj.search("apple"); // Check if the word exists in the Trie
    bool param_3 = obj.startsWith("app"); // Check if any word starts with the given prefix
    cout<<param_2<<" "<<param_3;
    return 0;
}