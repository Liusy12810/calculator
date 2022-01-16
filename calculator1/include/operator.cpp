

#include "operator.h"

namespace op {
// class method definition for OP
	Op::Op() :
		_left(0), 
		_right(0) 
	{};

	Op::Op(double left, double right = 0) :
		_left(left),
		_right(right)
	{};

// class method definitions for OpPlus
	OpPlus::OpPlus() : 
		Op() 
	{};

	OpPlus::OpPlus(double left, double right = 0) :
		Op(left, right) 
	{};

	OpPlus::~OpPlus() {
		Op::~Op();
	};

	double OpPlus::calculate() {
		return _getleft() + _getright();
	}

// class method definitions for OpMinus
	OpMinus::OpMinus() : 
		Op() 
	{};

	OpMinus::OpMinus(double left, double right = 0) :
		Op(left, right) 
	{};

	OpMinus::~OpMinus() {
		Op::~Op();
	};

	double OpMinus::calculate() {
		return _getleft() - _getright();
	}

// class method definitions for OpProduct
	OpProduct::OpProduct() : 
		Op() 
	{};
	
	OpProduct::OpProduct(double left, double right = 0) :
		Op(left, right) 
	{};
	
	OpProduct::~OpProduct() {
		Op::~Op(); 
	}
	double OpProduct::calculate() {
		return _getleft() * _getright();
	}

// class method definitions for OpDivide
	OpDivide::OpDivide() : 
		Op() 
	{};

	OpDivide::OpDivide(double left, double right = 0) :
		Op(left, right) 
	{};

	OpDivide::~OpDivide() { 
		Op::~Op(); 
	};

	double OpDivide::calculate() {
		return _getleft() / _getright();
	}

	// other function definitions

	/// <summary>
	/// 
	/// </summary>
	/// <param name="_c"> : the input character to be checked</param>
	/// <returns>
	/// <para>0 : '.'</para>
	/// <para>1 : '+'</para>
	/// <para>2 : '-'</para>
	/// <para>3 : '*'</para>
	/// <para>4 : '/'</para>
	/// <para>-1: other</para>
	/// </returns>
	int isop(int _c)
	{
		int result;
		switch (_c)
		{
		case 0x2e: result = 0;
			break;
		case 0x2b: result = 1;
			break;
		case 0x2d: result = 2;
			break;
		case 0x2a: result = 3;
			break;
		case 0x2f: result = 4;
			break;
		default:   result = -1;
			break;
		}
		return result;
	}
}