using System;
using System.Threading;

namespace NET.MST.Seventh.SynchroThis
{
    class MainClass
    {
        /// <summary>
        /// 使用SynchroThis
        /// </summary>
        static void Main(string[] args)
        {
            SynchroThis st = new SynchroThis();
            //惡意的使用者
            Monitor.Enter(st);
            //正常的使用者
            //但是受到惡意使用者的影響
            //這裡的程式碼完全正確，同步區塊卻已經被鎖住
            Thread t = new Thread(st.Work);
            t.Start();
            t.Join();
            //程式不會執行到這裡
            Console.WriteLine("使用結束");
            Console.Read();
        }
    }
    /// <summary>
    /// 使用this來同步執行緒
    /// 缺乏健壯性的類別
    /// </summary>
    class SynchroThis
    {
        private int i = 0;
        /// <summary>
        /// 使用this來同步執行緒
        /// </summary>
        /// <param name="state">狀態物件</param>
        public void Work(Object state)
        {
            lock (this)
            {
                Console.WriteLine("i的值為：{0}", i.ToString());
                i++;
                //模擬做了其他工作
                Thread.Sleep(200);
                Console.WriteLine("i自增1後的值為：{0}", i.ToString());
            }
        }
    }

}
