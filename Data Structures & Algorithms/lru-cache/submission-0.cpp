class LRUCache {
public:
    struct ListNode {
        int key;
        int val;
        ListNode* next;
        ListNode* prev;

        ListNode(int k, int v) {
            key = k;
            val = v;
            next = nullptr;
            prev = nullptr;
        }
    };

    int cap;
    ListNode* head = NULL;
    ListNode* tail = NULL;

    unordered_map<int, ListNode*> mp;

    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        ListNode* curr = mp[key];

        // Already most recently used
        if (curr == tail) {
            return curr->val;
        }

        // Node is head
        if (curr == head) {
            head = head->next;
            head->prev = NULL;

            tail->next = curr;
            curr->prev = tail;
            curr->next = NULL;

            tail = curr;
        }

        // Node is in the middle
        else {
            ListNode* before = curr->prev;
            ListNode* forward = curr->next;

            before->next = forward;
            forward->prev = before;

            tail->next = curr;
            curr->prev = tail;
            curr->next = NULL;

            tail = curr;
        }

        return curr->val;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {

            ListNode* curr = mp[key];

            // Update value
            curr->val = value;

            // Already at tail
            if (curr == tail) {
                return;
            }

            // If curr is head
            if (curr == head) {
                head = head->next;
                head->prev = NULL;
            }

            // If curr is in middle
            else {
                ListNode* before = curr->prev;
                ListNode* forward = curr->next;

                before->next = forward;
                forward->prev = before;
            }

            // Move curr to tail
            tail->next = curr;
            curr->prev = tail;
            curr->next = NULL;
            tail = curr;

            return;
        }

        // Key doesn't exist
        // If cache is full, remove LRU node
        if (mp.size() == cap) {

            ListNode* q = head;

            // Remove key from map
            mp.erase(q->key);

            // If only one node exists
            if (head == tail) {
                head = NULL;
                tail = NULL;
            }

            else {
                head = head->next;
                head->prev = NULL;
            }

            delete q;
        }

        // Create new node
        ListNode* curr = new ListNode(key, value);

        // If cache is empty
        if (head == NULL) {
            head = curr;
            tail = curr;
        }

        // Add at tail
        else {
            tail->next = curr;
            curr->prev = tail;
            tail = curr;
        }

        mp[key] = curr;
    }
};