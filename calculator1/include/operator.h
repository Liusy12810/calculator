//

#pragma once
#include <string>

namespace op {

	class Op {
	public:
		double virtual calculate(double left, double right) = 0;
		bool virtual supportOp(std::string) = 0;
	};

	class OpPlus : public Op {
	public:
		double virtual calculate(double left, double right) override;
		bool supportOp(std::string) override;
	};

	class OpMinus : public Op {
	public:
		double virtual calculate(double left, double right) override;
		bool supportOp(std::string) override;
	};

	class OpProduct : public Op {
	public:
		double virtual calculate(double left, double right) override;
		bool supportOp(std::string) override;
	};

	class OpDivide : public Op {
	public:
		double virtual calculate(double left, double right) override;
		bool supportOp(std::string) override;
	};
}