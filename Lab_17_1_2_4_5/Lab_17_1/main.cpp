//
//  main.cpp
//  Lab_17_1
//
//  Created by Joe McIlhargey on 5/28/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>

using namespace std;

class IntList {
private:
    struct ListNode {
        int value;
        struct ListNode *next;
    };
    ListNode *head;
public:
    IntList();
    void appendNode(int );
    void insertNode(int );
    void deleteNode(int );
    void displayList();
    void destroyList();
    void reverseList();
    int searchList(int );
};

IntList::IntList() {
    head = nullptr;
}

void IntList::appendNode(int num) {
    
    ListNode *newNode;
    ListNode *nodePtr;
    
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;
    
    if (!head) {
        head = newNode;
    } else {
        nodePtr = head;
        
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void IntList::insertNode(int num) {

    ListNode *newNode;
    ListNode *nodePtr;
    ListNode *previousNode;
    
    newNode = new ListNode;
    newNode->value = num;
    
    if (!head) {
        head = newNode;
        newNode->next = nullptr;
    } else {
        
        nodePtr = head;
        previousNode = nullptr;
        
        while (nodePtr != nullptr && nodePtr->value < num) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (previousNode == nullptr) {
            head = newNode;
        } else {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void IntList::deleteNode(int num) {
    
    ListNode *nodePtr;
    ListNode *previousNode;
    
    if (!head) {
        return;
    }
    if (head->value == num) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    } else {
        
        nodePtr = head;
        previousNode = nullptr;
        
        while (nodePtr && nodePtr->value != num) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr) {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

void IntList::displayList() {

    ListNode *nodePtr;
    
    nodePtr = head;
    
    while (nodePtr) {
        cout << nodePtr->value << endl;
        
        nodePtr = nodePtr->next;
    }
}

void IntList::destroyList() {

    ListNode *nodePtr;
    ListNode *nextNode;
    
    nodePtr = head;
        
    while (nodePtr) {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void IntList::reverseList() {
    
    ListNode *nodePtr;
    ListNode *previousNode = nullptr;
    ListNode *nextNode;
    
    nodePtr = head;
    
    while (nodePtr) {
        
        nextNode = nodePtr->next;
        nodePtr->next = previousNode;
        previousNode = nodePtr;
        nodePtr = nextNode;
    }
    head = previousNode;
}

int IntList::searchList(int num) {

    ListNode *nodePtr;
    
    int position = -1;
    bool found = false;
    
    nodePtr = head;
    
    while (nodePtr && !found) {
        
        position++;
        
        if (nodePtr->value == num) {
            found = true;
        }
        nodePtr = nodePtr->next;
    }
    return found ? position : -1;
}

int main() {
    
    IntList ourList;
    
    ourList.appendNode(1);
    ourList.appendNode(4);
    ourList.appendNode(5);
    ourList.appendNode(7);
    
    ourList.insertNode(6);
    ourList.insertNode(2);
    
    ourList.deleteNode(4);
    
    ourList.reverseList();
    
    cout << "Displaying reversed list: " << endl;
    ourList.displayList();
    
    cout << "Searching for position of value: " << endl;
    cout << ourList.searchList(2) << endl;
    
    return 0;
}
