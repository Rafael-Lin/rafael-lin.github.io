using System;
using System.IO;
using System.Threading;
using System.Security;
using System.Security.Permissions;
namespace NET.MST.Seventh.ExecutionContextFlow
{
    partial class ExecutionContextFlow
    {
        const String _testFile = "C:\\TestContext.txt";
        static void Main(string[] args)
        {
            try
            {
                //建立測試檔案
                CreateTestFile();
                //測試當下執行緒安全內容
                Console.WriteLine("主執行緒權限測試：");
                TestPermission(null);
                //建立一個子執行緒
                Console.WriteLine("子執行緒權限測試：");
                Thread son1 = new Thread(TestPermission);
                son1.Start();
                son1.Join();
                //現在修改安全內容
                //阻止檔案呼叫
                FileIOPermission fip = new FileIOPermission
                              (FileIOPermissionAccess.AllAccess, _testFile);
                fip.Deny();
                Console.WriteLine("已阻止檔案呼叫");
                //測試當下執行緒安全內容
                Console.WriteLine("主執行緒權限測試：");
                TestPermission(null);
                //建立一個子執行緒
                Console.WriteLine("子執行緒權限測試：");
                Thread son2 = new Thread(TestPermission);
                son2.Start();
                son2.Join();
                //現在修改安全內容
                //恢復檔案呼叫
                SecurityPermission.RevertDeny();
                Console.WriteLine("已恢復檔案呼叫");
                //測試當下執行緒安全內容
                Console.WriteLine("主執行緒權限測試：");
                TestPermission(null);
                //建立一個子執行緒
                Console.WriteLine("子執行緒權限測試：");
                Thread son3 = new Thread(TestPermission);
                son3.Start();
                son3.Join();
                Console.Read();
            }
            finally
            {
                //刪除測試檔案
                DeleteTestFile();
            }
        }
    }

    /// <summary>
    /// 輔助方法
    /// </summary>
    partial class ExecutionContextFlow
    {
        /// <summary>
        /// 建立測試檔案
        /// </summary>
        static void CreateTestFile()
        {
            if (!File.Exists(_testFile))
            {
                using (FileStream fs = File.Create(_testFile))
                { }
            }
        }
        /// <summary>
        /// 清除測試檔案
        /// </summary>
        static void DeleteTestFile()
        {
            try
            {
                if (File.Exists(_testFile))
                    File.Delete(_testFile);
            }
            finally
            { }
        }
        /// <summary>
        /// 嘗試呼叫測試檔案來測試安全內容
        /// </summary>
        /// <param name="state">狀態變數</param>
        static void TestPermission(object state)
        {
            try
            {
                //嘗試呼叫檔案
                File.GetCreationTime(_testFile);
                //如果沒有例外拋出，則測試通過
                Console.WriteLine("權限測試通過");
            }
            catch (SecurityException)
            {
                //說明沒有呼叫權限
                Console.WriteLine("權限測試沒有通過");
            }
        }
    }

}
