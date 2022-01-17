
#include <string>
#include "../include/Expression.h"

namespace expr {
// class method definitions for Expression
	Expression::Expression() : 
		_op(nullptr), _left(0), _right(0)
	{}

	Expression::Expression(double value) : 
		_op(nullptr), _left(value), _right(0)
	{}

	void Expression::Operator(op::Op& op) {
		_op = &op;
	}

	void Expression::Left(double v) {
		_left = v;
	}

	void Expression::Right(double v) {
		_right = v;
	}

	double Expression::Value() {
		return _op->calculate(_left, _right);
	}
}