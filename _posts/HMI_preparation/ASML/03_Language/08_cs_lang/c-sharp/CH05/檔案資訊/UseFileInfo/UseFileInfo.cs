using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace NET.MST.Fifth.UseFileInfo
{
    class UseFileInfo
    {
        static void Main(string[] args)
        {
            ProcessFile();
            Console.Read();
        }
        //操作檔案的功能
        static void ProcessFile()
        {
            FileInfo info = null;
            FileInfo newinfo = null;
            try
            {
                //建立檔案
                info = new FileInfo("C:\\test1.txt");
                using (FileStream fs = info.Create()) { }
                Console.WriteLine("原始檔案：");
                ReadFileInfo(info);
                //移動檔案
                info.MoveTo("C:\\test2.txt");
                Console.WriteLine("移動後的新檔案：");
                ReadFileInfo(info);
                //複製檔案
                newinfo = info.CopyTo("C:\\test3.txt");
                Console.WriteLine("複製後的新檔案：");
                ReadFileInfo(newinfo);
            }
            finally
            {
                //刪除檔案
                if (info != null)
                    info.Delete();
                if (info != null)
                    newinfo.Delete();
            }
        }
        //讀取檔案狀態資訊的功能
        static void ReadFileInfo(FileInfo fi)
        {
            Console.WriteLine("檔案名為：" + fi.Name);
            Console.WriteLine("檔案在：" + fi.DirectoryName);
            Console.WriteLine("檔案的長度： " + fi.Length);
            Console.WriteLine("檔案建立於：" + fi.CreationTime);
            Console.WriteLine("檔案最後修改時間：" + fi.LastWriteTime);
            Console.WriteLine("檔案最後存取時間：" + fi.LastAccessTime);
            Console.WriteLine("檔案全名是：" + fi.FullName);
            Console.WriteLine("檔案副檔名是：" + fi.Extension);
        }
    }

}
