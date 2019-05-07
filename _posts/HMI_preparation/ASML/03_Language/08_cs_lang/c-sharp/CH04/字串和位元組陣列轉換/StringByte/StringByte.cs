using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fourth.StringByte
{
    class StringByte
    {
        static void Main(string[] args)
        {
            String s = "我是字串，I am string";
            //位元組陣列轉換到字串
            //UTF8編碼
            Byte[] utf8 = StringToByte(s, Encoding.UTF8);
            //GB2312編碼
            Byte[] gb2312 = StringToByte(s, Encoding.GetEncoding("GB2312"));
            //UNICODE編碼
            Byte[] unicode = StringToByte(s, Encoding.Unicode);
            Console.WriteLine(utf8.Length);
            Console.WriteLine(gb2312.Length);
            Console.WriteLine(unicode.Length);
            //轉換回字串
            Console.WriteLine(ByteToString(utf8, Encoding.UTF8));
            Console.WriteLine(ByteToString(gb2312, Encoding.GetEncoding("GB2312")));
            Console.WriteLine(ByteToString(unicode, Encoding.Unicode));
            Console.Read();
        }
        //把字串轉換為位元組陣列
        static Byte[] StringToByte(String s, Encoding encoding)
        {
            return encoding.GetBytes(s);
        }
        //把位元組陣列轉換為字串
        static String ByteToString(Byte[] b, Encoding encoding)
        {
            return encoding.GetString(b);
        }
    }

}
