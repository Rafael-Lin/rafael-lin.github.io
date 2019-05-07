using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.People
{
    public class Program
    { 
        static void Main(string[] args)
        {
            Console.Read();
        }
    }

    public class People
    {
        protected int MaxNameLength = 8;
        protected String _name;
        public String Name
        {
            get
            {
                return _name;
            }
            //受保護的set
            protected set
            {
                //長度檢查
                if (value.Length >= MaxNameLength ||
                    value.Length <= 0)
                    throw new ArgumentException("名字長度不合法。");
                _name = value;
            }
        }
    }

}
