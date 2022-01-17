//---

#include "../include/OperatorFactory.h"

namespace op {
	OperatorFactory::OperatorFactory() {
		_operators.push_back(new op::OpPlus());
		_operators.push_back(new op::OpMinus());
		_operators.push_back(new op::OpProduct());
		_operators.push_back(new op::OpDivide());
	}

	OperatorFactory::~OperatorFactory() {
		for (auto op : _operators) {
			delete op;
			op = nullptr;
		}
		_operators.clear();
	}

	op::Op* OperatorFactory::GetOperator(const std::string& opStr) const {
		// TODO: replace this search in better cpp style
		for (auto op : _operators) {
			if (op->supportOp(opStr)) {
				return op;
			}
		}
		return nullptr;
	}
}