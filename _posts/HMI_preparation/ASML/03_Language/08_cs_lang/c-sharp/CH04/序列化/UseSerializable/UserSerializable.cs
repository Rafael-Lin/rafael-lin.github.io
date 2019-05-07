using System;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;

namespace NET.MST.Fourth.UseSerializable
{
    class UserSerializable
    {
        static void Main(string[] args)
        {
            MyObject obj = new MyObject(10, "我是字串");
            Console.WriteLine("初始狀態：");
            Console.WriteLine(obj);
            //序列化物件
            Byte[] data = Serialize(obj);
            //反序列化物件
            MyObject newobj = DeSerialize(data);
            Console.WriteLine("經過序列化和反序列化後：");
            Console.WriteLine(newobj);
            Console.Read();
        }
        //序列化物件
        static Byte[] Serialize(MyObject obj)
        {
            //二進位序列化
            IFormatter formatter = new BinaryFormatter();
            using (MemoryStream ms = new MemoryStream())
            {
                formatter.Serialize(ms, obj);
                return ms.ToArray();
            }
        }
        //反序列化物件
        static MyObject DeSerialize(Byte[] data)
        {
            IFormatter formatter = new BinaryFormatter();
            using (MemoryStream ms = new MemoryStream(data))
            {
                return (MyObject)formatter.Deserialize(ms);
            }
        }
    }
    //一個可序列化的類別
    [Serializable]
    public class MyObject
    {
        private int _myInt;
        [NonSerialized]
        //這個成員不可被序列化
        private String _myPrivate;
        public MyObject(int i, String s)
        {
            _myInt = i;
            _myPrivate = s;
        }
        public override string ToString()
        {
            return "整數是：" + _myInt.ToString() +
                   "\r\n字串是：" + _myPrivate;
        }
    }

}
