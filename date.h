#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <tuple>

class Date {
public:
	Date(int year, int month, int day);
	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
private:
	int year_, month_, day_;
};

Date ParseDate(std::istream& is);

inline std::ostream &operator << (std::ostream &os, const Date &date) {
	os << std::setfill('0') << std::setw(4) << date.GetYear() << '-' << std::setw(2)
	<< date.GetMonth() << '-' << std::setw(2) << date.GetDay();
	return (os);
}

inline std::ostream &operator << (std::ostream &os, const std::pair<Date, std::string> &db) {
	os << db.first << " " << db.second;
	return (os);
}

inline bool operator == (const Date &lhs, const Date &rhs) {
	return (std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
			== std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
}

inline bool operator != (const Date &lhs, const Date &rhs) {
	return (std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
	        != std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
}

inline bool operator > (const Date &lhs, const Date &rhs) {
	return (std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
	        > std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
}

inline bool operator < (const Date &lhs, const Date &rhs) {
	return (std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
	        < std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
}

inline bool operator >= (const Date &lhs, const Date &rhs) {
	return (std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
	        >= std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
}

inline bool operator <= (const Date &lhs, const Date &rhs) {
	return (std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay())
	        <= std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()));
}

#endif