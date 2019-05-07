using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fourth.Base64
{
    class Base64
    {
        static void Main(string[] args)
        {
            String abc = "abcde ";
            //生成UTF8位元組陣列
            Byte[] bytes = Encoding.UTF8.GetBytes(abc);
            //轉換成Base64字串
            String base64 = BytesToBase64(bytes);
            Console.WriteLine(base64);
            //轉換回UTF8位元組陣列
            bytes = Base64ToBytes(base64);
            //轉換回字串
            Console.WriteLine(Encoding.UTF8. 
            GetString(bytes));
            Console.Read();
        }
        //把8位元位元組陣列轉換成Base64字串
        static String BytesToBase64(Byte[] bytes)
        {
            try
            {
                //轉換不成功會拋出例外
                return Convert.ToBase64String(bytes);
            }
            catch
            {
                return null;
            }
        }
        //把Base64字串轉換成8位元位元組陣列
        static Byte[] Base64ToBytes(String base64)
        {
            try
            {
                //轉換不成功會拋出例外
                return Convert.FromBase64String(base64);
            }
            catch
            {
                return null;
            }
        }
    }

}
