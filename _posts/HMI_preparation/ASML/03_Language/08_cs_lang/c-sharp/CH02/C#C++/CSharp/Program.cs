using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharp
{
    public class CSharp
    {
        static void Main(string[] args)
        {
            CPlus cplus = new CPlus(12);        	//初始化一個CPlus執行個體
            Console.WriteLine(cplus.GetI());     	//檢查該物件的私有成員
            //呼叫dispose方法，即CPlus::~CPlus方法
            cplus.Dispose();
            Console.Read();
        }
    }

}
