using System;
using System.Collections.Generic;
using System.Text;

//申明C符合CLS規範
[assembly: CLSCompliantAttribute(true)]
namespace NET.MST.Second
{
    public class CLS
    {
        private uint i; //這是一個私有成員，所以不違反CLS規範
        public CLS()
        {
            i = 0;
        }
        static void Main(string[] args)
        {
        }
        //這裡不符合CLS規範，uint在CLS中沒有定義
        public uint GetI()
        {
            return i;
        }
    }
}

