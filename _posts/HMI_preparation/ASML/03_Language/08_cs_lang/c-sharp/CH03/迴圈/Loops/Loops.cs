using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace NET.MST.Third.Loops
{
    public class Loops
    {
        static void Main(string[] args)
        {
            A[] array = new A[3];
            foreach (A a in array)
            {
                //a = new A(1);			//編譯錯誤，不能改變項目
                //a._i = 1;				//編譯錯誤，不能改變項目成員變數
                //a.I = 1;				//編譯錯誤，不能透過屬性改變成員變數
                a.ModifyI(1);				//正確，可以呼叫公共方法
                Console.WriteLine(a);
            }
            Console.Read();
        }
        public struct A
        {
            public int _i;
            public A(int i)
            {
                _i = i;
            }
            //透過屬性改變成員
            public int I
            {
                set { _i = value; }
            }
            //透過公共方法改變成員
            public void ModifyI(int i)
            {
                _i = i;
            }
            public override string ToString()
            {
                return _i.ToString();
            }
        }
    }

}
