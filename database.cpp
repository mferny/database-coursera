#include "database.h"
using namespace std;

/*
 * check if the event is already in database
 */

void Database::Add(const Date &date, const string &event) {
	const auto it = check_[date].insert(event);
	if (it.second)
		db_[date].push_back(event);
}

void Database::Print(ostream &os) const {
	for (const auto &ev : db_) {
		for (const auto &en : ev.second) {
			os << ev.first << " " << en << endl;
		}
	}
}

/*
 * if no dates less or equal than given throw exeption
 * if given date is in database, print last event
 * if given date is not in database, take previous iterator and last event
 */

pair<Date, string> Database::Last(const Date &date) const {
	const auto it = db_.lower_bound(date);
	if (it == db_.begin() && it->first != date)
		throw invalid_argument("No entries");

	else if (it->first == date) {
		return {it->first, *prev(it->second.end())};
	}
	const auto prev_it = prev(it);
	return {prev_it->first, *prev(prev_it->second.end())};
}


