using System;

namespace NET.MST.Second
{
    public class Compile
    {
        private int m_Int;
        private String m_String;
        //建構式
        public Compile(int i, String s)
        {
            m_Int = i;
            m_String = s;
        }
        //建構式
        public Compile()
        {
        }
        //唯讀屬性
        public int M_Int
        {
            get
            {
                return m_Int;
            }
        }
        //唯讀屬性
        public String M_String
        {
            get
            {
                return m_String;
            }
        }
        //覆寫ToString來獲得想要的輸出
        public override string ToString()
        {
            return "整數值： " + m_Int + ", 字串值：" + m_String;
        }
        static void Main(string[] args)
        {
            Compile compile = new Compile(2, "Test Compile");
            Console.WriteLine(compile);
            Console.Read();
        }
    }

}
