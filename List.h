#pragma once
#include <exception>
#include <stdexcept>
 
template <typename T>
class List
{
private:
   
    struct Node
    {
        explicit Node(T value) noexcept
            : value(value), next(nullptr), prev(nullptr) {}

        T value;      
        Node* next;    
        Node* prev;    
    };
 
    Node* head;       
    Node* tail;        
    size_t listSize;   
 
public:
   
    List() noexcept
        : head(nullptr), tail(nullptr), listSize(0) {}


    ~List()
    {
        
        while (head != nullptr)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }
 
   
    size_t size() const noexcept
    {
        return listSize; 
    }
 
    
    void pushFront(T value)
    {
        Node* newNode = new Node(value); 
        newNode->next = head;         

        if (head != nullptr)
            head->prev = newNode;      
        else
            tail = newNode;             
        
        head = newNode;               
        ++listSize;                    
    }
};
