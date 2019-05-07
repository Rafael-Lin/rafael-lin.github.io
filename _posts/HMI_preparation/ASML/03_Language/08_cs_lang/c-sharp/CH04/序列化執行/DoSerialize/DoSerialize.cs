using System;
using System.Collections.Generic;
using System.Runtime.Serialization.Formatters.Soap;
using System.IO;
using System.Text;
using System.Xml.Serialization;

namespace NET.MST.Fourth.DoSerialize
{
    partial class DoSerialize
    {
        static void Main(string[] args)
        {
            MyObject obj = new MyObject(10, "我是字串");
            Console.WriteLine("原始物件是：");
            Console.WriteLine(obj.ToString());
            //使用 SoapFormatter進行序列化
            Byte[] data = SoapFormatterSerialize(obj);
            Console.WriteLine("SoapFormatter序列化後：");
            Console.WriteLine(Encoding.UTF8.GetString(data));
            //使用XmlSerializer進行序列化
            Byte[] data1 = XmlSerializerSerialize(obj);
            Console.WriteLine("XmlSerializer序列化後：");
            Console.WriteLine(Encoding.UTF8.GetString(data1));
            Console.Read();
        }
    }

    partial class DoSerialize
    {
        /// <summary>
        /// Soap序列化
        /// </summary>
        static Byte[] SoapFormatterSerialize(MyObject obj)
        {
            using (MemoryStream ms = new MemoryStream())
            {
                SoapFormatter sf = new SoapFormatter();
                sf.Serialize(ms, obj);
                return ms.ToArray();
            }
        }
        /// <summary>
        /// Soap反序列化
        /// </summary>
        static MyObject SoapFormatterDeserialize(Byte[] data)
        {
            using (MemoryStream ms = new MemoryStream(data))
            {
                SoapFormatter sf = new SoapFormatter();
                return (MyObject)sf.Deserialize(ms);
            }
        }
        /// <summary>
        /// 使用XmlSerializer序列化
        /// </summary>
        static Byte[] XmlSerializerSerialize(MyObject obj)
        {
            using (MemoryStream ms = new MemoryStream())
            {
                XmlSerializer xs = new XmlSerializer(typeof(MyObject));
                xs.Serialize(ms, obj);
                return ms.ToArray();
            }
        }
        /// <summary>
        /// 使用XmlSerializer反序列化
        /// </summary>
        static MyObject XmlSerializerDeserialize(Byte[] data)
        {
            using (MemoryStream ms = new MemoryStream(data))
            {
                XmlSerializer xs = new XmlSerializer(typeof(MyObject));
                return (MyObject)xs.Deserialize(ms);
            }
        }
    }

    [Serializable]
    public class MyObject
    {
        //私有成員，不能被XmlSerializer序列化
        private int _myInt;
        //宣告不可被序列化
        [NonSerialized]
        public String _MyString1;
        //宣告不可被XmlSerializer序列化
        [XmlIgnore]
        public String _MyString2;
        public MyObject()
        {
            _myInt = 0;
            _MyString1 = "";
            _MyString2 = "";
        }
        public MyObject(int i, String s)
        {
            _myInt = i;
            _MyString1 = s;
            _MyString2 = s;
        }
        public override string ToString()
        {
            return "整數是：" + _myInt.ToString() +
                   "\r\n字串1是：" + _MyString1 +
                   "\r\n字串2是：" + _MyString2 + "\r\n";
        }
    }

}
