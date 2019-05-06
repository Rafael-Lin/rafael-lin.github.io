
WPF快速入门系列(2)——深入解析依赖属性
一、引言
　　感觉最近都颓废了，好久没有学习写博文了，出于负罪感，今天强烈逼迫自己开始更新
WPF系列。尽管最近看到一篇WPF技术是否老矣的文章，但是还是不能阻止我系统学习WPF。
今天继续分享WPF中一个最重要的知识点——依赖属性。

二、依赖属性的全面解析
　　听到依赖属性，自然联想到C#中属性的概念。C#中属性是抽象模型的核心部分，而依赖
属性是专门基于WPF创建的。在WPF库实现中，依赖属性使用普通的C#属性进行了包装，使得
我们可以通过和以前一样的方式来使用依赖属性，但我们必须明确，在WPF中我们大多数都
在使用依赖属性，而不是使用属性。依赖属性重要性在于，在WPF核心特性，如动画、数据
绑定以及样式中都需要使用到依赖属性。既然WPF引入了依赖属性，也自然有其引入的道理。
WPF中的依赖属性主要有以下三个优点：

依赖属性加入了属性变化通知、限制、验证等功能。这样可以使我们更方便地实现应用，同
时大大减少了代码量。许多之前需要写很多代码才能实现的功能，在WPF中可以轻松实现。

节约内存：在WinForm中，每个UI控件的属性都赋予了初始值，这样每个相同的控件在内存
中都会保存一份初始值。而WPF依赖属性很好地解决了这个问题，它内部实现使用哈希表存
储机制，对多个相同控件的相同属性的值都只保存一份。关于依赖属性如何节约内存的更多
内容参考：WPF的依赖属性是怎么节约内存的

支持多种提供对象：可以通过多种方式来设置依赖属性的值。可以配合表达式、样式和绑定
来对依赖属性设置值。

2.1 依赖属性的定义
　　上面介绍了依赖属性所带来的好处，这时候，问题又来了，怎样自己定义一个依赖属性呢？C#属性的定义大家再熟悉不过了。下面通过把C#属性进行改写成依赖属性的方式来介绍依赖属性的定义。下面是一个属性的定义：
 public class Person
    {
         public string Name { get; set; }
     }

　　在把上面属性改写为依赖属性之前，下面总结下定义依赖属性的步骤：
让依赖属性的所在类型继承自DependencyObject类。
使用public static 声明一个DependencyProperty的变量，该变量就是真正的依赖属性。
在类型的静态构造函数中通过Register方法完成依赖属性的元数据注册。
提供一个依赖属性的包装属性，通过这个属性来完成对依赖属性的读写操作。
　　根据上面的四个步骤，下面来把Name属性来改写成一个依赖属性，具体的实现代码如下所示：
``` 
// 1. 使类型继承DependencyObject类
    public class Person : DependencyObject
    {
        // 2. 声明一个静态只读的DependencyProperty 字段
        public static readonly DependencyProperty nameProperty;
       
        static Person()
        {
            // 3. 注册定义的依赖属性
            nameProperty = DependencyProperty.Register("Name", typeof(string), typeof(Person), 
                new PropertyMetadata("Learning Hard",OnValueChanged)); 
        }

        // 4. 属性包装器，通过它来读取和设置我们刚才注册的依赖属性
        public string Name
        {
            get { return (string)GetValue(nameProperty); }
            set { SetValue(nameProperty, value); }
        }

        private static void OnValueChanged(DependencyObject dpobj, DependencyPropertyChangedEventArgs e)
        {
            // 当只发生改变时回调的方法
        }

    }

```
　　从上面代码可以看出，依赖属性是通过调用DependencyObject的GetValue和SetValue来
对依赖属性进行读写的。它使用哈希表来进行存储的，对应的Key就是属性的HashCode值，
而值（Value）则是注册的DependencyPropery；而C#中的属性是类私有字段的封装，可以通
过对该字段进行操作来对属性进行读写。总结为：属性是字段的包装，WPF中使用属性对依
赖属性进行包装。

2.2 依赖属性的优先级
 　　WPF允许在多个地方设置依赖属性的值，则自然就涉及到依赖属性获取值的优先级问题。
 例如下面XMAL代码，我们在三个地方设置了按钮的背景颜色，那最终按钮会读取那个设置
 的值呢？是Green、Yellow还是Red？
```
<Window x:Class="DPSample.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="MainWindow" Height="350" Width="525">
    <Grid>
        <Button x:Name="myButton" Background="Green" Width="100" Height="30">
            <Button.Style>
                <Style TargetType="{x:Type Button}">
                    <Setter Property="Background" Value="Yellow"/>
                    <Style.Triggers>
                        <Trigger Property="IsMouseOver" Value="True">
                            <Setter Property="Background" Value="Red" />
                        </Trigger>
                    </Style.Triggers>
                </Style>
            </Button.Style>
            Click Me 
        </Button>
    </Grid>
</Window>
```
　　上面按钮的背景颜色是Green。之所以背景色是Green，是因为WPF每访问一个依赖属性，
它都会按照下面的顺序由高到底处理该值。具体优先级如下图所示：

　　在上面XAML中，按钮的本地值设置的是Green，自定义Style Trigger设置的为Red，自
定义的Style Setter设置的为Yellow，由于这里的本地值的优先级最高，所以按钮的背景色
或者的是Green值。如果此时把本地值Green去掉的话，此时按钮的背景颜色是Yellow而不是
Red。这里尽管Style Trigger的优先级比Style Setter高，但是由于此时Style Trigger的
IsMouseOver属性为false，即鼠标没有移到按钮上，一旦鼠标移到按钮上时，此时按钮的颜
色就为Red。此时才会体现出Style Trigger的优先级比Style Setter优先级高。所以上图中
优先级是比较理想情况下，很多时候还需要具体分析。

2.3 依赖属性的继承
　　依赖属性是可以被继承的，即父元素的相关设置会自动传递给所有的子元素。下面代码演示了依赖属性的继承。
```
<Window x:Class="Custom_DPInherited.DPInherited"
      xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
      xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
      xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006" 
      xmlns:d="http://schemas.microsoft.com/expression/blend/2008" 
      mc:Ignorable="d" 
      d:DesignHeight="300" d:DesignWidth="300"
      FontSize="18"
      Title="依赖属性的继承">
    <StackPanel >
        <Label Content="继承自Window的FontSize" />
        <Label Content="显式设置FontSize" 
               TextElement.FontSize="36"/>
        <StatusBar>Statusbar没有继承自Window的FontSize</StatusBar>
    </StackPanel>
</Window>

```
上面的代码的运行效果如下图所示：

　　在上面XAML代码中。Window.FontSize设置会影响所有内部子元素字体大小，这就是依
赖属性的继承。如第一个Label没有定义FontSize，所以它继承了Window.FontSize值。但一
旦子元素提供了显式设置，这种继承就会被打断，所以Window.FontSize值对于第二个Label
不再起作用。

　　这时，你可能已经发现了问题：StatusBar没有显式设置FontSize值，但它的字体大小
没有继承Window.FontSize的值，而是保持了系统的默认值。那这是什么原因呢？其实导致
这样的问题：并不是所有元素都支持属性值继承的，如StatusBar、Tooptip和Menu控件。另
外，StatusBar等控件截获了从父元素继承来的属性，并且该属性也不会影响StatusBar控件
的子元素。例如，如果我们在StatusBar中添加一个Button。那么这个Button的FontSize属
性也不会发生改变，其值为默认值。

　　前面介绍了依赖属性的继承，那我们如何把自定义的依赖属性设置为可被其他控件继承呢？通过AddOwer方法可以依赖属性的继承。具体的实现代码如下所示：
```
 public class CustomStackPanel : StackPanel
    {
         public static readonly DependencyProperty MinDateProperty;
 
         static CustomStackPanel()
        {
             MinDateProperty = DependencyProperty.Register("MinDate", typeof(DateTime), typeof(CustomStackPanel), new FrameworkPropertyMetadata(DateTime.MinValue, FrameworkPropertyMetadataOptions.Inherits));
        }
 
         public DateTime MinDate
        {
             get { return (DateTime)GetValue(MinDateProperty); }
             set { SetValue(MinDateProperty, value); }
        }
    }
 
     public class CustomButton :Button
    {
         private static readonly DependencyProperty MinDateProperty;
 
         static CustomButton()
        {
             // AddOwner方法指定依赖属性的所有者，从而实现依赖属性的继承，即CustomStackPanel的MinDate属性被CustomButton控件继承。
             // 注意FrameworkPropertyMetadataOptions的值为Inherits
             MinDateProperty = CustomStackPanel.MinDateProperty.AddOwner(typeof(CustomButton), new FrameworkPropertyMetadata(DateTime.MinValue, FrameworkPropertyMetadataOptions.Inherits));
        }
 
         public DateTime MinDate
        {
             get { return (DateTime)GetValue(MinDateProperty); }
             set { SetValue(MinDateProperty, value); }
        }
     }
```

　　接下来，你可以在XAML中进行测试使用，具体的XAML代码如下：

```
<Window x:Class="Custom_DPInherited.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:local="clr-namespace:Custom_DPInherited"
        xmlns:sys="clr-namespace:System;assembly=mscorlib"
        Title="实现自定义依赖属性的继承" Height="350" Width="525">
    <Grid>
        <local:CustomStackPanel x:Name="customStackPanle" MinDate="{x:Static sys:DateTime.Now}">
            <!--CustomStackPanel的依赖属性-->
            <ContentPresenter Content="{Binding Path=MinDate, ElementName=customStackPanle}"/>
            <local:CustomButton Content="{Binding RelativeSource={x:Static RelativeSource.Self}, Path=MinDate}" Height="25"/>
        </local:CustomStackPanel>
    </Grid>
</Window>
```

　　上面XAML代码中，显示设置了CustomStackPanel的MinDate的值，而在CustomButton中
却没有显式设置其MinDate值。CustomButton的Content属性的值是通过绑定MinDate属性来
进行获取的，关于绑定的更多内容会在后面文章中分享。在这里CustomButton中并没有设置
MinDate的值，但是CustomButton的Content的值却是当前的时间，从而可以看出，此时
CustomButton的MinDate属性继承了CustomStackPanel的MinDate的值，从而设置了其
Content属性。最终的效果如下图所示：

## 2.4 只读依赖属性

 　　在C#属性中，我们可以通过设置只读属性来防止外界恶意更改该属性值，同样，在WPF
 中也可以设置只读依赖属性。如IsMouseOver就是一个只读依赖属性。那我们如何创建一个
 只读依赖属性呢？其实只读的依赖属性的定义方式与一般依赖属性的定义方式基本一样。
 只读依赖属性仅仅是用DependencyProperty.RegisterReadonly替换了
 DependencyProperty.Register而已。下面代码实现了一个只读依赖属性。
```
public partial class MainWindow : Window
    {
         public MainWindow()
        {
            InitializeComponent();
 
             // 内部使用SetValue来设置值
             SetValue(counterKey, 8);
        }
 
         // 属性包装器，只提供GetValue，你也可以设置一个private的SetValue进行限制。
         public int Counter
        {
             get { return (int)GetValue(counterKey.DependencyProperty); }
        }
 
         // 使用RegisterReadOnly来代替Register来注册一个只读的依赖属性
         private static readonly DependencyPropertyKey counterKey =
             DependencyProperty.RegisterReadOnly("Counter",
             typeof(int),
             typeof(MainWindow),
             new PropertyMetadata(0));
     }
```

　　对应的XAML代码为：
```
<Window x:Class="ReadOnlyDP.MainWindow" 
        Name="ThisWin"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="ReadOnly Dependency Property" Height="350" Width="525">
    <Grid>
        <Viewbox>
            <TextBlock Text="{Binding ElementName=ThisWin, Path=Counter}"/>
        </Viewbox>
    </Grid>
</Window>
```

　　此时Counter包装的counterKey就是一个只读依赖属性，因为其定义为private的，所以在类外也不能使用DependencyObject.SetValue方法来对其值，而包装的Counter属性又只提供了GetValue方法，所以类外部只能对该依赖属性进行读取，而不能对其赋值。此时运行效果如下图所示。

2.5 附加属性
　　WPF中还有一类特殊的属性——附加属性。附加是一种特殊的依赖属性。它允许给一个对象添加一个值，而该对象可能对这个值一无所知。附加属性最常见的例子就是布局容器中DockPanel类中的Dock附加属性和Grid类中Row和Column附加属性。那问题又来了，我们怎样在自己的类中定义一个附加属性呢？其实定义附加属性和定义一般的依赖属性一样没什么区别，只是用RegisterAttached方法代替了Register方法罢了。下面代码演示了附加属性的定义。

public class AttachedPropertyClass
    {
        // 通过使用RegisterAttached来注册一个附加属性
        public static readonly DependencyProperty IsAttachedProperty =
            DependencyProperty.RegisterAttached("IsAttached", typeof(bool), typeof(AttachedPropertyClass),
            new FrameworkPropertyMetadata((bool)false));

        // 通过静态方法的形式暴露读的操作
        public static bool GetIsAttached(DependencyObject dpo)
        {
            return (bool)dpo.GetValue(IsAttachedProperty);
        }

        public static void SetIsAttached(DependencyObject dpo, bool value)
        {
            dpo.SetValue(IsAttachedProperty, value);
        }
    }

　　在上面代码中，IsAttached就是一个附加属性，附加属性没有采用CLR属性进行封装，而是使用静态SetIsAttached方法和GetIsAttached方法来存取IsAttached值。这两个静态方法内部一样是调用SetValue和GetValue来对附加属性读写的。
2.6 依赖属性验证和强制
 　　在定义任何类型的属性时，都需要考虑错误设置属性的可能性。对于传统的CLR属性，可以在属性的设置器中进行属性值的验证，不满足条件的值可以抛出异常。但对于依赖属性来说，这种方法不合适，因为依赖属性通过SetValue方法来直接设置其值的。然而WPF有其代替的方式，WPF中提供了两种方法来用于验证依赖属性的值。
ValidateValueCallback:该回调函数可以接受或拒绝新值。该值可作为DependencyProperty.Register方法的一个参数。
CoerceValueCallback:该回调函数可将新值强制修改为可被接受的值。例如某个依赖属性Age的值范围是0到120，在该回调函数中，可以对设置的值进行强制修改，对于不满足条件的值，强制修改为满足条件的值。如当设置为负值时，可强制修改为0。该回调函数可作为PropertyMetadata构造函数参数进行传递。
　　当应用程序设置一个依赖属性时，所涉及的验证过程如下所示：
首先，CoerceValueCallback方法可以修改提供的值或返回DependencyProperty.UnsetValue。
如果CoerceValueCallback方法强制修改了提供的值，此时会激活ValidateValueCallback方法进行验证，如果该方法返回为true，表示该值合法，被认为可被接受的，否则拒绝该值。不像CoerceValueCallback方法，ValidateValueCallback方法不能访问设置属性的实际对象，这意味着你不能检查其他属性值。即该方法中不能对类的其他属性值进行访问。
如果上面两个阶段都成功的话，最后会触发PropertyChangedCallback方法来触发依赖属性值的更改。
　　下面代码演示了基本的流程。

``` 
class Program
    {
         static void Main(string[] args)
        {
             SimpleDPClass sDPClass = new SimpleDPClass();
             sDPClass.SimpleDP = 2;
            Console.ReadLine();
        }
    }
 
     public class SimpleDPClass : DependencyObject
    {
         public static readonly DependencyProperty SimpleDPProperty =
             DependencyProperty.Register("SimpleDP", typeof(double), typeof(SimpleDPClass),
                 new FrameworkPropertyMetadata((double)0.0,
                    FrameworkPropertyMetadataOptions.None,
                     new PropertyChangedCallback(OnValueChanged),
                     new CoerceValueCallback(CoerceValue)),
                     new ValidateValueCallback(IsValidValue));
 
         public double SimpleDP
        {
             get { return (double)GetValue(SimpleDPProperty); }
             set { SetValue(SimpleDPProperty, value); }
        }
 
         private static void OnValueChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
             Console.WriteLine("当值改变时，我们可以做的一些操作，具体可以在这里定义： {0}", e.NewValue);
        }
 
         private static object CoerceValue(DependencyObject d, object value)
        {
             Console.WriteLine("对值进行限定，强制值： {0}", value);
             return value;
        }
 
         private static bool IsValidValue(object value)
        {
             Console.WriteLine("验证值是否通过，返回bool值，如果返回True表示验证通过，否则会以异常的形式暴露： {0}", value);
             return true;
        }
     }
```
　　其运行结果如下图所示：

　　从运行结果可以看出，此时并没有按照上面的流程先Coerce后Validate的顺序执行，这可能是WPF内部做了一些特殊的处理。当属性被改变时，首先会调用Validate来判断传入的value是否有效，如果无效就不继续后续操作。并且CoerceValue后面并没有运行ValidateValue，而是直接调用PropertyChanged。这是因为CoerceValue操作并没有强制改变属性的值，而前面对这个值已经验证过了，所以也就没有必要再运行Valudate方法来进行验证了。但是如果在Coerce中改变了Value的值，那么还会再次调用Valudate操作来验证值是否合法。
2.7  依赖属性的监听
　　我们可以用两种方法对依赖属性的改变进行监听。这两种方法是：
使用DependencyPropertyDescriptor类
使用OverrideMetadata的方式。
　　下面分别使用这两种方式来实现下对依赖属性的监听。
　　第一种方式：定义一个派生于依赖属性所在的类，然后重写依赖属性的元数据并传递一个PropertyChangedCallback参数即可，具体的实现如下代码所示：

1 public class MyTextBox : TextBox
 2    {
 3         public MyTextBox()
 4             : base()
 5        {
 6        }
 7 
 8         static MyTextBox()
 9        {
10             //第一种方法，通过OverrideMetadata
11             TextProperty.OverrideMetadata(typeof(MyTextBox), new FrameworkPropertyMetadata(new PropertyChangedCallback(TextPropertyChanged)));
12        }
13 
14         private static void TextPropertyChanged(DependencyObject sender, DependencyPropertyChangedEventArgs args)
15        {
16             MessageBox.Show("", "Changed");
17        }
18     }

　　第二种方法：这个方法更加简单，获取DependencyPropertyDescriptor并调用AddValueChange方法为其绑定一个回调函数。具体实现代码如下所示：

public MainWindow()
        {
            InitializeComponent();
            //第二种方法，通过OverrideMetadata
            DependencyPropertyDescriptor descriptor = DependencyPropertyDescriptor.FromProperty(TextBox.TextProperty, typeof(TextBox));
            descriptor.AddValueChanged(tbxEditMe, tbxEditMe_TextChanged);
        }

        private void tbxEditMe_TextChanged(object sender, EventArgs e)
        {
            MessageBox.Show("", "Changed");
        }

三、总结
 　　到这里，依赖属性的介绍就结束了。WPF中的依赖属性通过一个静态只读字段进行定义，并且在静态构造函数中进行注册，最后通过.NET传统属性进行包装，使其使用与传统的.NET属性并无两样。在后面一篇文章将分享WPF中新的事件机制——路由事件。

  
  
