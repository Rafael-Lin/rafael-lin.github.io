using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Sixth.CatCry
{
    class MainClass
    {
        static void Main(string[] args)
        {
            //開始模擬場景
            Console.WriteLine("開始模擬");
            Cat cat = new Cat("湯姆貓");
            Mouse mouse1 = new Mouse("米老鼠", cat);
            Mouse mouse2 = new Mouse("傑瑞鼠", cat);
            Master master = new Master("朱毅", cat);
            cat.CatCry();
            Console.Read();
        }
    }


    #region cat 
    /// <summary>
    /// 貓類別，維護貓叫事件
    /// </summary>
    public class Cat
    {
        /// <summary>
        /// 貓名
        /// </summary>
        private String _name;
        /// <summary>
        /// 貓叫的事件
        /// </summary>
        public event EventHandler<CatCryEventArgs> CatCryEvent;
        /// <summary>
        /// 建構式
        /// </summary>
        public Cat(String name)
        {
            _name = name;
        }
        /// <summary>
        /// 觸發貓叫事件
        /// </summary>
        public void CatCry()
        {
            CatCryEventArgs args = new CatCryEventArgs(_name);
            Console.WriteLine(args);
            CatCryEvent(this, args);
        }
    }
    /// <summary>
    /// 貓叫事件的參數
    /// </summary>
    public class CatCryEventArgs : EventArgs
    {
        //發出叫聲的貓的名字
        private String _catname;
        public CatCryEventArgs(String catname)
            : base()
        {
            _catname = catname;
        }
        /// <summary>
        /// 輸出參數內容
        /// </summary>
        public override string ToString()
        {
            return _catname + "叫了";
        }
    }

    #endregion

    #region Master
    /// <summary>
    /// 主人類別
    /// </summary>
    public class Master
    {
        /// <summary>
        /// 主人名字
        /// </summary>
        private String _name;
        /// <summary>
        /// 建構式，訂閱事件
        /// </summary>
        public Master(String name, Cat cat)
        {
            _name = name;
            cat.CatCryEvent += CatCryHandler;
        }
        /// <summary>
        /// 貓叫事件處理方法
        /// </summary>
        private void CatCryHandler(object sender, CatCryEventArgs args)
        {
            WakeUp();
        }
        /// <summary>
        /// 驚醒方法
        /// </summary>
        private void WakeUp()
        {
            Console.WriteLine(_name + "醒了");
        }
    }

    #endregion

    #region mouse
    /// <summary>
    /// 老鼠類別
    /// </summary>
    public class Mouse
    {
        /// <summary>
        /// 老鼠名字
        /// </summary>
        private String _name;
        public Mouse(String name, Cat cat)
        {
            _name = name;
            cat.CatCryEvent += CatCryHandler;
        }
        /// <summary>
        /// 貓叫事件處理方法
        /// </summary>
        private void CatCryHandler(object sender, CatCryEventArgs args)
        {
            Run();
        }
        /// <summary>
        /// 逃跑方法
        /// </summary>
        private void Run()
        {
            Console.WriteLine(_name + "逃走了");
        }
    }

    #endregion
}
