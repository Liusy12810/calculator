
#include <string>
#include <regex>
#include "Expression.h"

namespace expr {

// class method definitions for Expression
	Expression::Expression() :
		_exp("") {
		_op = nullptr;
	};

	Expression::Expression(std::string Str_exp) :
		_exp(Str_exp) {
		set_Operator();
	};

	Expression::~Expression() {
		delete _op;
	};

	void Expression::set_Operator() {
		int i;
		int op_id = -1;
		int left = 0, right = 0;
		int len = _exp.length();
		std::string sub_Str_left  = "0";
		std::string sub_Str_right = "0";

		if (!std::regex_match(_exp, std::regex("\\d+[-+*/]\\d+"))){
			throw std::exception("Invalid expression: wrong format");
		}

		i = find_Operator();
		op_id = op::isop(_exp[i]);

		if (i > 0 && i < len) {
			sub_Str_left  = _exp.substr(0, i);
			sub_Str_right = _exp.substr(i + 1);
			left = std::stod(sub_Str_left);
			right = std::stod(sub_Str_right);
		}

		set_op(op_id, left, right);
	}

	void Expression::set_op(int op_id, double left, double right) {
		switch (op_id) {
		case 1: _op = new op::OpPlus(left, right);
			break;
		case 2: _op = new op::OpMinus(left, right);
			break;
		case 3: _op = new op::OpProduct(left, right);
			break;
		case 4: _op = new op::OpDivide(left, right);
			break;
		default: throw std::exception("Invalid expression: No such operator");
			break;
		}
	}

	int Expression::find_Operator() const{
		int i;
		int len = _exp.length();
		for (i = 0; i < len; i++) {
			if (op::isop(i) > 0)
			{
				break;
			}
		}
		return i;
	};
}