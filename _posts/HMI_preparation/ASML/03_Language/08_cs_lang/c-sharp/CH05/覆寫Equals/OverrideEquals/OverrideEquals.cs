using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fifth.OverrideEquals
{
    class OverrideEquals
    {
        static void Main(string[] args)
        {
            MyObject o1 = new MyObject(10, "我是字串");
            MyObject o2 = new MyObject(10, "我是字串");
            //列印參考比較結果
            Console.WriteLine("參考比較：" + Object.ReferenceEquals(o1, o2));
            //列印內容比較結果
            Console.WriteLine("自訂的內容比較：" + o1.Equals(o2));
            Console.Read();
        }
    }
    class MyObject
    {
        public int _MyInt;
        public String _MyString;
        public MyObject(int i, String s)
        {
            _MyInt = i;
            _MyString = s;
        }
        //覆寫執行個體Equals方法
        //實作內容比較
        public override bool Equals(object obj)
        {
            //檢查參考為空
            if (obj == null)
                return false;
            //做參考比較，如果兩者參考相等，勢必內容相等
            if (Object.ReferenceEquals(this, obj))
                return true;
            //檢查兩者的型別是否相等
            //考慮到繼承的原因，執行時的型別未必是MyObject
            //所以使用反映得到確切的型別，犧牲效能來確保正確性
            if (this.GetType() != obj.GetType())
                return false;
            //實現內容比較
            MyObject right = obj as MyObject;
            if (_MyInt == right._MyInt &&
                //String雖然是參考型別，但實作了內容比較的==
                _MyString == right._MyString)
                return true;
            return false;
        }
    }

}
