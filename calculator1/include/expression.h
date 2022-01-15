#pragma once

#include <string>
#include "operator.h"

namespace expr {
	/// <summary>
	/// Class Expression:
	/// <para> the class which represent a expression </para>
	/// </summary>
	class Expression {
	public:
		// constructors and deconstrutors.
		Expression();

		// create a expression by passing value directlly
		Expression(double value);

		// set operator of this expression
		// take 3 * 5 for example, * is left number
		void Operator(op::Op& op);

		// set left number of expression
		// take 3 * 5 for example, 3 is left number
		void Left(double);

		// set right number of expression
		// take 3 * 5 for example, 5 is left number
		void Right(double);

		// return expression value
		double Value();
	private:
		double _left;
		double _right;
		op::Op*	_op;
	};

}