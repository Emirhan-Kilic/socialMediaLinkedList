//
// Created by Emirhan Kılıç 22203360 on 11/28/2023.
//

#include "user.h"

int user::getId() const {
    return this->id;
}

void user::setId(const int idInput) {
    this->id = idInput;
}

const string &user::getName() const {
    return this->name;
}

void user::setName(const string &nameInput) {
    this->name = nameInput;
}

user::user(int id, const string &name) : id(id), name(name) {}

bool user::operator<(const user &userInput) const {
    if (this -> id < userInput.id){
        return true;
    } else {
        return false;
    }
}

user::user() = default;

user::~user() = default;

