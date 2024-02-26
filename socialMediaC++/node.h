//
// Created by Emirhan Kılıç 22203360 on 11/29/2023.
//

#ifndef CS201HW3_NODE_H
#define CS201HW3_NODE_H


#include <iostream>

template <typename type>
class node {
private:
    node<type>* nextNode;
    type dt;
public:

    node();

    node(const type dt);

    node(node<type> *nextNode,const type dt);


    node<type> *getNextNode() const;

    void setNextNode(node<type> *nextNode);

    type& getDt();

    void setDt( const type dt);


};

#endif //CS201HW3_NODE_H
