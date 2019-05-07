using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;

namespace NET.MST.Sixth.GetAttributes
{
    [My("GetAttributes")]
    class GetAttributes
    {
        static void Main(string[] args)
        {
            Type attributeType=typeof(MyAttribute);
            Type thisClass=typeof(GetAttributes);
            //使用IsDefined方法
            bool defined = Attribute.IsDefined(thisClass, attributeType);
            Console.WriteLine("GetAttributes型別是否宣告了MyAttribute特性：{0}",
                 defined.ToString());
            //使用Attribute.GetCustomAttribute方法
            Attribute att = Attribute.GetCustomAttribute(thisClass, attributeType);
            if (att != null)
            {
                Console.WriteLine("GetAttributes型別宣告了MyAttribute特性。");
                Console.WriteLine("名字為：{0}", ((MyAttribute)att).Name);
            }
            //使用Attribute.GetCustomAttributes方法
            Attribute[] atts = Attribute.GetCustomAttributes(thisClass, attributeType);
            if (atts.Length > 0)
            {
                Console.WriteLine("GetAttributes型別宣告了MyAttribute特性。");
                Console.WriteLine("名字為：{0}",  ((MyAttribute)atts[0]).Name);
            }
            //使用System.Reflection.CustomAttributeData類別
            IList<CustomAttributeData> list =
                CustomAttributeData.GetCustomAttributes(thisClass);
            if (list.Count > 0)
            {
                Console.WriteLine("GetAttributes型別宣告了MyAttribute特性。");
                //注意這裡可以對特性進行分析，但不能得到其執行個體
                CustomAttributeData attdata = list[0];
                Console.WriteLine("特性的名字是：{0}",attdata.Constructor.DeclaringType.Name);
                Console.WriteLine("特性的建構式有{0}個參數。",attdata.ConstructorArguments.Count);
            }
            Console.Read();
        }
    }
    /// <summary>
    /// 一個簡單的特性
    /// </summary>
    [AttributeUsage(AttributeTargets.All)]
    public sealed class MyAttribute : Attribute
    {
        private String _name;
        public MyAttribute(String s)
        {
            _name = s;
        }
        public String Name
        {
            get
            {
                return _name;
            }
        }
    }

}
