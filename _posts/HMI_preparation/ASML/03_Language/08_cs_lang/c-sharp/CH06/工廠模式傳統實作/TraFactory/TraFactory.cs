using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Sixth.TraFactory
{
    /// <summary>
    /// 使用者
    /// </summary>
    class Customer
    {
        static void Main(string[] args)
        {
            //根據需要獲得不同的產品零件
            IProduct window = FactoryManager.GetProduct(RoomParts.Window);
            IProduct roof = FactoryManager.GetProduct(RoomParts.Roof);
            IProduct pillar = FactoryManager.GetProduct(RoomParts.Pillar);
        }
    }

    /// <summary>
    /// 屋子產品的零件
    /// </summary>
    enum RoomParts
    {
        Roof,
        Window,
        Pillar
    }
    /// <summary>
    /// 工廠介面
    /// </summary>
    interface IFactory
    {
        IProduct Produce();
    }
    /// <summary>
    /// 產品介面
    /// </summary>
    interface IProduct
    {
        String GetName();
    }

    /// <summary>
    /// 工廠管理者
    /// </summary>
    class FactoryManager
    {
        public static IProduct GetProduct(RoomParts part)
        {
            IFactory factory = null;
            //這裡就是傳統工廠模式的問題
            //工廠管理者和工廠類別群組耦合
            switch (part)
            {
                //如要根據不同的產品類別，找到對應的工廠
                case RoomParts.Pillar:
                    factory = new PillarFactory();
                    break;
                case RoomParts.Roof:
                    factory = new RoofFactory();
                    break;
                case RoomParts.Window:
                    factory = new WindowFactory();
                    break;
            }
            //利用工廠生產出產品
            IProduct product = factory.Produce();
            Console.WriteLine("生產了一個產品：" + product.GetName());
            return product;
        }
    }

    #region 工廠類別群組
    class RoofFactory : IFactory
    {
        //實作介面，回傳一個產品物件
        public IProduct Produce()
        {
            return new Roof();
        }
    }
    class WindowFactory : IFactory
    {
        //實作介面，回傳一個產品物件
        public IProduct Produce()
        {
            return new Window();
        }
    }
    class PillarFactory : IFactory
    {
        //實作介面，回傳一個產品物件
        public IProduct Produce()
        {
            return new Pillar();
        }
    }
    #endregion


    #region 產品類別群組
    class Roof : IProduct
    {
        //實作介面，回傳產品名字
        public String GetName()
        {
            return "屋頂";
        }
    }
    class Window : IProduct
    {
        //實作介面，回傳產品名字
        public String GetName()
        {
            return "窗戶";
        }
    }
    class Pillar : IProduct
    {
        //實作介面，回傳產品名字
        public String GetName()
        {
            return "柱子";
        }
    }
    #endregion

}
