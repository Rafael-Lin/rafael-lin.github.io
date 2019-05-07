using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.Param
{
    class Params
    {
        static void Main(string[] args)
        {
            //測試params傳遞參數的功能
            String s = "我是字串";
            int i = 10;
            double f = 2.3;
            Object[] par = new Object[3] { s, i, f };
            NotParams(par);
            ParamsParam(s, i, f);
            Console.Read();
        }
        //不使用params關鍵字來傳遞參數
        public static void NotParams(Object[] par)
        {
            foreach (Object obj in par)
                Console.WriteLine(obj);
        }
        //使用params關鍵字來傳遞參數
        public static void ParamsParam(params Object[] par)
        {
            foreach (Object obj in par)
                Console.WriteLine(obj);
        }
    }

}
