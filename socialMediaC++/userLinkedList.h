//
// Created by Emirhan Kılıç 22203360 on 12/1/2023.
//

#ifndef CS201HW3_USERLINKEDLIST_H
#define CS201HW3_USERLINKEDLIST_H

#include "node.h"
#include "node.cpp"
#include "user.h"

class userLinkedList {
private:
    node<user>* head;
    int size;
public:
    userLinkedList();

    bool addToTheList(const user& inputUser);

    bool removeFromTheList(const int id);

    bool findInTheList(const user& inputUser) const;

    bool findIdInTheList(const int inputId) const;


    void showTheList() const;

    void showTheListOnlyId() const;


    ~userLinkedList();

    int getSize() const;

    user &getUserFromId(const int id) const;


};


#endif //CS201HW3_USERLINKEDLIST_H
