#pragma once

namespace op {

	class Op {
	public:
		Op();
		Op(double left, double right=0);
		virtual ~Op() {};

		double virtual calculate() = 0;

	protected:
		double _getleft() { return _left; };
		double _getright() { return _right; };

	private:
		double _left;
		double _right;
	};

	class OpPlus : public Op {
	public:
		OpPlus();
		OpPlus(double left, double right=0);
		~OpPlus();

		double virtual calculate() override;
	};

	class OpMinus : public Op {
	public:
		OpMinus();
		OpMinus(double left, double right = 0);
		~OpMinus();

		double virtual calculate() override;
	};

	class OpProduct : public Op {
	public:
		OpProduct();
		OpProduct(double left, double right = 0);
		~OpProduct();

		double virtual calculate() override;
	};

	class OpDivide : public Op {
	public:
		OpDivide();
		OpDivide(double left, double right = 0);
		~OpDivide();

		double virtual calculate() override;
	};

	int isop(int _C);
}