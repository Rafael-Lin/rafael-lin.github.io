using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.PerfCCtor
{
    public class PerfCCtor
    {
        static void Main(string[] args)
        {
            //按照主機進行調整
            long number = 1000000000;
            Test(number);
            Console.Read();
        }
        private static void Test(long number)
        {
            long startBeforeFieldInit = DateTime.Now.Ticks;
            for (long i = 0; i < number; i++)
                //初始化器可提前執行
                BeforeFieldInit.i = 1;
            long endBeforeFieldInit = DateTime.Now.Ticks;
            long startNotBeforeFieldInit = DateTime.Now.Ticks;
            for (long j = 0; j < number; j++)
                //這裡必須檢查是否需要呼叫初始化器
                NotBeforeFieldInit.i = 1;
            long endNotBeforeFieldInit = DateTime.Now.Ticks;
            //輸出使用的時間
            Console.WriteLine("BeforeFieldInit：" +
                (endBeforeFieldInit - startBeforeFieldInit));
            Console.WriteLine("NotBeforeFieldInit：" +
                (endNotBeforeFieldInit - startNotBeforeFieldInit));
        }
    }
    public class BeforeFieldInit
    {
        public static int i = 1;
    }
    public class NotBeforeFieldInit
    {
        public static int i;
        static NotBeforeFieldInit()
        {
            i = 1;
        }
    }

}
