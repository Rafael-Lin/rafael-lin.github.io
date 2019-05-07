using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.Constructor
{
    class Constructor
    {
        static void Main(string[] args)
        {
            //初始化一個繼承鏈上的底層類別
            C c = new C();
            Console.Read();
        }
    }
    //一個簡單的參考型別
    public class Ref
    {
        public Ref(string s)
        {
            Console.WriteLine(s);
        }
    }
    //基底類別型別
    public class Base
    {
        public Ref basestring = new Ref("Base初始設定式");
        public Base()
        {
            Console.WriteLine("Base建構式");
        }
    }
    //繼承基底類別
    public class A : Base
    {
        public Ref astring = new Ref("A初始設定式");
        public A()
            : base()
        {
            Console.WriteLine("A建構式");
        }
    }
    //繼承A
    public class B : A
    {
        public Ref bstring = new Ref("B初始設定式");
        public B()
            : base()
        {
            Console.WriteLine("B建構式");
        }
    }
    //繼承B
    public class C : B
    {
        public Ref cstring = new Ref("C初始設定式");
        public C()
            : base()
        {
            Console.WriteLine("C建構式");
        }
    }

}
