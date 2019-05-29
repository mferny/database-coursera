#ifndef NODE_H
#define NODE_H

#include "date.h"
#include <memory>

enum class Comparison {
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperation {
	And,
	Or
};

class Node {
public:
	virtual bool Evaluate(const Date &date, const std::string &event) const = 0;
};

class EmptyNode : public Node {
public:
	bool Evaluate (const Date &date, const std::string &event) const override;
};

class DateComparisonNode : public Node {
public:
	DateComparisonNode(const Comparison &cmp, const Date &date);
	bool Evaluate(const Date &date, const std::string &event) const override;

//private:
	const Comparison cmp_;
	const Date date_;
};

class EventComparisonNode : public Node {
public:
	EventComparisonNode(const Comparison &cmp, const std::string &event);
	bool Evaluate(const Date &date, const std::string &event) const override;

//private:
	const Comparison cmp_;
	const std::string event_;
};

class LogicalOperationNode : public Node {
public:
	LogicalOperationNode(const LogicalOperation &op, const std::shared_ptr<Node> &lhs, const std::shared_ptr<Node> &rhs);
	bool Evaluate(const Date &date, const std::string &event) const override;

//private:
	const LogicalOperation op_;
	const std::shared_ptr<Node> lhs_, rhs_;
};

#endif
