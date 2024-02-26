//
// Created by emirh on 12/3/2023.
//

#ifndef CS201HW3_CONTENTCREATORLINKEDLIST_H
#define CS201HW3_CONTENTCREATORLINKEDLIST_H

#include "contentCreator.h"
class contentCreatorLinkedList {
private:
    node<contentCreator> *head;
    int size;
public:
    contentCreatorLinkedList();

    bool addToTheList(const contentCreator& inputcontentCreator);

    bool removeFromTheList(const int id);

    bool findInTheList(const contentCreator& inputcontentCreator) const;

    bool findIdInTheList(const int inputId) const;


    void showTheList() const;

    void showTheListOnlyId() const;

    ~contentCreatorLinkedList();

    int getSize() const;

    bool addContentToId(const int contentCreatorId, const int contentId, const string& title );

    bool removeContentFromId( const int contentCreatorId, const int contentId );

    bool addFollowerToId(const int id, const string& name, const int contentCreatorId);

    bool removeFollowerToId(const int regularUserId, const int contentCreatorId);

    void showContentOfCreator(const int id) const;

    void showFollowerOfCreator(const int id) const;

    void removeUserFromEveryContentCreator(const int id);


};


#endif //CS201HW3_CONTENTCREATORLINKEDLIST_H
