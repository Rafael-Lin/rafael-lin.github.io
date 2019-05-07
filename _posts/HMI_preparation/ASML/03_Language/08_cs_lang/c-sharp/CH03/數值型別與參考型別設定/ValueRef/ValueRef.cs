using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.ValueRef
{
    public class ValueRef
    {
        static void Main(string[] args)
        {
            //測試參考型別的設定
            Ref ref1 = new Ref(1);
            Ref ref2 = ref1;
            ref2.I = 2;
            //測試數值型別的設定
            Val val1 = new Val(1);
            Val val2 = val1;
            val2.I = (2);
            //輸出
            Console.WriteLine("ref1 " + ref1);
            Console.WriteLine("ref2 " + ref2);
            Console.WriteLine("val1 " + val1);
            Console.WriteLine("val2 " + val2);
            Console.Read();
            // 2,2,1,2
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
