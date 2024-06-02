#ifndef USER_H
#define USER_H
#include <string>
class User {
public:
	User(int=0, std::string="");
	bool operator< (User&) const;
	bool operator> (User&) const;
	bool operator== (User&) const;
	bool operator== (int) const;
	int getId() const;
	std::string toString() const;
private:
	int id;
	std::string name;
};
#endif // !USER_H
