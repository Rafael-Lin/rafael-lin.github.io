using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.OverrideNew
{
    public class OverrideNew
    {
        static void Main(string[] args)
        {
            //測試覆寫和隱藏的功能
            OverrideBase ob = new OverrideBase();
            NewBase nb = new NewBase();
            Console.WriteLine(ob.ToString() + ":" + ob.GetString());
            Console.WriteLine(nb.ToString() + ":" + nb.GetString());
            Console.WriteLine("\r\n");
            //覆寫和隱藏的區別
            Base obb = ob as Base;
            Base nbb = nb as Base;
            Console.WriteLine(obb.ToString() + ":" + obb.GetString());
            Console.WriteLine(nbb.ToString() + ":" + nbb.GetString());
            Console.Read();
        }
    }
    //基底類別
    class Base
    {
        public virtual string GetString()
        {
            return "我是基底類別";
        }
    }
    //覆寫
    class OverrideBase : Base
    {
        public override string GetString()
        {
            return "我覆寫了基底類別";
        }
    }
    //隱藏
    class NewBase : Base
    {
        public new virtual string GetString()
        {
            return "我隱藏了基底類別";
        }
    }

}
