using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Fifth.UseIFormattable
{
    class UseIFormattable : IFormattable
    {
        private DateTime _time;
        public UseIFormattable(DateTime time)
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
            //這一段將在後面章節討論
            if (provider != null)
            {
                ICustomFormatter fmt = provider.GetFormat(this.GetType())
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
                //null和“”在這裡實作
                default:
                    return _time.ToString();
            }
        }
        static void Main(string[] args)
        {
            UseIFormattable use = new UseIFormattable(DateTime.Now);
            //呼叫的是IFormattable.ToString方法
            Console.WriteLine(use);
            Console.WriteLine(use.ToString("ld", null));
            Console.WriteLine(use.ToString("lt", null));
            Console.WriteLine(use.ToString("sd", null));
            Console.WriteLine(use.ToString("st", null));
            Console.Read();
        }
    }

}
