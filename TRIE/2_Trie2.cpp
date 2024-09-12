#include <bits/stdc++.h> 
using namespace std;
struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool flag = false;
    bool containsKey(char ch){
        return links[ch-'a'];
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    void setEnd(){
        flag = true;
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void deletePrefix(){
        cntPrefix--;
    }
    int getEnds(){
        return cntEndWith; 
    }
    int getPrefix(){
        return cntPrefix;
    }
};
class Trie{
    private:
        Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->setEnd();
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getEnds();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->deletePrefix();
            }
            else{
                return ;
            }
        }
        node->deleteEnd();
    }
};
