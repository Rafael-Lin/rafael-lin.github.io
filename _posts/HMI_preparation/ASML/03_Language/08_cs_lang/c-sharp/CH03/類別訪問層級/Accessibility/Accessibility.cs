using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.Accessibility
{
    public class Accessibility
    {
        static void Main(string[] args)
        {
            AccessibilityBase ta = new AccessibilityBase();
            Console.WriteLine(ta.myprotectedinternal);
            Console.WriteLine(ta.mypublic);
            Console.Read();
        }
    }

    public class AccessibilityBase
    {
        public String mypublic = "我是 public";
        protected internal String myprotectedinternal = "我是 protected internal";
        private String myprivate = "我是 private";
        protected String myprotected = "我是 protected";
    }
}
