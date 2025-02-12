#include <bits/stdc++.h>
using namespace std;

// Define the node structure for the Trie
struct node {
    bool endmark;         // Marks the end of a word
    node* next[26];       // Pointers for each letter 'a' to 'z'

    // Constructor to initialize a new node
    node() {
        endmark = false;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

// Root of the Trie
node* root;

// Function to insert a word into the Trie
void insert(const string& str) {
    node* curr = root;
    for (char ch : str) {
        int id = ch - 'a';       // Map character to index (0 to 25)
        if (curr->next[id] == NULL) {
            curr->next[id] = new node(); // Create a new node if not already present
        }
        curr = curr->next[id];
    }
    curr->endmark = true;        // Mark the end of the word
}

// Function to search for a word in the Trie
bool search(const string& str) {
    node* curr = root;
    for (char ch : str) {
        int id = ch - 'a';
        if (curr->next[id] == NULL) {
            return false;        // Word not found
        }
        curr = curr->next[id];
    }
    return curr->endmark;        // Check if it's the end of a valid word
}

// Function to destroy the Trie (free memory)
void del(node* cur) {
    for (int i = 0; i < 26; i++) {
        if (cur->next[i]) {
            del(cur->next[i]);   // Recursively delete child nodes
        }
    }
    delete cur;                  // Delete current node
}

int main() {
    cout << "ENTER NUMBER OF WORDS:" << endl;
    root = new node();           // Initialize the root of the Trie

    int num_word;
    cin >> num_word;
    cout << "ENTER THE WORDS:" << endl;
    for (int i = 0; i < num_word; i++) {
        string str;
        cin >> str;
        insert(str);
    }

    cout << "ENTER NUMBER OF QUERIES:" << endl;
    int query;
    cin >> query;
    cout << "ENTER THE QUERY WORDS:" << endl;
    for (int i = 0; i < query; i++) {
        string str;
        cin >> str;
        if (search(str)) {
            cout << "FOUND" << endl;
        } else {
            cout << "NOT FOUND" << endl;
        }
    }

    del(root);                   // Destroy the Trie to free memory
    return 0;
}
