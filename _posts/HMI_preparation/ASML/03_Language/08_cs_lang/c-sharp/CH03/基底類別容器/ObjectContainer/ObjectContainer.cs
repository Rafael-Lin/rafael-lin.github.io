using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.ObjectContainer
{
    public class ObjectContainer
    {
        private List<System.Object> _list;
        public ObjectContainer()
        {
            //一個Object型別的容器
            _list = new List<object>();
        }
        public void Add(Object obj)
        {
            //加入一個元素
            _list.Add(obj);
        }
        public Object Get(int i)
        {
            //得到元素
            return _list[i];
        }
        public override string ToString()
        {
            //得到所有元素的字串表示
            StringBuilder builder = new StringBuilder();
            foreach (Object o in _list)
            {
                builder.Append(o.ToString());
                builder.Append("\n");
            }
            return builder.ToString();
        }
        static void Main(string[] args)
        {
            ObjectContainer oc = new ObjectContainer();
            oc.Add(1);				//加入整數物件
            oc.Add("我是字串");		//加入字串物件
            oc.Add(2.32);			//加入浮點數
            oc.Add(DateTime.Now);
            Console.WriteLine(oc);
            Console.Read();
        }
    }

}
