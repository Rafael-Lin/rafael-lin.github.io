using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace NET.MST.Sixth.DelegateLog
{
    class UseLog
    {
        /// <summary>
        /// 使用Log管理類別來記錄Log
        /// </summary>
        static void Main(string[] args)
        {
            //使用Log
            using (LogManager logmanager =
                new LogManager(Type.GetType("NET.MST.Sixth.DelegateLog.UseLog"), "C:\\TestLog.txt"))
            {
                //記錄Log
                logmanager.WriteLog("新建了Log", LogType.Debug);
                logmanager.WriteLog("寫資料", LogType.Debug);
                logmanager.UseUTCTime();
                logmanager.WriteLog("現在是UTC時間", LogType.Debug);
                logmanager.UseLocalTime();
                logmanager.WriteLog("回到本地時間", LogType.Debug);
                logmanager.WriteLog("發生錯誤", LogType.Error);
                logmanager.WriteLog("準備退出", LogType.Info);
            }
        }
    }


    /// <summary>
    /// Log的種類
    /// </summary>
    public enum LogType
    {
        Debug,
        Trace,
        Info,
        Warn,
        Error
    }
    /// <summary>
    /// Log委派類別，由Log使用者直接決定如何完成寫Log的工作
    /// </summary>
    /// <param name="content">Log內容</param>
    /// <param name="type">Log種類</param>
    public delegate void Log(String content, LogType type);


    /// <summary>
    /// Log管理類別，基本成員和建構式
    /// </summary>
    public sealed partial class LogManager : IDisposable
    {
        //寫Log的元件
        private Type _componentType;
        //Log檔名
        private String _logfile;
        //Log檔案讀寫流
        private FileStream _fs;
        //用來寫Log的委派
        public Log WriteLog;
        //lock用的物件
        private static object mutext = new object();
        //嚴格控制無參數的建構式
        private LogManager()
        {
            WriteLog = new Log(PrepareLogFile);
            WriteLog += OpenStream; //打開流
            WriteLog += AppendLocalTime;		//加入本地時間
            WriteLog += AppendSeperator;		//加入分隔符號
            WriteLog += AppendComponentType;	//加入模組種類
            WriteLog += AppendSeperator;		//加入分隔符號
            WriteLog += AppendType;			//加入Log種類
            WriteLog += AppendSeperator;		//加入分隔符號
            WriteLog += AppendContent;		//加入內容
            WriteLog += AppendNewLine;		//加入分行符號
            WriteLog += CloseStream;			//關閉流
        }
        /// <summary>
        /// 建構式
        /// </summary>
        /// <param name="type">使用該Log的種類</param>
        /// <param name="file">Log檔案完整路徑</param>
        public LogManager(Type type, String file)
            : this()
        {
            _logfile = file;
            _componentType = type;

        }
        /// <summary>
        /// 釋放FileStream物件
        /// </summary>
        public void Dispose()
        {
            if (_fs != null)
                _fs.Dispose();
            GC.SuppressFinalize(this);
        }
        ~LogManager()
        {
            if (_fs != null)
                _fs.Dispose();
        }
    }

    /// <summary>
    /// 委派鏈上的方法（和Log檔案有關的操作）
    /// </summary>
    public sealed partial class LogManager : IDisposable
    {
        /// <summary>
        /// 如果Log檔案不存在，則新建Log檔案
        /// </summary>
        private void PrepareLogFile(String content, LogType type)
        {
            //只允許單執行緒建立Log檔
            lock (mutext)
            {
                if (!File.Exists(_logfile))
                    using (FileStream fs = File.Create(_logfile))
                    { }
            }
        }
        /// <summary>
        /// 打開檔案流
        /// </summary>
        private void OpenStream(String content, LogType type)
        {
            _fs = File.Open(_logfile, FileMode.Append);
        }
        /// <summary>
        /// 關閉檔案流
        /// </summary>
        private void CloseStream(String content, LogType type)
        {
            _fs.Close();
            _fs.Dispose();
        }
    }

    /// <summary>
    /// 委派鏈上的方法（和Log時間有關的操作）
    /// </summary>
    public sealed partial class LogManager : IDisposable
    {
        /// <summary>
        /// 為Log加入目前UTC時間
        /// </summary>
        private void AppendUTCTime(String content, LogType type)
        {
            //得到目前UTC時間
            String time = DateTime.Now.ToUniversalTime().ToString();
            Byte[] con = Encoding.Default.GetBytes(time);
            _fs.Write(con, 0, con.Length);
        }
        /// <summary>
        /// 為Log加入本地時間
        /// </summary>
        private void AppendLocalTime(String content, LogType type)
        {
            //得到目前本地時間
            String time = DateTime.Now.ToLocalTime().ToString();
            Byte[] con = Encoding.Default.GetBytes(time);
            _fs.Write(con, 0, con.Length);
        }
    }

    /// <summary>
    /// 委派鏈上的方法（和Log內容有關的操作）
    /// </summary>
    public sealed partial class LogManager : IDisposable
    {
        /// <summary>
        /// 加入Log內容
        /// </summary>
        private void AppendContent(String content, LogType type)
        {
            Byte[] con = Encoding.Default.GetBytes(content);
            _fs.Write(con, 0, con.Length);
        }
        /// <summary>
        /// 為Log加入元件種類
        /// </summary>
        private void AppendComponentType(String content, LogType type)
        {
            Byte[] con = Encoding.Default.GetBytes(_componentType.ToString());
            _fs.Write(con, 0, con.Length);
        }
        /// <summary>
        /// 加入Log種類
        /// </summary>
        private void AppendType(String content, LogType type)
        {
            String typestring = String.Empty;
            switch (type)
            {
                //針對不同的Log種類來記錄
                case LogType.Debug:
                    typestring = "Debug";
                    break;
                case LogType.Error:
                    typestring = "Error";
                    break;
                case LogType.Info:
                    typestring = "Info";
                    break;
                case LogType.Trace:
                    typestring = "Trace";
                    break;
                case LogType.Warn:
                    typestring = "Warn";
                    break;
                default:
                    typestring = "";
                    break;
            }
            Byte[] con = Encoding.Default.GetBytes(typestring);
            _fs.Write(con, 0, con.Length);
        }
    }

    /// <summary>
    /// 委派鏈上的方法（和Log的格式控制有關的操作）
    /// </summary>
    public sealed partial class LogManager : IDisposable
    {

        /// <summary>
        /// 加入分隔符號
        /// </summary>
        private void AppendSeperator(String content, LogType type)
        {
            Byte[] con = Encoding.Default.GetBytes(" | ");
            _fs.Write(con, 0, con.Length);
        }
        /// <summary>
        /// 加入分行符號
        /// </summary>
        private void AppendNewLine(String content, LogType type)
        {
            Byte[] con = Encoding.Default.GetBytes("\r\n");
            _fs.Write(con, 0, con.Length);
        }
    }

    /// <summary>
    /// 修改所使用的時間種類
    /// </summary>
    public sealed partial class LogManager : IDisposable
    {
        /// <summary>
        /// 設定使用UTC時間
        /// </summary>
        public void UseUTCTime()
        {
            WriteLog = new Log(PrepareLogFile);
            WriteLog += OpenStream;
            //這裡加入記錄UTC時間的方法
            WriteLog += AppendUTCTime;
            WriteLog += AppendSeperator;
            WriteLog += AppendComponentType;
            WriteLog += AppendSeperator;
            WriteLog += AppendType;
            WriteLog += AppendSeperator;
            WriteLog += AppendContent;
            WriteLog += AppendNewLine;
            WriteLog += CloseStream;
        }
        /// <summary>
        /// 設定使用本地時間
        /// </summary>
        public void UseLocalTime()
        {
            WriteLog = new Log(PrepareLogFile);
            WriteLog += OpenStream;
            //這裡加入記錄本地時間的方法
            WriteLog += AppendLocalTime;
            WriteLog += AppendSeperator;
            WriteLog += AppendComponentType;
            WriteLog += AppendSeperator;
            WriteLog += AppendType;
            WriteLog += AppendSeperator;
            WriteLog += AppendContent;
            WriteLog += AppendNewLine;
            WriteLog += CloseStream;
        }
    }

}
