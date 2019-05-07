using System;
using System.Security;
using System.Runtime.InteropServices;

namespace NET.MST.Fourth.UseSecureString
{
    class UseSecureString
    {
        static void Main(string[] args)
        {
            //使用using保證Dispose方法被呼叫
            using (SecureString ss = new SecureString())
            {
                //只能逐字元地呼叫SecureString物件
                ss.AppendChar('a');
                ss.AppendChar('c');
                ss.AppendChar('d');
                ss.InsertAt(1, 'c');
                PrintSecureString(ss);
                Console.Read();
            }
        }
        //列印SecureString物件
        public unsafe static void PrintSecureString(SecureString ss)
        {
            char* buffer = null;
            try
            {
                //只能逐字元地呼叫SecureString物件
                buffer = (char*)Marshal.SecureStringToCoTaskMemUnicode(ss);
                for (int i = 0; *(buffer + i) != '\0'; i++)
                    Console.Write(*(buffer + i));
                Console.Write("\r\n");
            }
            finally
            {
                //釋放記憶體物件
                if (buffer != null)
                    Marshal.ZeroFreeCoTaskMemUnicode((System.IntPtr)buffer);
            }
        }
    }

}
