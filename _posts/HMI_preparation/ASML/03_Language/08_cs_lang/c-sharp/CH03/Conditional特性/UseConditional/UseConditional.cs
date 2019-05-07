using System;
using System.Collections.Generic;
using System.Text;
using System.Diagnostics;

namespace NET.MST.Third.UseConditional
{
    //含有兩個成員，生日和身份證
    //身份證的第6位到第14位必須是生日
    //身份證必須是18位
    public class People
    {
        private DateTime _birthday;
        private String _id;
        public DateTime Birthday
        {
            //設定時檢查是否符合商業邏輯
            set
            {
                _birthday = value;
                if (!Check())
                    throw new ArgumentException();
            }
            get
            {
                Debug();
                return _birthday;
            }
        }
        public String ID
        {
            //設定時檢查是否符合商業邏輯
            set
            {
                _id = value;
                if (!Check())
                    throw new ArgumentException();
            }
            get
            {
                Debug();
                return _id;
            }
        }
        public People(String id, DateTime birthday)
        {
            _id = id;
            _birthday = birthday;
            Check();
            Debug();
        }
        //只希望在DEBUG版本中出現
        [Conditional("DEBUG")]
        protected void Debug()
        {
            Console.WriteLine(_birthday.ToString("yyyy-MM-dd"));
            Console.WriteLine(_id);
        }
        //檢查是否符合商業邏輯
        //在所有版本中都需要
        protected bool Check()
        {
            if (_id.Length != 18 ||
                _id.Substring(6, 8) != _birthday.ToString("yyyyMMdd"))
                return false;
            return true;
        }
        static void Main(string[] args)
        {
            try
            {
                People p = new People("310101198008010031",
                    new DateTime(1980, 8, 1));
                p.ID = "310101198709080031";
            }
            catch (ArgumentException ex)
            {
                Console.WriteLine(ex.GetType().ToString());
            }
            finally
            {
                Console.Read();
            }
        }
    }

}
