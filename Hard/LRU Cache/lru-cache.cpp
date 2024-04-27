//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> cache;

    // Function to move a node to the front of the linked list
    void moveToHead(Node* node) {
        if (node == head) return; // Already at the front

        if (node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        node->next = head;
        node->prev = nullptr;
        head->prev = node;
        head = node;
    }

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) : capacity(cap), head(nullptr), tail(nullptr) {}

    // Function to return value corresponding to the key.
    int GET(int key) {
        if (cache.find(key) == cache.end()) return -1; // Key not found

        Node* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    // Function for storing key-value pair.
    void SET(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key already exists, update its value and move it to the front
            cache[key]->value = value;
            moveToHead(cache[key]);
        } else {
            // Key doesn't exist, create a new node and add it to the front
            Node* newNode = new Node(key, value);
            if (cache.size() >= capacity) {
                // Cache is full, remove the least recently used node (from the end)
                cache.erase(tail->key);
                if (tail == head) {
                    delete tail;
                    head = tail = nullptr;
                } else {
                    tail = tail->prev;
                    delete tail->next;
                    tail->next = nullptr;
                }
            }

            if (!head) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            cache[key] = newNode;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends