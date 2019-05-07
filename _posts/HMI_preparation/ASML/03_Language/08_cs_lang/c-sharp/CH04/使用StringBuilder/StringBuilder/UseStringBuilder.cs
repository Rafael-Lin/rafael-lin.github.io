using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fourth.StringBuilder
{
    class TestStringBuilder
    {
        private const String item = "一個項目";
        private const String split = ";";
        static void Main(string[] args)
        {
            int number = 10000;
            //使用StringBuilder
            long sbStart = DateTime.Now.Ticks;
            UseStringBuilder(number);
            long sbEnd = DateTime.Now.Ticks;
            //不使用StringBuilder
            long nsbStart = DateTime.Now.Ticks;
            NotUseStringBuilder(number);
            long nsbEnd = DateTime.Now.Ticks;
            //列印串接字串所花的時間
            Console.WriteLine("使用StringBuilder: " + (sbEnd - sbStart).ToString());
            Console.WriteLine("不使用StringBuilder: " + (nsbEnd - nsbStart).ToString());
            Console.Read();
        }
        //使用StringBuilder串接字串
        static String UseStringBuilder(int number)
        {
            System.Text.StringBuilder sb = new System.Text.StringBuilder();
            for (int i = 0; i < number; i++)
            {
                sb.Append(item);
                sb.Append(split);
            }
            sb.Remove(sb.Length - 1, 1);
            return sb.ToString();
        }
        //不使用StringBuilder串接字串
        static String NotUseStringBuilder(int number)
        {
            String result = "";
            for (int i = 0; i < number; i++)
            {
                result += item;
                result += split;
            }
            return result;
        }
    }

}
