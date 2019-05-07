using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.CCtor
{
    public class CCtor
    {
        public static int m_Int = 1;	//初始設定式
        static CCtor()      			//初始化器
        {
            m_Int = 2;
        }
        public CCtor()
        {
            Console.WriteLine("建構式呼叫。");
        }
        static void Main(string[] args)
        {
            Console.Read();
        }
    }

}
