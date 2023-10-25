#include <iostream>
#include "cstack.h"

using namespace std;

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
    Node* temp = new Node(val);
    temp->info = val;
    temp->next = ptop;
    ptop = temp;
}

template <typename T>

void cstack<T>::display()
{
    Node* temp;
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