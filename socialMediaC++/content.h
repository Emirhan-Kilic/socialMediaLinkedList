//
// Created by Emirhan Kılıç 22203360 on 11/29/2023.
//

#ifndef CS201HW3_CONTENT_H
#define CS201HW3_CONTENT_H

#include <iostream>
using namespace std;

class content {
private:
    string title;
    int id;
public:
    const string &getTitle() const;

    void setTitle(const string &title);

    int getId() const;

    void setId(int id);

    bool operator<(const content & contentInput) const;

    content(const string &title, int id);

    content();

    ~content();

};


#endif //CS201HW3_CONTENT_H
