using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.Overload
{
    public class Overload
    {
        private String text = "我是一個字串";
        //三個方法實現了Print方法的三個多載版本
        public String Print()
        {
            return text;
        }
        // Print方法的多載版本
        public String Print(int start, int end)
        {
            return text.Substring(start, end - start);
        }
        // Print方法的多載版本
        public String Print(char fill)
        {
            StringBuilder builder = new StringBuilder();
            foreach (char c in text)
            {
                builder.Append(c);
                builder.Append(fill);
            }
            builder.Remove(builder.Length - 1, 1);
            return builder.ToString();
        }
        static void Main(string[] args)
        {
            Overload ol = new Overload();
            //傳入不同的參數
            //Print的不同多載版本將被呼叫
            Console.WriteLine(ol.Print());
            Console.WriteLine(ol.Print(2, 4));
            Console.WriteLine(ol.Print('/'));
            Console.Read();
        }
    }

}
