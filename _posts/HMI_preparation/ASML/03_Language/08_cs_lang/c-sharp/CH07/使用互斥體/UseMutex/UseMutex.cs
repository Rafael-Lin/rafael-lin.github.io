using System;
using System.Threading;
using System.IO;
using System.Text;
using System.Diagnostics;
namespace NET.MST.Seventh.UseMutex
{
    /// <summary>
    /// 這裡測試Mutex的作用，程式本身是單執行緒的
    /// 但是最終測試時將多個處理序同時執行
    /// </summary>
    class UseMutex
    {
        const String _testFile = "C:\\TestMutex.txt";
        /// <summary>
        /// 這個互斥體保證所有的處理序都能得到同步
        /// </summary>
        static Mutex mutex = new Mutex(false, "TestMutex");
        /// <summary>
        /// 測試互斥體
        /// </summary>
        static void Main(string[] args)
        {
            //休眠3秒以空出時間來啟動其他處理序
            Thread.Sleep(3000);
            DoWork();
            mutex.Close();
            Console.Read();
        }
        /// <summary>
        /// 往檔案裡寫連續的內容
        /// </summary>
        static void DoWork()
        {
            long d1 = DateTime.Now.Ticks;
            //進入互斥
            mutex.WaitOne();
            long d2 = DateTime.Now.Ticks;
            Console.WriteLine("經過了{0}個Tick後處理序{1}得到互斥體，進入臨界區程式碼。",
                (d2 - d1).ToString(), Process.GetCurrentProcess().Id.ToString());
            try
            {
                if (!File.Exists(_testFile))
                {
                    using (FileStream fs = File.Create(_testFile))
                    { }
                }
                for (int i = 0; i < 5; i++)
                {
                    //確保每次檔案都被關閉再重新打開
                    //確定由mutex來同步，而不是IO機制
                    using (FileStream fs = File.Open(_testFile, FileMode.Append))
                    {
                        String content = "【處理序" + Process.GetCurrentProcess().Id.ToString() +
                            "】:" + i.ToString() + "\r\n";
                        Byte[] data = Encoding.Default.GetBytes(content);
                        fs.Write(data, 0, data.Length);
                    }
                    //模擬做了其他工作
                    Thread.Sleep(300);
                }
            }
            finally
            {
                //退出互斥
                mutex.ReleaseMutex();
            }
        }
    }
}
