#pragma once
#include <string>
#include <vector>
#include "./Operator.h"

class OperatorFactory
{
public:
	OperatorFactory();
	~OperatorFactory();

	op::Op* GetOperator(const std::string&);

private:
	std::vector<op::Op*> _operators;
};