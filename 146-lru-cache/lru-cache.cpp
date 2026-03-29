class Node {
public:
    int key;
    int val;
    Node *prev, *next;

    Node(int k, int v) {
        key = k;
        val = v;
        next = prev = NULL;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }
    void remove(Node* node) {
        Node* prevnode = node->prev;
        Node* nextnode = node->next;

        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }
    void addatfront(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        Node* node = mp[key];
        remove(node);
        addatfront(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];
            temp->val = value;
            remove(temp);
            addatfront(temp);
            return;
        } else {
            if (mp.size() == cap) {
                Node* lru = tail->prev;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* newnode = new Node(key, value);
            addatfront(newnode);
            mp[key] = newnode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */