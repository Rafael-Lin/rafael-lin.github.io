// DllFromCPlus.h
#pragma once
using namespace System;
public ref class CPlus  	//�ŧi�@�ӥi�H�Q.NET�ج[����L�y���I�s������
{ 
private:
    int m_Int;
public:
    CPlus();           		//�L�Ѽƫغc��
    CPlus(int i);        	//�غc��
    ~CPlus();          		//�Ѻc���
    !CPlus();           		//�Ѻc���
    int GetI();
};
