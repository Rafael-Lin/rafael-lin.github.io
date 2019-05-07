using System;
namespace NET.MST.Sixth.SimpleDelegate
{
    class SimpleDelegate
    {
        /// <summary>
        /// 定義的委派。
        /// </summary>
        /// <param name="i">接受一個整數參數</i>
        public delegate void TestDelegate(int i);
        static void Main(string[] args)
        {
            //呼叫委派方法
            TestDelegate d = new TestDelegate(PrintMessage1);
            d(0);
            d(1);
            Console.Read();
        }
        /// <summary>
        /// 一個靜態方法，符合TestDelegate的定義
        /// </summary>
        /// <param name="i">整數參數</param>
        static void PrintMessage1(int i)
        {
            Console.WriteLine("第" + i + "個方法");
        }
    }

}
