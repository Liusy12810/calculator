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
		void set_Operator(const std::string & Str_exp);
	private:
		std::string _exp;
		op::Op* _Op;
	};

}