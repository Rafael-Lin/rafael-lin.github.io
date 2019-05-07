using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Sixth.Reenter
{
    class Reenter
    {
        //用來造成執行緒同步問題的靜態成員
        private static int TestInt1 = 0;
        private static int TestInt2 = 0;
        static void Main(string[] args)
        {
            Console.WriteLine("System.Timers.Timer 回呼方法重入測試：");
            TimersTimerReenter();
            //這裡確保已經開始的回呼方法有機會結束
            System.Threading.Thread.Sleep(2 * 1000);
            Console.WriteLine("System.Threading.Timer 回呼方法重入測試：");
            ThreadingTimerReenter();
            Console.Read();
        }
        /// <summary>
        /// 說明System.Timers.Timer的回呼方法重入
        /// </summary>
        static void TimersTimerReenter()
        {
            System.Timers.Timer timer = new System.Timers.Timer();
            timer.Interval = 100;	//100毫秒
            timer.Elapsed += TimersTimerHandler;
            timer.Start();
            System.Threading.Thread.Sleep(2 * 1000); 	//執行2秒
            timer.Stop();
        }
        /// <summary>
        /// 說明System.Threading.Timer的回呼方法重入
        /// </summary>
        static void ThreadingTimerReenter()
        {
            //100毫秒
            using (System.Threading.Timer timer = new System.Threading.Timer
             (new System.Threading.TimerCallback(ThreadingTimerHandler), null, 0, 100))
            {
                System.Threading.Thread.Sleep(2 * 1000); //執行2秒
            }
        }
        /// <summary>
        /// System.Timers.Timer的回呼方法
        /// </summary>
        private static void TimersTimerHandler(object sender, EventArgs args)
        {
            Console.WriteLine("測試整數：" + TestInt1.ToString());
            //休眠10秒，保證方法重入
            System.Threading.Thread.Sleep(1000);
            TestInt1++;
            Console.WriteLine("增加1後測試整數：" + TestInt1.ToString());
        }
        /// <summary>
        /// System.Threading.Timer的回呼方法
        /// </summary>
        /// <param name="state">狀態參數</param>
        private static void ThreadingTimerHandler(object state)
        {
            Console.WriteLine("測試整數：" + TestInt2.ToString());
            //休眠10秒，保證方法重入
            System.Threading.Thread.Sleep(1000);
            TestInt2++;
            Console.WriteLine("增加1後測試整數：" + TestInt2.ToString());
        }
    }
}
