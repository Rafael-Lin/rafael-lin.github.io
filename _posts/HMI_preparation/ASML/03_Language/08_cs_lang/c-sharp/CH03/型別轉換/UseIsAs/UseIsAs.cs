using System;
using System.Collections.Generic;
using System.Text;

namespace UseIsAs
{
    public class UseIsAs
    {
        static void Main(string[] args)
        {
            Base b = new Base();
            Son s = new Son();
            String mystring = "我的型別不吻合";
            DateTime n = DateTime.Now;
            //對三套方法進行驗證，結果應該是一樣的
            CastToBase1(b);
            CastToBase1(s);
            CastToBase1(mystring);
            CastToBase1(n);
            CastToBase2(b);
            CastToBase2(s);
            CastToBase2(mystring);
            CastToBase2(n);
            CastToBase3(b);
            CastToBase3(s);
            CastToBase3(mystring);
            CastToBase3(n);
            Console.Read();
        }
        //用is進行轉換
        static void CastToBase1(Object o)
        {
            if (o is Base)
            {
                Base b = (Base)o;
                Console.WriteLine(b.ToString());
            }
            else
                Console.WriteLine("轉換失敗");
        }
        //用as進行轉換
        static void CastToBase2(Object o)
        {
            Base b = o as Base;
            if (b != null)
                Console.WriteLine(b.ToString());
            else
                Console.WriteLine("轉換失敗");
        }
        static void CastToBase3(Object o)
        {
            try
            {
                Base b = (Base)o;
                Console.WriteLine(b.ToString());
            }
            catch
            {
                Console.WriteLine("轉換失敗");
            }
        }
    }

    /// <summary>
    /// 簡單的基底類別和子類別
    /// </summary>
    public class Base
    {
        public override string ToString()
        {
            return "我是基底類別";
        }
    }
    public class Son : Base
    {
        public override string ToString()
        {
            return "我是子類別";
        }
    }

}
