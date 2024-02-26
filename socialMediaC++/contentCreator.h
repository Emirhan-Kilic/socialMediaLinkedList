//
// Created by Emirhan Kılıç 22203360 on 11/29/2023.
//

#ifndef CS201HW3_CONTENTCREATOR_H
#define CS201HW3_CONTENTCREATOR_H


#include "contentLinkedList.h"

class contentCreator {
private:
    int id;
    string name;
    userLinkedList followers;
    contentLinkedList contents;

public:

    contentCreator(int id, const string &name);

    contentCreator();

    const string &getName() const;

    void setName(const string &name);

    int getId() const;

    void setId(int id);

    bool operator<(const contentCreator & contentCreatorInput) const;

    bool addFollower(const int id, const string& name);

    bool removeFollower(const int id);

    bool addContent(const int id, const string &title);

    bool removeContent(const int id);

    void toString();

    void showTheFollowersOnlyId();

    void showTheFollowersWithName();

    void showTheContentsOnlyId();

    virtual ~contentCreator();


};


#endif //CS201HW3_CONTENTCREATOR_H
