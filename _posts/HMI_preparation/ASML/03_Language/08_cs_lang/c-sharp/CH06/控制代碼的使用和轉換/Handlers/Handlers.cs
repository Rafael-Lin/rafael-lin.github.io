using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;

namespace NET.MST.Sixth.Handlers
{
    class Handlers
    {
        static void Main(string[] args)
        {
            //得到Type、MethodInfo和FieldInfo
            Type sctype = typeof(SimpleClass);
            MethodInfo getmethod = sctype.GetMethod("GetInt");
            FieldInfo intfield = sctype.GetField("_myint", BindingFlags.NonPublic |
                            BindingFlags.Instance | BindingFlags.Public);
            //轉換成RuntimeTypeHanlde、
            //RuntimeMethodHandle和RuntimeFieldHandle
            RuntimeTypeHandle th = Type.GetTypeHandle(sctype);
            RuntimeMethodHandle mh = getmethod.MethodHandle;
            RuntimeFieldHandle fh = intfield.FieldHandle;
            //轉換回Type、MethodInfo和FieldInfo
            Type newsctype = Type.GetTypeFromHandle(th);
            MethodInfo newgetmethod = (MethodInfo)MethodInfo.GetMethodFromHandle(mh);
            FieldInfo newintfield = FieldInfo.GetFieldFromHandle(fh);
            //驗證轉換是否成功
            Console.WriteLine(newsctype.Name);
            Console.WriteLine(newgetmethod.Name);
            Console.WriteLine(newintfield.Name);
            Console.Read();
        }
    }
    /// <summary>
    /// 一個簡單的類別
    /// </summary>
    class SimpleClass
    {
        private int _myint;
        public SimpleClass(int i)
        {
            _myint = i;
        }
        public int GetInt()
        {
            return _myint;
        }
    }

}
