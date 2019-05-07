using System;
using System.Collections.Generic;
using System.IO;

namespace NET.MST.Fourth.GenericPrimaryConstraint
{
    public class PrimaryConstraint
    {
        static void Main(string[] args)
        {
            Console.Read();
        }
    }
    //主要約束限定T繼承自Exception類別
    public class ClassT1<T> where T : Exception
    {
        private T myException;
        public ClassT1(T t)
        {
            myException = t;
        }
        public override string ToString()
        {
            //主要約束保證了myException擁有source成員
            return myException.Source;
        }
    }
    //主要約束限定T是參考型別
    public class ClassT2<T> where T : class
    {
        private T myT;
        public void Clear()
        {
            //T是參考型別，可以設定為null
            myT = null;
        }
    }
    //主要約束限定T是數值型別
    public class ClassT3<T> where T : struct
    {
        private T myT;
        public override string ToString()
        {
            //T是數值型別，不會發生NullReferenceException例外
            return myT.ToString();
        }
    }

}
