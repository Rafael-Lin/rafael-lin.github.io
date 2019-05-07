using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fourth.Compression
{
    class Compression
    {
        //緩衝陣列的長度
        private const int bufferlength = 1024;
        static void Main(string[] args)
        {
            String test = GetTestString();
            Byte[] original = Encoding.Default.GetBytes(test);
            Console.WriteLine("資料的原始長度是：" + original.LongLength.ToString());
            //進行壓縮
            Byte[] compressed = Compress(original);
            Console.WriteLine("壓縮後的資料長度是：" + compressed.LongLength);
            //進行解壓縮
            Byte[] back = DeCompress(compressed);
            Console.WriteLine("解壓縮後得到資料長度：" +
                back.LongLength.ToString());
            Console.WriteLine("解壓縮前後是否相等：" +
                test.Equals(Encoding.Default.GetString(back)));
            Console.Read();
        }
        //壓縮資料
        static Byte[] Compress(Byte[] data)
        {
            //壓縮寫入這個記憶體流
            using (MemoryStream target = new MemoryStream())
            {
                using (GZipStream gs = new GZipStream
                    (target, CompressionMode.Compress, true))
                {
                    //把資料寫入壓縮流
                    WriteAllBytes(gs, data, bufferlength);
                }
                return target.ToArray();
            }
        }
        //解壓縮數據
        static Byte[] DeCompress(Byte[] data)
        {
            using (MemoryStream source = new MemoryStream(data))
            {
                using (GZipStream gs = new GZipStream
                    (source, CompressionMode.Decompress, true))
                {
                    //從壓縮流中讀取所有資料
                    return ReadAllBytes(gs, bufferlength);
                }
            }
        }
        //準備測試資料
        static String GetTestString()
        {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < 1000; i++)
                builder.Append("我是測試資料");
            return builder.ToString();
        }

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
