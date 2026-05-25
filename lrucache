#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = NULL;
    }
};

class LRUCache {
private:
    int capacity;

    unordered_map<int, Node*> mp;

    Node* head;
    Node* tail;

    // Add node right after head
    void addNode(Node* node) {
        Node* temp = head->next;

        head->next = node;
        node->prev = head;

        node->next = temp;
        temp->prev = node;
    }

    // Remove node from list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int cap) {
        capacity = cap;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];
        int ans = node->value;

        // Move node to front
        deleteNode(node);
        addNode(node);

        return ans;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            Node* existingNode = mp[key];

            deleteNode(existingNode);

            mp.erase(key);
        }

        // Capacity full
        if (mp.size() == capacity) {

            Node* lru = tail->prev;

            deleteNode(lru);

            mp.erase(lru->key);
        }

        Node* newNode = new Node(key, value);

        addNode(newNode);

        mp[key] = newNode;
    }
};

int main() {

    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout << cache.get(1) << endl;

    cache.put(3, 30);

    cout << cache.get(2) << endl;

    return 0;
}
