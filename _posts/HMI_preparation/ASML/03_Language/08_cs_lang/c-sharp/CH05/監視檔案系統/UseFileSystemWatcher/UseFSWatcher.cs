using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace NET.MST.Fifth.UseFileSystem_fsw
{
    class UseFS_fsw
    {
        //退出程式命令
        private const String Exit = "exit";
        //監視的資料夾
        private const String Folder = "C:\\Test";
        private FileSystemWatcher _fsw;
        public UseFS_fsw()
        {
            _fsw = new FileSystemWatcher();
            //建立要檢查的資料夾
            if (Directory.Exists(Folder))
                Directory.Delete(Folder, true);
            Directory.CreateDirectory(Folder);
            _fsw.Path = Folder;
            //這裡選擇最後呼叫檔案時間、最後寫檔案時間、
            //檔案名、資料夾名變化時，觸發事件
            _fsw.NotifyFilter = NotifyFilters.LastAccess
                | NotifyFilters.LastWrite | NotifyFilters.FileName | NotifyFilters.DirectoryName;
            //這裡選擇檢查所有的zip檔案
            _fsw.Filter = "*.zip";
            //為這些事件加入處理方法。.
            _fsw.Changed += new FileSystemEventHandler(OnChanged);
            _fsw.Created += new FileSystemEventHandler(OnChanged);
            _fsw.Deleted += new FileSystemEventHandler(OnChanged);
            _fsw.Renamed += new RenamedEventHandler(OnRenamed);
            //這裡開始所有事件會被觸發
            _fsw.EnableRaisingEvents = true;
        }
        //處理變化時間，變化可以包含建立、修改和刪除
        private void OnChanged(object source, FileSystemEventArgs e)
        {
            Console.WriteLine("檔案: " + e.FullPath + " " + e.ChangeType);
        }
        //處理重新命名事件
        private static void OnRenamed(object source, RenamedEventArgs e)
        {
            Console.WriteLine("檔案: {0} 重新命名為： {1}", e.OldFullPath, e.FullPath);
        }
        static void Main(string[] args)
        {
            try
            {
                UseFS_fsw ws = new UseFS_fsw();
                while (Console.ReadLine() != Exit) ;
            }
            finally
            {
                //清理測試資料
                if (Directory.Exists(Folder))
                    Directory.Delete(Folder, true);
            }
        }
    }

}
