using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.RootRef
{
    public class RefRoot
    {
        //這裡是一個佔用大量記憶體的成員
        public String[] BigMembor;
        public RefRoot(String content)
        {
            //初始化大物件
            BigMembor = new String[1000];
            for (int i = 0; i < BigMembor.Length; i++)
                BigMembor[i] = content;
        }
    }
    public class MainClass
    {
        //公共靜態大物件
        public static RefRoot bigobject = new RefRoot("aaa");
        static void Main()
        {
            Console.Read();
        }
    }

}
