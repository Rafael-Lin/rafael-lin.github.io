using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace NET.MST.Fifth.UseDirectoryInfo
{
    class UseDirectoryInfo
    {
        static void Main(string[] args)
        {
            ProcessDirectory();
            Console.Read();
        }
        //操作資料夾的功能
        static void ProcessDirectory()
        {
            DirectoryInfo di = null;
            try
            {
                //建立資料夾
                di = new DirectoryInfo("C:\\Test");
                di.Create();
                //為資料夾加入子資料夾
                di.CreateSubdirectory("subdic");
                //為子資料夾加入一個檔案
                FileInfo info = new FileInfo("C:\\Test\\subdic\\text.txt");
                using (FileStream fs = info.Create()) { }
                //讀取資料夾信息
                ReadDirectoryInfo(di);
                //移動資料夾
                di.MoveTo("C:\\Test2");
            }
            finally
            {
                if (di != null)
                    //刪除資料夾
                    //一起刪除子檔案和子資料夾
                    di.Delete(true);
            }
        }
        //讀取資料夾狀態資訊的功能
        static void ReadDirectoryInfo(DirectoryInfo di)
        {
            Console.WriteLine("資料夾名為：" + di.Name);
            Console.WriteLine("父資料夾為：" + di.Parent.Name);
            Console.WriteLine("資料夾建立於：" + di.CreationTime);
            Console.WriteLine("資料夾最後修改時間：" + di.LastWriteTime);
            Console.WriteLine("資料夾最後存取時間：" + di.LastAccessTime);
            Console.WriteLine("資料夾全名是：" + di.FullName);
            Console.WriteLine("資料夾中的檔案：");
            FileInfo[] fis = di.GetFiles();
            foreach (FileInfo fi in fis)
                ReadFileInfo(fi);
            Console.WriteLine("資料夾中的子資料夾：");
            DirectoryInfo[] dis = di.GetDirectories();
            foreach (DirectoryInfo sdi in dis)
                ReadDirectoryInfo(sdi);
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
