using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fourth.StringAttribute
{
    class StringAttribute
    {
        static void Main(string[] args)
        {
            String a = "我是字串";
            String b = a;
            Console.WriteLine(Object.ReferenceEquals(a, b));
            //嘗試使用參考b修改a指向的物件
            b = "我是新的字串";
            Console.WriteLine(a);
            Console.WriteLine(b);
            //參考比較，並且列印比較的結果
            Console.WriteLine(Object.ReferenceEquals(a, b));
            Console.Read();
        }
    }

}
