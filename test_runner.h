#ifndef TEST_RUNNER_H
#define TEST_RUNNER_H

#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

template <typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
	for (const auto& elem : v) {
		os << v << " ";
	}

	os << endl;
	return os;
}

template <class T>
inline ostream& operator << (ostream& os, const set<T>& s) {
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << " ";
		}
		first = false;
		os << x;
	}
	return os;
}

template <class K, class V>
inline ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
inline void AssertEqual(const T& t, const U& u,
                        const string& hint)
{
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u
		   << " hint: " << hint;
		throw runtime_error(os.str());
	}
}

inline void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		} catch (runtime_error& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

#endif