#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <initializer_list>

// TODO your code goes here:
template<typename T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int nodeCount;

public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        nodeCount = 0;
    }

    LinkedList(std::initializer_list const storeThese){

    }

    ~LinkedList(){
        for (NodeIterator<T> it = begin(); it != end();) {
                NodeIterator<T> temp = it.getNode();
                ++it;
                delete temp;
        }
    }

    void push_front(T data) {
        Node<T>* newHead = new Node<T>(data);
        if (empty()) {
                tail = newHead;
        } else {
                (*head).setPrev(newHead);
                (*newHead).setNext(head);
        }
        head = newHead;
        nodeCount++;
    }

    bool empty() const {
            return nodeCount == 0;
    }

    T front() const {
        return head->data; //the * might be a an &
    }

    void push_back(T const &data) {
        Node<T>* newTail = new Node<T>(data);
        if (empty()) {
                head = newTail;
        } else {
                (*tail).setNext(newTail);
                (*newTail).setPrev(tail);
        }
        tail = newTail;
        nodeCount++;
    }

    T back() const {
        return tail->data; //see front() note
    }

    int size() const {
        return nodeCount;
    }

    NodeIterator<T> begin() const {
        if (head == nullptr) {
                return NULL;
        }
        return NodeIterator<T>(head);
    }

    NodeIterator<T> end() const {
        if (tail == nullptr) {
                return NULL;
        }
        NodeIterator<T> itr = NodeIterator<T>(tail);
        ++itr;
        return itr;
    }
};



// do not edit below this line

#endif
