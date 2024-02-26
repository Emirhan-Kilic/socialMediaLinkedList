//
// Created by Emirhan Kılıç 22203360 on 12/2/2023.
//

#ifndef CS201HW3_CONTENTLINKEDLIST_H
#define CS201HW3_CONTENTLINKEDLIST_H


#include "userLinkedList.h"
#include "content.h"
class contentLinkedList {
private:
    node<content>* head;
    int size;
public:
    contentLinkedList();

    bool addToTheList(const content& inputContent);

    bool removeFromTheList(const int id);

    bool findInTheList(const content& inputContent) const;

    bool findIdInTheList(const int inputId) const;


    void showTheList() const;

    void showTheListOnlyId() const;


    ~contentLinkedList();

    int getSize() const;

};


#endif //CS201HW3_CONTENTLINKEDLIST_H
