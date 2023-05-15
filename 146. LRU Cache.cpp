class Node {
public:
    Node* next;
    Node* prev;
    int key;
    int data;
    Node (int key, int data) {
        this->key = key;
        this->data = data;
    }
};

class LRUCache {
    int cap;
    Node* head = new Node (-1, -1);
    Node* tail = new Node (-1, -1);
    unordered_map<int, Node*> um;

    void removeKey (Node* node) {
        Node* next = node->next;
        Node* prev = node->prev;
        next->prev = prev;
        prev->next = next;
    }
    void addKey (Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        head->prev = tail->next = nullptr;
        tail->prev = head;
    }
    
    int get(int key) {
        if (um.find(key) == um.end()) {
            return -1;
        }
        Node* node = um[key];
        int retData = node->data;
        removeKey (node);
        addKey (node);
        um.erase(key);
        um[key] = head->next;
        return retData;
    }
    
    void put(int key, int value) {
        if (um.find(key) != um.end()) {
            Node* node = um[key];
            um.erase (key);
            removeKey (node);
        }
        if (um.size() == cap) {
            Node* node = tail->prev;
            removeKey (node);
            um.erase (node->key);
        }
        addKey(new Node(key, value));
        um[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
