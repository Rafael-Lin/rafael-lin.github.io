using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;

namespace NET.MST.Second
{
    class LoadFrom
    {
        static void Main(string[] args)
        {
            //需要針對不同的主機目錄結構進行修改
            String codebase = @"..\Compile.dll";
            //從指定位置載入程式集
            Assembly compiledll = Assembly.LoadFrom(codebase);
            //建立物件
            Object compile = compiledll.CreateInstance("NET.MST.Second.Compile");
            Console.WriteLine(compile);
            Console.Read();
        }
    }

}
