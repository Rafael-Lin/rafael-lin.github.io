using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Sixth.MyAttribute
{
    /// <summary>
    /// 使用自訂特性
    /// </summary>
    [MyAttribute("UseMyAttribute")]
    class UseMyAttribute
    {
        static void Main(string[] args)
        {
            Type t = typeof(UseMyAttribute);
            //得到自訂特性
            Object[] attributes = t.GetCustomAttributes(false);
            MyAttribute att = (MyAttribute)attributes[0];
            Console.WriteLine(att.ClassName);
            Console.Read();
        }
    }
    /// <summary>
    /// 自訂的特性
    /// </summary>
    [AttributeUsage(AttributeTargets.Class)]
    public class MyAttribute : Attribute
    {
        private String _classname;
        public MyAttribute(String s)
        {
            _classname = s;
        }
        //一個唯讀屬性
        public String ClassName
        {
            get
            {
                return _classname;
            }
        }
    }

}
