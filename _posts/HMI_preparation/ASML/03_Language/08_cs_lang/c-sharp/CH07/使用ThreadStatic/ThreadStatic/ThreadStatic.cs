using System;
using System.Threading;

namespace NET.MST.Seventh.ThreadStatic
{
    class MainClass
    {
        /// <summary>
        /// 測試執行緒靜態欄位
        /// </summary>
        static void Main()
        {
            Console.WriteLine("現在開始測試執行緒靜態欄位");
            //建立五個執行緒來同時執行
            //這裡不適合用執行緒池,
            //因為執行緒池內的執行緒會被反覆使用
            //導致執行緒ID一致
            for (int i = 0; i < 5; i++)
            {
                Thread thread =
                 new Thread(ThreadStatic.Work);
                thread.Start();
            }
            Console.Read();
        }
    }
    /// <summary>
    /// 包含執行緒靜態資料
    /// </summary>
    class ThreadStatic
    {
        //數值型別的執行緒靜態資料
        [ThreadStatic]
        static int _threadid = 0;
        //參考型別的執行緒靜態資料
        static Ref _refthreadid = new Ref();
        /// <summary>
        /// 執行緒方法，操作執行緒靜態資料
        /// </summary>
        public static void Work()
        {
            // 儲存執行緒ID
            // 一個應用程式內執行緒ID不會重複
            _threadid = Thread.CurrentThread.ManagedThreadId;
            _refthreadid._id = Thread.CurrentThread.ManagedThreadId;
            // 檢查一下剛剛插入的資料
            Console.WriteLine("[{0}執行緒]：執行緒靜態值變數：{1}" +
                "，執行緒靜態參考變數：{2}",
                Thread.CurrentThread.ManagedThreadId.ToString(), _threadid, _refthreadid._id.ToString());
            // 這裡執行緒休眠1秒
            Thread.Sleep(1000);
            //檢查其他執行緒的執行是否干擾了當下執行緒靜態資料
            Console.WriteLine("[{0}執行緒]：執行緒靜態值變數：{1} ，執行緒靜態參考變數：{2}",
                Thread.CurrentThread.ManagedThreadId.ToString(),
                _threadid, _refthreadid._id.ToString());
        }
    }
    /// <summary>
    /// 簡單參考型別
    /// </summary>
    class Ref
    {
        public int _id;
    }

}
