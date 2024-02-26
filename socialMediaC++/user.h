//
// Created by Emirhan Kılıç 22203360 on 11/28/2023.
//

#ifndef CS201HW3_USER_H
#define CS201HW3_USER_H

#include <iostream>
using namespace std;

class user {
private:
    int id;
    string name;
public:

    user(int id, const string &name);

    user();

    ~user();

    int getId() const;

    void setId(int idInput);

    const string &getName() const;

    void setName(const string &nameInput);

    bool operator<(const user & userInput) const;




};


#endif //CS201HW3_USER_H
