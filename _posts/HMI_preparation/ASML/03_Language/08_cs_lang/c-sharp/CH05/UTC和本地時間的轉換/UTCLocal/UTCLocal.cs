using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fifth.UTCLocal
{
    class UTCLocal
    {
        static void Main(string[] args)
        {
            DateTime date = DateTime.Now;
            Console.WriteLine("當前本地時間：" + date);
            Console.WriteLine("Kind旗標：" + date.Kind);
            //轉換到UTC時間
            DateTime newdate = date.ToUniversalTime();
            Console.WriteLine("轉換到UTC時間：" + newdate);
            Console.WriteLine("新的Kind旗標：" + newdate.Kind);
            //轉換到本地時間
            DateTime back = newdate.ToLocalTime();
            Console.WriteLine("轉換回本地時間：" + back);
            Console.WriteLine("轉換回後的Kind旗標：" + back.Kind);
            Console.Read();
        }
    }

}
