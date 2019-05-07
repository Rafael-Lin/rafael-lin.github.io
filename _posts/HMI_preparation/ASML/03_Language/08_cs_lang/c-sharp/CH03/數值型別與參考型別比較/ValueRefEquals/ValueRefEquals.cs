using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.ValueRefEquals
{
    public class ValueRefEquals
    {
        static void Main(string[] args)
        {
            //參考型別
            Ref ref1 = new Ref(1);
            Ref ref2 = new Ref(1);
            //數值型別
            Val val1 = new Val(1);
            Val val2 = new Val(1);
            //輸出
            Console.WriteLine(ref1.Equals(ref2));
            Console.WriteLine(val1.Equals(val2));
            Console.Read();
        }
    }


    /// <summary>
    /// 一個簡單的參考型別
    /// </summary>
    public class Ref
    {
        private int _int;
        public Ref(int i)
        {
            _int = i;
        }
        public int I
        {
            get
            {
                return _int;
            }
            set
            {
                _int = value;
            }
        }
        public override string ToString()
        {
            return "I 的值為：" + _int.ToString();
        }
    }
    /// <summary>
    /// 一個簡單的數值型別
    /// </summary>
    public struct Val
    {
        private int _int;
        public Val(int i)
        {
            _int = i;
        }
        public int I
        {
            get
            {
                return _int;
            }
            set
            {
                _int = value;
            }
        }
        public override string ToString()
        {
            return "I 的值為：" + _int.ToString();
        }
    }

}
