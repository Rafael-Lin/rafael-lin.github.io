// 這是主 DLL檔
#include "stdafx.h"
#include "DllFromCPlus.h"
CPlus::CPlus()
{
    m_Int=-1;
}
// 建構式
CPlus::CPlus(int i)
{
    m_Int=i;
}
// 返回int
int CPlus::GetI()
{
    return m_Int;
}
// 解構函數
CPlus::~CPlus()
{
    m_Int = 0;
    Console::WriteLine("對象被Dispose。");
}
CPlus::!CPlus()
{
   //什麼都不做
}
