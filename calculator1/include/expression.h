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
		Expression(std::string Str_exp);
		~Expression();

	// other member methods
		void set_op(int op_id, double left, double right);
		void set_Operator();
		int find_Operator() const;
	private:
		std::string _exp;
		op::Op* _op;
	};

}