using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Sixth.DelegateReturn
{
    public delegate String GetStringDelegate();

    class DelegateReturn
    {
        static void Main(string[] args)
        {
            ////GetSelfDefinedString被最後加入
            //GetStringDelegate _myDelegate1 = new GetStringDelegate(GetTimeString);
            //_myDelegate1 += GetTypeName;
            //_myDelegate1 += GetSelfDefinedString;
            //Console.WriteLine(_myDelegate1());
            ////GetTimeString被最後加入
            //GetStringDelegate _myDelegate2 = new GetStringDelegate(GetSelfDefinedString);
            //_myDelegate2 += GetTypeName;
            //_myDelegate2 += GetTimeString;
            //Console.WriteLine(_myDelegate2());
            ////GetTypeName被最後加入
            //GetStringDelegate _myDelegate3 = new GetStringDelegate(GetSelfDefinedString);
            //_myDelegate3 += GetTimeString;
            //_myDelegate3 += GetTypeName;
            //Console.WriteLine(_myDelegate3());


            GetStringDelegate _myDelegate1 = new GetStringDelegate(GetTimeString);
            _myDelegate1 += GetTypeName;
            _myDelegate1 += GetSelfDefinedString;
            foreach (Delegate d in _myDelegate1.GetInvocationList())
                Console.WriteLine(d.DynamicInvoke());

            Console.Read();
        }
        static String GetTimeString()
        {
            return DateTime.Now.ToString();
        }
        static String GetTypeName()
        {
            return typeof(DelegateReturn).ToString();
        }
        static String GetSelfDefinedString()
        {
            return "我是字串。";
        }

    }
}
