using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.ConstructorVirtualProblem
{
    class ConstructorVirtual
    {
        static void Main(string[] args)
        {
            try
            {
				Console.WriteLine("try this");
                B b = new B();
            }
            catch (Exception ex)
            {
                //這裡看到問題
				Console.WriteLine("hello");
                Console.WriteLine(ex.GetType().ToString());
            }
            Console.Read();
        }
    }
    class A
    {
        protected Ref my;
        public A()
        {
            my = new Ref();
            //建構式中呼叫了虛擬方法，問題根源
            Console.WriteLine(ToString());
        }
        //虛擬方法
        public override string ToString()
        {
            //使用了內部成員
            return my.s;
        }
    }
    //A的衍生類別
    class B : A
    {
        private Ref my2;
        public B()
            : base()
        {
            my2 = new Ref();
        }
        //覆寫虛擬方法
        public override string ToString()
        {
            //使用了內部成員
            return my2.s;
        }
    }
    //一個簡單的參考型別
    class Ref
    {
        public string s = "我是一個物件";
    }

}
