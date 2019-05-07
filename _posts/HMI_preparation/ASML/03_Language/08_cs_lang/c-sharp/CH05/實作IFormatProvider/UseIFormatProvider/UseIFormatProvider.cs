using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fifth.UseIFormatProvider
{
    class UseIFormatProvider : IFormattable
    {
        public DateTime _time;
        public UseIFormatProvider(DateTime time)
        {
            _time = time;
        }
        //覆寫ToString方法
        public override string ToString()
        {
            return "Object.ToString()";
        }
        public String ToString(String format, IFormatProvider provider)
        {
            //這裡判斷使用者是否提供了格式化器
            if (provider != null)
            {
                ICustomFormatter fmt = provider.GetFormat(
                  this.GetType())
                  as ICustomFormatter;
                if (fmt != null)
                    return fmt.Format(format, this, provider);
            }
            //這裡實作格式化輸出
            switch (format)
            {
                case "ld":
                    return _time.ToLongDateString();
                case "lt":
                    return _time.ToLongTimeString();
                case "sd":
                    return _time.ToShortDateString();
                case "st":
                    return _time.ToShortTimeString();
                //G必須實作
                case "G":
                //nul和“”在這裡實作
                default:
                    return _time.ToString();
            }
        }
        static void Main(string[] args)
        {
            UseIFormatProvider use = new UseIFormatProvider(DateTime.Now);
            IFormatProvider provider = new MyProvider();
            Console.WriteLine(use);   //呼叫的是IFormattable.ToString方法
            //使用者提供格式化方法，格式化字串不再起作用
            Console.WriteLine(use.ToString("lt", provider));
            Console.WriteLine(use.ToString("st", provider));
            Console.Read();
        }
    }


    //實作了IFormatProvider的類別，
    //為了方便範例說明，同時實作ICustomFormatter介面，
    //其實在實際情況中，這樣的做法也很常見
    class MyProvider : ICustomFormatter, IFormatProvider
    {
        //實作了ICustomFormatter的Format方法
        //實際的格式化工作在這裡完成
        String ICustomFormatter.Format(string format, object arg, IFormatProvider formatProvider)
        {
            UseIFormatProvider obj = arg as UseIFormatProvider;
            if (obj == null)
                return arg.ToString();
            return obj._time.ToString("yyyy-MM-dd HH:mm:ss");
        }
        //本類別可以實作對UseIFormatProvider類別的格式化，
        //所以先判斷物件的類別
        Object IFormatProvider.GetFormat(Type type)
        {
            if (type == typeof(UseIFormatProvider))
                return this;
            else
                return null;
        }
    }

}
