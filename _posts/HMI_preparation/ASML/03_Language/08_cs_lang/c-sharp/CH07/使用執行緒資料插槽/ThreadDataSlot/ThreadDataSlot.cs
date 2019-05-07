using System;
using System.Threading;

namespace NET.MST.Seventh.ThreadDataSlot
{
    class MainClass
    {
        /// <summary>
        /// 測試資料插槽
        /// </summary>
        static void Main()
        {
            Console.WriteLine("現在開始測試資料插槽");
            //建立五個執行緒來同時執行
            //這裡不適合用執行緒池,
            //因為執行緒池內的執行緒會被反覆使用
            //導致執行緒ID一致
            for (int i = 0; i < 5; i++)
            {
                Thread thread =
                 new Thread(ThreadDataSlot.Work);
                thread.Start();
            }
            Console.Read();
        }
    }
    /// <summary>
    /// 包含執行緒方法和資料插槽
    /// </summary>
    class ThreadDataSlot
    {
        //分配一個資料插槽，注意插槽本身是全域可見的，
        //因為這裡的分配是在所有執行緒的TLS內建立資料區塊
        static LocalDataStoreSlot _localSlot = Thread.AllocateDataSlot();
        /// <summary>
        /// 執行緒方法，運算元根據插槽來存放資料
        /// </summary>
        public static void Work()
        {
            // 這裡把執行緒ID存放在資料插槽內
            // 一個應用程式內執行緒ID不會重複
            Thread.SetData(_localSlot, Thread.CurrentThread.ManagedThreadId);
            // 檢查一下剛剛插入的資料
            Console.WriteLine("執行緒{0}內的數據是：{1}",
                Thread.CurrentThread.ManagedThreadId.ToString(),
                Thread.GetData(_localSlot).ToString());
            // 這裡執行緒休眠1秒
            Thread.Sleep(1000);
            //查看其他執行緒的執行是否干擾了當下執行緒資料插槽內的資料
            Console.WriteLine("執行緒{0}內的數據是：{1}",
                Thread.CurrentThread.ManagedThreadId.ToString(),
                Thread.GetData(_localSlot).ToString());
        }
    }

}
