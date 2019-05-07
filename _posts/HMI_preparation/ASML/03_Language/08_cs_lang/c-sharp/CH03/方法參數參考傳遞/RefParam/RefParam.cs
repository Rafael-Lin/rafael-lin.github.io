using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Thrid.RefParam
{
    class RefParam
    {
        static void Main(string[] args)
        {
            //測試ref傳遞參數的功能
            int i = 0;
            Console.WriteLine("原始值：" + i.ToString());
            NotRef(i);
            Console.WriteLine("呼叫非參考傳遞參數方法後：" + i.ToString());
            Ref(ref i);
            Console.WriteLine("呼叫參考傳遞參數方法後：" + i.ToString());
            Console.Read();
        }
        //不使用ref關鍵字來傳遞參數
        public static void NotRef(int i)
        {
            i++;
        }
        //使用ref關鍵字來傳遞參數
        public static void Ref(ref int i)
        {
            i++;
        }
    }

}
