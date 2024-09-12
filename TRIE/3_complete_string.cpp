#include <bits/stdc++.h> 
using namespace std;
struct Node{
        Node *links[26];
        bool flag = false;
        bool containsKey(char ch){
            return (links[ch-'a']!=NULL);
        }
        void put(char ch,Node *node){
            links[ch-'a']=node;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
        void setEnd(){
            flag=true;
        }
        bool isEnd(){
            return flag;
        }
};
class Trie {
private: 
    Node* root;
public:
    
    Trie() {
        root = new Node();    
    }
    
    void insert(string word) {
        Node* node = root;
        int n=word.length();
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();

    }
    
    bool search(string word) {
        Node* node = root;
        int n=word.length();
        bool flag = true; 
        for(int i=0;i<n && flag;i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                if(node->isEnd()==false){
                    return false;
                }
            }
            else{
                return false;
            }
            
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto &str:a){
        trie.insert(str);
    }
    string longest="";
    for(auto str:a){
        if(trie.search(str)){
            if(str.length()>longest.length()){
                longest = str;
            }
            else if(str.length()==longest.length() && str<longest){
                longest = str;
            }
        }
    }
    return (longest=="")?"None":longest;
}