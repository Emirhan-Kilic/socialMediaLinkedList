//
// Created by Emirhan Kılıç 22203360 on 11/29/2023.
//

#include "contentCreator.h"


const string &contentCreator::getName() const {
    return this->name;
}

void contentCreator::setName(const string &name) {
    this->name = name;
}

int contentCreator::getId() const {
    return this->id;
}

void contentCreator::setId(int id) {
    this->id = id;
}

contentCreator::contentCreator(int id, const string &name) : id(id), name(name) {
    followers = userLinkedList();
    contents = contentLinkedList();

}

bool contentCreator::operator<(const contentCreator &contentCreatorInput) const {
    if (this->id < contentCreatorInput.id) {
        return true;
    } else {
        return false;
    }
}

bool contentCreator::addFollower(const int id, const string& name) {

    bool result = this->followers.addToTheList(user(id,name));
    return result;
}

bool contentCreator::removeFollower(const int id) {

    bool result = this->followers.removeFromTheList(id);
    return result;
}

bool contentCreator::addContent(const int idContent, const string& titleContent) {
    bool result = this->contents.addToTheList(content(titleContent,idContent));
    return result;
}

bool contentCreator::removeContent(const int id) {
    bool result = this->contents.removeFromTheList(id);
    return result;

}

void contentCreator::toString() {

    cout << this->getId() << ", " << this->getName() << ", " << this->followers.getSize() << " follower(s), "
         << this->contents.getSize() << " content(s)" << endl;

}

void contentCreator::showTheFollowersOnlyId() {
    cout << "Regular users following content creator with ID " << this->getId() << ":" << endl;

    if (this->followers.getSize() != 0) {
        this->followers.showTheListOnlyId();

    } else {
        cout << "None" << endl;
    }

}

void contentCreator::showTheContentsOnlyId() {
    cout << "Contents of content creator with ID " << this->getId() << ":" << endl;
    if (this->contents.getSize() != 0) {
        this->contents.showTheListOnlyId();
    } else {
        cout << "None" << endl;

    }


}

void contentCreator::showTheFollowersWithName() {
    cout << "Regular users following content creator with ID " << this->getId() << ":" << endl;

    if (this->followers.getSize() != 0) {
        this->followers.showTheList();

    } else {
        cout << "None" << endl;
    }
}

contentCreator::~contentCreator() = default;

contentCreator::contentCreator() = default;


