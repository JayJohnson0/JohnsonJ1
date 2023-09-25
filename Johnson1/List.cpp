#include<iostream>
#include "List.h"
using namespace std;

List::List(const List &old)
{
    Node *oldNodePtr;
    head = nullptr;

    oldNodePtr = old.head;

    while(oldNodePtr != nullptr)
    {
        add(oldNodePtr->element);
        oldNodePtr = oldNodePtr->next;
    }
    return;
}

void List::appendNode(int num)  //adds a node at the end
{
    ListNode * newNode;
    ListNode * nodePtr;


    newNode = new ListNode;    // allocate
    newNode->value = num;      // set value to the number passed in
    newNode->next = nullptr;   // set next value to nullptr


    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        nodePtr = head;


        while(nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }

        nodePtr->next = newNode;
    }

return;
}

void List::insertNode(int num)     //inserts the node in descending order
{
    ListNode *newNode;
    ListNode *nodePtr;
    ListNode *previousNode = nullptr;

    newNode = new ListNode;
    newNode->value = num;

    if(!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else
    {
        nodePtr = head;


        previousNode = nullptr;

        while (nodePtr != nullptr && nodePtr->value > num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if(previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void List::deleteNode(int num)    //deletes the desired node in the list
{
    ListNode *nodePtr;
    ListNode *previousNode;

    if (!head)
        return;     //if there is no values, returns

    if(head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;

        while(nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
            if(nodePtr->value != num)
                cout << "Node not found.";


        if(nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }

    }
}


void List::displayList() const    //displays the list
{
    ListNode *nodePtr;

    nodePtr = head;
    while(nodePtr)
    {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
}

List::~List()
{
    ListNode *nodePtr;
    ListNode *nextNode;

    nodePtr = nextNode = head;
    while(nodePtr)
    {
        nextNode = nodePtr->next;

        delete nodePtr;

        nodePtr = nextNode;
    }
    head = nullptr;

}