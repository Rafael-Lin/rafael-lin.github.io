using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.Properties
{
    class Properties
    {
        static void Main(string[] args)
        {
            Normal normal = new Normal();
            normal.SetS("傳統的實作方式");
            Console.WriteLine(normal.GetS());
            Property p = new Property();
            p.S = "屬性實作";
            Console.WriteLine(p.S);
            Console.Read();
        }
    }
    //傳統的GetXXX和SetXXX函數
    public class Normal
    {
        private String _s;
        //Get函數
        public String GetS()
        {
            return _s;
        }
        //Set函數
        public void SetS(String s)
        {
            _s = s;
        }
    }
    //使用屬性
    public class Property
    {
        private String _s;
        public String S
        {
            get
            {
                return _s;
            }
            set
            {
                _s = value;
            }
        }
    }

}
