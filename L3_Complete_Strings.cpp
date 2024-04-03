//***********************************ASHUTOSH KUMAR***********************************//
/*
कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

Karmanye vadhikaraste Ma Phaleshu Kadachana,
Ma Karmaphalaheturbhurma Te Sangostvakarmani,

The meaning of the verse is :—
You have the right to work only but never to its fruits.
Let not the fruits of action be your motive, nor let your attachment be to
inaction
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *links[26];   // Array of pointers to child nodes, each representing a character (a-z).
    bool flag = false; // Flag to indicate if the node represents the end of a word.

    // Check if the given character is a key in the children nodes.
    bool ContainsKey(char ch)
    {
        return (links[ch - 'a'] != NULL); // Returns true if the link is not NULL.
    }

    // Put a new node at the corresponding index of the character.
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    // Get the node corresponding to the given character.
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    // Mark the node as the end of a word.
    void setEnd()
    {
        flag = true;
    }

    // Check if the node represents the end of a word.
    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root; // Root node of the trie.
public:
    Trie()
    {
        root = new Node(); // Initialize the trie with an empty root node.
    }

    // Insert a word into the trie.
    void insert(string word)
    {
        Node *node = root;
        // Traverse the trie according to the characters in the word.
        for (int i = 0; i < word.size(); i++)
        {
            // If the current character is not a key in the children nodes, create a new node.
            if (!(node->ContainsKey(word[i])))
            {
                node->put(word[i], new Node());
            }
            // Move to the next node.
            node = node->get(word[i]);
        }
        // Mark the last node as the end of the word.
        node->setEnd();
    }

    // Check if there is any word in the trie that starts with the given prefix.
    bool startsWith(string prefix)
    {
        Node *node = root;
        // Traverse the trie according to the characters in the prefix.
        for (int i = 0; i < prefix.size(); i++)
        {
            // If the current character is not a key in the children nodes, no word starts with this prefix.
            if (!(node->ContainsKey(prefix[i])))
            {
                return false;
            }
            // Move to the next node.
            node = node->get(prefix[i]);
            if (node->isEnd() == false)
            {
                return false;
            }
        }
        // At this point, all characters in the prefix exist in the trie.
        // So, there is at least one word that starts with the given prefix.
        return true;
    }
};
string completeString(int n, vector<string> &a)
{
    Trie trie;

    // Step 1:Insert all elements in the trie
    for (auto &it : a)
    {
        trie.insert(it);
    }

    // Step 2: Make a string longest and check for the answer
    string longest = "";

    // Step 3:Iterate over all the values again and check if the prefix exists or not
    for (auto &it : a)
    {
        if (trie.startsWith(it))
        {
            if (it.size() > longest.size())
            {
                longest = it;
            }
            else if (it.size() == longest.size() && it < longest)
            {
                longest = it;
            }
        }
    }

    // Step 4: Return longest string
    return longest;
}
int main()
{
    return 0;
}