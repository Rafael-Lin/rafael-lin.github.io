using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fourth.GenericClass
{
    class MainClass
    {
        static void Main(string[] args)
        {
            //從開放型別到封閉型別
            GenericClass<String> gc = new GenericClass<String>("我是泛型");
            Console.WriteLine(gc);
            Console.Read();
        }
    }
    //一個簡單的泛型類別
    public class GenericClass<T>
    {
        T my;
        public GenericClass(T t)
        {
            my = t;
        }
        public override string ToString()
        {
            return my.ToString();
        }
    }

}
