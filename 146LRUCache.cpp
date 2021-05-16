class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node *pre;
        Node *next;

        Node() {}

        Node(int key, int value) : key(key), value(value) {
            pre = nullptr;
            next = nullptr;
        }
    };

    void move2Head(Node *node) {
        removeNode(node);
        add2Head(node);
    }

    void add2Head(Node *node) {
        Node *temp = head->next;
        head->next = node;
        node->next = temp;
        temp->pre = node;
        node->pre = head;
    }


    void removeNode(Node *node) {
        node->next->pre = node->pre;
        node->pre->next = node->next;
    }

    Node *removeTail() {
        Node *node = tail->pre;
        removeNode(node);
        return node; //防止内存泄露
    }


public:
    unordered_map<int, Node *> map;
    Node *head;
    Node *tail;
    int size;

    LRUCache(int capacity) {
        size = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        Node *node = map[key];
        move2Head(node);
        return node->value;
    }

    void put(int key, int value) {
        Node *node;
        if (map.find(key) == map.end()) { //不存在
            node = new Node(key, value);
            map[key] = node;
            add2Head(node);
            if (size < map.size()) {
                Node *remove = removeTail();
                map.erase(remove->key);
                delete remove;
            }
        } else {
            node = map[key];
            node->value = value;
            move2Head(node);
        }

    }

};