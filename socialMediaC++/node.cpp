//
// Created by Emirhan Kılıç 22203360 on 11/29/2023.
//

#include "node.h"
template<typename type>
node<type> *node<type>::getNextNode() const {
    return nextNode;
}

template<typename type>
void node<type>::setNextNode(node<type> *nextNode) {
    this->nextNode = nextNode;
}

template<typename type>
type& node<type>::getDt()  {
    return dt;
}

template<typename type>
void node<type>::setDt(const type dt) {
    this->dt = dt;
}

template<typename type>
node<type>::node(node<type> *nextNode, const type dt):nextNode(nextNode), dt(dt) {}

template<typename type>
node<type>::node() {
    this->nextNode = nullptr;

}

template<typename type>
node<type>::node(const type dt) {
    this->nextNode = nullptr;
    this->dt = dt;

}
