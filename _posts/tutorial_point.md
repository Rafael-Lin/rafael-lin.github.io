
# TutorialPoint - WPF

## dependency property
In WPF applications, dependency property is a specific type of property which
extends the CLR property. It takes the advantage of specific functionalities
available in the WPF property system.

A class which defines a dependency property must be inherited from the
DependencyObject class. Many of the UI controls class which are used in XAML are
derived from the DependencyObject class and they support dependency properties,
e.g. Button class supports the IsMouseOver dependency property.

The following XAML code creates a button with some properties.
```
<Window x:Class = "WPFDependencyProperty.MainWindow"
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation"
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml"
   xmlns:local = "clr-namespace:WPFDependencyProperty"
   Title = "MainWindow" Height = "350" Width = "604">

   <Grid>
      <Button  Height = "40" Width = "175" Margin = "10" Content = "Dependency Property">
         <Button.Style>
            <Style TargetType = "{x:Type Button}">
               <Style.Triggers>

                  <Trigger Property = "IsMouseOver" Value = "True">
                     <Setter Property = "Foreground" Value = "Red" />
                  </Trigger>

               </Style.Triggers>
            </Style>
         </Button.Style>
      </Button>
   </Grid>

</Window>
```

The x:Type markup extension in XAML has a similar functionality like typeof() in
C#. It is used when attributes are specified which take the type of the object
such as <Style TargetType = "{x:Type Button}">

When the above code is compiled and executed, you would get the following MainWindow. When the mouse is over the button, it will change the foreground color of a button. When the mouse leaves the button, it changes back to its original color.

### Dependency Property

Why We Need Dependency Properties

Dependency property gives you all kinds of benefits when you use it in your
application. Dependency Property can used over a CLR property in the following
scenarios −

If you want to set the style
If you want data binding
If you want to set with a resource (a static or a dynamic resource)
If you want to support animation

Basically, Dependency Properties offer a lot of functionalities that you won’t get by using a CLR property.

The main difference between dependency properties and other CLR properties are
listed below −

CLR properties can directly read/write from the private member of a class by
using getter and setter. In contrast, dependency properties are not stored in
local object.

Dependency properties are stored in a dictionary of key/value pairs which is
provided by the DependencyObject class. It also saves a lot of memory because it
stores the property when changed. It can be bound in XAML as well.

Custom Dependency Properties
In .NET framework, custom dependency properties can also be defined. Follow the steps given below to define custom dependency property in C#.

Declare and register your dependency property with system call register.

Provide the setter and getter for the property.

Define a static handler which will handle any changes that occur globally

Define an instance handler which will handle any changes that occur to that particular instance.

1) Need to declare and register the dependency property
2) provide setter and getter function for it
3) provide static handler to handle the changes globally
4) provide the instance handler

The following C# code defines a dependency property to set the SetText property of the user control.
```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace WpfApplication3 {
   /// <summary>
      /// Interaction logic for UserControl1.xaml
   /// </summary>

   public partial class UserControl1 : UserControl {

      public UserControl1() {
         InitializeComponent();
      }

      public static readonly DependencyProperty SetTextProperty =
         DependencyProperty.Register("SetText", typeof(string), typeof(UserControl1), new
            PropertyMetadata("", new PropertyChangedCallback(OnSetTextChanged)));

      public string SetText {
         get { return (string)GetValue(SetTextProperty); }
         set { SetValue(SetTextProperty, value); }
      }

      private static void OnSetTextChanged(DependencyObject d,
         DependencyPropertyChangedEventArgs e) {
         UserControl1 UserControl1Control = d as UserControl1;
         UserControl1Control.OnSetTextChanged(e);
      }

      private void OnSetTextChanged(DependencyPropertyChangedEventArgs e) {
         tbTest.Text = e.NewValue.ToString();
      }
   }
}
```
Here is the XAML file in which the TextBlock is defined as a user control and the Text property will be assigned to it by the SetText dependency property.

The following XAML code creates a user control and initializes its SetText dependency property.
```
<Window x:Class = "WpfApplication3.MainWindow"
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation"
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml"
   xmlns:views = "clr-namespace:WpfApplication3"
   Title = "MainWindow" Height = "350" Width = "604">

   <Grid>
      <views:UserControl1 SetText = "Hellow World"/>
   </Grid>

</Window>
```
Let's run this application. You can immediately observe that in our MainWindow, the dependency property for user control has been successfully used as a Text.


## Data Binding
Advertisements


 Previous Page Next Page
Data binding is a mechanism in WPF applications that provides a simple and easy way for Windows Runtime apps to display and interact with data. In this mechanism, the management of data is entirely separated from the way data.

Data binding allows the flow of data between UI elements and data object on user interface. When a binding is established and the data or your business model changes, then it reflects the updates automatically to the UI elements and vice versa. It is also possible to bind, not to a standard data source, but to another element on the page.

Data binding is of two types − one-way data binding and two-way data binding.

One-Way Data Binding
In one-way binding, data is bound from its source (that is the object that holds the data) to its target (that is the object that displays the data)

Let’s take a simple example to understand one-way data binding in detail. First of all, create a new WPF project with the name WPFDataBinding.

The following XAML code creates two labels, two textboxes, and one button and initializes them with some properties.

<Window x:Class = "WPFDataBinding.MainWindow"
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation"
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml"
   xmlns:d = "http://schemas.microsoft.com/expression/blend/2008"
   xmlns:mc = "http://schemas.openxmlformats.org/markup-compatibility/2006"
   xmlns:local = "clr-namespace:WPFDataBinding"
   mc:Ignorable = "d" Title = "MainWindow" Height = "350" Width = "604">

   <Grid>

      <Grid.RowDefinitions>
         <RowDefinition Height = "Auto" />
         <RowDefinition Height = "Auto" />
         <RowDefinition Height = "*" />
      </Grid.RowDefinitions>

      <Grid.ColumnDefinitions>
         <ColumnDefinition Width = "Auto" />
         <ColumnDefinition Width = "200" />
      </Grid.ColumnDefinitions>

      <Label Name = "nameLabel" Margin = "2">_Name:</Label>

      <TextBox Name = "nameText" Grid.Column = "1" Margin = "2"
         Text = "{Binding Name, Mode = OneWay}"/>

      <Label Name = "ageLabel" Margin = "2" Grid.Row = "1">_Age:</Label>

      <TextBox Name = "ageText" Grid.Column = "1" Grid.Row = "1" Margin = "2"
         Text = "{Binding Age, Mode = OneWay}"/>

      <StackPanel Grid.Row = "2" Grid.ColumnSpan = "2">
         <Button Content = "_Show..." Click="Button_Click" />
      </StackPanel>

   </Grid>
</Window>
The text properties of both the textboxes bind to “Name” and “Age” which are class variables of Person class which is shown below.

In Person class, we have just two variables Name and Age, and its object is initialized in MainWindow class.

In XAML code, we are binding to a property Name and Age, but we have not selected what object that property belongs to.

The easier way is to assign an object to DataContext whose properties we are binding in the following C# code in MainWindowconstructor.

using System.Windows;
namespace WPFDataBinding {

   public partial class MainWindow : Window {

      Person person = new Person { Name = "Salman", Age = 26 };

      public MainWindow() {
         InitializeComponent();
         this.DataContext = person;
      }

      private void Button_Click(object sender, RoutedEventArgs e) {
         string message = person.Name + " is " + person.Age;
         MessageBox.Show(message);
      }
   }

   public class Person {

      private string nameValue;

      public string Name {
         get { return nameValue; }
         set { nameValue = value; }
      }

      private double ageValue;

      public double Age {
         get { return ageValue; }

         set {
            if (value != ageValue) {
               ageValue = value;
            }
         }
      }

   }
}
Let's run this application and you can see immediately in our MainWindow that we have successfully bound to the Name and Age of that Person object.

Output of DataBinding
When you press the Show button, it will display the name and age on the message box.

when show button is pressed
Let’s change the Name and Age in the dialog box.

Changes made in DataBinding
If you now click the Show button, it will again display the same message.

Display same Message
This because data binding mode is set to one-way in the XAML code. To show the updated data, you will need to understand two-way data binding.

Two-Way Data Binding
In two-way binding, the user can modify the data through the user interface and have that data updated in the source. If the source changes while the user is looking at the view, you want the view to be updated.

Let’s take the same example but here, we will change the binding mode from One Way to Two Way in the XAML code.

<Window x:Class = "WPFDataBinding.MainWindow"
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation"
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml"
   xmlns:d = "http://schemas.microsoft.com/expression/blend/2008"
   xmlns:mc = "http://schemas.openxmlformats.org/markup-compatibility/2006"
   xmlns:local = "clr-namespace:WPFDataBinding"
   mc:Ignorable = "d" Title = "MainWindow" Height = "350" Width = "604">

   <Grid>

      <Grid.RowDefinitions>
         <RowDefinition Height = "Auto" />
         <RowDefinition Height = "Auto" />
         <RowDefinition Height = "*" />
      </Grid.RowDefinitions>

      <Grid.ColumnDefinitions>
         <ColumnDefinition Width = "Auto" />
         <ColumnDefinition Width = "200" />
      </Grid.ColumnDefinitions>

      <Label Name = "nameLabel" Margin = "2">_Name:</Label>
      <TextBox Name = "nameText" Grid.Column = "1" Margin = "2"
         Text = "{Binding Name, Mode = TwoWay}"/>
      <Label Name = "ageLabel" Margin = "2" Grid.Row = "1">_Age:</Label>
      <TextBox Name = "ageText" Grid.Column = "1" Grid.Row = "1" Margin = "2"
         Text = "{Binding Age, Mode = TwoWay}"/>

      <StackPanel Grid.Row = "2" Grid.ColumnSpan = "2">
         <Button Content = "_Show..." Click = "Button_Click" />
      </StackPanel>

   </Grid>

</Window>
Let's run this application again.

Two way DataBinding
It will produce the same output −

Output of Two way DataBinding
Let’s now change the Name and Age values −

changes in two way
If you click the Show button now, it will display the updated message.

Updated Output
We recommend that you execute the above code with both the cases for a better understanding of the concept.


# misc

Routed Events

Routed Events have three main routing strategies which are as follows,

Direct Event
Bubbling Event
Tunneling Event
Direct Event

A direct event is similar to events in Windows forms which are raised by the element in which the event is originated.

Unlike a standard CLR event, direct routed events support class handling and they can be used in Event Setters and Event Triggers within your style of your Custom Control.

A good example of a direct event would be the MouseEnter event.

## Bubbling Event

A bubbling event begins with the element where the event is originated. Then it
travels up the visual tree to the topmost element in the visual tree. As you
probably have guessed, in WPF, the topmost element is most likely a window.

Now coming to the example that I set earlier, if you click the Button, then the Bubbling event shall move in this direction,

Button > Stackpanel 1 > Window

If you click any of the Textboxes, then the event route will be,

Textbox 1 or 2 > Stackpanel 2 > Stackpanel 1> Window

## Tunnel Event

The direction of Tunneling event is opposite to the Bubbling event. Here the
event handlers on the element tree root are invoked and then the event travels
down the visual tree to all the children nodes until it reaches the element in
which the event originated.

The difference between a bubbling and a tunneling event (apart from the
direction) is that a tunneling event name will always start with a ‘preview’.

In a WPF application, events are often implemented as a tunneling/bubbling pair.
So, you'll have a previewMouseDown and then a MouseDown event.

## Event Sequence

Now let’s clear your concept a bit more with the proper event chain.

A standard Button control is derived from ButtonBase, and so it inherits a Click
event that fires when a user clicks on the button. As ButtonBase inherits from
UIElement, a Button will also have access to all of the mouse button events
(like MouseLeftButtonDown and MouseDown) defined for UIElement. But as the
Button does something in response to button presses, it swallows the bubbling
events (e.g. MouseLeftButtonDown and MouseDown). In general, controls that do
something as the result of a user pressing a mouse button will swallow the
related events. Clicking on a TextBox gives it focus. Clicking on a Button or
ComboBox also results in the control responding to the click, so these controls
also swallow the non-preview events. Remember, these types of controls only fire
the Tunneling events.

E.g. When a user clicks on a button, there are a series of preview events (tunneling) and actual events (bubbling) that travel up and down the logical tree.

For a left-click on a Button, you’ll normally see click-related events in the following order,

PreviewMouseLeftButtonDown (Tunnel)
PreviewMouseDown (Tunnel)
PreviewMouseLeftButtonUp (Tunnel)
PreviewMouseUp (Tunnel)
Click (Bubble)
But for a Label contained in a StackPanel, which is contained in a Window, the full sequence of events for a left mouse button click on the Label is,

PreviewMouseLeftButtonDown for Window (Tunnel)
PreviewMouseDown for Window (Tunnel)
PreviewMouseLeftButtonDown for StackPanel (Tunnel)
PreviewMouseDown for StackPanel (Tunnel)
PreviewMouseLeftButtonDown for Label (Tunnel)
PreviewMouseDown for Label (Tunnel)

MouseLeftButtonDown for Label (Bubble)
MouseDown for Label (Bubble)
MouseLeftButtonDown for StackPanel (Bubble)
MouseDown for StackPanel (Bubble)
MouseLeftButtonDown for Window (Bubble)
MouseDown for Window (Bubble)
PreviewMouseLeftButtonUp for Window (Tunnel)
PreviewMouseUp for Window (Tunnel)
PreviewMouseLeftButtonUp for StackPanel (Tunnel)
PreviewMouseUp for StackPanel (Tunnel)
PreviewMouseLeftButtonUp for Label (Tunnel)
PreviewMouseUp for Label (Tunnel)
MouseLeftButtonUp for Label (Bubble)
MouseUp for Label (Bubble)
MouseLeftButtonUp for Stackpanel (Bubble)
MouseUp for StackPanel (Bubble)
MouseLeftButtonUp for Window (Bubble)
MouseUp for Window (Bubble)

Now get ready for some hands-on demo of this beautiful feature of routed events.
In this example I will show you only Bubble events, but don’t worry! Very soon I
will post few more examples on Tunneling events as well.

Many of the easy tutorials available on the internet provide examples based on
buttons. It is very basic and easy and it hides the important aspects of using
the Routed events. So, I have decided to use controls other than buttons (more
specifically TextBlock!) in order to properly indicate the features of routed
events.

Hands-on Demo

Here I will create a custom routed event. You need to follow the steps given below to define a custom routed event in C#.

Declare and register your routed event with system call RegisterRoutedEvent.
Specify the Routing Strategy, i.e. Bubble, Tunnel, or Direct.
Provide the event handler.
Follow the steps given below,

Create a new WPF project called WpfCustomRoutedEventTutorial.
Right-click on your solution and select Add > New Item... In the following dialog, select Custom Control (WPF) and name it MyCustomControl.
Click the Add button and you will see that two new files (Themes/Generic.xaml and MyCustomControl.cs) will be added to your solution.
The following XAML code sets the style for the custom control in Generic.xaml file.
```

<ResourceDictionary
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:local="clr-namespace:WpfCustomRoutedEventTutorial">


    <Style TargetType="{x:Type local:MyCustomControl}">
        <Setter Property="Template">
            <Setter.Value>
                <ControlTemplate TargetType="{x:Type local:MyCustomControl}">
                    <Border Background="{TemplateBinding Background}"
                            BorderBrush="{TemplateBinding BorderBrush}"
                            BorderThickness="{TemplateBinding BorderThickness}">
                        <TextBlock x:Name = "tbCustomControl" Text = "I am Custom Textblock. Click or Double-click Me!" />
                    </Border>
                </ControlTemplate>
            </Setter.Value>
        </Setter>
    </Style>
</ResourceDictionary>
```

Given below is the C# code for the MyCustomControl class which inherits from the Control class in which a custom routed event Click is created for the custom control. The code is heavily commented in order to spoon-feed you with the logic. Don’t worry.

```
using System.Windows;
using System.Windows.Controls;

namespace WpfCustomRoutedEventTutorial
{
    public class MyCustomControl : Control
    {
        static MyCustomControl()
        {
            DefaultStyleKeyProperty.OverrideMetadata(typeof(MyCustomControl), new FrameworkPropertyMetadata(typeof(MyCustomControl)));
        }

        /* Assign event handler to the Routed events here. Templates are the section of an element's
        * completed visual tree that comes from the Template property of a Style that is applied to the element.
        */
        public override void OnApplyTemplate()
        {
            base.OnApplyTemplate();

            var custextblock = GetTemplateChild("tbCustomControl") as TextBlock;
            if (custextblock != null)
            {
                /* Assign mouse wheel event handler to the mouse wheel event. This is fired
                 * when the user rotates the mouse wheel while the cursor is on the control.
                 * */
                custextblock.MouseWheel += Custom_MouseWheel;
                /* Assign mouse down event handler to the mouse down event. This is fired
                 * when the user clicks any mouse button while the cursor is on the control.
                 * */
                custextblock.MouseDown += Custom_MouseClick;
            }
        }

        /* Event handler for mouse click */
        private void Custom_MouseClick(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            RaiseMouseClickEvent();
        }

        /* Event handler for mouse wheel rotate */
        void Custom_MouseWheel(object sender, RoutedEventArgs e)
        {
            RaiseMouseWheelEvent();
        }


        /***************** 1ST ROUTED EVENT ******************/
        /* Now we will create a custom routed event called CustomWheelEvent. The name of the event is MyCustomWheelRotate
         * Use bubbling strategy, handler type is RoutedEventHandler, Owner type is MyCustomControl.
         */
        public static readonly RoutedEvent CustomWheelEvent =
         EventManager.RegisterRoutedEvent("MyCustomWheelRotate", RoutingStrategy.Bubble,
         typeof(RoutedEventHandler), typeof(MyCustomControl));

        /* Just like Dependency Properties, routed events are also like wrapper over underlying RoutedEvent instance
         * and they wrap through a set of getter-setter methods.
         */
        public event RoutedEventHandler MyCustomWheelRotate
        {
            add { AddHandler(CustomWheelEvent, value); }
            remove { RemoveHandler(CustomWheelEvent, value); }
        }


        /***************** 2ND ROUTED EVENT ******************/
        /* Now we will create another custom routed event called CustomClickEvent. The name of the event is MyCustomClick
         * Use bubbling strategy, handler type is RoutedEventHandler, Owner type is MyCustomControl.
         */
        public static readonly RoutedEvent CustomClickEvent =
         EventManager.RegisterRoutedEvent("MyCustomClick", RoutingStrategy.Bubble,
         typeof(RoutedEventHandler), typeof(MyCustomControl));

        /* Just like Dependency Properties, routed events are also like wrapper over underlying RoutedEvent instance
         * and they wrap through a set of getter-setter methods.
         */
        public event RoutedEventHandler MyCustomClick
        {
            add { AddHandler(CustomClickEvent, value); }
            remove { RemoveHandler(CustomClickEvent, value); }
        }


        /* Raise the Mouse wheel routed event that travels through the element tree.
         */
        protected virtual void RaiseMouseWheelEvent()
        {
            RoutedEventArgs args = new RoutedEventArgs(CustomWheelEvent);
            RaiseEvent(args);
        }
        /* Raise the Mouse click routed event that travels through the element tree.
         */
        protected virtual void RaiseMouseClickEvent()
        {
            RoutedEventArgs args = new RoutedEventArgs(CustomClickEvent);
            RaiseEvent(args);
        }
    }
}
```

If you are clear up to here, you are more or less through. Now, only the client-side logic remains, that is, after you create your own custom routed event on a custom control, you want to use this custom control in a WPF application, right?

So, here it is.

Here is the implementation in MainWindow.xaml to add your own custom control with two routed events.
```

<Window x:Class="WpfCustomRoutedEventTutorial.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
        xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
        xmlns:local="clr-namespace:WpfCustomRoutedEventTutorial"
        mc:Ignorable="d"
        Title="MainWindow" Height="350" Width="525" MouseDown="Window_Click">
    <Grid>
        <StackPanel Margin = "20" MouseDown="StackPanel_Click">
            <StackPanel Margin = "10">
                <TextBlock Name = "txt1" FontSize = "18" Margin = "5" Text = "This is a TextBlock 1" />
                <TextBlock Name = "txt2" FontSize = "18" Margin = "5" Text = "This is a TextBlock 2" />
                <TextBlock Name = "txt3" FontSize = "18" Margin = "5" Text = "This is a TextBlock 3" />
            </StackPanel>
            <local:MyCustomControl MyCustomWheelRotate="MyCustomControl_MouseWheel" MyCustomClick="MyCustomControl_MouseClick" />
        </StackPanel>
    </Grid>
</Window>
```
Here is the custom routed event implementation in C# which will change the text of the three textboxes depending upon which event you fired.

using System.Windows;
```
namespace WpfCustomRoutedEventTutorial
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        /* The custom routed event implementation which will display a message box when the user clicks it.
         */
        private void MyCustomControl_MouseWheel(object sender, RoutedEventArgs e)
        {
            txt1.Text = "Wheel rotated! It is the custom routed event of your custom control";
        }

        private void MyCustomControl_MouseClick(object sender, RoutedEventArgs e)
        {
            txt1.Text = "Clicked! It is the custom routed event of your custom control";
        }

        /* The event will be routed to its parent which is a stackpanel.
         */
        private void StackPanel_Click(object sender, RoutedEventArgs e)
        {
            txt2.Text = "Only the Click event is bubbled to Stack Panel";
        }

        /* The event will then again be routed to its parent which is the window.
         */
        private void Window_Click(object sender, RoutedEventArgs e)
        {
            txt3.Text = "Only the Click event is bubbled to Window";
        }
    }
}
```

When the above code is compiled and executed, it will produce the following window which contains a custom control.


WPF

Now you point to the Textblock and rotate your mouse wheel. You will see this. The red colored text is only to indicate (it's not part of the output).

WPF
Now, if you single-click on the Textblock, you will see the following.

WPF
Interesting! Isn’t it?

When you single-click on the Textblock, the MouseEnter event is fired. In this case, the Routed event originated from the TextBlock and moved in the direction,

TextBlock > StackPanel > Window.

So, each of these control’s event handlers are triggered and the textboxes text are changed. So far so good.

But why doesn't the Routed event bubble up when Mouse Wheel is rotated??

To understand this, you need to know why Routed event bubbled up when MouseEnter event fired in the first case.

If you notice in MainWindow.xaml file, you will see that I have set the
MouseDown event in both the parent controls i.e. Window and StackPanel. The
MyCustomClick event of the MyCustomControl is the Routed Event which is raised
when Custom_MouseClick() handler is triggered, which is again when the MouseDown
event is raised. So, it is evident that the same event is routed up along the
Visual tree. If it’s a MouseDown event, then only the MouseDown event will
bubble up and hence, only the MouseDown handlers of all the parent Controls will
be triggered.

In the Mouse Wheel event case, you will notice that it’s the MouseWheel event
that is getting fired in the Custom Control, but no MouseWheel event handler is
set in the parent controls like StackPanel and Window. Hence this MouseWheel
event is not handled anywhere except the originating control which is TextBlock
because it already has defined Mouse Wheel event handler.

You can in fact set the Mouse wheel event handler in both StackPanel and Window controls and check for yourself the real fun. It's your homework folks!!!

If at any point in time, you want to stop the routed event at any particular level, then you will need to set the e.Handled = true;

Let’s change the StackPanel_Click event as shown below,

private void StackPanel_Click(object sender, RoutedEventArgs e)
        {
            txt2.Text = "Only the Click event is bubbled to Stack Panel";
            e.Handled = true;
        }
When you click on the TextBlock, you will observe that the click event will not be routed to the Window and will stop at the StackPanel and the third text block will not be updated.


# misc 2

WPF – MVVM (一)
小弟本來是專注於網頁設計，最近被公司抓去寫WPF，所以就開始了新的生涯XDD，而既然講
到WPF，就不可能不需要知道MVVM，翻了一些國外文章，寫的還不錯，小弟我就邊看邊把他
記錄一下，並分享給大家吧，不過因為MVVM的東西比較多，所以小弟我也會分成好幾篇慢慢
地來講解。

What’s MVVM
MVVM當然也是縮寫，也就是Model-View-ViewModel，簡稱MVVM，他也算是一種設計樣式，目
的是為了讓各自的相依性降低，這樣以後也比較好維護與測試，而MVVM的意思如下。

Model是一個來自服務或資料庫數據的類別。
View就是一個顯示的介面，預計是要將資料展現出來。

ViewModel就如同膠水般，它把Model和View黏合起來。它將Model包裝起來，而且
ViewModel還會控制View的應用部分，例如在View那邊按下按鈕後，要處理的動作，實際上
會放在ViewModel。

而它們之間的關係如下圖般，View也就是XAML，透過Data Binding技術與View Model繫結，
但實際上ViewModel是不會知道哪個View繫結了它( ViewModel )；而ViewModel與Model的關
係也是如此，Model永遠不知道他被哪個ViewModel所參考到，而ViewModel則會參考到Model；
換言之，就是View會知道ViewModel，ViewModel會知道Model，這種單向的關係。

image

View與ViewModel
其實如上圖所說，其實View與ViewModel溝通是利用了Binding的技術；我們可以利用下圖更
明確的理解，

image

逐步進行(一)
不過我想講了那麼多，還不如實際的一步一步來走走看，我想感覺是比較明顯的，首先，我
們先實作一個簡單的MVVM架構試試看，而這個畫面是這次預計的目標，其實滿簡單的，就是
會顯示一個文章Title ( 我稱取為PostsTitle )，然後按下按鈕後，會改變Title，雖然這
畫面看起來沒啥成就感，但至少我們可以從很簡單的例子看到MVVM。

image

Model
提到MVVM，當然第一步我們要先把Model建立起來，假設這套系統是要處理文章資料的管理
( 實際上我並不會把它完成，這裡只是假設要建立文章管理系統 )，既然如此，最重要的
Model，顧名思義就是文章了，假設我們此類別取名為Posts，並開始撰寫此類別。

以下是Posts Class的程式碼，超級簡單，就兩行，裡面兩個屬性。


```
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WPFMVVM
{
    public class Posts
    {
        public string postsText { get; set; }
        public string postsTitle { get; set; }

    }
}

```

到這邊我們的Model就建置好了，接下來我們要做的是黏合View和Model的ViewModel!

ViewModel
其實也不長，但比較特別的是，ViewModel裡面的屬性會參考到Model，換言之，Model不會
知道有那些ViewModel用到他 ( 因為Model裡面並沒有參考到ViewModel. )，然後我們會定
義一些方法，讓Model的屬性可以被存取到 ( 例如這邊的PostsTitle方法 )。
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WPFMVVM
{
    public class PostsViewModel
    {
        public Posts posts{ get; set;}

        public PostsViewModel()
        {
            posts = new Posts { postsText = "", postsTitle = "Unknown" };
        }

        public string PostsTitle
        {
            get { return posts.postsTitle; }
            set { posts.postsTitle  = value; }
        }
    }
}
接下來，我們再來處理View的部分。

View
這個地方比較要注意的是Window標籤裡面，我們必須要定義一個local這個NameSpace，當然
這個local你也可以取名其他的名稱，而後面接的就是我們剛剛定義ViewModel的NameSpace，
其次就是DataContext標籤裡面，我們直接實例化PostsViewModel出來；最後利用Binding將
Label的Content細節至PostsViewModel的PostsTitle。

```
<Window x:Class="WPFMVVM.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:local="clr-namespace:WPFMVVM"
        Title="MainWindow" Height="350" Width="525">
    <Window.DataContext>
        <!-- 實例化PostViewModel -->
        <local:PostsViewModel />
    </Window.DataContext>
    <Grid>
        <Label  Content="{Binding PostsTitle}"    Height="28" HorizontalAlignment="Left" Margin="12,12,0,0" Name="label1" VerticalAlignment="Top" />
        <Button Content="Button" Height="23" HorizontalAlignment="Left" Margin="145,13,0,0" Name="button1" VerticalAlignment="Top" Width="75" Click="button1_Click" />
    </Grid>
</Window>
```

這樣就是MVVM!那麼簡單!?，當然不是，這只是簡單的一個Binding而已，但不管怎樣，我們
已經看到了Model和ViewModel是如何處理的，也可以清楚的了解了Model、ViewModel與View
之間的關係，雖然目前只有利用Binding來將PostsTitle顯示於Label，按下Button也沒啥反
應 ( 因為我還沒實作阿XDD )，我們下一篇繼續看下去

```



