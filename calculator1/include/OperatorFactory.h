//

#pragma once
#include <string>
#include <vector>
#include "./Operator.h"

namespace op {
	class OperatorFactory
	{
	public:
		OperatorFactory();
		~OperatorFactory();

		op::Op* GetOperator(const std::string&) const;

	private:
		std::vector<op::Op*> _operators;
	};
}