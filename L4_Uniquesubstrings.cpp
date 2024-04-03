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
    Node *links[26]; // Array of pointers to child nodes, each representing a character (a-z).

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
};

int countDistinctSubstrings(string &s)
{
    Node *root = new Node();
    int n = s.size();
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        for (int j = i; j < n; j++)
        {
            if (!(node->ContainsKey(s[j])))
            {
                node->put(s[j], new Node());
                count++;
            }
            node = node->get(s[j]);
        }
    }
    return count;
}
int main()
{
    return 0;
}