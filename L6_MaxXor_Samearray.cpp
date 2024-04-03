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


//Leetcode


#include <bits/stdc++.h>
using namespace ::std;
// Node class representing a node in the Trie data structure
class Node
{
private:
    Node *links[2]; // Links to child nodes, assuming binary numbers (0 and 1)

public:
    // Check if the node contains a child node for a given bit (0 or 1)
    bool ContainsKey(int bit)
    {
        return links[bit] != NULL;
    }

    // Get the child node for a given bit (0 or 1)
    Node *get(int bit)
    {
        return links[bit];
    }

    // Put a child node for a given bit (0 or 1)
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};

// Trie class implementing a Trie data structure for XOR operations
class Trie
{
private:
    Node *root; // Root node of the Trie

public:
    // Constructor to initialize the Trie with an empty root node
    Trie()
    {
        root = new Node();
    }

    // Insert a number into the Trie
    void insert(int num)
    {
        Node *node = root;
        // Traverse through each bit of the number from left to right
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1; // Extract the i-th bit of the number
            // If the node doesn't have a child for the current bit, create one
            if (!(node->ContainsKey(bit)))
            {
                node->put(bit, new Node());
            }
            // Move to the child node corresponding to the current bit
            node = node->get(bit);
        }
    }

    // Find the maximum XOR of a number with any number present in the Trie
    int maxXor(int num)
    {
        Node *node = root;
        int maxx = 0; // Initialize the maximum XOR result
        // Traverse through each bit of the number from left to right
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1; // Extract the i-th bit of the number
            // If there is a different bit in the Trie for the current bit, update the maximum XOR result
            if (node->ContainsKey(1 - bit))
            {
                maxx = maxx | (1 << i);    // Update the maximum XOR result
                node = node->get(1 - bit); // Move to the child node with the different bit
            }
            else
            {
                node = node->get(bit); // Move to the child node with the same bit
            }
        }
        return maxx; // Return the maximum XOR result
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        // Initialize a trie
        Trie trie;

        // Check for maxx answer
        int maxx = 0;

        // Insert all elements in the trie
        for (auto &it : nums)
        {
            trie.insert(it);
        }

        // Check for the max xorr acorss all the elements
        for (auto &it : nums)
        {
            maxx = max(maxx, trie.maxXor(it));
        }

        // Return answer
        return maxx;
    }
};
int main()
{
    return 0;
}