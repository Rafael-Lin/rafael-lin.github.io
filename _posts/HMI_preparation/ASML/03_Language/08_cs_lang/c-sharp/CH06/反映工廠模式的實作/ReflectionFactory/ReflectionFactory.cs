using System;
using System.Collections.Generic;
using System.Text;
using System.Reflection;

namespace NET.MST.Sixth.ReflectionFactory
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
    /// 工廠管理類別
    /// </summary>
    class FactoryManager
    {
        public static IProduct GetProduct(RoomParts part)
        {
            //一共只有一個工廠，所以不再需要根據產品類別而挑選工廠
            Factory factory = new Factory();
            IProduct product = factory.Produce(part);
            Console.WriteLine("生產了一個產品：" +
                product.GetName());
            return product;
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
    /// 這個特性用來附加在產品類別之上，
    /// 來標示該類別為哪個產品，方便反映使用
    /// </summary>
    [AttributeUsage(AttributeTargets.Class)]
    class ProductAttribute : Attribute
    {
        //標示零件的成員
        private RoomParts _myRoomPart;
        public ProductAttribute(RoomParts part)
        {
            _myRoomPart = part;
        }
        public RoomParts RoomPart
        {
            get
            {
                return _myRoomPart;
            }
        }
    }
    /// <summary>
    /// 這個特性用來附加在產品介面之上
    /// 來標示一共實作了多少產品零件，方便反映使用
    /// </summary>
    [AttributeUsage(AttributeTargets.Interface)]
    class ProductListAttribute : Attribute
    {
        //產品型別集合
        private Type[] _myList;
        public ProductListAttribute(Type[] Products)
        {
            _myList = Products;
        }
        public Type[] ProductList
        {
            get
            {
                return _myList;
            }
        }
    }


    #region 產品類別群組
    /// <summary>
    /// 產品零件介面，
    /// 需要加入所有實作該介面的清單
    /// </summary>
    [ProductList(new Type[] { typeof(Roof), typeof(Window), typeof(Pillar) })]
    interface IProduct
    {
        String GetName();
    }
    /// <summary>
    /// 屋頂類別
    /// </summary>
    [ProductAttribute(RoomParts.Roof)]
    class Roof : IProduct
    {
        public String GetName()
        {
            return "屋頂";
        }
    }
    /// <summary>
    /// 窗戶類別
    /// </summary>
    [Product(RoomParts.Window)]
    class Window : IProduct
    {
        public String GetName()
        {
            return "窗戶";
        }
    }
    /// <summary>
    /// 柱子類別
    /// </summary>
    [ProductAttribute(RoomParts.Pillar)]
    class Pillar : IProduct
    {
        public String GetName()
        {
            return "柱子";
        }
    }
    #endregion


    #region 工廠類別
    /// <summary>
    /// 工廠類別，這裡不再需要一個類別群組，而只需要一個工廠類別
    /// </summary>
    class Factory
    {
        public IProduct Produce(RoomParts part)
        {
            //透過反映，從IProduct 介面中獲得屬性,
            //從而獲得所有的產品零件清單
            ProductListAttribute Attr = (ProductListAttribute)
                    Attribute.GetCustomAttribute(typeof(IProduct), typeof(ProductListAttribute));
            //逐一訪問所有的實作產品零件類別
            foreach (Type type in Attr.ProductList)
            {
                //利用反映讀取其特性
                ProductAttribute pa = (ProductAttribute)Attribute.GetCustomAttribute(
                                    type, typeof(ProductAttribute));
                //確定是否是需要的零件
                if (pa.RoomPart == part)
                {
                    //再一次利用反映
                    //建立產品零件類別
                    Object product = Assembly.GetExecutingAssembly().
                                 CreateInstance(type.FullName);
                    return product as IProduct;
                }
            }
            //不應該到達這裡
            return null;
        }
    }
    #endregion

}
