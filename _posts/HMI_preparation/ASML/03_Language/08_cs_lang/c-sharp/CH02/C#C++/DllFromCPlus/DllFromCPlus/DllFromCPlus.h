// DllFromCPlus.h
#pragma once
using namespace System;
public ref class CPlus  	//宣告一個可以被.NET框架中其他語言呼叫的類型
{ 
private:
    int m_Int;
public:
    CPlus();           		//無參數建構式
    CPlus(int i);        	//建構式
    ~CPlus();          		//解構函數
    !CPlus();           		//解構函數
    int GetI();
};
