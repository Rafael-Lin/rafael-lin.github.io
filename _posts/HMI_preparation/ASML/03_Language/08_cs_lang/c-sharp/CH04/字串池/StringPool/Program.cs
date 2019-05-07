using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fourth.StringPool
{
    class StringPool
    {
        static void Main(string[] args)
        {
            //兩個字串物件，理論上參考應該不相等
            //但由於字串池的機制，兩者實際指向了同一物件
            String a = "abcde";
            String b = "abcde";
            Console.WriteLine(Object.ReferenceEquals(a, b));

            //在本書前面章節的例子已中有介紹，編譯器會優化這樣的程式碼
            //所以這行程式碼等同於String c="abcde";
            //由於字串池，c和a還是指向同一物件
            String c = "a" + "b" + "c" + "d" + "e";
            Console.WriteLine(Object.ReferenceEquals(a, c));

            //明確使用new來分配記憶體
            //這時候字串池機制不能起作用，d和a指向不同物件
            Char[] chars = { 'a', 'b', 'c', 'd', 'e' };
            String d = new String(chars);
            Console.WriteLine(Object.ReferenceEquals(a, d));
            Console.Read();
        }
    }

}
