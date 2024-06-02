#ifndef CONTENT_H
#define CONTENT_H
#include <string>
class Content {
public:
	Content(int = 0, std::string="");
	bool operator< (Content&)const;
	bool operator> (Content&)const;
	bool operator== (Content&)const;
	bool operator== (int)const;
	int getId()const;
private:
	int id;
	std::string title;
};
#endif // !CONTENT_H
