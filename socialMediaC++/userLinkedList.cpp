//
// Created by Emirhan Kılıç 22203360 on 12/1/2023.
//

#include "userLinkedList.h"

userLinkedList::userLinkedList() {
    this->head = nullptr;
    this->size = 0;
}

bool userLinkedList::addToTheList(const user &inputUser) {

    node<user> *inputNode = new node<user>(inputUser);

    if (this->head == nullptr) {

        head = inputNode;
        this->size++;

        return true;

    } else {

        if (!findIdInTheList(inputUser.getId())) {
            bool inserted = false;
            node<user> *iterator = this->head;

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
    return false;
}

bool userLinkedList::findInTheList(const user &inputUser) const {

    if (this->head != nullptr) {


        node<user> *iterator = this->head;
        do {
            if (iterator->getDt().getId() == inputUser.getId()) {
                return true;
            }
            iterator = iterator->getNextNode();
        } while (iterator != nullptr);

        return false;

    }
    return false;
}

void userLinkedList::showTheList() const {

    node<user> *iterator = this->head;
    while (iterator != nullptr) {
        cout << iterator->getDt().getId() << ", " << iterator->getDt().getName() << endl;
        iterator = iterator->getNextNode();
    }
}

bool userLinkedList::findIdInTheList(const int inputId) const {

    if (this->head != nullptr) {

        node<user> *iterator = this->head;
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

bool userLinkedList::removeFromTheList(const int id) {
    if (this->findIdInTheList(id)) {
        if (this->head->getDt().getId() == id) {
            node<user> *tempHoldNext = head;
            head = head->getNextNode();
            delete tempHoldNext;
            this->size--;

            return true;
        } else if (this->head->getNextNode() != nullptr) {
            node<user> *iterator = this->head;
            while (iterator->getNextNode() != nullptr) {
                if (iterator->getNextNode()->getDt().getId() == id) {
                    node<user> *tempHoldNext = iterator->getNextNode();
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

userLinkedList::~userLinkedList() {

    if (this->head != nullptr) {
        node<user> *tempHoldNext = nullptr;
        node<user> *iterator = this->head;

        do {

            tempHoldNext = iterator->getNextNode();
            delete iterator;
            iterator = tempHoldNext;

        } while (iterator != nullptr);
    }

}

void userLinkedList::showTheListOnlyId() const {
    node<user> *iterator = this->head;
    while (iterator != nullptr) {
        cout << iterator->getDt().getId() << endl;
        iterator = iterator->getNextNode();
    }
}

int userLinkedList::getSize() const {
    return size;

}

user &userLinkedList::getUserFromId(const int id) const {
    if (this->head != nullptr) {

        node<user> *iterator = this->head;
        do {
            if (iterator->getDt().getId() == id) {

                return iterator->getDt();

            }
            iterator = iterator->getNextNode();
        } while (iterator != nullptr);

    }

    return head->getDt();

}
