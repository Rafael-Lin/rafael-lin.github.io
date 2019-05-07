using System;

namespace NET.MST.Sixth.SimpleAssembly
{
    /// <summary>
    /// 建立一個包含私有成員、特性、方法的簡單類別
    /// </summary>
    [Serializable]
    class SimpleAssembly
    {
        private String _MyString;
        public SimpleAssembly(String mystring)
        {
            _MyString = mystring;
        }
        public override string ToString()
        {
            return _MyString;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("簡單程式集");
            Console.Read();
        }
    }

}
