
#include <string>
#include "Expression.h"

namespace expr {

// class method definitions for Expression
	Expression::Expression() :
		_exp("") {
		_Op = nullptr;
	};

	Expression::Expression(std::string Str_exp) :
		_exp(Str_exp) {
		set_Operator(_exp);
	};

	Expression::~Expression() {
		delete _Op;
	};

	void Expression::set_Operator(const std::string & Str_exp) {

		int left = 0, right = 0;
		int op_id = -1;
		int len = Str_exp.length();

		for (int i = 0; i < len; i++) {
			if (!isdigit(Str_exp[i])) {
				if (op::isop(Str_exp[i]) > 0) {
					op_id = op::isop(Str_exp[i]);
				}
			}
		}
		switch (op_id) {
		case 1: _Op = new op::OpPlus   (left, right);
			break;
		case 2: _Op = new op::OpMinus  (left, right);
			break;
		case 3: _Op = new op::OpProduct(left, right);
			break;
		case 4: _Op = new op::OpDivide (left, right);
			break;
		default: throw std::exception("Invalid expression: No such operator");
			break;
		}
	}
}