

#include "../include/Operator.h"

namespace op {
// class method definition for OP

// class method definitions for OpPlus
	double OpPlus::calculate(double left, double right)
	{
		return left + right;
	}

	bool OpPlus::supportOp(std::string op)
	{
		return op.compare("+") == 0;
	}

// class method definitions for OpMinus
	double OpMinus::calculate(double left, double right) {
		return left - right;
	}

	bool OpMinus::supportOp(std::string op)
	{
		return op.compare("-") == 0;
	}

// class method definitions for OpProduct
	bool OpProduct::supportOp(std::string op)
	{
		return op.compare("*") == 0;
	}

	double OpProduct::calculate(double left, double right) {
		return left * right;
	}

	bool OpDivide::supportOp(std::string op)
	{
		return op.compare("/") == 0;
	}

// class method definitions for OpDivide
	double OpDivide::calculate(double left, double right) {
		return left / right;
	}
}