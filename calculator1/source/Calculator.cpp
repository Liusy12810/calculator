//

#include "../include/Calculator.h"
#include "../include/Operator.h"
#include "../include/OperatorFactory.h"
#include "../include/Expression.h"
#include "../include/ExpressionBuilder.h"

Calculator::Calculator()
{

}

// accept string like "1+2", return 3
// accept string like "3*5", return 15
double Calculator::calculate(std::string expression)
{
	// TODO: The logic here would be better to move to ExpressionBuilder
	// Step 1: create expression object
	// note: default vaule is 0
	expr::Expression* exp = new expr::Expression();
	// Create our operator factory so we have all supported operators registered
	op::OperatorFactory opFactory;

	expr::ExpressionBuilder exprBuilder(expression);
	
	if (!exprBuilder.checkExpression())
		throw "ERROR: Invalid operator";

	int op_loc = exprBuilder.locateOperator(opFactory);
	if (op_loc > -1) {
		std::string op_Str(std::to_string(expression[op_loc]));
		op::Op* op_ptr = opFactory.GetOperator(op_Str);
		exp->Operator(*op_ptr);
		exp->Left(exprBuilder.Left(op_loc));
		exp->Right(exprBuilder.Right(op_loc));
	}

	/*
	// TODO: implement logic
	// Step 2: analysize expression, identify 1st number
	double left = 2; // suppose we get 2
	exp.Left(left);

	// TODO: implement logic
	// Step 3: analysize expression, identify operator
	std::string opStr("+");  // suppose we get a "+" string here
	// check which operator we know support this operator string 
	
	op::Op* op = opFactory.GetOperator(opStr);	
	// TODO: check nullptr case of op, which mean we found a operator that we did not support at all
	// throw exception or return something to let caller know input error
	exp.Operator(*op);

	// TODO: implement logic
	// Step 4: analysize expression, identify 2st number
	double right = 3; // suppose we get 3
	exp.Right(right);
	*/

	double v = exp->Value();
	return v;
}