using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fourth.ArrayConvert
{
    class ArrayConvert
    {
        static void Main(string[] args)
        {
            String[] times = { "2008-1-1", "2008-1-2", "2008-1-3" };
            //使用不同的方法轉換
            DateTime[] result1 = OneByOne(times);
            DateTime[] result2 = ConvertAll(times);
            //結果是相同的
            foreach (DateTime item in result1)
                Console.WriteLine(item.ToString("yyyy-MM-dd"));
            foreach (DateTime item2 in result2)
                Console.WriteLine(item2.ToString("yyyy-MM-dd"));
            Console.Read();
        }
        //逐一手動轉換
        private static DateTime[] OneByOne(String[] times)
        {
            List<DateTime> result = new List<DateTime>();
            foreach (String item in times)
            {
                result.Add(DateTime.Parse(item));
            }
            return result.ToArray();
        }
        //使用Array.ConertAll方法
        private static DateTime[] ConvertAll(String[] times)
        {
            //這裡需要提供轉換演算法
            return Array.ConvertAll(times, new Converter<String, DateTime>
                (ArrayConvert.DateTimeToString));
        }
        //轉換演算法
        private static DateTime DateTimeToString(String time)
        {
            return DateTime.Parse(time);
        }
    }

}
