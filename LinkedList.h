#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(const T& d): data(d), next(nullptr) {}
};

template <typename T>
class LinkedList {
    Node<T>* head;

public:
    LinkedList(): head(nullptr) {}
    ~LinkedList();

    void push_back(const T& item);
    bool removeById(int id);
    T* findById(int id);
    void clear();
    Node<T>* getHead() const { return head; }
};

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::push_back(const T& item) {
    Node<T>* n = new Node<T>(item);
    if (!head) head = n;
    else {
        Node<T>* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = n;
    }
}

template <typename T>
bool LinkedList<T>::removeById(int id) {
    Node<T>* cur = head;
    Node<T>* prev = nullptr;
    while (cur) {
        if (cur->data.getId() == id) {
            if (prev) prev->next = cur->next;
            else head = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

template <typename T>
T* LinkedList<T>::findById(int id) {
    Node<T>* cur = head;
    while (cur) {
        if (cur->data.getId() == id) return &cur->data;
        cur = cur->next;
    }
    return nullptr;
}


template <typename T>
void LinkedList<T>::clear() {
    Node<T>* cur = head;
    while (cur) {
        Node<T>* nxt = cur->next;
        delete cur;
        cur = nxt;
    }
    head = nullptr;
}

#endif
