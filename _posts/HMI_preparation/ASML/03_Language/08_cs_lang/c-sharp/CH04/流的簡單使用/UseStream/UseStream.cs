using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

namespace NET.MST.Fourth.UseStream
{
    partial class UseStream
    {
        private const int bufferlength = 1024;
        static void Main(string[] args)
        {
            //建立一個檔案，並寫入內容
            String filename = "C:\\TestStream.txt";
            String filecontent = GetTestString();
            try
            {
                //建立檔案並寫入內容
                using (FileStream fs = new FileStream(filename, FileMode.Create))
                {
                    Byte[] bytes = Encoding.Default.GetBytes(filecontent);
                    WriteAllBytes(fs, bytes, bufferlength);
                    fs.Close();
                }
                //讀取檔案並且列印出來
                using (FileStream fr = new FileStream(filename, FileMode.Open))
                {
                    Byte[] result = ReadAllBytes(fr, bufferlength);
                    Console.WriteLine(Encoding.Default.GetString(result));
                    fr.Close();
                }
            }
            finally
            {
                //清除測試檔案
                try
                {
                    if (File.Exists(filename))
                        File.Delete(filename);
                }
                finally { }
                Console.Read();
            }
        }
        //取得測試資料
        static String GetTestString()
        {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < 10; i++)
                builder.Append("我是測試資料\r\n");
            return builder.ToString();
        }
    }

    partial class UseStream
    {
        //從一個流中，讀取所有位元組
        static Byte[] ReadAllBytes(Stream stream, int bufferlength)
        {
            //讀取的緩衝變數
            Byte[] buffer = new Byte[bufferlength];
            List<Byte> result = new List<Byte>();
            int read;
            //直至讀取結束
            while ((read = stream.Read(buffer, 0, bufferlength)) > 0)
            {
                if (read < bufferlength)
                {
                    Byte[] temp = new Byte[read];
                    Array.Copy(buffer, temp, read);
                    result.AddRange(temp);
                }
                else
                    result.AddRange(buffer);
            }
            return result.ToArray();
        }
        //把位元組寫入一個流中
        static void WriteAllBytes(Stream stream, Byte[] data, int bufferlength)
        {
            //寫入的緩衝變數
            Byte[] buffer = new Byte[bufferlength];
            for (long i = 0; i < data.LongLength; i += bufferlength)
            {
                int length = bufferlength;
                if (i + bufferlength > data.LongLength)
                    length = (int)(data.LongLength - i);
                Array.Copy(data, i, buffer, 0, length);
                stream.Write(buffer, 0, length);
            }
        }
    }

}
