using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Sixth.AllowMultiple
{
    //這次多次宣告了My特性
    [My("Class1")]
    [My("Class2")]
    [My("Class1")]
    class AllowMultiple
    {
        static void Main(string[] args)
        {
        }
    }
    /// <summary>
    /// 使用AttributeUsage限定使用範圍
    /// 並且允許在同一元素上多次宣告
    /// </summary>
    [AttributeUsage(AttributeTargets.Class, AllowMultiple = true)]
    class MyAttribute : Attribute
    {
        private String _s;
        public MyAttribute(String s)
        {
            _s = s;
        }
    }

}
