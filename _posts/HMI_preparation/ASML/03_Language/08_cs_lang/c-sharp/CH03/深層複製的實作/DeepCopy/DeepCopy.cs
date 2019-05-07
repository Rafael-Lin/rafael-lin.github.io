using System;
using System.Collections.Generic;
using System.Text;

namespace NET.NST.Third.DeepCopy
{
    public class Program
    {
        static void Main(string[] args)
        {
            DeepCopy dc = new DeepCopy();
            dc._i = 10;
            dc._a = new A();
            DeepCopy deepclone = (DeepCopy)dc.Clone();
            DeepCopy shadowclone = (DeepCopy)dc.MemberwiseClone();
            //深層複製的複製物件將擁有自己的參考型別成員物件，
            //所以這裡的設定不會影響原始物件
            deepclone._a._s = "我是深層複製的A";
            Console.WriteLine(dc);
            Console.WriteLine(deepclone);
            Console.WriteLine("\r\n");
            //表層複製的複製物件共用原始物件的參考型別成員物件，
            //這裡的設定將影響原始物件
            shadowclone._a._s = "我是表層複製的A";
            Console.WriteLine(dc);
            Console.WriteLine(shadowclone);
            Console.Read();
        }
    }
    public class DeepCopy : ICloneable
    {
        public int _i = 0;
        public A _a = new A();
        public object Clone()
        {
            //實現深層複製
            DeepCopy newdc = new DeepCopy();
            newdc._a = new A();
            newdc._a._s = _a._s;
            newdc._i = _i;
            return newdc;
        }
        //實現表層複製
        public new object MemberwiseClone()
        {
            return base.MemberwiseClone();
        }
        public override string ToString()
        {
            return "I的值為：" + _i.ToString() + "，A 為：" + _a._s;
        }
    }
    //包含一個參考成員的類別
    public class A
    {
        public String _s = "我是原始A";
    }

}
