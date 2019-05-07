using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

namespace NET.MST.Fourth.CustomizeSerialization
{
    class CustomizeSerialization
    {
        //main方法，測試自訂的序列化和反序列化
        static void Main(string[] args)
        {
            MyObjectSon obj = new MyObjectSon(10, "我是字串");
            Console.WriteLine("初始物件：");
            Console.WriteLine(obj);
            Byte[] data = Serialize(obj);
            Console.WriteLine("經過序列化和反序列化後：");
            Console.WriteLine(DeSerialize(data));
            Console.Read();
        }
        //序列化物件
        static Byte[] Serialize(MyObjectSon obj)
        {
            IFormatter formatter = new BinaryFormatter();
            using (MemoryStream ms = new MemoryStream())
            {
                formatter.Serialize(ms, obj);
                return ms.ToArray();
            }
        }
        //反序列化物件
        static MyObjectSon DeSerialize(Byte[] data)
        {
            IFormatter formatter = new BinaryFormatter();
            using (MemoryStream ms = new MemoryStream(data))
            {
                return (MyObjectSon)formatter.Deserialize(ms);
            }
        }
    }

    [Serializable]
    class MyObject : ISerializable
    {
        private int _MyInt;
        [NonSerialized]
        private String _MyString;
        public MyObject(int i, String s)
        {
            _MyInt = i;
            _MyString = s;
        }
        public override string ToString()
        {
            return "整數是：" + _MyInt.ToString() +
                "\r\n字串是：" + _MyString + "\r\n";
        }
        //實現自訂的反序列化
        protected MyObject(SerializationInfo info,
            StreamingContext context)
        {
            //從SerializationInfo結構中讀取內容
            _MyInt = info.GetInt32("MyObjectInt");
            _MyString = info.GetString("MyObjectString");
        }
        //實現自訂的序列化
        public virtual void GetObjectData
            (SerializationInfo info, StreamingContext context)
        {
            //寫入SerializationInfo結構
            info.AddValue("MyObjectInt", _MyInt);
            info.AddValue("MyObjectString", _MyString);
        }
    }

    [Serializable]
    class MyObjectSon : MyObject
    {
        private String _SonString;
        public MyObjectSon(int i, String s)
            : base(i, s)
        {
            _SonString = s;
        }
        public override string ToString()
        {
            return base.ToString() + "子類別字串是：" +
                _SonString + "\r\n";
        }
        //實現反序列化，只負責子類別加入的成員
        protected MyObjectSon(SerializationInfo info,
            StreamingContext context)
            : base(info, context)
        {
            _SonString = info.GetString("MyObjectSonString");
        }
        //實現序列化，只負責子類別加入的成員
        public override void GetObjectData(SerializationInfo info,
            StreamingContext context)
        {
            base.GetObjectData(info, context);
            info.AddValue("MyObjectSonString", _SonString);
        }
    }
}
