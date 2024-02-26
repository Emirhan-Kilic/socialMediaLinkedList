//
// Created by Emirhan Kılıç 22203360 on 11/29/2023.
//

#include "content.h"

const string &content::getTitle() const {
    return this->title;
}

void content::setTitle(const string &title) {
    this->title = title;
}

int content::getId() const {
    return this->id;
}

void content::setId(int id) {
    this->id = id;
}

bool content::operator<(const content &contentInput) const {
    if(this->id < contentInput.id){
        return true;
    } else {
        return false;
    }
}

content::content(const string &title, int id) : title(title), id(id) {}

content::content() = default;

content::~content() = default;
