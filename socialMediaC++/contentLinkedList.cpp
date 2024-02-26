//
// Created by Emirhan Kılıç 22203360 on 12/2/2023.
//

#include "contentLinkedList.h"

contentLinkedList::contentLinkedList() {

    this->head = nullptr;
    this->size = 0;

}

bool contentLinkedList::addToTheList(const content &inputContent) {
    node<content> *inputNode = new node<content>(inputContent);

    if (this->head == nullptr) {

        head = inputNode;
        this->size++;

        return true;

    } else {

        if (!findIdInTheList(inputContent.getId())) {
            bool inserted = false;
            node<content> *iterator = this->head;

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

bool contentLinkedList::findInTheList(const content &inputContent) const {
    if (this->head != nullptr) {

        node<content> *iterator = this->head;
        do {
            if (iterator->getDt().getId() == inputContent.getId()) {
                return true;
            }
            iterator = iterator->getNextNode();
        } while (iterator != nullptr);

        return false;
    }
    return false;
}

void contentLinkedList::showTheList() const {

    node<content> *iterator = this->head;
    while (iterator != nullptr) {
        cout << iterator->getDt().getId() << ", " << iterator->getDt().getTitle() << endl;
        iterator = iterator->getNextNode();
    }

}

bool contentLinkedList::findIdInTheList(const int inputId) const {

    if (this->head != nullptr) {
        node<content> *iterator = this->head;
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

bool contentLinkedList::removeFromTheList(const int id) {
    if (this->findIdInTheList(id)) {
        if (this->head->getDt().getId() == id) {
            node<content> *tempHoldNext = head;
            head = head->getNextNode();
            delete tempHoldNext;
            this->size--;
            return true;
        } else if (this->head->getNextNode() != nullptr) {
            node<content> *iterator = this->head;
            while (iterator->getNextNode() != nullptr) {
                if (iterator->getNextNode()->getDt().getId() == id) {
                    node<content> *tempHoldNext = iterator->getNextNode();
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

contentLinkedList::~contentLinkedList() {

    if (this->head != nullptr) {
        node<content> *tempHoldNext = nullptr;
        node<content> *iterator = this->head;

        do {

            tempHoldNext = iterator->getNextNode();
            delete iterator;
            iterator = tempHoldNext;

        } while (iterator != nullptr);
    }

}

void contentLinkedList::showTheListOnlyId() const {

    node<content> *iterator = this->head;
    while (iterator != nullptr) {
        cout << iterator->getDt().getId() << endl;
        iterator = iterator->getNextNode();
    }
}

int contentLinkedList::getSize() const {
    return size;
}
