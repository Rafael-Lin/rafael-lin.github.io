using System;
using System.Threading;

namespace NET.MST.Seventh.UseLock
{
    /// <summary>
    /// 程式入口
    /// </summary>
    class MainClass
    {
        /// <summary>
        /// 測試同步效果
        /// </summary>
        static void Main(string[] args)
        {
            //開始多執行緒
            Console.WriteLine("開始測試靜態方法的同步");
            for (int i = 0; i < 5; i++)
            {
                Thread t = new Thread(Lock.Increment1);
                t.Start();
            }
            //這裡等待中的執行緒執行結束
            Thread.Sleep(5 * 1000);
            Console.WriteLine("開始測試成員方法的同步");
            Lock l = new Lock();
            //開始多執行緒
            for (int i = 0; i < 5; i++)
            {
                Thread t = new Thread(l.Increment2);
                t.Start();
            }
            Console.Read();
        }
    }


    /// <summary>
    /// 說明同步鎖
    /// </summary>
    public class Lock
    {
        //用在靜態方法中同步
        private static Object o1 = new object();
        //用在成員方法中不同
        private Object o2 = new object();
        //成員變數
        private static int i1 = 0;
        private int i2 = 0;
        /// <summary>
        /// 測試靜態方法的同步
        /// </summary>
        /// <param name="state">狀態物件</param>
        public static void Increment1(Object state)
        {
            lock (o1)
            {
                Console.WriteLine("i1的值為：{0}", i1.ToString());
                //這裡刻意製造執行緒並行機會
                //來檢查同步的功能
                Thread.Sleep(200);
                i1++;
                Console.WriteLine("i1+1後為：{0}", i1.ToString());
            }
        }
        /// <summary>
        /// 測試成員方法的同步
        /// </summary>
        /// <param name="state">狀態物件</param>
        public void Increment2(Object state)
        {
            lock (o2)
            {
                Console.WriteLine("i2的值為：{0}", i2.ToString());
                //這裡刻意製造執行緒並行機會
                //來檢查同步的功能
                Thread.Sleep(200);
                i2++;
                Console.WriteLine("i2+1後為：{0}", i2.ToString());
            }
        }
    }

}
