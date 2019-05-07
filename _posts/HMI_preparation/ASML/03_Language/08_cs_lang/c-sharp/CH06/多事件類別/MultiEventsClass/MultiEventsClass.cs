using System;
using System.Collections.Generic;
using System.Text;
using System.ComponentModel;
using System.Runtime.CompilerServices;
namespace NET.MST.Sixth.MultiEventsClass
{
    class MainClass
    {
        static void Main(string[] args)
        {
            //測試事件的觸發
            using (MultiEventsClass c = new MultiEventsClass())
            {
                Customer customer = new Customer(c);
                c.RiseEvent1();
                c.RiseEvent2();
            }
            Console.Read();
        }
    }

    /// <summary>
    /// 多事件類別
    /// </summary>
    public partial class MultiEventsClass : IDisposable
    {
        /// <summary>
        /// System.ComponentModel.EventHandlerList包含了一個委派鏈的容器
        /// 實作了多事件存放在一個容器之中的包裝
        /// EventHandlerList使用的是連結串列(LinkedList)資料結構
        /// </summary>
        private EventHandlerList _events;
        //公共建構式
        public MultiEventsClass()
        {
            _events = new EventHandlerList();
        }
        /// <summary>
        /// 釋放EventHanlderList
        /// </summary>
        public void Dispose()
        {
            _events.Dispose();
        }
    }

    /// <summary>
    /// 多事件類別
    /// </summary>
    public partial class MultiEventsClass : IDisposable
    {
        //下面為每一個需要實作的事件，宣告委派類別、訂閱和取消訂閱方法
        //以及事件在集合中的鍵值和觸發事件方法
        //這樣的定義和實際宣告一個事件成員不同，
        //這樣做不會在一個新的MultiEventsClass中分配所有的事件委派鏈的記憶體空間
        //這就是提高效能的關鍵
        //宣告事件1
        #region event1
        //事件1的委派原型
        public delegate void Event1Handler(Object sender, EventArgs e);
        //這裡是靜態的欄位，有效提高效能
        protected static readonly Object Event1Key = new object();
        /// <summary>
        /// 一組訂閱、取消訂閱事件的方法
        /// 注意EventHandlerList並不提供執行緒同步，
        /// 所以在add和remove方法前加上執行緒同步屬性
        /// 讀者可以採取lock機制來代替
        /// </summary>
        public event Event1Handler Event1
        {
            [MethodImpl(MethodImplOptions.Synchronized)]
            add
            {
                _events.AddHandler(Event1Key, value);
            }
            [MethodImpl(MethodImplOptions.Synchronized)]
            remove
            {
                _events.RemoveHandler(Event1Key, value);
            }
        }
        /// <summary>
        /// 觸發事件1
        /// </summary>
        /// <param name="e"></param>
        protected virtual void OnEvent1(EventArgs e)
        {
            _events[Event1Key].DynamicInvoke(this, e);
        }
        /// <summary>
        /// 這個方法簡單地觸發事件1，以便於測試
        /// </summary>
        public void RiseEvent1()
        {
            OnEvent1(EventArgs.Empty);
        }
        #endregion
        //宣告事件2
        #region event2
        //事件2的委派原型
        public delegate void Event2Handler(Object sender, EventArgs e);
        //這裡是靜態的欄位，有效提高效能
        protected static readonly Object Event2Key = new object();
        /// <summary>
        /// 一組訂閱、取消訂閱事件的方法
        /// 注意EventHandlerList並不提供執行緒同步，
        /// 所以在add和remove方法前加上執行緒同步屬性
        /// 讀者可以採取lock機制來代替
        /// </summary>
        public event Event2Handler Event2
        {
            [MethodImpl(MethodImplOptions.Synchronized)]
            add
            {
                _events.AddHandler(Event2Key, value);
            }
            [MethodImpl(MethodImplOptions.Synchronized)]
            remove
            {
                _events.RemoveHandler(Event2Key, value);
            }
        }
        /// <summary>
        /// 觸發事件2
        /// </summary>
        /// <param name="e"></param>
        protected virtual void OnEvent2(EventArgs e)
        {
            _events[Event2Key].DynamicInvoke(this, e);
        }
        /// <summary>
        /// 這個方法簡單地觸發事件2，以便於測試
        /// </summary>
        public void RiseEvent2()
        {
            OnEvent2(EventArgs.Empty);
        }
        #endregion
    }


    /// <summary>
    /// 建立一個訂閱事件的類別
    /// </summary>
    public class Customer
    {
        public Customer(MultiEventsClass events)
        {
            //訂閱事件1
            events.Event1 += Event1Handler;
            //訂閱事件2
            events.Event2 += Event2Handler;
        }
        /// <summary>
        /// 事件1回呼方法
        /// </summary>
        private void Event1Handler(object sender, EventArgs args)
        {
            Console.WriteLine("事件1觸發");
        }
        /// <summary>
        /// 事件2回呼方法
        /// </summary>
        private void Event2Handler(object sender, EventArgs args)
        {
            Console.WriteLine("事件2觸發");
        }
    }

}
