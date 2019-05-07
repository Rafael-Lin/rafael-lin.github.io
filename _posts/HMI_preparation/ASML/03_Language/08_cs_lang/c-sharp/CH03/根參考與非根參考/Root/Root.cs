using System;
using System.Collections.Generic;
using System.Text;

namespace NET.MST.Third.Root
{
    public class Root
    {
        public static Employee staticEmployee;
        static void Main(string[] args)
        {
            staticEmployee = new Employee();	//靜態變數
            Employee a = new Employee();		//區域變數
            Employee b = new Employee();		//區域變數
            a._boss = new Employee();			//物件執行個體成員            
            Console.WriteLine(a);
            Console.Read();
        }
    }
    public class Employee
    {
        public Employee _boss;
        public override string ToString()
        {
            if (_boss == null)
                return "沒有BOSS";
            else
                return "有一個BOSS";
        }
    }

}
