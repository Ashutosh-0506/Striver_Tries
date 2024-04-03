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
using namespace ::std;
class Node
{
public:
    Node *list[26];       // Array of pointers to child nodes, each representing a character (a-z).
    int countEndWith = 0; // Counter to keep track of the number of words that end at this node.
    int countPrefix = 0;  // Counter to keep track of the number of words that have this node as a prefix.

    // Check if the given character is a key in the children nodes.
    bool containsKey(char ch)
    {
        return (list[ch - 'a'] != NULL);
    }

    // Get the node corresponding to the given character.
    Node *get(char ch)
    {
        return list[ch - 'a'];
    }

    // Put a new node at the corresponding index of the character.
    void put(char ch, Node *node)
    {
        list[ch - 'a'] = node;
    }

    // Increase the count of words that end at this node.
    void increaseEnd()
    {
        countEndWith++;
    }

    // Decrease the count of words that end at this node.
    void decreaseEnd()
    {
        countEndWith--;
    }

    // Increase the count of words that have this node as a prefix.
    void increasePrefix()
    {
        countPrefix++;
    }

    // Decrease the count of words that have this node as a prefix.
    void decreasePrefix()
    {
        countPrefix--;
    }

    // Get the count of words that have this node as a prefix.
    int getPrefix()
    {
        return countPrefix;
    }

    // Get the count of words that end at this node.
    int getEnd()
    {
        return countEndWith;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node(); // Initialize the trie with an empty root node.
    }

    // Insert a word into the trie.
    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!(node->containsKey(word[i])))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix(); // Increase the prefix count for each character encountered.
        }
        node->increaseEnd(); // Mark the last node as the end of a word and increase the count.
    }

    // Count the number of words equal to the given word.
    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!(node->containsKey(word[i])))
            {
                return 0; // If the word is not found, return 0.
            }
            node = node->get(word[i]);
        }
        return node->getEnd(); // Return the count of words that end at the last node.
    }

    // Count the number of words starting with the given prefix.
    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!(node->containsKey(word[i])))
            {
                return 0; // If the prefix is not found, return 0.
            }
            node = node->get(word[i]);
        }
        return node->getPrefix(); // Return the count of words that have this node as a prefix.
    }

    // Erase a word from the trie.
    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!(node->containsKey(word[i])))
            {
                return; // If the word is not found, return.
            }
            node = node->get(word[i]);
            node->decreasePrefix(); // Decrease the prefix count for each character encountered.
        }
        node->decreaseEnd(); // Decrease the count of words that end at the last node.
    }
};

int main()
{
    return 0;
}