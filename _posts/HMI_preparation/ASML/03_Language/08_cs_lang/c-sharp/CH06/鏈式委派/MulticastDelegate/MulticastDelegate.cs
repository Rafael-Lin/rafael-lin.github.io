using System;
namespace NET.MST.Sixth.MulticastDelegate
{
    class MulticastDelegate
    {
        /// <summary>
        /// 定義的委派。
        /// </summary>
        public delegate void TestMultiDelegate();
        static void Main(string[] args)
        {
            //宣告一個委派變數，並綁定第一個方法
            TestMultiDelegate handler = new TestMultiDelegate(PrintMessage1);
            //綁定第二個方法
            handler += new TestMultiDelegate(PrintMessage2);
            //綁定第三個方法
            handler += new TestMultiDelegate(PrintMessage3);
            //檢查結果
            handler();
            Console.Read();
        }
        static void PrintMessage1()
        {
            Console.WriteLine("第一個方法");
        }
        static void PrintMessage2()
        {
            Console.WriteLine("第二個方法");
        }
        static void PrintMessage3()
        {
            Console.WriteLine("第三個方法");
        }
    }

}
