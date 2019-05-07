using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.FinalizeDispose
{
    public class FinalizeDisposeBase : IDisposable
    {
        //標記物件是否已被釋放
        private bool _disposed = false;
        //Finalize方法:
        ~FinalizeDisposeBase()
        {
            Dispose(false);
        }
        //這裡實作了IDispose中的 Dispose方法
        public void Dispose()
        {
            Dispose(true);
            //告訴GC此物件的Finalize方法不再需要呼叫
            GC.SuppressFinalize(true);
        }
        //在這裡做實際的解構工作
        //宣告為虛擬方法，以供子類別在有必要時覆寫
        protected virtual void Dispose(bool isDisposing)
        {
            // 當物件已經被解構時，不再執行
            if (_disposed)
                return;
            if (isDisposing)
            {
                //在這裡釋放託管資源
                //只在使用者呼叫Dispose方法時執行
            }
            //在這裡釋放非託管資源
            //標記物件已被釋放
            _disposed = true;
        }
    }
    public sealed class FinalizeDispose : FinalizeDisposeBase
    {
        private bool _mydisposed = false;
        protected override void Dispose(bool isDisposing)
        {
            //保證只釋放一次
            if (_mydisposed)
                return;
            if (isDisposing)
            {
                //在這裡釋放託管且宣告於這個類別中的資源
            }
            //在這裡釋放非託管且宣告於這個類別中的資源
            //呼叫父類別的Dispose方法來釋放父類別中的資源
            base.Dispose(isDisposing);
            //設定子類別的標記
            _mydisposed = true;
        }
        static void Main()
        {
        }
    }

}