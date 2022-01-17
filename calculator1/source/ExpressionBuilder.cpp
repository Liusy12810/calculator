//

#include <string>
#include <regex>
#include "../include/Expression.h"
#include "../include/ExpressionBuilder.h"
#include "../include/OperatorFactory.h"

namespace expr {
	ExpressionBuilder::ExpressionBuilder() : 
		_exp_Str(""), _Expr(nullptr)
	{};
	ExpressionBuilder::ExpressionBuilder(const std::string& str) : 
		_exp_Str(""), _Expr(nullptr)
	{};

	ExpressionBuilder::~ExpressionBuilder() {
		delete _Expr;
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

	int ExpressionBuilder::locateOperator(const op::OperatorFactory& opfact) const {
		for (int i = 0; i < _exp_Str.length(); i++) {
			if (opfact.GetOperator(std::to_string(_exp_Str[i]))) {
				return i;
			}
		}
		return -1;
	};
}