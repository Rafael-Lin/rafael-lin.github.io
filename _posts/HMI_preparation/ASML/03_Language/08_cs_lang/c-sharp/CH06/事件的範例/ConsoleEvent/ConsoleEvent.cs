using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace NET.MST.Sixth.ConsoleEvent
{
    class ConsoleEvent
    {
        static void Main(string[] args)
        {
            //測試事件
            ConsoleManager cm = new ConsoleManager();
            Log log = new Log(cm);
            cm.ConsoleOutput("測試控制台輸出事件");
            cm.ConsoleOutput("測試控制台輸出事件");
            cm.ConsoleOutput("測試控制台輸出事件");
            Console.Read();
        }
    }

    /// <summary>
    /// 管理主控台，在輸出前發送輸出事件
    /// </summary>
    public class ConsoleManager
    {
        //定義控制台事件成員物件
        public event EventHandler<ConsoleEventArgs> ConsoleEvent;
        /// <summary>
        /// 控制台輸出
        /// </summary>
        /// <param name="message">用來建立事件參數</param>
        public void ConsoleOutput(String message)
        {
            //先發送事件
            ConsoleEventArgs args = new ConsoleEventArgs(message);
            SendConsoleEvent(args);
            //輸出
            Console.WriteLine(message);
        }
        /// <summary>
        /// 負責發送事件
        /// </summary>
        /// <param name="args">事件參數</param>
        protected virtual void SendConsoleEvent(ConsoleEventArgs args)
        {
            //定義一個臨時的參考變數，這樣可以確保多執行緒呼叫時不會發生問題
            EventHandler<ConsoleEventArgs> temp = ConsoleEvent;
            if (temp != null)
                temp(this, args);
        }
    }

    /// <summary>
    /// 自訂一個事件參數類別
    /// </summary>
    public class ConsoleEventArgs : EventArgs
    {
        //控制台輸出的消息
        private String _message;
        /// <summary>
        /// 建構式
        /// </summary>
        public ConsoleEventArgs()
            : base()
        {
            _message = String.Empty;
        }
        /// <summary>
        /// 建構式
        /// </summary>
        public ConsoleEventArgs(String message)
            : base()
        {
            _message = message;
        }
        /// <summary>
        /// 唯讀屬性
        /// </summary>
        public String Message
        {
            get
            {
                return _message;
            }
        }
    }

    /// <summary>
    /// Log類別，訂閱控制台輸出事件
    /// </summary>
    public class Log
    {
        //Log檔案路徑
        private const String LogFile = "C:\\TestLog.txt";
        public Log(ConsoleManager cm)
        {
            //訂閱控制台輸出事件
            cm.ConsoleEvent += WriteLog;
        }
        /// <summary>
        /// 事件處理方法，注意參數固定模式
        /// </summary>
        /// <param name="send">事件發送者</param>
        /// <param name="args">事件參數</param>
        private void WriteLog(object send, EventArgs args)
        {
            //檔案不存在的話，建立新檔案
            if (!File.Exists(LogFile))
            {
                using (FileStream fs = File.Create(LogFile)) { }
            }
            FileInfo info = new FileInfo(LogFile);
            using (StreamWriter sw = info.AppendText())
            {
                sw.WriteLine(DateTime.Now.ToString() + "|" +
                    send.ToString() + "|" +
                    ((ConsoleEventArgs)args).Message);
            }
        }
    }

}
