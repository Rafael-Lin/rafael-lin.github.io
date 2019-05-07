using System;
using System.Security.Permissions;
using System.Text;
using System.Reflection;

namespace UseReflection
{
    /// <summary>
    /// 這裡的特性要求程式的運行需要完全信任的安全級別
    /// </summary>
    [PermissionSetAttribute(SecurityAction.Demand, Name = "FullTrust")]
    partial class UseReflection
    {
        static void Main(string[] args)
        {
            //需要根據程式碼位置進行更新
            //對程式集進行逐一分析
            Assembly assembly = Assembly.LoadFrom(@"..\SimpleAssembly.exe");
            AnalyzeAssembly(assembly);
            //建立一個程式集中的類別物件
            //這裡嘗試建立SimpleAssembly物件
            Console.WriteLine("利用反映建立類別物件");
            String[] pars = { "測試反映" };
            Object o = assembly.CreateInstance(assembly.GetModules()[0].GetTypes()[0].ToString(),
                true, BindingFlags.CreateInstance, null, pars, null, null);
            Console.WriteLine(o);
            Console.Read();
        }
    }

    partial class UseReflection
    {
        /// <summary>
        /// 對一個程式集進行分析
        /// </summary>
        /// <param name="assembly">需要分析的程式集</param>
        private static void AnalyzeAssembly(Assembly assembly)
        {
            //列印程式集的名稱
            Console.WriteLine("程式集名字：" + assembly.FullName);
            //列印程式集的位置
            Console.WriteLine("程式集位置：" + assembly.Location);
            //列印程式集是否存在於GAC中
            Console.WriteLine("程式集是否在GAC中：" +
                        assembly.GlobalAssemblyCache.ToString());
            //列印包含組件資訊清單的模組名稱
            Console.WriteLine("包含組件資訊清單的模組名" +
                assembly.ManifestModule.Name);
            //列印程式集的CLR版本
            Console.WriteLine("執行程式集需要的CLR版本：" +
                assembly.ImageRuntimeVersion);
            Console.WriteLine("現在開始分析程式集中的模組");
            Module[] modules = assembly.GetModules();
            foreach (Module module in modules)
                AnalyzeModule(module);
            ////遞迴分析參考程式集
            ////這裡的程式碼供讀者參考
            //Console.WriteLine("開始分析參考的程式集");
            //AssemblyName[] refassemblies = assembly.GetReferencedAssemblies();
            //foreach (AssemblyName refname in refassemblies)
            //{
            //    Assembly refassembly = Assembly.Load(refname);
            //    AnalyzeAssembly(refassembly);
            //}
        }
    }

    partial class UseReflection
    {
        /// <summary>
        /// 對一個模組進行分析
        /// </summary>
        /// <param name="module">需要分析的模組</param>
        private static void AnalyzeModule(Module module)
        {
            //列印模組名
            Console.WriteLine("模組名：" + module.Name);
            //列印模組的UUID
            Console.WriteLine("模組的UUID：" + module.ModuleVersionId);
            Console.WriteLine("開始分析模組下的型別");
            Type[] types = module.GetTypes();
            foreach (Type type in types)
                AnalyzeType(type);
        }
    }

    partial class UseReflection
    {
        /// <summary>
        /// 對一個型別進行分析
        /// </summary>
        /// <param name="type">需要分析的型別</param>
        private static void AnalyzeType(Type type)
        {
            //列印型別名稱
            Console.WriteLine("型別名字：" + type.Name);
            //列印型別的種類
            Console.WriteLine("型別的種類是：" + type.Attributes);
            if (type.BaseType != null)
                Console.WriteLine("型別的基底類別是：" + type.BaseType.Name);
            Console.WriteLine("型別的GUID是：" + type.GUID);
            //設定感興趣的型別成員
            BindingFlags flags = (BindingFlags.NonPublic | BindingFlags.Public |
                            BindingFlags.Static | BindingFlags.Instance);
            //分析成員
            FieldInfo[] fields = type.GetFields(flags);
            if (fields.Length > 0)
            {
                Console.WriteLine("開始分析型別的成員");
                foreach (FieldInfo field in fields)
                    AnalyzeField(field);
            }
            //分析包含的方法
            MethodInfo[] methods = type.GetMethods(flags);
            if (methods.Length > 0)
            {
                Console.WriteLine("開始分析型別的方法");
                foreach (MethodInfo method in methods)
                    AnalyzeMethod(method);
            }
            //分析屬性
            PropertyInfo[] properties = type.GetProperties(flags);
            if (properties.Length > 0)
            {
                Console.WriteLine("開始分析類型的屬性");
                foreach (PropertyInfo property in properties)
                    AnalyzeProperty(property);
            }
        }
    }

    partial class UseReflection
    {
        /// <summary>
        /// 對一個成員進行分析，這裡只做簡單的分析
        /// 可以進一步分析成員的存取層級，
        /// 或透過成員得到包含它的型別、模組等
        /// </summary>
        /// <param name="field">需要分析的成員</param>
        private static void AnalyzeField(FieldInfo field)
        {
            Console.WriteLine("成員名字：" + field.Name);
            Console.WriteLine("成員的種類：" + field.Attributes);
            Console.WriteLine("成員的型別名稱：" + field.FieldType.Name);
        }
        /// <summary>
        /// 對一個方法進行分析
        /// </summary>
        /// <param name="method">需要分析的方法</param>
        private static void AnalyzeMethod(MethodInfo method)
        {
            Console.WriteLine("方法名字：" + method.Name);
            Console.WriteLine("方法的類別：" + method.Attributes);
            Console.WriteLine("開始分析方法的參數");
            //分析方法的參數
            ParameterInfo[] parameters = method.GetParameters();
            if (parameters.Length <= 0)
                Console.WriteLine("方法沒有參數");
            foreach (ParameterInfo parameter in parameters)
                AnalyzeParameter(parameter);
            ParameterInfo retpar = method.ReturnParameter;
            //分析方法的回傳參數
            Console.WriteLine("分析方法的回傳參數");
            AnalyzeParameter(retpar);
        }
        /// <summary>
        /// 分析方法參數
        /// </summary>
        /// <param name="parameter">需要分析的參數</param>
        private static void AnalyzeParameter(ParameterInfo parameter)
        {
            Console.WriteLine("參數名字：" + parameter.Name);
            Console.WriteLine("參數的種類：" + parameter.Attributes);
            Console.WriteLine("參數的型別：" + parameter.ParameterType.Name);
        }
        /// <summary>
        /// 分析屬性
        /// </summary>
        /// <param name="property"></param>
        private static void AnalyzeProperty(PropertyInfo property)
        {
            Console.WriteLine("屬性名字：" + property.Name);
            Console.WriteLine("屬性的種類：" + property.Attributes);
            Console.WriteLine("是否可讀：" + property.CanRead.ToString());
            Console.WriteLine("是否可寫：" + property.CanWrite.ToString());
        }
    }

}
