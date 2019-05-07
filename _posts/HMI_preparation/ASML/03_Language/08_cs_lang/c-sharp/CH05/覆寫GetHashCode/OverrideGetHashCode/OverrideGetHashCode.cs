using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fifth.OverrideGetHashCode
{
    sealed class OverrideGetHashCode
    {
        public int _MyInt;
        //唯讀成員
        public readonly String _MyString;
        //覆寫了Equals方法
        public override bool Equals(object obj)
        {
            //檢查空參考
            if (obj == null)
                return false;
            //進行參考比較，如果兩者參考相等，勢必內容相等
            if (Object.ReferenceEquals(this, obj))
                return true;
            if (this.GetType() != obj.GetType())
                return false;
            //實作內容比較
            OverrideGetHashCode right = obj as OverrideGetHashCode;
            if (_MyInt == right._MyInt && _MyString == right._MyString)
                return true;
            return false;
        }
        public OverrideGetHashCode(int i, String s)
        {
            _MyInt = i;
            _MyString = s;
        }
        //覆寫了 GetHashCode方法
        public override int GetHashCode()
        {
            //相依於唯讀成員的HashCode
            return _MyString.GetHashCode();
        }
        static void Main(string[] args)
        {
            //驗證相等的物件回傳相等的HashCode
            OverrideGetHashCode o1 = new OverrideGetHashCode
                                (10, "我是字串");
            OverrideGetHashCode o2 = new OverrideGetHashCode
                                            (10, "我是字串");
            Console.WriteLine("物件是否相等：" + o1.Equals(o2));
            Console.WriteLine("相等物件HashCode是否相等" +
                (o1.GetHashCode() == o2.GetHashCode()).ToString());
            //驗證同一物件回傳相等的HashCode
            int code = o1.GetHashCode();
            o1._MyInt = 12;
            Console.WriteLine("同一物件HashCode是否相等：" +
                          (o1.GetHashCode() == code).ToString());
            Console.Read();
        }
    }

}
