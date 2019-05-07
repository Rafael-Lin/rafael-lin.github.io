using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.Accessibility
{
    public class RefAccessibility : AccessibilityBase
    {
        static void Main(string[] args)
        {
            RefAccessibility rea = new RefAccessibility();
            rea.TestAccessibility();
            Console.Read();
        }

        public void TestAccessibility()
        {
            Console.WriteLine(myprotectedinternal);
            Console.WriteLine(mypublic);
            Console.WriteLine(myprotected);
        }
    }
}