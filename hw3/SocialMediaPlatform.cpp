#include <iostream>
#include <string>
using namespace std;

#include "SocialMediaPlatform.h"
#include "SortedLinkedList.h"

SocialMediaPlatform::SocialMediaPlatform() {}

void SocialMediaPlatform::addRegularUser(const int regularUserId, const string name) {
	User newUser (regularUserId, name);
	if (users.insert(newUser)) {
		cout << "Added regular user " << regularUserId << "." << endl;
	} else {
		cout << "Cannot add regular user. There is already a regular user with ID " << regularUserId << "." << endl;
	}
}

void SocialMediaPlatform::removeRegularUser(const int regularUserId) {
	if (users.find(regularUserId) != nullptr) {
		users.remove(regularUserId);
		for (int i = 0; i < contentCreators.getLength(); i++) {
			contentCreators[i]->unfollow(regularUserId);
		}
		cout << "Removed regular user " << regularUserId << "." << endl;
	} else {
		cout << "Cannot remove regular user. There is no regular user with ID " << regularUserId << "." << endl;
	}
}

void SocialMediaPlatform::addContentCreator(const int contentCreatorId, const string name) {
	ContentCreator newContentCreator (contentCreatorId, name);
	if (contentCreators.insert(newContentCreator)) {
		cout << "Added content creator " << contentCreatorId << "." << endl;
	} else {
		cout << "Cannot add content creator. There is already a content creator with ID " << contentCreatorId << "." << endl;
	}
}

void SocialMediaPlatform::removeContentCreator(const int contentCreatorId) {
	if (contentCreators.find(contentCreatorId) != nullptr) {
		contentCreators.remove(contentCreatorId);
		cout << "Removed content creator " << contentCreatorId << "." << endl;
	} else {
		cout << "Cannot remove content creator. There is no content creator with ID " << contentCreatorId << "." << endl;
	}
}

void SocialMediaPlatform::addContent(const int contentCreatorId, const int contentId, const string title) {
	if (contents.find(contentId)) {
		cout << "Cannot add content. There is already a content with ID " << contentId << "." << endl;
		return;
	}
	ContentCreator* owner = contentCreators.find(contentCreatorId);
	if (!owner) {
		cout << "Cannot add content. There is no content creator with ID " << contentCreatorId << "." << endl;
		return;
	}
	contents.insert(owner->addContent(contentId, title));
	cout << "Added content " << contentId << "." << endl;
}

void SocialMediaPlatform::removeContent(const int contentCreatorId, const int contentId) {
	ContentCreator* owner = contentCreators.find(contentCreatorId);
	if (!owner) {
		cout << "Cannot remove content. There is no content creator with ID " << contentCreatorId << "." << endl;
		return;
	}
	if (!owner->removeContent(contentId)) {
		cout << "Cannot remove content. There is no content with ID " << contentId << " shared by content creator with ID " << contentCreatorId << "." << endl;
		return;
	}
	cout << "Removed content " << contentId << "." << endl;
}

void SocialMediaPlatform::followContentCreator(const int regularUserId, const int contentCreatorId) {
	User* user = users.find(regularUserId);
	ContentCreator* contentCreator = contentCreators.find(contentCreatorId);
	if (!(user && contentCreator)) {
		cout << "Cannot follow. Regular user and/or content creator ID does not exist." << endl;
		return;
	}
	if (!contentCreator->follow(user->getId())) {
		cout << "Cannot follow. The user is already following the content creator." << endl;
		return;
	}
	cout << "Regular user with ID " << regularUserId << " followed content creator with ID " << contentCreatorId << "." << endl;
}

void SocialMediaPlatform::unfollowContentCreator(const int regularUserId, const int contentCreatorId) {
	User* user = users.find(regularUserId);
	ContentCreator* contentCreator = contentCreators.find(contentCreatorId);
	if (!(user && contentCreator)) {
		cout << "Cannot unfollow. Regular user and/or content creator ID does not exist." << endl;
		return;
	}
	if (!contentCreator->unfollow(user->getId())) {
		cout << "Cannot unfollow. The user is not following the content creator." << endl;
		return;
	}
	cout << "Regular user with ID " << regularUserId << " unfollowed content creator with ID " << contentCreatorId << "." << endl;
}

void SocialMediaPlatform::showContentsOf(const int contentCreatorId) const {
	ContentCreator* cc = contentCreators.find(contentCreatorId);
	if (!cc) {
		cout << "Cannot show. There is no content creator with ID " << contentCreatorId << "." << endl;
	} else cc->showContents();
}

void SocialMediaPlatform::showFollowersOf(const int contentCreatorId) const {
	ContentCreator* cc = contentCreators.find(contentCreatorId);
	if (!cc) {
		cout << "Cannot show. There is no content creator with ID " << contentCreatorId << "." << endl;
		return;
	} else cc->showFollowers();
}

void SocialMediaPlatform::showAllRegularUsers() const {
	cout << "Regular users in the social media platform:" << endl;
	if (users.getLength() == 0) cout << "None" << endl;
	else {
		for (int i = 0; i < users.getLength(); i++) {
			cout << users[i]->toString() << endl;
		}
	}
}

void SocialMediaPlatform::showAllContentCreators() const {
	cout << "Content creators in the social media platform:" << endl;
	if (contentCreators.getLength() == 0) cout << "None" << endl;
	else {
		for (int i = 0; i < contentCreators.getLength(); i++) {
			cout << contentCreators[i]->toString() << endl;
		}
	}
}

