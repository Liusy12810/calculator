//

#pragma once
#include <string>
#include "../include/OperatorFactory.h"

namespace expr {
	class ExpressionBuilder {
	public:
		ExpressionBuilder();
		ExpressionBuilder(const std::string &);

		~ExpressionBuilder();

		bool checkExpression() const;

		double Left(int oploc) const;

		double Right(int oploc) const;

		int locateOperator(const op::OperatorFactory& opfact) const;

	private:
		std::string _exp_Str;
		expr::Expression* _Expr;
	};
}