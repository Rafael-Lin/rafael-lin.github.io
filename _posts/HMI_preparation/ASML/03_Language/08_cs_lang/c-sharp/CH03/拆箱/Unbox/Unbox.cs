using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.Unbox
{
    class Unbox
    {
        static void Main(string[] args)
        {
            try
            {
                Int32 i = 3;
                //這裡裝箱
                Object o = i;
                //這裡拆箱, 型別轉換失敗
                Int16 j = (Int16)o;
            }
            catch (InvalidCastException e)
            {
                Console.WriteLine(e);
            }
            Int32 ii = 3;
            //這裡裝箱
            Object oo = ii;
            //這裡拆箱
            Int16 jj = (Int16)(Int32)oo;
            Console.WriteLine("拆箱成功！");
            Console.Read();
        }

    }
}
