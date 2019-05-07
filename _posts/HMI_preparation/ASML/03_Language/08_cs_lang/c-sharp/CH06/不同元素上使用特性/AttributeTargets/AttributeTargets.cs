using System;

//應用在程式集上
[assembly: MyAttribute]
//應用在模組上
[module: MyAttribute]
//應用在類別上
[type: MyAttribute]
class AttributeTargets<[typevar: MyAttribute] T> //泛型參數上
{
    //應用在欄位上
    [field: MyAttribute]
    private String _MyString;
    //應用在建構式上
    [method: MyAttribute]
    public AttributeTargets() { }
    //應用在屬性上
    [property: MyAttribute]
    public String MyString
    {
        get
        {
            return _MyString;
        }
    }
    //應用在方法上
    [return: MyAttribute]
    public String Format(
        //應用在方法參數上
        [param: MyAttribute]String f)
    {
        return null;
    }
    //應用在事件上
    [event: MyAttribute]
    public event EventHandler MyEvent;
}
/// <summary>
/// 一個空的特性，可用於所有元素
/// </summary>
public class MyAttribute : System.Attribute { }
public class MainClass
{
    static void Main(string[] args) { }
}
