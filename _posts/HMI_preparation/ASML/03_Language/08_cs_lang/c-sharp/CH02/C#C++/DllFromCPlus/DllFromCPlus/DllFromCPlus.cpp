// �o�O�D DLL��
#include "stdafx.h"
#include "DllFromCPlus.h"
CPlus::CPlus()
{
    m_Int=-1;
}
// �غc��
CPlus::CPlus(int i)
{
    m_Int=i;
}
// ��^int
int CPlus::GetI()
{
    return m_Int;
}
// �Ѻc���
CPlus::~CPlus()
{
    m_Int = 0;
    Console::WriteLine("��H�QDispose�C");
}
CPlus::!CPlus()
{
   //���򳣤���
}
