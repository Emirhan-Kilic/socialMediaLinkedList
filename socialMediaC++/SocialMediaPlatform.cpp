//
// Created by Emirhan Kılıç 22203360 on 11/22/2023.
//

#include "SocialMediaPlatform.h"

SocialMediaPlatform::SocialMediaPlatform() {
    contentCreatorsList = contentCreatorLinkedList();
    regularUserList = userLinkedList();
    contentList = contentLinkedList();
}

SocialMediaPlatform::~SocialMediaPlatform() {

}


void SocialMediaPlatform::addRegularUser(const int regularUserId, const string name) {

    bool result = this->regularUserList.addToTheList(user(regularUserId, name));

    if (result) {
        cout << "Added regular user " << regularUserId << "." << endl;
    } else {
        cout << "Cannot add regular user. There is already a regular user with ID " << regularUserId << "." << endl;
    }

}


void SocialMediaPlatform::removeRegularUser(const int regularUserId) {

    bool result = this->regularUserList.removeFromTheList(regularUserId);

    if (result) {
        this->contentCreatorsList.removeUserFromEveryContentCreator(regularUserId);
        cout << "Removed regular user " << regularUserId << "." << endl;
    } else {
        cout << "Cannot remove regular user. There is no regular user with ID " << regularUserId << "." << endl;
    }

}


void SocialMediaPlatform::showAllRegularUsers() const {

    cout << "Regular users in the social media platform:" << endl;

    if (this->regularUserList.getSize() == 0) {
        cout << "None" << endl;
    } else {
        this->regularUserList.showTheList();
    }

}

void SocialMediaPlatform::addContentCreator(const int contentCreatorId, const string name) {

    bool result = this->contentCreatorsList.addToTheList(contentCreator(contentCreatorId, name));

    if (result) {
        cout << "Added content creator " << contentCreatorId << "." << endl;

    } else {
        cout << "Cannot add content creator. There is already a content creator with ID " << contentCreatorId << "."
             << endl;

    }

}

void SocialMediaPlatform::removeContentCreator(const int contentCreatorId) {
    bool result = this->contentCreatorsList.removeFromTheList(contentCreatorId);

    if (result) {
        cout << "Removed content creator " << contentCreatorId << "." << endl;

    } else {
        cout << "Cannot remove content creator. There is no content creator with ID " << contentCreatorId << "."
             << endl;

    }
}

void SocialMediaPlatform::showAllContentCreators() const {

    cout << "Content creators in the social media platform:" << endl;

    if (this->contentCreatorsList.getSize() == 0) {
        cout << "None" << endl;
    } else {
        this->contentCreatorsList.showTheList();
    }

}

void SocialMediaPlatform::addContent(const int contentCreatorId, const int contentId, const string title) {

    if (this->contentList.findIdInTheList(contentId)) {
        cout << "Cannot add content. There is already a content with ID " << contentId << "." << endl;

    } else {
        if (!(this->contentCreatorsList.findIdInTheList(contentCreatorId))) {
            cout << "Cannot add content. There is no content creator with ID " << contentCreatorId << "." << endl;
        } else {
            this->contentCreatorsList.addContentToId(contentCreatorId, contentId, title);
            this->contentList.addToTheList(content(title, contentId));
            cout << "Added content " << contentId << "." << endl;
        }
    }

}

void SocialMediaPlatform::removeContent(const int contentCreatorId, const int contentId) {

    if (!(this->contentCreatorsList.findIdInTheList(contentCreatorId))) {
        cout << "Cannot remove content. There is no content creator with ID " << contentCreatorId << "." << endl;
    } else {

        bool result = this->contentCreatorsList.removeContentFromId(contentCreatorId, contentId);

        if (result) {
            cout << "Removed content " << contentId << "." << endl;
        } else {
            cout << "Cannot remove content. There is no content with ID " << contentId
                 << " shared by content creator with ID " << contentCreatorId << "." << endl;
        }

    }

}


void SocialMediaPlatform::followContentCreator(const int regularUserId, const int contentCreatorId) {

    if (!(this->contentCreatorsList.findIdInTheList(contentCreatorId))) {
        cout << "Cannot follow. Regular user and/or content creator ID does not exist." << endl;
    } else if (!(this->regularUserList.findIdInTheList(regularUserId))) {
        cout << "Cannot follow. Regular user and/or content creator ID does not exist." << endl;

    } else {

        user userObj = this->regularUserList.getUserFromId(regularUserId);

        bool result = this->contentCreatorsList.addFollowerToId(userObj.getId(), userObj.getName(), contentCreatorId);

        if (result) {
            cout << "Regular user with ID " << userObj.getId() << " followed content creator with ID "
                 << contentCreatorId << "." << endl;
        } else {
            cout << "Cannot follow. The user is already following the content creator." << endl;
        }

    }

}

void SocialMediaPlatform::showContentsOf(const int contentCreatorId) const {

    if (!(this->contentCreatorsList.findIdInTheList(contentCreatorId))) {
        cout << "Cannot show. There is no content creator with ID " << contentCreatorId << "." << endl;
    } else {

        this->contentCreatorsList.showContentOfCreator(contentCreatorId);

    }
}

void SocialMediaPlatform::showFollowersOf(const int contentCreatorId) const {

    if (!(this->contentCreatorsList.findIdInTheList(contentCreatorId))) {
        cout << "Cannot show. There is no content creator with ID " << contentCreatorId << "." << endl;
    } else {

        this->contentCreatorsList.showFollowerOfCreator(contentCreatorId);
    }
}



void SocialMediaPlatform::unfollowContentCreator(const int regularUserId, const int contentCreatorId) {

    if (!(this->contentCreatorsList.findIdInTheList(contentCreatorId))) {
        cout << "Cannot unfollow. Regular user and/or content creator ID does not exist." << endl;
    } else if (!(this->regularUserList.findIdInTheList(regularUserId))) {
        cout << "Cannot unfollow. Regular user and/or content creator ID does not exist." << endl;

    } else {

        //Todo
        user userObj = this->regularUserList.getUserFromId(regularUserId);
        bool result = this->contentCreatorsList.removeFollowerToId(userObj.getId(), contentCreatorId);

        if (result) {
            cout << "Regular user with ID " << userObj.getId() << " unfollowed content creator with ID "
                 << contentCreatorId << "." << endl;
        } else {
            cout << "Cannot unfollow. The user is not following the content creator." << endl;
        }

    }

}



