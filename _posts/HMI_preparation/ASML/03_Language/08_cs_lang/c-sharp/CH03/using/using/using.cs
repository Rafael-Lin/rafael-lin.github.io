using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.Using
{
    public class Using
    {
        static void Main(string[] args)
        {
            try
            {
                //使用using
                using (MyDispose md = new MyDispose())
                {
                    md.DoWork();
                    //拋出一個例外來測試using
                    throw new Exception("得到一個例外");
                }
            }
            catch { }
            finally
            {
                Console.Read();
            }
        }
    }
    //僅僅用來作為測試，不使用任何非託管資源
    public class MyDispose : IDisposable
    {
        public void Dispose()
        {
            Console.WriteLine("Dispose方法被呼叫");
        }
        public void DoWork()
        {
            Console.WriteLine("做了很多工作");
        }
    }

}
