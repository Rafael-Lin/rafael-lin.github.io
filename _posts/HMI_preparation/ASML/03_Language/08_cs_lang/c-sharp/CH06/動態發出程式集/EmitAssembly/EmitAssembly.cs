using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection.Emit;
using System.Threading;
using System.Reflection;

namespace NET.MST.Sixth.EmitAssembly
{
    class MainClass
    {
        /// <summary>
        /// 使用發出的類別
        /// </summary>
        static void Main(string[] args)
        {
            //定義建構式的參數
            Object[] ctorParams = new Object[2];
            ctorParams[0] = 1000;
            ctorParams[1] = 2000;
            //發出程式集，並得到AddClass類別
            Type type = CreateAssembly();
            //新建AddClass物件
            object ptInstance = Activator.CreateInstance(type, ctorParams);
            //呼叫動態發出的ToString方法
            Console.WriteLine(ptInstance.ToString());
            //呼叫動態發出的GetResult方法
            MethodInfo info = type.GetMethod("GetResult", new Type[0]);
            long result = (long)info.Invoke(ptInstance, null);
            Console.WriteLine(result.ToString());
            Console.Read();
        }


        /// <summary>
        /// 用来动态发射一个程序集的中间代码
        /// 放回发射的类型
        /// 创建的中间代码相当于这样的C#代码：
        // public class AddClass
        //{
        //     private long first;
        //     private long second;
        
        //     public AddClass(long f, long s)
        //     {
        //         first = f;
        //         second = s;
        //     }
        //     public long GetResult()
        //     {
        //         return first + second;
        //     }
        
        //     public override string ToString()
        //     {
        //         return      "第一个数字是：" +
        //                     first.ToString() +
        //                        "\r\n第二个数字是：" +
        //                       second.ToString();
        //     }
        // }
        /// </summary>
        static Type CreateAssembly()
        {
            //在目前應用程式定義域中定義新程式集
            AppDomain myDomain = Thread.GetDomain();
            AssemblyName myAsmName = new AssemblyName();
            myAsmName.Name = "NewAssembly";
            AssemblyBuilder assemblybuilder = myDomain.DefineDynamicAssembly(myAsmName, AssemblyBuilderAccess.RunAndSave);
            //定義模組
            ModuleBuilder addclassModule = assemblybuilder.DefineDynamicModule("AddClass", "AddClass.dll");
            //定義模組中的型別
            TypeBuilder addclass = addclassModule.DefineType("AddClass", TypeAttributes.Public);
            //這個型別將包含兩個私有成員
            //名字分別為：first和second
            FieldBuilder first = addclass.DefineField("first", typeof(long), FieldAttributes.Private);
            FieldBuilder second = addclass.DefineField("second", typeof(long), FieldAttributes.Private);
            //為AddClass定義一個公共建構式
            //接受兩個長整數參數
            Type[] ctorParams = new Type[] { typeof(long), typeof(long) };
            //AddClass的基底類別是System.Object
            Type objType = Type.GetType("System.Object");
            //得到無參數建構式
            ConstructorInfo objCtor = objType.GetConstructor(new Type[0]);
            //AddClass的公共建構式
            ConstructorBuilder addCtor = addclass.DefineConstructor(MethodAttributes.Public, CallingConventions.Standard, ctorParams);
            //開始建立建構式的中間程式碼
            ILGenerator ctorIL = addCtor.GetILGenerator();
            ctorIL.Emit(OpCodes.Ldarg_0);
            ctorIL.Emit(OpCodes.Call, objCtor);
            ctorIL.Emit(OpCodes.Ldarg_0);
            ctorIL.Emit(OpCodes.Ldarg_1);
            ctorIL.Emit(OpCodes.Stfld, first);
            ctorIL.Emit(OpCodes.Ldarg_0);
            ctorIL.Emit(OpCodes.Ldarg_2);
            ctorIL.Emit(OpCodes.Stfld, second);
            ctorIL.Emit(OpCodes.Ret);
            //這裡建立long GetResult()方法
            //用來得到兩個數字相加的結果
            MethodBuilder resultMethod = addclass.DefineMethod("GetResult", MethodAttributes.Public, typeof(long), new Type[0]);
            //發出GetResult方法的中間程式碼
            ILGenerator resultIL = resultMethod.GetILGenerator();
            // ILGenerator.EmitWriteLine(string) 建立一個字串物件，
            //並且透過控制台輸出 
            resultIL.EmitWriteLine("開始執行相加：");
            //執行相加程式
            //這裡的IL程式碼用來導入兩個成員變數，相加並回傳結果
            resultIL.Emit(OpCodes.Ldarg_0);
            resultIL.Emit(OpCodes.Ldfld, first);
            resultIL.Emit(OpCodes.Ldarg_0);
            resultIL.Emit(OpCodes.Ldfld, second);
            resultIL.Emit(OpCodes.Add);
            resultIL.Emit(OpCodes.Ret);
            //發出String ToString方法
            MethodBuilder tostringMethod = addclass.DefineMethod("ToString", MethodAttributes.Virtual | MethodAttributes.Public, typeof(String), new Type[0]);
            ILGenerator stringIL = tostringMethod.GetILGenerator();
            stringIL.Emit(OpCodes.Ldstr, "第一個數字是：");
            stringIL.Emit(OpCodes.Ldarg_0);
            stringIL.Emit(OpCodes.Ldflda, first);
            stringIL.Emit(OpCodes.Call, typeof(long).GetMethod("ToString", new Type[0]));
            stringIL.Emit(OpCodes.Ldstr, "\r\n第二個數字是：");
            stringIL.Emit(OpCodes.Ldarg_0);
            stringIL.Emit(OpCodes.Ldflda, second);
            stringIL.Emit(OpCodes.Call, typeof(long).GetMethod("ToString", new Type[0]));
            Type[] types = new Type[4];
            for (int i = 0; i < types.Length; i++)
                types[i] = typeof(String);
            stringIL.Emit(OpCodes.Call, typeof(String).GetMethod("Concat", types));
            stringIL.Emit(OpCodes.Ret);
            //說明方法覆寫System.Object方法
            addclass.DefineMethodOverride(tostringMethod, typeof(System.Object).GetMethod("ToString"));
            return addclass.CreateType();
        }

    }
}
