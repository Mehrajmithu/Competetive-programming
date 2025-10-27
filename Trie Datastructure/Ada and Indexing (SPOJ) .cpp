#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
struct Node{
 
    Node* links[26];
    ll cntwidth=0;
    ll cntPrefix=0;
    
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch, Node* node)
    {
        links[ch-'a']=node;
    }
    void increaseEnd()
    {
        cntwidth++;
        
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    void deleteEnd()
    {
        cntwidth--;
    }
    void reducePrefix()
    {
        cntPrefix--;
    }
    ll getEnd()
    {
        return cntwidth;
    }
    ll getPrefix()
    {
        return cntPrefix;
    }
};
class Trie
{
   private: Node* root;
    public:
    
    Trie(){
        root=new Node();
    }
    void insert(string &word)
    {
        Node* node=root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    ll countWordsEqualTo(string &word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
                
            }
            else
                return 0;
        }
        return node->getEnd();
        
    }
    ll countWordStartsWith(string &word)
    {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node=node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPrefix();
    }
 
 
};
 
int main()
{
    ll n,q;
    cin>>n>>q;
    Trie tr;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        tr.insert(s);
    }
    while(q--)
    {
        string s;
        cin>>s;
        cout<<tr.countWordStartsWith(s)<<endl;
    }
    
} 