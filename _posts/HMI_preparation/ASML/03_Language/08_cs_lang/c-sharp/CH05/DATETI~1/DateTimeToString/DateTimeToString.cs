using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fifth.DateTimeToString
{
    class DateTimeToString
    {
        static void Main(string[] args)
        {
            DateTime now = DateTime.Now;
            //嘗試各種format
            Display("d", now);
            Display("D", now);
            Display("f", now);
            Display("F", now);
            Display("g", now);
            Display("G", now);
            Display("m", now);
            Display("r", now);
            Display("s", now);
            Display("t", now);
            Display("T", now);
            Display("u", now);
            Display("U", now);
            Display("T", now);
            Display("y", now);
            Display("dd-MM-yy", now);
            Console.Read();
        }
        static void Display(String format, DateTime time)
        {
            //相依本機區域設定
            Console.WriteLine("使用區域設定 " + format + ":" + time.ToString(format));
            Console.WriteLine("不使用區域設定 " + format + ":" + time.ToString(format,
                //不相依本機區域設定
                System.Globalization.DateTimeFormatInfo.InvariantInfo) + "\r\n");
        }
    }

}
