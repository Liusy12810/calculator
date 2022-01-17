//

#include <iostream>
#include <string>
#include <regex>
#include "../include/Expression.h"
#include "../include/ExpressionBuilder.h"
#include "../include/OperatorFactory.h"

namespace expr {
	ExpressionBuilder::ExpressionBuilder() : 
		_exp_Str(""), _Expr() {
		std::cout << _exp_Str << std::endl;
	};
	ExpressionBuilder::ExpressionBuilder(const std::string& str) :
		_exp_Str(str), _Expr() {};

	ExpressionBuilder::~ExpressionBuilder() {
	};

	double ExpressionBuilder::Left(int oploc) const {
		return std::stod(_exp_Str.substr(0, oploc));
	};

	double ExpressionBuilder::Right(int oploc) const {
		return std::stod(_exp_Str.substr(oploc + 1));
	};

	bool ExpressionBuilder::checkExpression() const {
		return std::regex_match(_exp_Str, std::regex("\\d+[-+*/]\\d+"));
	};

	int ExpressionBuilder::LocateOperator(const op::OperatorFactory& opfact) const {
		std::string str;
		for (int i = 0; i < _exp_Str.length(); i++) {
			str = std::string(1, _exp_Str[i]);
			if (opfact.GetOperator(str)) {
				return i;
			}
		}
		return -1;
	};

	expr::Expression* ExpressionBuilder::BuildExpression(const op::OperatorFactory& opFact) {
		int op_loc = LocateOperator(opFact);
		std::string op_Str = std::string(1, _exp_Str[op_loc]);
		if (op_loc > -1) {
			op::Op* op_ptr = opFact.GetOperator(op_Str);
			_Expr.Operator(*op_ptr);
			_Expr.Left(Left(op_loc));
			_Expr.Right(Right(op_loc));
		} else {
			throw "ERROR: Invalid expression";
		}
		return &_Expr;
	};
}