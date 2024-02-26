//
// Created by emirh on 12/3/2023.
//

#include "contentCreatorLinkedList.h"

contentCreatorLinkedList::contentCreatorLinkedList() {

    this->head = nullptr;
    this->size = 0;

}


bool contentCreatorLinkedList::addToTheList(const contentCreator &inputContentCreator) {
    node<contentCreator> *inputNode = new node<contentCreator>(inputContentCreator);

    if (this->head == nullptr) {

        head = inputNode;
        this->size++;

        return true;

    } else {

        if (!findIdInTheList(inputContentCreator.getId())) {
            bool inserted = false;
            node<contentCreator> *iterator = this->head;

            if (inputNode->getDt() < head->getDt()) {

                inputNode->setNextNode(head);
                head = inputNode;
                this->size++;
                return true;

            } else {
                while (iterator->getNextNode() != nullptr) {

                    if ((iterator->getDt() < inputNode->getDt()) &&
                        (inputNode->getDt() < iterator->getNextNode()->getDt()))  {

                        inputNode->setNextNode(iterator->getNextNode());
                        iterator->setNextNode(inputNode);
                        inserted = true;
                        this->size++;

                        return true;

                    }

                    iterator = iterator->getNextNode();
                }
                if (!inserted) {
                    iterator->setNextNode(inputNode);
                    this->size++;
                    return true;
                }
            }
        } else {
            delete inputNode;
            inputNode = nullptr;
            return false;
        }

        return false;
    }
}


bool contentCreatorLinkedList::findInTheList(const contentCreator &inputcontentCreator) const {

    if (this->head != nullptr) {

        node<contentCreator> *iterator = this->head;
        do {
            if (iterator->getDt().getId() == inputcontentCreator.getId()) {
                return true;
            }
            iterator = iterator->getNextNode();
        } while (iterator != nullptr);

        return false;
    }
    return false;
}

void contentCreatorLinkedList::showTheList() const {
    node<contentCreator> *iterator = this->head;
    while (iterator != nullptr) {
        iterator->getDt().toString();
        iterator = iterator->getNextNode();
    }
}

bool contentCreatorLinkedList::findIdInTheList(const int inputId) const {

    if (this->head != nullptr) {


        node<contentCreator> *iterator = this->head;
        do {
            if (iterator->getDt().getId() == inputId) {
                return true;

            }
            iterator = iterator->getNextNode();
        } while (iterator != nullptr);

        return false;

    }
    return false;

}

bool contentCreatorLinkedList::removeFromTheList(const int id) {
    if (this->findIdInTheList(id)) {
        if (this->head->getDt().getId() == id) {
            node<contentCreator> *tempHoldNext = head;
            head = head->getNextNode();
            delete tempHoldNext;
            this->size--;

            return true;
        } else if (this->head->getNextNode() != nullptr) {
            node<contentCreator> *iterator = this->head;
            while (iterator->getNextNode() != nullptr) {
                if (iterator->getNextNode()->getDt().getId() == id) {
                    node<contentCreator> *tempHoldNext = iterator->getNextNode();
                    iterator->setNextNode(iterator->getNextNode()->getNextNode());
                    delete tempHoldNext;
                    this->size--;

                    return true;
                }
                iterator = iterator->getNextNode();
            }
        }
    }
    return false;
}

contentCreatorLinkedList::~contentCreatorLinkedList() {

    if (this->head != nullptr) {
        node<contentCreator> *tempHoldNext = nullptr;
        node<contentCreator> *iterator = this->head;

        do {

            tempHoldNext = iterator->getNextNode();
            delete iterator;
            iterator = tempHoldNext;

        } while (iterator != nullptr);
    }

}

void contentCreatorLinkedList::showTheListOnlyId() const {
    node<contentCreator> *iterator = this->head;
    while (iterator != nullptr) {
        cout << iterator->getDt().getId() << endl;
        iterator = iterator->getNextNode();
    }
}

int contentCreatorLinkedList::getSize() const {
    return this->size;
}

bool contentCreatorLinkedList::addContentToId(const int contentCreatorId, const int contentId, const string &title) {
    if (this->head != nullptr) {


        node<contentCreator> *iterator = this->head;
        do {
            if (iterator->getDt().getId() == contentCreatorId) {

                iterator->getDt().addContent(contentId, title);
                return true;

            }
            iterator = iterator->getNextNode();
        } while (iterator != nullptr);

        return false;
    }
    return false;
}

bool contentCreatorLinkedList::removeContentFromId(const int contentCreatorId, const int contentId) {
    if (this->head != nullptr) {

        node<contentCreator> *iterator = this->head;
        do {
            if (iterator->getDt().getId() == contentCreatorId) {

                bool result = iterator->getDt().removeContent(contentId);
                return result;
            }
            iterator = iterator->getNextNode();
        } while (iterator != nullptr);

        return false;
    }
    return false;
}

bool contentCreatorLinkedList::addFollowerToId(const int id, const string &name, const int contentCreatorId) {
    if (this->head != nullptr) {

        node<contentCreator> *iterator = this->head;
        do {
            if (iterator->getDt().getId() == contentCreatorId) {

                bool result = iterator->getDt().addFollower(id, name);
                return result;

            }
            iterator = iterator->getNextNode();
        } while (iterator != nullptr);

        return false;
    }
    return false;
}

bool contentCreatorLinkedList::removeFollowerToId(const int regularUserId, const int contentCreatorId) {
    if (this->head != nullptr) {

        node<contentCreator> *iterator = this->head;
        do {
            if (iterator->getDt().getId() == contentCreatorId) {

                bool result = iterator->getDt().removeFollower(regularUserId);
                return result;

            }
            iterator = iterator->getNextNode();
        } while (iterator != nullptr);

        return false;
    }

    return false;
}

void contentCreatorLinkedList::showContentOfCreator(const int id) const {

    if (this->head != nullptr) {

        node<contentCreator> *iterator = this->head;
        do {
            if (iterator->getDt().getId() == id) {

                iterator->getDt().showTheContentsOnlyId();

            }
            iterator = iterator->getNextNode();
        } while (iterator != nullptr);

    }


}

void contentCreatorLinkedList::showFollowerOfCreator(const int id) const {

    if (this->head != nullptr) {

        node<contentCreator> *iterator = this->head;
        do {
            if (iterator->getDt().getId() == id) {

                iterator->getDt().showTheFollowersOnlyId();

            }
            iterator = iterator->getNextNode();
        } while (iterator != nullptr);

    }

}

void contentCreatorLinkedList::removeUserFromEveryContentCreator(const int id) {

    if (this->head != nullptr) {

        node<contentCreator> *iterator = this->head;
        do {

            iterator->getDt().removeFollower(id);
            iterator = iterator->getNextNode();

        } while (iterator != nullptr);

    }


}


