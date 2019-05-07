# 【C#】委託delegate,Func<>,Action 解說系列(二)
最後帶著大家來實現自己的Linq Where

先來看 Func<> ，Action<>原始定義

我們發現Func<> ，Action<> 其實本質就是委託 ，雖然有十幾個重載 但大同小異


public delegate TResult Func<out TResult>();


public delegate void Action<in T>(T obj);


## Func固定最後一個泛型參數為方法回傳值，其餘是傳入參數

public delegate TResult Func<in T, out TResult>(T arg);


解說：
宣告一個Func<Person,string>委託 _thunkCheckAge
_thunkCheckAge委託指向CheckAge方法
執行_thunkCheckAge委託 (執行CheckAge方法)
```
public class Person
{
    public int Age { get; set; }
    public string Name { get; set; }
}

/// <summary>
/// 年紀超過10歲算老人
/// </summary>
/// <param name="person"></param>
/// <returns></returns>
public static string CheckAge(Person person)
{
    string result = "年紀剛剛好";
    if (person.Age >= 10)
        {
        result = "老人";
    }
    return result;
}
static void Main(string[] args)
{
    //Init一個Person物件
    Person p = new Person()
    {
        Age = 10,
        Name = "tom"
    };

    #region Func
    //宣告一個Func<Person,string>委託 _thunkCheckAge
    Func<Person, string> _thunkCheckAge;

    //_thunkCheckAge委託指向CheckAge方法
    _thunkCheckAge = new Func<Person, string>(CheckAge);

    //執行_thunkCheckAge委託 (執行CheckAge方法)
    string result = _thunkCheckAge(p);

    //最後將結果顯示出來
    Console.WriteLine(result);
    #endregion



    Console.ReadKey();
}
```


Action這個委託是Void，傳入參數型態是由泛型來決定

public delegate void Action<in T>(T obj);


解說：
宣告一個Action<Person>委託的 _thunkPerson物件
將CallPersonInfo方法 賦予給_thunkPerson
執行_thunkPerson (就是執行CallPersonInfo方法)

```
public class Person
{
    public int Age { get; set; }
    public string Name { get; set; }
}
static void Main(string[] args)
{
    //宣告_thunkPerson為Action<Person>委託
    //此Action傳入參數是Person由泛型來決定
    Action<Person> _thunkPerson;
    //Init一個Person物件
    Person p = new Person()
    {
        Age = 10,
        Name = "tom"
    };
    //將CallPersonInfo方法 賦予給_thunkPerson
    _thunkPerson = new Action<Person>(CallPersonInfo);

    //執行_thunkPerson (就是執行CallPersonInfo方法)
    _thunkPerson(p);
    Console.ReadKey();
}

public static void CallPersonInfo(Person person)
{
    Console.WriteLine($"Age:{person.Age} Name:{person.Name}");
}
```


小總結：

Action和Func差別是

Action是void不回傳值 as 委託
Func是有回傳值 as 委託


有了以上的基礎，我們就來實現我們自己的Linq Where 和 Linq Select

先來分析 Where 方法簽章

public static IEnumerable<TSource> Where<TSource>(this IEnumerable<TSource> source, Func<TSource, bool> predicate)

分析：
如果我要找一個大於10歲的人,撰寫一般Linq Where 如下在where中塞選此集合的條件，那我要怎麼自己實現呢？

重點在於[執行塞選條件]這個動作
```

List<Person> pList = new List<Person>()
{
    new Person() { Age=100,Name="daniel"},
    new Person() { Age=20,Name="Tom" },
    new Person() { Age = 10,Name = "Amy"},
    new Person() { Age=5,Name = "rjo"}
};
pList.Where(per => per.Age > 10);
```

以下是實現自己的Where語法 有沒有很簡單^^

重點在if(where(item)) 判斷物件是否符合條件，如符合就回傳此物件

```
public static class LinqExtension
{
    /// <summary>
    /// 自訂一個Where
    /// </summary>
    /// <typeparam name="TSource"></typeparam>
    /// <param name="source"></param>
    /// <param name="where"></param>
    /// <returns></returns>
    public static IEnumerable<TSource> MyWhere<TSource>(this IEnumerable<TSource> source
        ,Func<TSource, bool> where)
    {
        foreach (var item in source)
        {
            if (where(item))
            {
                yield return item;
            }
        }
    }
}
```


總結：
委託把不確定的動作，轉移給呼叫端來撰寫。

而不是寫死在程式中

上面的MyWhere挖了一個洞，關於判斷是否符合條件，給呼叫端實現

雖然在裡面一樣是一個一個判斷是否符合條件，符合再返回

但利用委託和泛型就可以對於任何條件和任何型別來做比較　大大提升了程式效率


# IOC(控制反轉) ， DI(依賴注入) 深入淺出~~
5963 1 Comment 設計範式 檢舉文章  2019-04-15
Ioc是一個oop重要的程式設計思想。

此文帶著大家初探 IOC(控制反轉) ， DI(依賴注入) ~~

學一個技術或思想前我們最好先了解，這個技術或思想為我們解決怎樣問題。



Ioc—Inversion of Control 控制反轉
控制反轉是一個設計思想 ，把對於某個物件的控制權移轉給第三方容器

簡單解釋

A物件程式內部需要使用B物件 A,B物件中有依賴的成份

控制反轉是把原本A對B控制權移交給第三方容器

降低A對B物件的耦合性，讓雙方都倚賴第三方容器。



反轉概念如下圖



我們可發現有兩點差異

使用者原本直接耦合於A，但使用IoC容器使用者就直接對容器而不是A 至於A關連於誰由容器決定
原本A直接控制於B,C，但透過一個IoC容器我們控制權反轉給了容器
IoC經典實現對象設計法則　好萊塢法則：“別找我們，我們找你”
系統中模組建議依賴抽象，因為各個模組間不需要知道對方太多細節（實作），知道越多耦合越強。
DI—Dependency Injection 依賴注入


把被依賴物件注入被動接收物件中



案例解釋：

小明是個愛乾淨的人，但他工作時常加班導致房間雜亂，他不能忍受此狀況，所以小明去找一個清潔阿姨每天幫忙他打掃家裡
哪天阿姨哪天有事不能打掃，小明就必須要再去找人來幫忙打掃，由此可知小明耦合阿姨

------------------------------------------------------------------------------------



如果今天是....

小明把他要的條件給「打掃仲介公司」，仲介公司幫他尋找有沒有符合小明需求的打掃阿姨，假如今天A阿姨請假了，仲介公司會自動找另一個符合需求B阿姨幫忙打掃...



原本小明需耦合於打掃阿姨，現在被「仲介公司」做了控制反轉讓「仲介公司」來提供打掃阿姨。

小明不用管是否今天有人會來打掃，「仲介公司」會幫小明找到一個掃地阿姨。



「仲介公司」可看作 依賴注入容器
「小明」可看作 被動接收物件

「打掃阿姨」可看作 被依賴物件



在使用IOC容器前需先了解雙方的依賴關係(誰依賴誰?)



上述還有一個很重要的觀念是，依賴和被接收對象要倚賴抽象。





範例使用：VS2015

IOC容器：AutoFac

下面範例來說明上面的例子

小明自己依賴於掃地阿姨
依賴程式碼寫在小明類別內部日後要更改只能動內部程式碼。

/// <summary>
/// 小明直接依賴 Aunt 不是依賴抽象
/// 日後要改必須動內部
/// </summary>
public class Mine
{
    public Aunt aunt = new Aunt();

    public void Room()
    {
        aunt.Swapping();
    }
}


呼叫使用時

Mine mine = new Mine();
mine.Room();


小明找仲介公司


仲介公司(Ioc容器)

在仲介公司內註冊需求，讓仲介公司日後幫你找人（註冊的類別）

/// <summary>
/// 仲介公司
/// </summary>
/// <returns></returns>
private static IContainer MiddleCompany()
{
    ContainerBuilder builder = new ContainerBuilder();

    //在仲介公司裡寫需求人申請單
    builder.RegisterType<MineWithMiddle>();
    //小明所需打掃阿姨需求
    builder.RegisterType<Aunt>().As<ISwapable>();

    return builder.Build();
}


使用起來

IContainer middleCompany = MiddleCompany();
//仲介公司(IOC AutoFac)自動幫小明注入一個打掃阿姨
MineWithMiddle mineWithMiddle = middleCompany.Resolve<MineWithMiddle>();

mineWithMiddle.Room();


總結：

系統中模組建議依賴抽象，因為各個模組間不需要知道對方太多細節（實作），知道越多耦合越強。
像網頁瀏覽器和伺服器是依賴Http協議，用戶端不管是手機.電腦,平板，伺服器端php,asp.net,java都可互相交信，依賴Http協議共用的合約
控制反轉：是一個設計思想 ，把對於某個物件的控制權移轉給共同第三方
依賴注入：把被依賴物件注入被動接收物件中

範例原始碼 ：https://github.com/isdaniel/IOC_Sample

參考連結 :　http://www.cnblogs.com/xdp-gacl/p/4249939.html

2019/03/28 更新
在原始碼中有第二個專案AutofacWihtAOP 這是對於另一篇IOC+AOP的綜合使用文章 Autofac + Interceptors(AOP) 動態代理



# 【C#】委託delegate,Func<>,Action 解說系列 (三)

那到底是神麼意思呢?

讓我們一起看下去....

//Action delegate
public delegate void Action<in T>(T obj);

//fun delegate
public delegate TResult Func<in T, out TResult>(T arg);
上面程式碼我列出Action和Func 委派方法各其中一個重載

我們可以發現到泛型中有關鍵字 in 和 out 這是代表神麼意思呢?

讓我們繼續看下去.....


分享前先探討一個問題 泛型是否可以父類別指向子類別
public interface IGeneric<T> { }
public class Base<T> : IGeneric<T> { }

public class A { }

class Program
{

    static void Main(string[] args)
    {
        IGeneric<object> b = new Base<object>();
        IGeneric<A> a = new Base<A>();
        //無法執行父類只向子類別 因為泛型預設是Invariance
        b = a;
        Console.ReadKey();
    }
}
上面範例程式很清楚知道無法編譯，那我要怎麼處理和解決的？

第一種解法 使用 AS :

public interface IGeneric<T> { }
public class Base<T> : IGeneric<T> { }

public class A { }

class Program
{

    static void Main(string[] args)
    {
        IGeneric<object> b = new Base<object>();
        IGeneric<A> a = new Base<A>();
        //使用AS來轉型
        b = a as IGeneric<object>;
        Console.ReadKey();
    }
}


第二種解法 在interface的泛型中使用 Out (今天要介紹的主角)

//這裡使用out將T 解釋為Covariance
public interface IGeneric<out T> { }
public class Base<T> : IGeneric<T> { }

public class A { }

class Program
{

    static void Main(string[] args)
    {
        IGeneric<object> b = new Base<object>();
        IGeneric<A> a = new Base<A>();
        //在上面的泛型用out
        b = a;
        Console.ReadKey();
    }
}


MSDN中有解釋 此關鍵字 泛型中的共變數和反變數

有三個重要名詞 Covariance，Contravariance，Invariance


Covariance(共變數) ：
MSDN說明：可讓您使用比原本指定更多衍生的類型。您可以將 IEnumerable<Derived> (在 Visual Basic 中為 IEnumerable(Of Derived)) 的執行個體指派給 IEnumerable<Base> 類型的變數
簡單說明：泛型支援父類指向子類別  [泛型中使用out ]  (支援泛型介面或泛型委派)
如下面的範例:

因IGeneric<out T>所以下面a付值給b就不需轉型

//這裡使用out將T 解釋為Covariance
public interface IGeneric<out T> { }
public class Base<T> : IGeneric<T> { }

public class A { }

class Program
{

    static void Main(string[] args)
    {
        IGeneric<object> b = new Base<object>();
        IGeneric<A> a = new Base<A>();
        //在上面的泛型用out
        b = a;
        Console.ReadKey();
    }
}



Contravariance(反變數)
MSDN說明：可讓您使用比原本所指定更泛型 (較少衍生) 的類型。您可以將 IEnumerable<Base> (在 Visual Basic 中為 IEnumerable(Of Base)) 的執行個體指派給IEnumerable<Derived> 類型的變數。

簡單說明：可將父類物件引用賦予給子類別 [泛型中有in]
如下範例：

因IComparer<in T> 所以子類可以取得父類的引用

//這裡使用in將T 解釋為Contravariance
public interface IGeneric<in T> { }

public class Base<T> : IGeneric<T> { }

public abstract class Shape
{
    public virtual double Area { get { return 0; } }
}

public class Square : Shape
{
    private double r;
    public Square(double radius) { r = radius; }
    public double Radius { get { return r; } }
    public override double Area { get { return r * r; } }
}

public class Circle : Shape
{
    private double r;
    public Circle(double radius) { r = radius; }
    public double Radius { get { return r; } }
    public override double Area { get { return Math.PI * r * r; } }
}

public class ShapeAreaComparer : IComparer<Shape>
{
    int IComparer<Shape>.Compare(Shape a, Shape b)
    {
        if (a == null) return b == null ? 0 : -1;
        return b == null ? 1 : a.Area.CompareTo(b.Area);
    }
}

class Program
{

    static void Main(string[] args)
    {
        //泛型[形狀類別(基類)]
        IGeneric<Shape> b = new Base<Shape>();
        //泛型[圓形類別(子類)]
        IGeneric<Circle> a = new Base<Circle>();
        //子類可以取得父類引用
        a = b;
        Console.ReadKey();
    }
}


Invariance 只能該類別指向該類別
一般泛型預設就是這個





總結：

Func 泛型委派的最後一個泛型類型參數會指定委派簽章中的傳回值類型

Covariance (共變數) (out 關鍵字) 泛型支援父類指向子類別

Contravariant (反變數) (in 關鍵字)  泛型子類可以取得父類的引用

Invariance 一般泛型預設就是這個

# Caliburn

Caliburn Micro
This is another small open-source framework that helps you implement the MVVM
pattern and also supports a number of things out-of-the-box.

Caliburn Micro is a small, yet powerful framework, designed for building
applications across all XAML platforms.

With strong support for MVVM and other proven UI patterns, Caliburn Micro will
enable you to build your solution quickly, without the need to sacrifice code
quality or testability.

# DI/IOC

In this chapter, we will briefly discuss about dependency injection. We have already covered data binding decouples Views and ViewModels from each other that allows them to communicate without knowing explicitly what is going on at the other end of the communication.

Now we need something similar to decouple our ViewModel from the client services.

In early days of object-oriented programming, developers have faced the issue of creating and retrieving instances of classes in applications. Various solutions have been proposed for this problem.

For the past few years, dependency injection and inversion of control (IoC) have gained popularity among developers and have taken precedence over some older solutions such as the Singleton pattern.

Dependency Injection / IoC Containers
IoC and dependency injection are two design patterns that are closely related
and the container is basically a chunk of infrastructure code that does both of
those patterns for you.

IoC pattern is about delegating responsibility for construction and the
dependency injection pattern is about providing dependencies to an object that's
already been constructed.

They can both be treated as a two-phase approach to constructing. When you use a
container, the container takes several responsibilities which are as follows −


It constructs an object when asked.
The container will determine what that object depends on.
Constructing those dependencies.
Injecting them into the object being constructed.

Recursively doing process.

Let's have a look at how we can use dependency injection to break decoupling
between ViewModels and the client services. We will wire up the save handling
AddEditCustomerViewModel form by using dependency injection related to that.

First we need to create a new interface in our project in Services folder. If
you don’t have a services folder in your project then create it first and add
the following interface in the Services folder.

using MVVMHierarchiesDemo.Model;

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MVVMHierarchiesDemo.Services {

   public interface ICustomersRepository {
      Task<List<Customer>> GetCustomersAsync();
      Task<Customer> GetCustomerAsync(Guid id);
      Task<Customer> AddCustomerAsync(Customer customer);
      Task<Customer> UpdateCustomerAsync(Customer customer);
      Task DeleteCustomerAsync(Guid customerId);
   }
}
Following is the implementation of ICustomersRepository.

using MVVMHierarchiesDemo.Model;

using System;
using System.Collections.Generic;
using System.Linq; using System.Text;
using System.Threading.Tasks;

namespace MVVMHierarchiesDemo.Services {

   public class CustomersRepository : ICustomersRepository {
      ZzaDbContext _context = new ZzaDbContext();

      public Task<List<Customer>> GetCustomersAsync() {
         return _context.Customers.ToListAsync();
      }

      public Task<Customer> GetCustomerAsync(Guid id) {
         return _context.Customers.FirstOrDefaultAsync(c => c.Id == id);
      }

      public async Task<Customer> AddCustomerAsync(Customer customer){
         _context.Customers.Add(customer);
         await _context.SaveChangesAsync();
         return customer;
      }

      public async Task<Customer> UpdateCustomerAsync(Customer customer) {

         if (!_context.Customers.Local.Any(c => c.Id == customer.Id)) {
            _context.Customers.Attach(customer);
         }

         _context.Entry(customer).State = EntityState.Modified;
         await _context.SaveChangesAsync();
         return customer;

      }

      public async Task DeleteCustomerAsync(Guid customerId) {
         var customer = _context.Customers.FirstOrDefault(c => c.Id == customerId);

         if (customer != null) {
            _context.Customers.Remove(customer);
         }

         await _context.SaveChangesAsync();
      }
   }
}
The simple way to do Save handling is to add a new instance of ICustomersRepository in AddEditCustomerViewModel and overload the AddEditCustomerViewModel and CustomerListViewModel constructor.

private ICustomersRepository _repo;

public AddEditCustomerViewModel(ICustomersRepository repo) {
   _repo = repo;
   CancelCommand = new MyIcommand(OnCancel);
   SaveCommand = new MyIcommand(OnSave, CanSave);
}
Update the OnSave method as shown in the following code.

private async void OnSave() {
   UpdateCustomer(Customer, _editingCustomer);

   if (EditMode)
      await _repo.UpdateCustomerAsync(_editingCustomer);
   else
      await _repo.AddCustomerAsync(_editingCustomer);
   Done();
}

private void UpdateCustomer(SimpleEditableCustomer source, Customer target) {
   target.FirstName = source.FirstName;
   target.LastName = source.LastName;
   target.Phone = source.Phone;
   target.Email = source.Email;
}
Following is the complete AddEditCustomerViewModel.

using MVVMHierarchiesDemo.Model;
using MVVMHierarchiesDemo.Services;

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MVVMHierarchiesDemo.ViewModel {

   class AddEditCustomerViewModel : BindableBase {
      private ICustomersRepository _repo;

      public AddEditCustomerViewModel(ICustomersRepository repo) {
         _repo = repo;
         CancelCommand = new MyIcommand(OnCancel);
         SaveCommand = new MyIcommand(OnSave, CanSave);
      }

      private bool _EditMode;

      public bool EditMode {
         get { return _EditMode; }
         set { SetProperty(ref _EditMode, value); }
      }

      private SimpleEditableCustomer _Customer;

      public SimpleEditableCustomer Customer {
         get { return _Customer; }
         set { SetProperty(ref _Customer, value); }
      }

      private Customer _editingCustomer = null;

      public void SetCustomer(Customer cust) {
         _editingCustomer = cust;

         if (Customer != null) Customer.ErrorsChanged -= RaiseCanExecuteChanged;
         Customer = new SimpleEditableCustomer();
         Customer.ErrorsChanged += RaiseCanExecuteChanged;
         CopyCustomer(cust, Customer);
      }

      private void RaiseCanExecuteChanged(object sender, EventArgs e) {
         SaveCommand.RaiseCanExecuteChanged();
      }

      public MyIcommand CancelCommand { get; private set; }
      public MyIcommand SaveCommand { get; private set; }

      public event Action Done = delegate { };

      private void OnCancel() {
         Done();
      }

      private async void OnSave() {
         UpdateCustomer(Customer, _editingCustomer);

         if (EditMode)
            await _repo.UpdateCustomerAsync(_editingCustomer);
         else
            await _repo.AddCustomerAsync(_editingCustomer);
         Done();
      }

      private void UpdateCustomer(SimpleEditableCustomer source, Customer target) {
         target.FirstName = source.FirstName;
         target.LastName = source.LastName;
         target.Phone = source.Phone;
         target.Email = source.Email;
      }

      private bool CanSave() {
         return !Customer.HasErrors;
      }

      private void CopyCustomer(Customer source, SimpleEditableCustomer target) {
         target.Id = source.Id;

         if (EditMode) {
            target.FirstName = source.FirstName;
            target.LastName = source.LastName;
            target.Phone = source.Phone;
            target.Email = source.Email;
         }
      }
   }
}

When the above code is compiled and executed, you will see the same output but now ViewModels are more loosely decoupled.

MVVM Dependency Injection MainWindow1
When you press the Add Customer button, you will see the following view. When the user leaves any field empty, then it will become highlighted and the save button will become disabled.


# WCF Tutorial point


## WCF - Creating WCF Service

Creating a WCF service is a simple task using Microsoft Visual Studio 2012.
Given below is the step-by-step method for creating a WCF service along with all
the requisite coding, to understand the concept in a better way.

Launch Visual Studio 2012.
Click on new project, then in Visual C# tab, select WCF option.


A WCF service is created that performs basic arithmetic operations like
addition, subtraction, multiplication, and division. The main code is in two
different files – one interface and one class.

A WCF contains one or more interfaces and its implemented classes.

```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

namespace WcfServiceLibrary1 {
   // NOTE: You can use the "Rename" command on the "Refactor" menu to
   // change the interface name "IService1" in both code and config file
   // together.

   [ServiceContract]
   Public interface IService1 {
      [OperationContract]
      int sum(int num1, int num2);

      [OperationContract]
      int Subtract(int num1, int num2);

      [OperationContract]
      int Multiply(int num1, int num2);

      [OperationContract]
      int Divide(int num1, int num2);
   }

   // Use a data contract as illustrated in the sample below to add
   // composite types to service operations.

   [DataContract]
   Public class CompositeType {
      Bool boolValue = true;
      String stringValue = "Hello ";

      [DataMember]
      Public bool BoolValue {
         get { return boolValue; }
         set { boolValue = value; }
      }

      [DataMember]
      Public string StringValue {
         get { return stringValue; }
         set { stringValue = value; }
      }
   }
}
```

The code behind its class is given below.

```
using System;
usingSystem.Collections.Generic;
usingSystem.Linq;
usingSystem.Runtime.Serialization;
usingSystem.ServiceModel;
usingSystem.Text;

namespace WcfServiceLibrary1 {
   // NOTE: You can use the "Rename" command on the "Refactor" menu to
   // change the class name "Service1" in both code and config file
   // together.

   publicclassService1 :IService1 {
      // This Function Returns summation of two integer numbers

      publicint sum(int num1, int num2) {
         return num1 + num2;
      }

      // This function returns subtraction of two numbers.
      // If num1 is smaller than number two then this function returns 0

      publicint Subtract(int num1, int num2) {
         if (num1 > num2) {
            return num1 - num2;
         }
         else {
            return 0;
         }
      }

      // This function returns multiplication of two integer numbers.
      publicint Multiply(int num1, int num2) {
         return num1 * num2;
      }

      // This function returns integer value of two integer number.
      // If num2 is 0 then this function returns 1.
      publicint Divide(int num1, int num2) {
         if (num2 != 0) {
            return (num1 / num2);
         } else {
            return 1;
         }
      }
   }
}
```

To run this service, click the Start button in Visual Studio.

Wcf Creating Service4
While we run this service, the following screen appears.

Wcf Creating Service5
On clicking the sum method, the following page opens. Here, you can enter any two integer numbers and click on the Invoke button. The service will return the summation of those two numbers.

Wcf Creating Service6Wcf Creating Service7
Like summation, we can perform all other arithmetic operations which are listed in the menu. And here are the snaps for them.

The following page appears on clicking the Subtract method. Enter the integer numbers, click the Invoke button, and get the output as shown here −

Wcf Creating Service8
The following page appears on clicking the Multiply method. Enter the integer numbers, click the Invoke button, and get the output as shown here −

Wcf Creating Service9
The following page appears on clicking the Divide method. Enter the integer numbers, click the Invoke button, and get the output as shown here −

Wcf Creating Service10
Once the service is called, you can switch between them directly from here.

## WCF - Hosting WCF Service
After creating a WCF service, the next step is to host it so that the client
applications can consume it. This is known as WCF service hosting. A WCF service
can be hosted by using any of the four ways given below −

IIS Hosting − IIS stands for Internet Information Services. Its working model is
similar to that of ASP.NET while hosting a WCF service. The best feature of IIS
hosting is that the service activation is processed automatically. IIS hosting
also offers process health monitoring, idle shutdown, process recycling, and
many more features to facilitate a WCF service hosting.

Self-Hosting − When a WCF service is hosted in a managed application, it is
known as self-hosting. It requires a developer to write the requisite coding for
ServiceHost initialization. In self-hosting, a WCF service can be hosted in a
variety of applications like Console application, Windows form, etc.

WAS Hosting − Hosting a WCF service in Windows Activation Service (WAS) is most
advantageous because of its features such as process recycling, idle time
management, common configuration system, and support for HTTP, TCP, etc.

Windows Service Hosting − For local system clients, it is best to host WCF
service as a window service and this is known as Window Service Hosting. All the
versions of Windows support this type of hosting and here, the Service Control
Manager can control the process lifecycle of the WCF service.


## Hosting a WCF service in IIS
(Internet Information Services) is a step-by-step process. IIS Hosting is
illustrated below in detail with the desired coding as well as screenshots to
understand the process.

Step 1 − Start Visual Studio 2012 and click File → New → Web site. Select “WCF
Service” and Location as http. This will host the service in IIS. Click OK.

Wcf Hosting Services IIS 1 Step 2 − The code behind the interface is given
below.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

// NOTE: You can use the "Rename" command on the "Refactor" menu to
// change the interface name "IService" in both code and config file
// together.

[ServiceContract]
Public interface IService {
   [OperationContract]
   String GetData(int value);

   [OperationContract]
   CompositeType GetDataUsingDataContract(CompositeType composite);

   // TODO: Add your service operations here
}

// Use a data contract as illustrated in the sample below to add
// composite types to service operations.

[DataContract]
Public class CompositeType {
   Bool boolValue = true;
   String stringValue = "Hello ";

   [DataMember]
   Public bool BoolValue {
      get { return boolValue; }
      set { boolValue = value; }
   }

   [DataMember]
   Public string StringValue {
      get { return stringValue; }
      set { stringValue = value; }
   }
}
Step 3 − The code behind the class file is given below.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

// NOTE: You can use the "Rename" command on the "Refactor" menu to
// change the class name "Service" in code, svc and config file
// together.

Public class Service : IService {
   Public string GetData(int value) {
      Return string.Format("You entered: {0}", value);
   }

   Public CompositeType GetDataUsingDataContract(CompositeType composite) {
      if(composite == null) {
         thrownewArgumentNullException("composite");
      }

      if(composite.BoolValue) {
         composite.StringValue += "Suffix";
      }
      return composite;
   }
}
Step 4 − Service file (.svc) contains the name of the service and the code behind the file name. This file is used to know about the service.

Wcf Hosting Services IIS 4
<%@ ServiceHost Language = "C#" Debug = "true" Service = "Service"
   CodeBehind = "~/App_Code/Service.cs" %>

Step 5 − Server-side configurations are mentioned in the config file. Here,
there is a mention of only one end-point which is configured to 'wsHttpBinding';
we can also have multiple endpoints with different bindings. Since we are going
to host in IIS, we have to use only http binding.

IIS ==> http binding

<?xml version = "1.0"?>
<configuration>
   <!--
      Note: As an alternative to hand editing this file you can use the
         web admin tool to configure settings for your application. Use
         the Website->Asp.Net Configuration option in Visual Studio.
         A full list of settings and comments can be found in
         machine.config.comments usually located in
         \Windows\Microsoft.Net\Framework\vx.x\Config
   -->
   <configSections>
      <sectionGroup name = "system.web.extensions"
         ype = "System.Web.Configuration.SystemWebExtensionsSectionGroup,
         System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
         PublicKeyToken = 31BF3856AD364E35">

         <sectionGroup name = "scripting"
            type = "System.Web.Configuration.ScriptingSectionGroup,
            System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35">

            <section name = "scriptResourceHandler"
               type = "System.Web.Configuration.ScriptingScriptResourceHandlerSection,
               System.Web.Extensions, Version = 3.5.0.0,
               Culture = neutral, PublicKeyToken = 31BF3856AD364E35"
               requirePermission = "false"
               allowDefinition = "MachineToApplication"/>

            <sectionGroup name = "webServices"
               type = "System.Web.Configuration.ScriptingWebServicesSectionGroup,
               System.Web.Extensions, Version = 3.5.0.0,
               Culture = neutral, PublicKeyToken = 31BF3856AD364E35">

               <section name = "jsonSerialization"
                  type = "System.Web.Configuration.ScriptingJsonSerializationSection,
                  System.Web.Extensions, Version = 3.5.0.0,
                  Culture = neutral, PublicKeyToken = 31BF3856AD364E35"
                  requirePermission = "false" allowDefinition = "Everywhere"/>

               <section name = "profileService"
                  type = "System.Web.Configuration.ScriptingProfileServiceSection,
                  System.Web.Extensions, Version = 3.5.0.0,
                  Culture = neutral, PublicKeyToken = 31BF3856AD364E35"
                  requirePermission = "false"
                  allowDefinition = "MachineToApplication"/>

               <section name = "authenticationService"
                  type = "System.Web.Configuration.ScriptingAuthenticationServiceSection,
                  System.Web.Extensions, Version = 3.5.0.0,
                  Culture = neutral, PublicKeyToken = 31BF3856AD364E35"
                  requirePermission = "false"
                  allowDefinition = "MachineToApplication"/>

               <section name = "roleService"
                  type = "System.Web.Configuration.ScriptingRoleServiceSection,
                  System.Web.Extensions, Version = 3.5.0.0,
                  Culture = neutral, PublicKeyToken = 31BF3856AD364E35"
                  requirePermission = "false"
                  allowDefinition = "MachineToApplication"/>

            </sectionGroup>
         </sectionGroup>
      </sectionGroup>
   </configSections>

<appSettings/>
   <connectionStrings/>
   <system.web>
      <!--
         Set compilation debug="true" to insert debugging
         symbols into the compiled page. Because this
         affects performance, set this value to true only
         during development.
      -->

      <compilation debug = "true">
         <assemblies>

            <add assembly = "System.Core, Version = 3.5.0.0, Culture = neutral,
               PublicKeyToken = B77A5C561934E089"/>

            <add assembly = "System.Web.Extensions, Version = 3.5.0.0,
               Culture = neutral, PublicKeyToken = 31BF3856AD364E35"/>

            <add assembly = "System.Data.DataSetExtensions, Version = 3.5.0.0,
               Culture = neutral, PublicKeyToken = B77A5C561934E089"/>

            <add assembly = "System.Web.Extensions, Version = 3.5.0.0,
               Culture = neutral, PublicKeyToken = 31BF3856AD364E35"/>

            <add assembly = "System.Xml.Linq, Version = 3.5.0.0, Culture = neutral,
               PublicKeyToken = B77A5C561934E089"/>

         </assemblies>
      </compilation>

         <!--
            The <authentication> section enables configuration
            of the security authentication mode used by
            ASP.NET to identify an incoming user.
         -->

      <authentication mode="Windows"/>
         <!--
            The <customErrors> section enables configuration
            of what to do if/when an unhandled error occurs
            during the execution of a request. Specifically,
            it enables developers to configure html error pages
            to be displayed in place of a error stack trace.

            <customErrors mode = "RemoteOnly" defaultRedirect = "GenericErrorPage.htm">
               <error statusCode = "403" redirect = "NoAccess.htm" />
               <error statusCode = "404" redirect = "FileNotFound.htm" />
            </customErrors>
         -->

         <pages>
            <controls>
               <add tagPrefix = "asp" namespace = "System.Web.UI"
                  assembly = "System.Web.Extensions, Version = 3.5.0.0,
                  Culture = neutral, PublicKeyToken = 31BF3856AD364E35"/>

               <add tagPrefix = "asp" namespace = "System.Web.UI.WebControls"
                  assembly = "System.Web.Extensions, Version = 3.5.0.0,
                  Culture = neutral, PublicKeyToken = 31BF3856AD364E35"/>

            </controls>
         </pages>

         <httpHandlers>
            <remove verb = "*" path = "*.asmx"/>

            <add verb = "*" path = "*.asmx" validate = "false"
               type = "System.Web.Script.Services.ScriptHandlerFactory,
               System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
               PublicKeyToken = 31BF3856AD364E35"/>

            <add verb = "*" path = "*_AppService.axd" validate = "false"
               type = "System.Web.Script.Services.ScriptHandlerFactory,
               System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
               PublicKeyToken = 31BF3856AD364E35"/>

            <add verb = "GET,HEAD" path = "ScriptResource.axd"
               type = "System.Web.Handlers.ScriptResourceHandler,
               System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
               PublicKeyToken = 31BF3856AD364E35" validate = "false"/>
         </httpHandlers>

         <httpModules>
            <add name = "ScriptModule"
               type = "System.Web.Handlers.ScriptModule,
               System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
               PublicKeyToken = 31BF3856AD364E35"/>
         </httpModules>
   </system.web>

   <system.codedom>
      <compilers>

         <compiler language = "c#;cs;csharp" extension = ".cs"
            warningLevel = "4" type = "Microsoft.CSharp.CSharpCodeProvider,
            System, Version = 2.0.0.0, Culture = neutral,
            PublicKeyToken = b77a5c561934e089">

            <providerOption name = "CompilerVersion" value = "v3.5"/>
            <providerOption name = "WarnAsError" value = "false"/>

         </compiler>

         <compiler language = "vb;vbs;visualbasic;vbscript" extension = ".vb"
            warningLevel = "4" type = "Microsoft.VisualBasic.VBCodeProvider,
            System, Version = 2.0.0.0, Culture = neutral,
            PublicKeyToken = b77a5c561934e089">

            <providerOption name = "CompilerVersion" value = "v3.5"/>
            <providerOption name = "OptionInfer" value = "true"/>
            <providerOption name = "WarnAsError" value = "false"/>

         </compiler>
      </compilers>

   </system.codedom>
   <!--
      The system.webServer section is required for running ASP.NET AJAX
      under Internet Information Services 7.0.
      It is not necessary for previous version of IIS.
   -->
   <system.webServer>
      <validation validateIntegratedModeConfiguration="false"/>

      <modules>
         <remove name = "ScriptModule"/>
         <add name = "ScriptModule" preCondition = "managedHandler"
            type = "System.Web.Handlers.ScriptModule,
            System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35"/>
      </modules>

      <handlers>
         <remove name = "WebServiceHandlerFactory-Integrated"/>
         <remove name = "ScriptHandlerFactory"/>
         <remove name = "ScriptHandlerFactoryAppServices"/>
         <remove name = "ScriptResource"/>

         <add name = "ScriptHandlerFactory" verb = "*" path = "*.asmx"
            preCondition = "integratedMode"
            type = "System.Web.Script.Services.ScriptHandlerFactory,
            System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35"/>

         <add name = "ScriptHandlerFactoryAppServices"
            verb = "*" path = "*_AppService.axd" preCondition = "integratedMode"
            type = "System.Web.Script.Services.ScriptHandlerFactory,
            System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35"/>

         <add name = "ScriptResource" preCondition = "integratedMode"
            verb = "GET,HEAD" path = "ScriptResource.axd"
            type = "System.Web.Handlers.ScriptResourceHandler,
            System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35"/>
      </handlers>

      <!--To browse web app root directory during debugging,
         set the value below to true. Set to false before deployment to
         avoid disclosing web app folder information.-->

      <directoryBrowse enabled = "true"/>
   </system.webServer>

   <runtime>
      <assemblyBinding appliesTo = "v2.0.05727" xmlns =" urn:schemas-microsoft-com:asm.v1">

         <dependentAssembly>
            <assemblyIdentity name = "System.Web.Extensions" publicKeyToken = "31bf3856ad364e35"/>
            <bindingRedirect oldVersion = "1.0.0.0-1.1.0.0" newVersion = "3.5.0.0"/>
         </dependentAssembly>

         <dependentAssembly>
            <assemblyIdentity name = "System.Web.Extensions.Design" publicKeyToken =" 31bf3856ad364e35"/>
            <bindingRedirect oldVersion = "1.0.0.0-1.1.0.0" newVersion = "3.5.0.0"/>
         </dependentAssembly>

      </assemblyBinding>
   </runtime>

   <system.serviceModel>
      <services>
         <service name = "Service" behaviorConfiguration = "ServiceBehavior">
         <!-- Service Endpoints -->
            <endpoint address = "" binding = "basicHttpBinding" contract = "IService">
               <!--
                  Upon deployment, the following identity element should be removed or replaced
                  to reflect the identity under which the deployed service runs. If removed,
                  WCF will infer an appropriate identity automatically.
               -->

               <identity>
                  <dns value="localhost"/>
               </identity>

            </endpoint>
            <endpoint address = "mex" binding = "mexHttpBinding" contract = "IMetadataExchange"/>

         </service>
      </services>

      <behaviors>
         <serviceBehaviors>
            <behavior name = "ServiceBehavior">
               <!-- To avoid disclosing metadata information, set the value below
                  to false before deployment -->

               <serviceMetadata httpGetEnabled = "true"/>

               <!-- To receive exception details in faults for debugging purposes,
                  set the value below to true.
                  Set to false before deployment to false avoid
                  disclosing exception information -->

               <serviceDebug includeExceptionDetailInFaults = "false"/>
            </behavior>
         </serviceBehaviors>
      </behaviors>

   </system.serviceModel>
</configuration>
Step 6 − You need to mention the service file name, along with the Address mentioned in the config file. The screenshot of IIS is given here.

Click Start → run → inetmgr which will open the following window.

Wcf Hosting Service IIS 6
Step 7 − Run the application which will produce the following screen.



## WCF - Self Hosting

Here, the WCF service is hosted in a console application. Given below is the process with suitable steps in a sequential manner that explains the entire process.

Step 1 − First, let's create the Service contract and its implementation. Create
a console application and name it as MyCalculatorService. This is a simple
service to return the addition of two numbers.

Wcf Hosting Services Self 1
Step 2 − Now, right click on the References in the Solution Explorer and click
Add References. The following window opens; add System.ServiceModel reference to
the project.

Wcf Hosting Services Self 2

Step 3 − Create an ISimpleCalculator interface, Add ServiceContract and
OperationContract attribute to the class and function as shown below. You will
know more about these contracts in the later session. These contracts will
expose the method to the outside world for using this service.

Step 4 − The code behind this file is as follows −
```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ServiceModel;

namespace MyCalculatorWCFService {
   [ServiceContract()]
   Public interface ISimpleCalculator {
      [OperationContract()]
      int Add(int num1, int num2);
   }
}
```

Step 5 − MyCalculatorService is the implementation class for IMyCalculatorService interface as shown below.

```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MyCalculatorWCFService {
   Class SimpleCalculator : ISimpleCalculator {
      Public int Add(int num1, int num2) {
         return num1 + num2;
      }
   }
}
```

Step 6 − Now, we are ready with the service. Let's go for implementing the
hosting process. Create a new console application and name it as
'MyCalculatorWCFServiceHost'.

Wcf Hosting Services Self 5
Step 7 − Add the reference of system.servicemodel and the project MyCalculatorWCFService.

Wcf Hosting Services 6
The code behind this is as follows −

==> very important here!!!

```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using MyCalculatorWCFService;
using System.ServiceModel;
using System.ServiceModel.Description;

namespace MyCalculatorWCFServiceHost {
   class Program {
      static void Main(string[] args) {
         //Create a URI to serve as the base address
         UrihttpUrl = newUri("http://localhost:8090/MyCalculatorWCFService/SimpleCalculator");

         //Create ServiceHost
         ServiceHost host = newServiceHost(typeof(MyCalculatorWCFService.ISimpleCalculator), httpUrl);

         //Add a service endpoint
         host.AddServiceEndpoint(typeof(MyCalculatorWCFService.ISimpleCal culator), newWSHttpBinding(), "");

         //Enable metadata exchange
         ServiceMetadataBehaviorsmb = newServiceMetadataBehavior();
         smb.HttpGetEnabled = true;
         host.Description.Behaviors.Add(smb);

         //Start the Service
         host.Open();
         Console.WriteLine("Service is host at " + DateTime.Now.ToString());
         Console.WriteLine("Host is running... Press  key to stop");
         Console.ReadLine();
      }
   }
}
```

# WCF - WAS Hosting


To understand the concept of WAS hosting, we need to comprehend how a system is
configured and how a service contract is created, enabling different binding to
the hosted service.

First of all, enable WCF for non-protocols. Before we start creating the
service, we need to configure the system to support WAS. Following are the steps
to configure WAS −

Click Start Menu → Control Panel → Programs and Features, and click "Turn
Windows Components On or Off" in the left pane.

Expand "Microsoft .Net Framework 3.0" and enable "Windows Communication
Foundation HTTP Activation" and "Windows Communication Foundation Non- HTTP
Activation".

Next, we need to add Binding to the default website. As an example, we will bind
the default website to the TCP protocol. Go to Start Menu → Programs →
Accessories. Right click on the "Command Prompt", and select "Run as
administrator" from the context menu.

Execute the following command −

C:\Windows\system32\inetsrv> appcmd.exe set site "Default Web Site" -+bindings.[protocol='net.tcp',bindingInformation='808:*']
This command adds the net.tcp site binding to the default website by modifying the applicationHost.config file located in the "C:\Windows\system32\inetsrv\config" directory. Similarly, we can add different protocols to the default website.

Create WAS Hosted Service
Step-1 − Open Visual Studio 2008 and click New → WebSite and select WCF Service
from the template and Location as HTTP, as shown below −

Wcf Hosting Services WAS 1
Step-2 − Create the Contract by creating an interface IMathService. Add the
ServiceContract attribute to the interface and the OperationContract attribute
to the method declaration.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.Text;

// NOTE: You can use the "Rename" command on the "Refactor" menu to
// change the interface name "IService" in both code and config file
// together.

[ServiceContract]

Public interface IMathService {
   [OperationContract]
   int Add(int num1, int num2);

   [OperationContract]
   int Subtract(int num1, int num2);
}
Step-3 − The implementation of the IMathService interface is shown below −

using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Serialization;
using System.ServiceModel;
using System.ServiceModel.Web;
using System.Text;

// NOTE: You can use the "Rename" command on the "Refactor" menu to
// change the class name "Service" in code, svc and config file
// together.

Public class MathService : IMathService {
   Public int Add(int num1, int num2) {
      return num1 + num2;
   }
   Public int Subtract(int num1, int num2) {
      return num1 - num2;
   }
}
Step-4 − The Service file is shown below.

Wcf Hosting Services WAS 2
<%@ServiceHostLanguage="C#"Debug="true"Service="MathService"CodeBehind="~/App_Code/MathService.cs"%>

Step-5 − In the web.Config file, create endpoint with 'netTcpBinding' binding
and the service metadata will be published using the Metadata Exchange point. So
create the Metadata Exchange end-point with the address as 'mex' and the binding
as 'mexTcpBinding'. Without publishing the service metadata, we cannot create
the proxy using the net.tcp address, for example −

important ===> netTcpBinding
svcutil.exe net.tcp://localhost/WASHostedService/MathService.svc).
<?xml version = "1.0" ?>
<configuration>
   <!--
      Note: As an alternative to hand editing this file you can use the
         web admin tool to configure settings for your application. Use
         the Website->Asp.Net Configuration option in Visual Studio.
         A full list of settings and comments can be found in
         machine.config.comments usually located in
         \Windows\Microsoft.Net\Framework\vx.x\Config
   -->
   <configSections>
      <sectionGroup name = "system.web.extensions"
         type = "System.Web.Configuration.SystemWebExtensionsSectionGroup,
         System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
         PublicKeyToken = 31BF3856AD364E35">

         <sectionGroup name = "scripting"
            type = "System.Web.Configuration.ScriptingSectionGroup,
            System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken =3 1BF3856AD364E35">

            <section name = "scriptResourceHandler"
               type = "System.Web.Configuration.ScriptingScriptResourceHandlerSection,
               System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
               PublicKeyToken = 31BF3856AD364E35"
               requirePermission = "false"
               allowDefinition = "MachineToApplication"/>

            <sectionGroup name = "webServices"
               type = "System.Web.Configuration.ScriptingWebServicesSectionGroup,
               System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
               PublicKeyToken = 31BF3856AD364E35">

               <section name = "jsonSerialization"
                  type = "System.Web.Configuration.ScriptingJsonSerializationSection,
                  System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
                  PublicKeyToken = 31BF3856AD364E35" requirePermission = "false"
                  allowDefinition = "Everywhere"/>

               <section name = "profileService"
                  type = "System.Web.Configuration.ScriptingProfileServiceSection,
                  System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
                  PublicKeyToken = 31BF3856AD364E35" requirePermission = "false"
                  allowDefinition = "MachineToApplication"/>

               <section name = "authenticationService"
                  type = "System.Web.Configuration.ScriptingAuthenticationServiceSection,
                  System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
                  PublicKeyToken = 31BF3856AD364E35" requirePermission = "false"
                  allowDefinition = "MachineToApplication"/>

               <section name = "roleService"
                  type = "System.Web.Configuration.ScriptingRoleServiceSection,
                  System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
                  PublicKeyToken = 31BF3856AD364E35" requirePermission = "false"
                  allowDefinition = "MachineToApplication"/>

            </sectionGroup>
         </sectionGroup>
      </sectionGroup>
   </configSections>

   <appSettings/>
   <connectionStrings/>

   <system.web>
      <!--
         Set compilation debug="true" to insert debugging
         symbols into the compiled page. Because this
         affects performance, set this value to true only
         during development.
      -->
      <compilation debug = "true">
         <assemblies>
            <add assembly = "System.Core, Version = 3.5.0.0,
               Culture = neutral, PublicKeyToken = B77A5C561934E089"/>

            <add assembly = "System.Web.Extensions, Version = 3.5.0.0,
               Culture = neutral, PublicKeyToken = 31BF3856AD364E35"/>

            <add assembly = "System.Data.DataSetExtensions,
               Version = 3.5.0.0, Culture = neutral,
               PublicKeyToken = B77A5C561934E089"/>

            <add assembly = "System.Web.Extensions, Version = 3.5.0.0,
               Culture = neutral, PublicKeyToken = 31BF3856AD364E35"/>

            <add assembly = "System.Xml.Linq,
               Version = 3.5.0.0, Culture = neutral,
               PublicKeyToken = B77A5C561934E089"/>
         </assemblies>
      </compilation>

      <!--
         The <authentication> section enables configuration
         of the security authentication mode used by
         ASP.NET to identify an incoming user.
      -->

      <authentication mode="Windows"/>

      <!--
         The <customErrors> section enables configuration
         of what to do if/when an unhandled error occurs
         during the execution of a request. Specifically,
         it enables developers to configure html error pages
         to be displayed in place of a error stack trace.
         <customErrors mode = "RemoteOnly" defaultRedirect = "GenericErrorPage.htm">
         <error statusCode = "403" redirect = "NoAccess.htm" />
         <error statusCode = "404" redirect = "FileNotFound.htm" />
         </customErrors>
      -->

      <pages>
         <controls>
            <add tagPrefix = "asp" namespace = "System.Web.UI"
               assembly = "System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
               PublicKeyToken = 31BF3856AD364E35"/>

            <add tagPrefix = "asp" namespace = "System.Web.UI.WebControls"
               assembly = "System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
               PublicKeyToken = 31BF3856AD364E35"/>
         </controls>
      </pages>

      <httpHandlers>
         <remove verb = "*" path = "*.asmx"/>

         <add verb =" *" path =" *.asmx" validate="false"
            type = "System.Web.Script.Services.ScriptHandlerFactory,
            System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35"/>

         <add verb = "*" path = "*_AppService.axd" validate = "false"
            type = "System.Web.Script.Services.ScriptHandlerFactory,System.Web.Extensions,
            Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35"/>

         <add verb = "GET,HEAD" path = "ScriptResource.axd"
            type = "System.Web.Handlers.ScriptResourceHandler, System.Web.Extensions,
            Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35" validate = "false"/>
      </httpHandlers>

      <httpModules>
         <add name = "ScriptModule"
            type = "System.Web.Handlers.ScriptModule,
            System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35"/>
      </httpModules>

   </system.web>

   <system.codedom>
      <compilers>

         <compiler language = "c#;cs;csharp" extension = ".cs" warningLevel = "4"
            type = "Microsoft.CSharp.CSharpCodeProvider, System,
            Version = 2.0.0.0, Culture = neutral,
            PublicKeyToken = b77a5c561934e089">

            <providerOption name = "CompilerVersion" value = "v3.5"/>
            <providerOption name = "WarnAsError" value = "false"/>
         </compiler>

         <compiler language = "vb;vbs;visualbasic;vbscript"
            extension = ".vb" warningLevel = "4"
            type = "Microsoft.VisualBasic.VBCodeProvider, System,
            Version = 2.0.0.0, Culture = neutral,
            PublicKeyToken = b77a5c561934e089">

            <providerOption name = "CompilerVersion" value = "v3.5"/>
            <providerOption name = "OptionInfer" value = "true"/>
            <providerOption name = "WarnAsError" value = "false"/>
         </compiler>

      </compilers>
   </system.codedom>

   <!--
      The system.webServer section is required for running ASP.NET AJAX under
      Internet Information Services 7.0. It is not necessary for previous version of IIS.
   -->

   <system.webServer>
      <validation validateIntegratedModeConfiguration = "false"/>

      <modules>
         <remove name = "ScriptModule"/>
         <add name = "ScriptModule" preCondition = "managedHandler"
            type = "System.Web.Handlers.ScriptModule, System.Web.Extensions,
            Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35"/>
      </modules>

      <handlers>
         <remove name = "WebServiceHandlerFactory-Integrated"/>
         <remove name = "ScriptHandlerFactory"/>
         <remove name = "ScriptHandlerFactoryAppServices"/>
         <remove name = "ScriptResource"/>

         <add name = "ScriptHandlerFactory"
            verb = "*" path = "*.asmx" preCondition = "integratedMode"
            type = "System.Web.Script.Services.ScriptHandlerFactory,
            System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35"/>

         <add name = "ScriptHandlerFactoryAppServices"
            verb = "*" path = "*_AppService.axd" preCondition = "integratedMode"
            type = "System.Web.Script.Services.ScriptHandlerFactory,
            System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35"/>

         <add name = "ScriptResource" preCondition = "integratedMode"
            verb = "GET,HEAD" path = "ScriptResource.axd"
            type = "System.Web.Handlers.ScriptResourceHandler,
            System.Web.Extensions, Version = 3.5.0.0, Culture = neutral,
            PublicKeyToken = 31BF3856AD364E35"/>

      </handlers>
      <!--
         To browse web app root directory during debugging, set the value below to true.
         Set to false before deployment to avoid disclosing web app folder information.
      -->
      <directoryBrowse enabled="true"/>
   </system.webServer>

   <runtime>
      <assemblyBinding appliesTo = "v2.0.05727" xmlns = "urn:schemas-microsoft-com:asm.v1">

         <dependentAssembly>
            <assemblyIdentity name = "System.Web.Extensions" publicKeyToken = "31bf3856ad364e35"/>
            <bindingRedirect oldVersion = "1.0.0.0-1.1.0.0" newVersion = "3.5.0.0"/>
         </dependentAssembly>

         <dependentAssembly>
            <assemblyIdentity name = "System.Web.Extensions.Design" publicKeyToken = "31bf3856ad364e35"/>
            <bindingRedirect oldVersion = "1.0.0.0-1.1.0.0" newVersion = "3.5.0.0"/>
         </dependentAssembly>

      </assemblyBinding>
   </runtime>

   <system.serviceModel>
      <services>
         <service behaviorConfiguration = "ServiceBehavior" name = "Service">
            <endpoint address = "" binding = "basicHttpBinding" contract = "IMathService">

            <identity>
               <dns value = "localhost" />
            </identity>

            </endpoint>
            <endpoint address = "mex" binding = "mexHttpBinding" contract = "IMetadataExchange"/>
         </service>
      </services>

      <behaviors>
         <serviceBehaviors>
            <behavior name = "ServiceBehavior">
               <!--
                  To avoid disclosing metadata information, set the value below
                  to false before deployment.
               -->
               <serviceMetadata httpGetEnabled="true"/>

               <!--
                  To receive exception details in faults for debugging purposes,
                  set the value below to true. Set to false before deployment to avoid
                  disclosing exception information
               -->
               <serviceDebug includeExceptionDetailInFaults="false"/>
            </behavior>
         </serviceBehaviors>
      </behaviors>

   </system.serviceModel>
</configuration>
Enable Different Bindings to the Hosted Service
Go to Start menu → Programs → Accessories. Right click on the "Command Prompt", and select "Run as administrator" from the context menu.

Execute the following command -

C:\Windows\system32\inetsrv>appcmd set app "Default Web Site/WASHostedService" /enabledProtocols:http,net.tcp
It will produce the following output −


# WCF - Windows Service Hosting

The operation of Windows service hosting is a simple one. Given below are the steps with requisite coding and screenshots that explain the process in an easy way.

Step 1 − Now let’s create a WCF service. Open Visual Studio 2008 and click New → Project and select Class Library from the template.

Wcf Hosting Services Windows Service 1
Step 2 − Add reference System.ServiceModel to the project. This is the core assembly used for creating the WCF service.

Step 3 − Next, we can create the ISimpleCalulator interface. Add the Service and Operation Contract attribute as shown below −

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ServiceModel;

namespace WindowsServiceHostedService{
   [ServiceContract]
   public interfaceISimpleCalculator {
      [OperationContract]
      int Add(int num1, int num2);

      [OperationContract]
      int Subtract(int num1, int num2);

      [OperationContract]
      int Multiply(int num1, int num2);

      [OperationContract]
      double Divide(int num1, int num2);
   }
}
Step 4 − Implement the ISimpleCalculator interface as shown below −

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WindowsServiceHostedService {
   Class SimpleCalulator : ISimpleCalculator {
      Public int Add(int num1, int num2) {
         return num1 + num2;
      }
      Public int Subtract(int num1, int num2) {
         return num1 - num2;
      }
      Public int Multiply(int num1, int num2) {
         return num1 * num2;
      }
      Public double Divide(int num1, int num2) {
         if (num2 != 0)
            return num1 / num2;
         else
            return 0;
      }
   }
}
Step 5 − Build the Project and get the dll. Now, we are ready with the WCF
service. We are going to see how to host the WCF service in Windows service.

Note − In this project, it is mentioned that we are creating both Contract and
Service (implementation) in the same project. However it is always a good
practice if you have both in different projects.

Step 6 − Open Visual Studio 2008 and Click New → Project and select Windows
Service.

Wcf Hosting Services Windows Service 1 Step 7 − Add
'WindowsServiceHostedService.dll' as reference to the project. This assembly is
going to act as service.

Wcf Hosting Services Windows Service 4 Step 8 − The OnStart method of the
service can be used to write the hosting code for WCF. We have to make sure that
we are using only one service host object. OnStop method is used to close the
Service Host. The following code shows how to host the WCF service in Windows
service.

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.ServiceProcess;
using System.Text;
using System.ServiceModel;
using System.ServiceModel.Description;

namespace WCFHostedWindowsService {
   Partial class WCFHostedWindowsService : ServiceBase {
      ServiceHost m_Host;

      Public WCFHostedWindowsService() {
         InitializeComponent();
      }
      Private void InitializeComponent() {
         thrownewNotImplementedException();
      }
      protected override void OnStart(string[] args) {
         if (m_Host != null) {
            m_Host.Close();
         }

         //Create a URI to serve as the base address
         UrihttpUrl httpUrl = newUri("http://localhost:8090/WindowsServiceHostedService/SimpleCalculator");

         //Create ServiceHost
         m_Host = new ServiceHost typeof(WindowsServiceHostedService.SimpleCalulator), httpUrl);

         //Add a service endpoint
         m_Host.AddServiceEndpoint (typeof(WindowsServiceHostedService.ISimpleCalculator), newWSHttpBinding(), "");

         //Enable metadata exchange
         ServiceMetadataBehaviorsmb = newServiceMetadataBehavior();
         smb.HttpGetEnabled = true;
         m_Host.Description.Behaviors.Add(smb);

         //Start the Service
         m_Host.Open();
      }
      protected override voidOnStop() {
         if (m_Host != null) {
            m_Host.Close();
            m_Host = null;
         }
      }
      staticvoid Main() {
         ServiceBase[] ServicesToRun;
         ServicesToRun = newServiceBase[] {
            newWCFHostedWindowsService();
         }
         ServiceBase.Run(ServicesToRun);
      }
   }
}
Step 9 − In order to install the service, we need to have the Installer class for the Windows service. So add a new Installer class to the project, which is inherited from the Installer class. Given below is the code that shows the Service name, StartUp type, etc. of the service.

using System;
using System.Collections.Generic;
using System.Text;
using System.ServiceProcess;
using System.Configuration.Install;
using System.ComponentModel;
using System.Configuration;

namespace WCFHostedWindowsService {
   [RunInstaller(true)]
   Public class WinServiceInstaller : Installer {
      Private ServiceProcessInstaller process;
      Private ServiceInstaller service;

      Public WinServiceInstaller() {
         process = newServiceProcessInstaller();
         process.Account = ServiceAccount.NetworkService;
         service = newServiceInstaller();

         service.ServiceName = "WCFHostedWindowsService";
         service.DisplayName = "WCFHostedWindowsService";
         service.Description = "WCF Service Hosted";
         service.StartType = ServiceStartMode.Automatic;

         Installers.Add(process);
         Installers.Add(service);
      }
   }
}
Step 10 − Build the project to get the executable file WCFHostedWindowsService.exe. Next, we need to install the service using the Visual Studio Command Prompt. So open the command prompt by clicking Start→All Programs→Microsoft Visual Studio 2008→Visual Studio Tools→ Visual Studio Command Prompt. Using the install util utility application, you can install the service as shown below.

# WCF - Consuming WCF Service
WCF services allow other applications to access or consume them. A WCF service
can be consumed by many ways depending on the hosting type. Here, we are
explaining the step-by-step method to consume a WCF service for each of the
following popular hosting options −

Consuming WCF Service hosted in IIS 5/6
Consuming WCF Service that is self-hosted
Consuming WCF Service hosted in Windows Activation Service
Consuming WCF Service hosted in Windows Service
Consuming WCF Service Hosted in IIS 5/6

The process of consumption of a WCF service hosted in IIS 5/6 is discussed below
in detail. In addition, the discussion includes how to create proxy and console
applications.

Step 1 − Once a service is hosted in IIS, we have to consume it in client
applications. Before creating the client application, we need to create a proxy
for the service. This proxy is used by the client application to interact with
the service. To create a proxy, run Visual Studio 2008 command prompt. Using
service utility, we can create the proxy class and its configuration
information.

svcutilhttp://localhost/IISHostedService/Service.svc

Wcf Consuming Services IIS 1
After executing this command, we will get two files generated in the default location.

MyService.cs − Proxy class for the WCF service

output.config − Configuration information about the service

Step 2 − Now, we will start creating the Console application using Visual Studio 2008 (Client application).

Wcf Consuming Services IIS 2
Step 3 − Add the reference 'System.ServiceModel'; this is the core dll for WCF.

Step 4 − Create a Proxy class.
```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MyServiceClient {
   Class Program {
      Static void Main(string[] args) {
         // Creating Proxy for the MyService
         ServiceClient Client = newServiceClient();
         Console.WriteLine("Client calling the service...");
         Console.WriteLine("Hello Ram");
         Console.Read();
      }
   }
}
```

The output appears as follows −

Wcf Consuming Services IIS 4
Consuming Self-hosted WCF Service
Here, the entire process of consuming a self-hosted WCF Service is explained step-by-step along with ample coding and screenshots wherever necessary.

Step 1 − Service is hosted, now we need to implement the proxy class for the client. There are different ways of creating the proxy.

Using SvcUtil.exe, we can create the proxy class and its configuration file with end-points.

Adding Service reference to the client application.

Implementing ClientBase<T> class

Of these three methods, Implementing ClientBase<T> is the best practice. If you are using the other two methods, we need to create a proxy class every time we make any changes in the Service implementation. But this is not the case for ClientBase<T>. It will create the proxy only at runtime and so it will take care of everything.

For this purpose, create one proxy class, which includes the references of System.ServiceModel and MyCalculatorService.
```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ServiceModel;
using MyCalculatorService;

namespace MyCalculatorServiceProxy {
   // WCF create proxy for ISimpleCalculator using ClientBase
   Public class MyCalculatorServiceProxy :
   ClientBase<ISimpleCalculator>,

   ISimpleCalculator {
      Public int Add(int num1, int num2) {
         //Call base to do funtion
         returnbase.Channel.Add(num1, num2);
      }
   }
}
```

Now, create one console application, which includes the references of System.ServiceModel and MyCalculatorServiceProxy.

```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.ServiceModel;
using MyCalculatorServiceProxy;

namespace MyCalculatorServiceClient {
   classProgram {
      Static void Main(string[] args) {
         MyCalculatorServiceProxy.MyCalculatorServiceProxy proxy = newMyCalculatorServiceProxy.MyCalculatorServiceProxy();

         Console.WriteLine("Client is running at " + DateTime.Now.ToString());
         Console.WriteLine("Sum of two numbers. 5 + 5 =" + proxy.Add(5,5));
         Console.ReadLine();
      }
   }
}
```

Step 2 − End-point (same as service) information should be added to the configuration file of the client application.
```
<?xmlversion = "1.0"encoding = "utf-8" ?>
<configuration>
   <system.serviceModel>
      <client>
         <endpoint address
            ="http://localhost:8090/MyCalculatorServiceProxy/ISimpleCalculator"
            binding = "wsHttpBinding" contract "MyCalculatorServiceProxy.ISimpleCalculator">
            </endpoint>
      </client>
   </system.serviceModel>
</configuration>
```

Step 3 − Before running the client application, you need to run the service. Shown below is the output of the client application.

Wcf Consuming Services Self 3
Consuming WCF Service Hosted in WAS
Consuming a WCF service that is hosted in WAS is a simple process involving only a few steps. The steps are as follows −

```
Add the proxy class and the configuration file to the client application.
Create the object for the MathServiceClient and call the method.
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespaceWASHostedClient {
   classProgram {
      staticvoid Main(string[] args) {
         MathServiceClient client = newMathServiceClient();
         Console.WriteLine("Sum of two number 5,6");
         Console.WriteLine(client.Add(5, 6));
         Console.ReadLine();
      }
   }
}
```

The output appears as shown below.

Wcf Consuming Services WAS 2
Consuming WCF Service Hosted in Windows Service

The step-by-step process of how to consume a WCF service hosted in Windows
Service is expressed below in detail with coding and instructions.

Once it is hosted successfully, we can create a proxy class for the service and
start using in the client application. Here, it is shown with the IIS hosting
type consuming.

Wcf Consuming Services Windows Service 1
Add the reference of ServiceModel.

```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespaceWindowServiceClient {
   classProgram {
      staticvoid Main(string[] args) {
         //Creating Proxy for the MyService
         MyServiceClient client = newMyServiceClient();
         Console.WriteLine("Client calling the service...");
         Console.WriteLine("Sum of two numbers 5,6");
         Console.WriteLine(client.Add(5, 6));

         Console.WriteLine("Subtraction of two numbers 6,5");
         Console.WriteLine(client.Sub(6, 5));

         Console.WriteLine("Multiplication of two numbers 6,5");
         Console.WriteLine(client.Mul(6, 5));

         Console.WriteLine("Division of two numbers 6,3");
         Console.WriteLine(client.Div(6, 3));
         Console.Read();
      }
   }
}

```

The output appears as follows −
# WCF - Service Binding

WCF service binding is a set of several elements in which each element defines
the way the service is communicating with the client. A transport element and a
message encoding element are the two most vital components of each binding. In
this chapter, we will discuss various WCF service bindings that are commonly
used.

Basic Binding

Basic binding is offered by the BasicHttpBinding class. It uses the HTTP
protocol to transport and represent a WCF service as an ASP.NET web service
(ASMX web service), so that old clients who use ASMX web services can consume
the new services conveniently.

Basic binding is set as default binding in a WCF web service enabled by
Silverlight and is a standard binding for communications in web service style.
It does not support reliable messaging.

Given below is a code snippet depicting the default settings for basic binding.
```
<basicHttpBinding>
   <binding name = "basicHttpBindingDefaults" allowCookies = "false"
      bypassProxyOnLocal = "false" hostNameComparisonMode = "StrongWildcard"
      maxBufferPoolSize = "524288" maxBufferSize = "65536"
      maxReceivedMessageSize = "65536" messageEncoding = "Text" proxyAddress = ""
      textEncoding = "utf-8" transferMode = "Buffer" useDefaultWebProxy = "true"
      closeTimeout = "00:01:00" openTimeout = "00:01:00" receiveTimeout = "00:10:00"
      sendTimeout = "00:01:00">

      <readerQuotas maxArrayLength = "16384" maxBytesPerRead = "4096"
         maxDepth = "32"
         maxNameTableCharCount = "16384" maxStringContentLength = "8192"/>

      <security mode = "None">
         <transport clientCredentialType = "None" proxyCredentialType = "None" realm = ""/>
         <message algorithmSuite = "Basic256" clientCredentialType = "UserName" />
      </security>
   </binding>

</basicHttpBinding>
```

The above default settings have their obvious limitations, as the message size
is limited and there is no security mode. However, customization of basic
binding solves this problem like the one below.

```
<basicHttpBinding>
   <binding name = "basicHttpSecure" maxBufferSize = "100000" maxReceivedMessageSize = "100000">

      <readerQuotas maxArrayLength = "100000" maxStringContentLength = "100000"/>
      <security mode = "TransportWithMessageCredential" />

   </binding>
</basicHttpBinding>
```

Web Service Binding

Web Service (WS) binding is provided by the WSHttpBinding class. It is quite
similar to basic binding and uses the same protocols for transport, but offers
several WS–* specifications such as WS–Reliable Messaging, WS–Transactions,
WS–Security, and many more. In a nutshell, WSHttpBinding equals to the sum of
basicHttpBinding and WS–* specifications. Given below is a code snippet
depicting the default settings for WS Binding −

```
<wsHttpBinding>
   <binding name = "wsHttpBindingDefaults" allowCookies = "false"
      bypassProxyOnLocal = "false" closeTimeout = "00:01:00"
      hostNameComparisonMode = "StrongWildcard"
      maxBufferPoolSize = "524288" maxReceivedMessageSize = "65536"
      messageEncoding = "Text" openTimeout = "00:01:00"
      receiveTimeout = "00:10:00" proxyAddress = "" sendTimeout = "00:01:00"
      textEncoding = "utf-8" transactionFlow = "false"
      useDefaultWebProxy = "true" >

      <readerQuotas maxArrayLength = "16384" maxBytesPerRead = ."4096"
         maxDepth = "32" maxNameTableCharCount = "16384"
         maxStringContentLength = "8192"/>

      <reliableSession enabled = "false" ordered = "true"
         inactivityTimeout = "oo:10:00" />

      <security mode = "Message">
         <message algorithmSuite = "Basic256" clientCredentialType = "Windows"
            esatalishSecurityContext = "true"
            negotiateServiceCredential = "true" />

         <transport clientCredentialType = "Windows"
            proxyCredentialType = "None" realm = ""/>
      </security>

   </binding>
</wsHttpBinding>
```

IPC Binding
IPC binding makes use of named pipe and is offered by the netNamedPipeBinding
class. This is the fastest binding and the most secure one amidst all the
available bindings. Although message-level security is not supported here,
messages are secure by default because of a robust transport security. Given
below is the code snippet depicting the default settings for IPC binding −
```
<netNamedPipeBinding>

   <binding name = "netPipeDefaults" closeTimeout = "00:01:00"
      hostNameComparisonMode = "StrongWildcard" maxBufferPoolSize = "524288"
      maxBufferSize = "65536" maxConnections = "10"
      maxReceivedMessageSize = "65536" openTimeout = "00:01:00"
      receiveTimeout = "00:10:00" sendTimeout = "00:01:00" transactionFlow = "false"
      transactionProtocol = "OleTransactions" transferMode = "Buffered">

      <readerQuotas maxArrayLength = "16384" maxBytesPerRead = "4096"
         maxDepth = "32" maxNameTableCharCount = "16384"
         maxStringContentLength = "8192"/>

      <security mode = "Transport">
      </security>

   </binding>
</netNamedPipeBinding>
```

Other Types of Service Bindings

TCP Binding − Provided by the NetTCPBinding class, this binding makes use of the
TCP protocol for communication within the same network and does the message
encoding in binary format. This binding is considered as the most reliable in
contrast to others.

WS Dual Binding − This type of binding is more like WSHttpBinding with the only
exception that it facilitates bidirectional communication, i.e., messages can be
sent and received by both clients and services. It is offered by the
WSDualHttpBinding class.

Web binding − Web binding is designed to represent WCF services in the form of
HTTP requests by the use of HTTP-GET, HTTP-POST, etc. It is offered by the
WebHttpBinding class and is used commonly with social networks.

MSMQ Binding − It is offered by the NetMsmqBinding class and is used to provide
solutions in case the service processes a message at a distinct time than that
sent by the client. MSMQ binding makes use of MSMQ for transportation and
provides support to detached message queued. MSMQ is an implementation for
message queuing offered by Microsoft.

Federated WS Binding − It is a specific form of WS binding and offers support
for federated security. It is offered by the WSFederationHttpBinding class.

Peer Network Binding − Offered by the NetPeerTCPBinding class, it is mainly used
in file sharing systems. It uses TCP protocol but makes use of peer networking
as transport. In this networking, each machine (node) acts as a client and a
server to the other nodes. Peer network binding is used in file sharing systems
like torrent.

MSMQ Integration Binding − Offered by the MsmqIntegrationBinding class, it helps
communicate with existing systems that communicate via MSMQ (Microsoft Message
Queuing).

Apart from these, it is also possible to create custom bindings. However, since
it is possible to tweak the configuration properties of each WCF binding, the
need for creating custom bindings arises rarely.


## WCF - Instance Management

The set of techniques employed by WCF for binding a set of messages (client requests) to service instances is known as Instance Management. WCF supports three types of instance activation and they are discussed in this chapter.

Per-Call Service
Per-call service is the default instance activation mode of WCF. When a WCF service is configured for a per-call service, a CLR object is created for the timespan a client call or request is in progress. CLR stands for Common Language Runtime and it includes service instances in WCF.

In per-call service, every client request achieves a new dedicated service instance and its memory consumption is less as compared to other types of instance activation.

The InstanceContextMode property is required to be set to InstanceContextMode.PerCall, in order to indicate a WCF service to act as a per-call service. The InstanceContextMode property belongs to the ServiceBehavior attribute. Hence, a per-call service can be configured as follows −
```
[ServiceContract]
interface IMyContract
{...}
[ServiceBehavior (InstanceContextMode = InstanceContextMode.PerCall)]
class MyService : IMyContract
{...}
```

A service is here expressed as IMyContract. The following figure shows the process of per-call service instance activation.

Wcf Instance Management Per Call Service
Implementing a Per-Call Service
```
[DataContract]
class Param {....}

[ServiceContract]
interface IMyContract {
   [OperationContract]
   void MyMethod(Param objectIdentifier);
}
class MyPerCallService : IMyContract, IDisposable {
   public void MyMethod(Param objectIdentifier) {
      GetState(objectIdentifier);
      DoWork();
      SaveState(objectIdentifier);
   }

   void GetState(Param objectIdentifier) {....}
   void DoWork() {....}
   void SaveState(Param objectIdentifier) {....}
   public void Dispose() {....}
}
```

Here, Param is the pseudo type parameter invented for the above example.

Per-Session Service

In this activation mode of WCF, a private or we can say a confidential session is maintained between the two entities, i.e., the client and a particular service instance. Also known as the private session service, the per-session service offers a new service instance which remains dedicated to each client request and autonomous of all the other instances pertaining to that session-aware service.

To initiate a per-session service, the InstanceContextMode property is required to set to PerSession. Here, the service instance stays in memory all through the session duration.

The activation mode suffers from scalability as the configured service is unable to support any additional outstanding clients other than a few (or maybe up to some hundred) because of the cost involved in each of this dedicated service instance.

A per-session service can be configured as −
```
[ServiceBehavior (InstanceContextMode = InstanceContextMode.PerSession)]
class MyService : IMyContract
{...}
```

The process of per-session service can be described as shown in the following figure −

Wcf Instance Management Per Session Service
The following code shows a contract and service configured for the usage of a private session. The output indicates that the client indeed got a dedicated service instance.

Service code
```
[ServiceContract(Session = true)]
interface IMyContract {
   [OperationContract]
   void MyMethod();
}

[ServiceBehavior(InstanceContextMode = InstanceContextMode.PerSession)]
class MyService : IMyContract, IDisposable {
   int m_Counter = 0; MyService() {Console.WriteLine("MyService.MyService()"); }

   public void MyMethod() {
      m_Counter++;
      Console.WriteLine("Counter = " + m_Counter);
   }
   public void Dispose() {
      Console.WriteLine("MyService.Dispose()");
   }
}
```

Client Code

```
MyContractProxy proxy = new MyContractProxy(); proxy.MyMethod(); proxy.MyMethod();
proxy.Close();
```

Output
```

MyService.MyService() Counter = 1 Counter = 2 MyService.Dispose()
```

Singleton Service
In this activation mode of WCF, all client requests independent to each other get connected to the same well-known single instance, irrespective of their connection to the service endpoints. The singleton service gets disposed only when the host closes down.

This service is created just for once when the host is created. In case, the host is not provided with any singleton instance, the service returns as NULL. The activation mode is at its best when the work amount in each method call is little and no pending operations are there in the background.

The InstanceContextMode property is required to set to InstanceContextMode.Single to initiate this Singleton service.

Hence, a Singleton service can be configured as −
```
[ServiceBehavior(InstanceContextMode = InstanceContextMode.Single)]
class MySingleton : ...
{...}
The process of Singleton service is shown in the following figure −

Wcf Instance Management Singleton Service
The following code is used for initializing and hosting a singleton instance.

Service code
[ServiceContract]
interface IMyContract {
   [OperationContract]
   void MyMethod( );
}
[ServiceBehavior(InstanceContextMode = InstanceContextMode.Single)]
class MySingleton : IMyContract {
   int m_Counter = 0;

   public int Counter {
      get {
         return m_Counter;
      }
      set {
         m_Counter = value;
      }
   }
   public void MyMethod( ) {
      m_Counter++;
      Trace.WriteLine("Counter = " + Counter);
   }
}
Host code
MySingleton singleton = new MySingleton( );
singleton.Counter = 42;
ServiceHost host = new ServiceHost(singleton);
host.Open( );

//Do some blocking calls then
host.Close( );
Client code
MyContractClient proxy = new MyContractClient( );
proxy.MyMethod( );
proxy.Close( );
Output
Counter = 43
```


# [C#.NET] 如果可以 請盡量使用LINQ查詢語法而不是使用迴圈

我相信在for/foreach迴圈絕對是大多數人還在使用的控制結構，假設我有以下的Member類別，_memberList 則是Member類別集合

 

public struct Member
{
    public string Name { get; set; }
    public int Age { get; set; }
    public List<string> Phones { get; set; }
}

List<Member> _memberList = new List<Member>();
private void Form1_Load(object sender, EventArgs e)
{
    this._memberList = new List<Member>() 
    { 
        new Member(){Name="Yao",Age=18,Phones=new List<string>(){"0911123456789","0912123456789"}},
        new Member(){Name="gy",Age=20,Phones=new List<string>(){"0913123456789","0914123456789"}},
        new Member(){Name="LaLa",Age=19,Phones=new List<string>(){"0915123456789","0916123456789"}},
        new Member(){Name="9GY",Age=12,Phones=new List<string>(){"0917123456789","0918123456789"}}
    };
}

在LINQ還沒有出現以前foreach這是我很常用的查詢方式，比如說我想要查詢集合內的某個屬性，使用foreach迴圈來處理，用來找尋是否有Age大於10的項目

foreach的寫法：

 

List<Member> query = new List<Member>();
foreach (Member item in this._memberList)
{
    if (item.Age > 10)
    {
        query.Add(item);
    }
}
在LINQ裡這麼做：

var find = from data in this._memberList
           where data.Age > 10
           select data;

foreach (var item in find)
{
     //TODO:
}
或是找尋是否有某個關鍵字存在

foreach的寫法：

foreach (var item in this._memberList)
{
    if (item.Name.ToUpper() == "YAO")
    {
        query.Add(item);
    }
}
在LINQ裡這麼做：

var find = from data in this._memberList
           where data.Name.ToUpper() == "YAO"
           select data;
foreach (var item in find)
{
      //TODO:
}
在LINQ裡我們的程式語法由"命令式"變成了"聲明式"，我們只管下達命令不用管它的實作方式，在閱讀上LINQ優於傳統的for/foreach迴圈

from data in this._memberList    →指定資料來源
where data.Age > 10              →條件
select data;                     →查詢結果

 

除了閱讀性，還有修改上的彈性，由其是當需求一變動的時候，LINQ則能很快的變動，比如說PM騎著機車要變更需求，找出 "大於10歲" "名字很GY的人" "並且由小到大排序"

foreach的寫法：

List<Member> query = new List<Member>();
foreach (Member item in this._memberList)
{
    if (item.Age > 10 && item.Name.ToUpper().IndexOf("GY") >= 0)
    {
        query.Add(item);
    }
}
query.Sort(CompareMember);

int CompareMember(Member a, Member b)
{
    return a.Age – b.Age; 
} 
在LINQ裡這麼做：

 

var find = from data in this._memberList
           where data.Age > 10 && data.Name.ToUpper().IndexOf("GY") >= 0
           orderby data.Age
           select data;


有沒有發現差異性越來越明顯了，好的，若需求再變更時程式碼會有什麼變化呢!?這時開著卡車來的PM，要求找出特定的電話號碼 0917123456789

foreach的寫法：

巢狀迴圈的寫法越讀起來越來越吃力了，好吧!!或許有人會說我把巢狀迴圈拆開不就好了，就算拆開也沒有辦法像LINQ那麼乾淨，對吧!?

List<Member> query = new List<Member>();
foreach (Member item in this._memberList)
{
    if (item.Age > 10 && item.Name.ToUpper().IndexOf("GY") >= 0)
    {
        foreach (string phone in item.Phones)
        {
            if (phone == "0917123456789")
            {
                query.Add(item);
            }
        }
    }
}
query.Sort(CompareMember);
LINQ裡這麼做：

 

var find = from data in this._memberList
           where data.Age > 10 
           where data.Name.ToUpper().IndexOf("GY") >= 0
           orderby data.Age
           from phone in data.Phones
           where phone == "0917123456789"
           select data;


 

後記：

雖然LINQ效能並沒有想像中的好，不過它的查詢功能的可讀性以及修改彈性都很高，在上面的例子我會捨棄效能來迎合這樣的閱讀性及修改彈性，所以如果可以我都會盡可能的使用LINQ。


# Lambda expression 

2010-01-19
[C#] Lambda 運算式
18905 0  檢舉文章
[C#] Lambda 運算式

Introduction

詳細完整的說明請參考

 http://msdn.microsoft.com/zh-tw/library/bb397687.aspx
 

這邊節錄片段：

「Lambda 運算式」(Lambda Expression) 是一種匿名函式，它可以包含運算式和陳述式
(Statement)，而且可以用來建立委派 (Delegate) 或運算式樹狀架構型別。

所有的 Lambda 運算式都會使用 Lambda 運算子 =>，意思為「移至」。Lambda 運算子的左
邊會指定輸入參數 (如果存在)，右邊則包含運算式或陳述式區塊。Lambda 運算式 x =>
x * x 的意思是「x 移至 x 乘以 x」。這個運算式可以指派成委派型別 (Delegate Type)，
如下所示：

delegate int del(int i);
del myDelegate = x => x * x;
int j = myDelegate(5); //j = 25
 
這邊做個練習，溫故知新一下。
 
Example
``` 
namespace TestLambda {
    class Program {

        //宣告委派
        delegate string MyDelegate(string title, string name);
        delegate T MyDelegate2<T>(T a, T b);

        static void Main(string[] args) {
            
            MyDelegate Del = (title, name) => string.Format("{0} {1}", title, name);
            Console.WriteLine(Del("世界杯", "小小羅"));
            Console.WriteLine("=====================================================");

            MyDelegate Del2 = (title, name) => {
                string s = string.Format("{0} {1}", title, name);
                return s;
            };
            Console.WriteLine(Del2("c#", "Jave"));
            Console.WriteLine("=====================================================");

            MyDelegate2<string> Del3 = (A, B) => string.Format("{0} {1}", A, B);
            Console.WriteLine(Del3("A", "B"));
            Console.WriteLine("=====================================================");

            MyDelegate2<int> Del4 = (C, D) => {
                
                int iResult = C + D;
                return iResult;
            };
            Console.WriteLine(Del4(3, 4).ToString());

            Console.ReadKey();
        }
    }
}
 
```

