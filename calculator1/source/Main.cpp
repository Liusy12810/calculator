// calculator1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../include/Calculator.h"

int main()
{
    Calculator calc;
    
    std::cout << calc.calculate("1+2") << std::endl;
    std::cout << calc.calculate("4*7") << std::endl;
    std::cout << calc.calculate("13/2") << std::endl;
}

