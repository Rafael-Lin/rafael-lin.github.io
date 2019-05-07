using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fifth.UseNotObject
{
    //使用並且驗證剛剛產生的無父類別的型別
    class UseNotObject
    {
        static void Main(string[] args)
        {
            //檢查是否可以建立一個物件
            NotObject.NotObject obj = new NotObject.NotObject();
            //檢查基底類別
            Type t = typeof(NotObject.NotObject);
            Console.WriteLine("NotObject的基底類別是：" + t.BaseType);
            Console.Read();
        }
    }

}
