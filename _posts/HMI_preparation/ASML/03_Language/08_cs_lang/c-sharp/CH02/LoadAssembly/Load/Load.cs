using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;

namespace Load
{
    class Load
    {
        static void Main(string[] args)
        {
            //需要針對不同的主機安裝情況進行修改
            String assemblyname = @"Compile, " +
                                   "Version=1.0.0.0, " +
                                   "Culture=Neutral, " +
                                   "PublicKeyToken=60c29e5f0af3e9bb";
            //根據程式集的四要素載入程式集
            Assembly compiledll = Assembly.Load(assemblyname);
            //建立物件
            Object compile = compiledll.CreateInstance("NET.MST.Second.Compile");
            Console.WriteLine(compile);
            Console.Read();
        }
    }

}
