#pragma once
#include <iostream>
#include <cstdint>

using namespace std;

template <typename T>

struct Node
{
public:
    T info;
    Node<T>* next = nullptr;
    Node() {}
    Node(T value) : info(value) {}
    Node(T value, Node<T>* nod) : info(value), next(nod) {}

    bool operator<(const Node<T>& other) const
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
    ~cstack();
    T top();

    void operator *= (T c)
    {
        Node<T>* node = ptop;
        while (node) {
            node->info *= c;
            node = node->next;
        }
    }

    int operator [](int c)
    {
        Node<T>* node = ptop;
        for (int i = 0; i < c; i++) {
            node = node->next;
        }
        return node->info;

    }

    cstack& operator=(const cstack& other)
    {
        if (this != &other) {
            clear();

            Node<T>* current = other.ptop;
            Node<T>* previous = nullptr;

            while (current) {
                Node<T>* newNode = new Node<T>(current->info);
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
};

template <typename T>

cstack<T>::cstack()
{
    ptop = NULL;
}

template <typename T>

bool cstack<T>::empty()
{
    return ptop == nullptr;
}

template <typename T>

void cstack<T>::pop()
{
    Node<T>* temp;
    if (empty())
    {
    }
    else
    {
        temp = ptop;
        ptop = ptop->next;
        free(temp);
    }
}

template <typename T>

void cstack<T>::push(T val)
{
    Node<T>* temp = new Node<T>(val);
    temp->info = val;
    temp->next = ptop;
    ptop = temp;
}

template <typename T>

void cstack<T>::display()
{
    Node<T>* temp;
    if (ptop == NULL) {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = ptop;
        while (temp != NULL)
        {
            cout << temp->info;
            temp = temp->next;
            if (temp != NULL)
                cout << " ";
        }
    }
}

template <typename T>

T cstack<T>::top()
{
    if (ptop)
    {
        return ptop->info;
    }

    return 0;
}

template <typename T>

void cstack<T>::clear()
{
    if (empty())
    {
        while (ptop != nullptr)
        {
            pop();
        }
    }

}

template <typename T>

cstack<T>::~cstack()
{
    clear();
}