#pragma once
#include <iostream>
#include <cstdint>

template <typename T>

struct Node
{
    T info;
    Node<T>* next = nullptr;
    Node() {}
    Node(T value) : info(value) {}
    Node(T value, Node* nod) : info(value), next(nod) {}

    bool operator<(const Node& other) const
    {
        return this->info < other.info;
    }
};

template <typename T>

class cstack
{
    Node<T>* ptop;
    void clear();

public:
    cstack();
    void pop();
    void push(T val);
    bool empty();
    void display();

    void operator *= (T c)
    {
        Node* node = ptop;
        while (node) {
            node->info *= c;
            node = node->next;
        }
    }

    int operator [](int c)
    {
        Node* node = ptop;
        for (int i = 0; i < c; i++) {
            node = node->next;
        }
        return node->info;

    }

    cstack& operator=(const cstack& other)
    {
        if (this != &other) {
            clear();

            Node* current = other.ptop;
            Node* previous = nullptr;

            while (current) {
                Node* newNode = new Node(current->info);
                if (!ptop) {
                    ptop = newNode;
                }
                else {
                    previous->next = newNode;
                }
                previous = newNode;

                current = current->next;
            }
        }
        return *this;
    }

    ~cstack();
    T top();
};