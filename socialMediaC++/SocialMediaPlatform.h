//
// Created by Emirhan Kılıç 22203360 on 11/22/2023.
//

#ifndef CS201HW3_SOCIALMEDIAPLATFORM_H
#define CS201HW3_SOCIALMEDIAPLATFORM_H

#include "contentCreatorLinkedList.h"

class SocialMediaPlatform {
private:
    contentCreatorLinkedList contentCreatorsList;
    userLinkedList regularUserList;
    contentLinkedList contentList;
public:
    SocialMediaPlatform();
    ~SocialMediaPlatform();
    void addRegularUser( const int regularUserId, const string name );
    void removeRegularUser( const int regularUserId );
    void addContentCreator( const int contentCreatorId, const string name );
    void removeContentCreator( const int contentCreatorId );
    void addContent( const int contentCreatorId, const int contentId, const string
    title );
    void removeContent( const int contentCreatorId, const int contentId );
    void followContentCreator( const int regularUserId, const int contentCreatorId );
    void unfollowContentCreator( const int regularUserId, const int contentCreatorId);
    void showFollowersOf( const int contentCreatorId ) const;
    void showContentsOf( const int contentCreatorId ) const;
    void showAllRegularUsers( ) const;
    void showAllContentCreators( ) const;
};


#endif //CS201HW3_SOCIALMEDIAPLATFORM_H
