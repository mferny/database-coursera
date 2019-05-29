#ifndef DATABASE_H
#define DATABASE_H

#include "date.h"
#include <map>
#include <vector>
#include <set>
#include <memory>
#include "node.h"

class Database
{
public:
	void Add(const Date &date, const std::string &event);

	void Print(std::ostream &os) const;

	template <typename Predicate>
	int RemoveIf(const Predicate& predicate) {
		int result = 0;
		std::vector<Date> del = {};

		for(auto& entry : db_) {
			std::vector<std::string> safe_del = {};

			for (const std::string& event : entry.second) {
				if (predicate(entry.first, event)) {
					result++;
					check_[entry.first].erase(event);
				} else {
					safe_del.push_back(event);
				}
			}

			if(safe_del.size() == 0) {
				del.push_back(entry.first);
			} else {
				entry.second = safe_del;
			}
		}

		for (const auto& date : del) {
			db_.erase(date);
			check_.erase(date);
		}

		return result;
	}

	template <class Predicate>
	std::vector<std::pair<Date, std::string>> FindIf(const Predicate &predicate) const {
		std::vector <std::pair<Date, std::string>> res;
		for (const auto &ent : db_) {
			for (const std::string &ev : ent.second) {
				if (predicate(ent.first, ev))
					res.push_back({ent.first, ev});
			}
		}
		return (res);
	}

	std::pair<Date, std::string> Last(const Date &date) const;

private:
	std::map<Date, std::vector<std::string>> db_;
	std::map<Date, std::set<std::string>> check_;
};

#endif
