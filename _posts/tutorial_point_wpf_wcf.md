# XAML overview

One of the first things you will encounter while working with WPF is XAML. XAML
stands for Extensible Application Markup Language. It’s a simple and declarative
language based on XML.

In XAML, it very easy to create, initialize, and set properties of objects with
hierarchical relations.

It is mainly used for designing GUIs, however it can be used for other purposes
as well, e.g., to declare workflow in Workflow Foundation.

Basic Syntax
When you create your new WPF project, you will encounter some of the XAML code
by default in MainWindow.xaml as shown below.

<Window x:Class = "Resources.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml"
   Title = "MainWindow" Height = "350" Width = "525"> 
	
   <Grid> 
         
   </Grid> 
	
</Window>

Example of object element with some attributes
<Button Content = "Click Me" Height = "30" Width = "60" /> 
==> Height ==> attributes

Example of an alternate syntax do define properties (Property element syntax)
<Button> 
   <Button.Content>Click Me</Button.Content> 
   <Button.Height>30</Button.Height> 
   <Button.Width>60</Button.Width> 
</Button> 
Example of Object with Child Element: StackPanel contains Textblock as child element
<StackPanel Orientation = "Horizontal"> 
   <TextBlock Text = "Hello"/> 
</StackPanel> 

Why XAML in WPF

XAML is not only the most widhttps://www.pornhub.com/view_video.php?viewkey=ph5cacd08b4c910ely known feature of WPF, but it's also one of the
most misunderstood features. If you have exposure to WPF, then you must have
heard of XAML; but take a note of the following two less known facts about XAML
−

WPF doesn't need XAML
XAML doesn't need WPF
They are in fact separable pieces of technology. To understand how that can be,
let's look at a simple example in which a button is created with some properties
in XAML.

<Window x:Class = "WPFXAMLOverview.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml"
   Title = "MainWindow" Height = "350" Width = "604"> 
	
   <StackPanel> 
      <Button x:Name = "button" Content = "Click Me" HorizontalAlignment = "Left"  
         Margin = "150" VerticalAlignment = "Top" Width = "75" /> 
   </StackPanel> 
	
</Window> 

In case you choose not to use XAML in WPF, then you can achieve the same GUI
result with procedural language as well. Let’s have a look at the same example,
but this time, we will create a button in C#.
```
using System.Windows; 
using System.Windows.Controls;  

namespace WPFXAMLOverview { 
   /// <summary> 
      /// Interaction logic for MainWindow.xaml 
   /// </summary> 
	
   public partial class MainWindow : Window { 
	
      public MainWindow() { 
         InitializeComponent(); 
			
         // Create the StackPanel 
         StackPanel stackPanel = new StackPanel(); 
         this.Content = stackPanel; 
			
         // Create the Button 
         Button button = new Button();
         button.Content = "Click Me"; 
         button.HorizontalAlignment = HorizontalAlignment.Left; 
         button.Margin = new Thickness(150); 
         button.VerticalAlignment = VerticalAlignment.Top; 
         button.Width = 75; 
         stackPanel.Children.Add(button);  
      } 
   } 
} 
```

When you compile and execute either the XAML code or the C# code, you will see
the same output as shown below.

XAML Output From the above example, it is clear that what you can do in XAML to
create, initialize, and set properties of objects, the same tasks can also be
done using code.

XAML is just another simple and easy way to design UI elements.

With XAML, it doesn’t mean that what you can do to design UI elements is the
only way. You can either declare the objects in XAML or define them using code.

XAML is optional, but despite this, it is at the heart of WPF design.

The goal of XAML is to enable visual designers to create user interface elements
directly.

WPF aims to make it possible to control all visual aspects of the user interface
from mark-up.



# Elements Tree
There are many technologies where the elements and components are ordered in a
tree structure so that the programmers can easily handle the object and change
the behavior of an application. Windows Presentation Foundation (WPF) has a
comprehensive tree structure in the form of objects. In WPF, there are two ways
that a complete object tree is conceptualized −

1) Logical Tree Structure
2) Visual Tree Structure

With the help of these tree structures, you can easily create and identify the
relationship between UI elements. Mostly, WPF developers and designers either
use procedural language to create an application or design the UI part of the
application in XAML keeping in mind the object tree structure.

## Logical Tree Structure
In WPF applications, the structure of the UI elements in XAML represents the
logical tree structure. In XAML, the basic elements of UI are declared by the
developer. The logical tree in WPF defines the following −

1) Dependency properties
2) Static and dynamic resources
3) Binding the elements on its name etc.

Let’s have a look at the following example in which a button and a list box are created.

<Window x:Class = "WPFElementsTree.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml"
   Title = "MainWindow" Height = "350" Width = "604"> 
	
   <StackPanel> 
      <Button x:Name = "button" Height = "30" Width = "70" Content = "OK" Margin = "20" /> 
		
      <ListBox x:Name = "listBox" Height = "100" Width = "100" Margin = "20"> 
         <ListBoxItem Content = "Item 1" /> 
         <ListBoxItem Content = "Item 2" /> 
         <ListBoxItem Content = "Item 3" /> 
      </ListBox> 
		
   </StackPanel> 
	
</Window> 
If you look at the XAML code, you will observe a tree structure, i.e. the root
node is the Window and inside the root node, there is only one child, that is
StackPanel. But StackPanel contains two child elements, button and list box.
List box has three more child list box items.

## Visual Tree Structure 
In WPF, the concept of the visual tree describes the
structure of visual objects, as represented by the Visual Base Class. It
signifies all the UI elements which are rendered to the output screen.

When a programmer wants to create a template for a particular control, he is
actually rendering the visual tree of that control. The visual tree is also very
useful for those who want to draw lower level controls for performance and
optimization reasons.

In WPF applications, visual tree is used for −

1) Rendering the visual objects.
2) Rendering the layouts.
3) The routed events mostly travel along the visual tree, not the logical tree. To

see the visual tree of the above simple application which contains a button and
a list box, let’s compile and execute the XAML code and you will see the
following window.

Visual Tree Structure When the application is running, you can see the visual
tree of the running application in Live Visual Tree window which shows the
complete hierarchy of this application, as shown below.

logical_tree The visual tree is typically a superset of the logical tree. You
can see here that all the logical elements are also present in the visual tree.
So these two trees are really just two different views of the same set of
objects that make up the UI.

The logical tree leaves out a lot of detail enabling you to focus on the core
structure of the user interface and to ignore the details of exactly how it has
been presented.

The logical tree is what you use to create the basic structure of the user
interface.

The visual tree will be of interest if you're focusing on the presentation. For
example, if you wish to customize the appearance of any UI element, you will
need to use the visual tree.


# Dependency Properties

 
In WPF applications, dependency property is a specific type of property which
extends the CLR property. It takes the advantage of specific functionalities
available in the WPF property system.

A class which defines a dependency property must be inherited from the
DependencyObject class. Many of the UI controls class which are used in XAML are
derived from the DependencyObject class and they support dependency properties,
e.g. Button class supports the IsMouseOver dependency property.

The following XAML code creates a button with some properties.

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

The x:Type markup extension in XAML has a similar functionality like typeof() in
C#. It is used when attributes are specified which take the type of the object
such as <Style TargetType = "{x:Type Button}">

When the above code is compiled and executed, you would get the following
MainWindow. When the mouse is over the button, it will change the foreground
color of a button. When the mouse leaves the button, it changes back to its
original color.

### Dependency Property
Why We Need Dependency Properties
Dependency property gives you all kinds of benefits when you use it in your
application. Dependency Property can used over a CLR property in the following
scenarios −

If you want to set the style
If you want data binding
If you want to set with a resource (a static or a dynamic resource)
If you want to support animation

Basically, Dependency Properties offer a lot of functionalities that you won’t
get by using a CLR property.

The main difference between dependency properties and other CLR properties are
listed below −

CLR properties can directly read/write from the private member of a class by
using getter and setter. In contrast, dependency properties are not stored in
local object.

Dependency properties are stored in a dictionary of key/value pairs which is
provided by the DependencyObject class. It also saves a lot of memory because it
stores the property when changed. It can be bound in XAML as well.

Custom Dependency Properties In .NET framework, custom dependency properties can
also be defined. Follow the steps given below to define custom dependency
property in C#.

1) Declare and register your dependency property with system call register.

2) Provide the setter and getter for the property.

3) Define a static handler which will handle any changes that occur globally

Define an instance handler which will handle any changes that occur to that
particular instance.

The following C# code defines a dependency property to set the SetText property
of the user control.
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

 ```
Here is the XAML file in which the TextBlock is defined as a user control and
the Text property will be assigned to it by the SetText dependency property.

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

Let's run this application. You can immediately observe that in our MainWindow,
the dependency property for user control has been successfully used as a Text.



# routed event
A routed event is a type of event that can invoke handlers on multiple listeners
in an element tree rather than just the object that raised the event. It is
basically a CLR event that is supported by an instance of the Routed Event
class. It is registered with the WPF event system. RoutedEvents have three main
routing strategies which are as follows −

Direct Event
Bubbling Event
Tunnel Event
## Direct Event
A direct event is similar to events in Windows forms which are raised by the
element in which the event is originated.

Unlike a standard CLR event, direct routed events support class handling and
they can be used in Event Setters and Event Triggers within your style of your
Custom Control.

A good example of a direct event would be the MouseEnter event.

## Bubbling Event

A bubbling event begins with the element where the event is originated. Then it
travels up the visual tree to the topmost element in the visual tree. So, in
WPF, the topmost element is most likely a window.

## Tunnel Event
Event handlers on the element tree root are invoked and then the event travels
down the visual tree to all the children nodes until it reaches the element in
which the event originated.

The difference between a bubbling and a tunneling event is that a tunneling
event will always start with a preview.

tunneling --> always start with a preview

In a WPF application, events are often implemented as a tunneling/bubbling pair.
So, you'll have a preview MouseDown and then a MouseDown event.

Given below is a simple example of a Routed event in which a button and three
text blocks are created with some properties and events.

```
<Window x:Class = "WPFRoutedEvents.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   Title = "MainWindow" Height = "450" Width = "604" ButtonBase.Click  = "Window_Click" >
	
   <Grid> 
      <StackPanel Margin = "20" ButtonBase.Click = "StackPanel_Click">
		
         <StackPanel Margin = "10"> 
            <TextBlock Name = "txt1" FontSize = "18" Margin = "5" Text = "This is a TextBlock 1" /> 
            <TextBlock Name = "txt2" FontSize = "18" Margin = "5" Text = "This is a TextBlock 2" /> 
            <TextBlock Name = "txt3" FontSize = "18" Margin = "5" Text = "This is a TextBlock 3" /> 
         </StackPanel> 
			
         <Button Margin = "10" Content = "Click me" Click = "Button_Click" Width = "80"/> 
      </StackPanel> 
   </Grid> 
	
</Window>
```
Here is the C# code for the Click events implementation for Button, StackPanel, and Window.
```
using System.Windows; 
 
namespace WPFRoutedEvents { 
   /// <summary> 
      /// Interaction logic for MainWindow.xaml 
   /// </summary>
	
   public partial class MainWindow : Window { 
	
      public MainWindow() { 
         InitializeComponent(); 
      }  
		
      private void Button_Click(object sender, RoutedEventArgs e) { 
         txt1.Text = "Button is Clicked"; 
      } 
		
      private void StackPanel_Click(object sender, RoutedEventArgs e) { 
         txt2.Text = "Click event is bubbled to Stack Panel"; 
      } 
		
      private void Window_Click(object sender, RoutedEventArgs e) { 
         txt3.Text = "Click event is bubbled to Window"; 
      }
		
   } 
}
```
When you compile and execute the above code, it will produce the following window −

Routed Event
When you click on the button, the text blocks will get updated, as shown below.

Click on Button
If you want to stop the routed event at any particular level, then you will need to set the e.Handled = true;

Let’s change the StackPanel_Click event as shown below −
```
private void StackPanel_Click(object sender, RoutedEventArgs e) { 
   txt2.Text = "Click event is bubbled to Stack Panel"; 
   e.Handled = true; 
}
```
When you click on the button, you will observe that the click event will not be routed to the window and will stop at the stackpanel and the 3rd text block will not be updated.

click event
Custom Routed Events
In .NET framework, custom routed event can also be defined. You need to follow the steps given below to define a custom routed event in C#.

0) Declare and register your routed event with system call RegisterRoutedEvent.

1) Specify the Routing Strategy, i.e. Bubble, Tunnel, or Direct.

2) Provide the event handler.

Let’s take an example to understand more about custom routed events. Follow the steps given below −

Create a new WPF project with WPFCustomRoutedEvent

Right click on your solution and select Add > New Item...

The following dialog will open, now select Custom Control (WPF) and name it MyCustomControl.

Custom Routed Events
Click the Add button and you will see that two new files (Themes/Generic.xaml and MyCustomControl.cs) will be added in your solution.

The following XAML code sets the style for the custom control in Generic.xaml file.
```
<ResourceDictionary 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   xmlns:local = "clr-namespace:WPFCustomRoutedEvent">
	
   <Style TargetType = "{x:Type local:MyCustomControl}"> 
      <Setter Property = "Margin" Value = "50"/> 
      <Setter Property = "Template"> 
         <Setter.Value> 
            <ControlTemplate TargetType = "{x:Type local:MyCustomControl}">
				
               <Border Background = "{TemplateBinding Background}" 
                  BorderBrush = "{TemplateBinding BorderBrush}" 
                  BorderThickness = "{TemplateBinding BorderThickness}"> 
                  <Button x:Name = "PART_Button" Content = "Click Me" /> 
               </Border> 
					
            </ControlTemplate> 
         </Setter.Value> 
      </Setter> 
   </Style> 
	
</ResourceDictionary>
```
Given below is the C# code for the MyCustomControl class which inherits from the Control class in which a custom routed event Click is created for the custom control.
```
using System.Windows; 
using System.Windows.Controls;  

namespace WPFCustomRoutedEvent { 

   public class MyCustomControl : Control { 
	
      static MyCustomControl() { 
         DefaultStyleKeyProperty.OverrideMetadata(typeof(MyCustomControl), 
            new FrameworkPropertyMetadata(typeof(MyCustomControl))); 
      } 
		
      public override void OnApplyTemplate() { 
         base.OnApplyTemplate();
			
         //demo purpose only, check for previous instances and remove the handler first 
         var button  =  GetTemplateChild("PART_Button") as Button; 
         if (button ! =  null) 
         button.Click + =  Button_Click;  
      } 
		
      void Button_Click(object sender, RoutedEventArgs e) { 
         RaiseClickEvent(); 
      } 
		
      public static readonly RoutedEvent ClickEvent  =  
         EventManager.RegisterRoutedEvent("Click", RoutingStrategy.Bubble, 
         typeof(RoutedEventHandler), typeof(MyCustomControl)); 
			
      public event RoutedEventHandler Click { 
         add { AddHandler(ClickEvent, value); } 
         remove { RemoveHandler(ClickEvent, value); } 
      } 
		
      protected virtual void RaiseClickEvent() { 
         RoutedEventArgs args = new RoutedEventArgs(MyCustomControl.ClickEvent); 
         RaiseEvent(args); 
      }
		
   } 
}
```
Here is the custom routed event implementation in C# which will display a message box when the user clicks it.
```
using System.Windows;  

namespace WPFCustomRoutedEvent { 
   // <summary> 
      // Interaction logic for MainWindow.xaml
   // </summary> 
	
   public partial class MainWindow : Window { 
	
      public MainWindow() { 
         InitializeComponent(); 
      }  
		
      private void MyCustomControl_Click(object sender, RoutedEventArgs e) { 
         MessageBox.Show("It is the custom routed event of your custom control"); 
      } 
		
   } 
}
```
Here is the implementation in MainWindow.xaml to add the custom control with a routed event Click.
```
<Window x:Class = "WPFCustomRoutedEvent.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   xmlns:local = "clr-namespace:WPFCustomRoutedEvent"
   Title = "MainWindow" Height = "350" Width = "604"> 
	
   <Grid> 
      <local:MyCustomControl Click = "MyCustomControl_Click" /> 
   </Grid> 
	
</Window>
```
When the above code is compiled and executed, it will produce the following window which contains a custom control.

custom control
When you click on the custom control, it will produce the following message.




# data binding 

Data binding is a mechanism in WPF applications that provides a simple and easy
way for Windows Runtime apps to display and interact with data. In this
mechanism, the management of data is entirely separated from the way data.

Data binding allows the flow of data between UI elements and data object on user
interface. When a binding is established and the data or your business model
changes, then it reflects the updates automatically to the UI elements and vice
versa. It is also possible to bind, not to a standard data source, but to
another element on the page.

Data binding is of two types − one-way data binding and two-way data binding.

## One-Way Data Binding 
In one-way binding, data is bound from its source (that is
the object that holds the data) to its target (that is the object that displays
the data)

Let’s take a simple example to understand one-way data binding in detail. First
of all, create a new WPF project with the name WPFDataBinding.

The following XAML code creates two labels, two textboxes, and one button and
initializes them with some properties.

```
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
```
The text properties of both the textboxes bind to “Name” and “Age” which are class variables of Person class which is shown below.

In Person class, we have just two variables Name and Age, and its object is
initialized in MainWindow class.

In XAML code, we are binding to a property Name and Age, but we have not
selected what object that property belongs to.

The easier way is to assign an object to DataContext whose properties we are binding in the following C# code in MainWindowconstructor.

```
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
```

Let's run this application and you can see immediately in our MainWindow that we
have successfully bound to the Name and Age of that Person object.

Output of DataBinding When you press the Show button, it will display the name
and age on the message box.

when show button is pressed Let’s change the Name and Age in the dialog box.

Changes made in DataBinding If you now click the Show button, it will again
display the same message.

Display same Message This because data binding mode is set to one-way in the
XAML code. To show the updated data, you will need to understand two-way data
binding.

## Two-Way Data Binding 
In two-way binding, the user can modify the data through
the user interface and have that data updated in the source. If the source
changes while the user is looking at the view, you want the view to be updated.

Let’s take the same example but here, we will change the binding mode from One
Way to Two Way in the XAML code.


```
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
```
Let's run this application again.

Two way DataBinding It will produce the same output −

Output of Two way DataBinding Let’s now change the Name and Age values −

changes in two way If you click the Show button now, it will display the updated
message.

Updated Output We recommend that you execute the above code with both the cases
for a better understanding of the concept.





# template 

A template describes the overall look and visual appearance of a control. For
each control, there is a default template associated with it which gives the
control its appearance. In WPF applications, you can easily create your own
templates when you want to customize the visual behavior and visual appearance
of a control.

Connectivity between the logic and the template can be achieved by data binding.
The main difference between styles and templates are listed below −

1) Styles can only change the appearance of your control with default properties of
that control.

2) With templates, you can access more parts of a control than in styles. You can
also specify both existing and new behavior of a control.

There are two types of templates which are most commonly used −

1) Control Template
2) Data Template

## Control Template
The Control Template defines the visual appearance of a control. All of the UI
elements have some kind of appearance as well as behavior, e.g., Button has an
appearance and behavior. Click event or mouse hover event are the behaviors
which are fired in response to a click and hover and there is also a default
appearance of button which can be changed by the Control template.

Example
Let’s take a simple example. We will create two buttons (one is with template and 
the other one is the default button) and initialize them with some properties.
```
<Window x:Class = "TemplateDemo.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   Title = "MainWindow" Height = "350" Width = "604"> 
	
   <Window.Resources> 
      <ControlTemplate x:Key = "ButtonTemplate" TargetType = "Button">
		
         <Grid> 
            <Ellipse x:Name = "ButtonEllipse" Height = "100" Width = "150" > 
               <Ellipse.Fill> 
                  <LinearGradientBrush StartPoint = "0,0.2" EndPoint = "0.2,1.4"> 
                     <GradientStop Offset = "0" Color = "Red" /> 
                     <GradientStop Offset = "1" Color = "Orange" /> 
                  </LinearGradientBrush> 
               </Ellipse.Fill> 
            </Ellipse> 
				
            <ContentPresenter Content = "{TemplateBinding Content}" 
               HorizontalAlignment = "Center" VerticalAlignment = "Center" /> 
         </Grid> 
			
         <ControlTemplate.Triggers> 
			
            <Trigger Property = "IsMouseOver" Value = "True"> 
               <Setter TargetName = "ButtonEllipse" Property = "Fill" > 
                  <Setter.Value> 
                     <LinearGradientBrush StartPoint = "0,0.2" EndPoint = "0.2,1.4"> 
                        <GradientStop Offset = "0" Color = "YellowGreen" /> 
                        <GradientStop Offset = "1" Color = "Gold" /> 
                     </LinearGradientBrush> 
                  </Setter.Value> 
               </Setter> 
            </Trigger> 
				
            <Trigger Property = "IsPressed" Value = "True"> 
               <Setter Property = "RenderTransform"> 
                  <Setter.Value> 
                     <ScaleTransform ScaleX = "0.8" ScaleY = "0.8" 
                        CenterX = "0" CenterY = "0"  /> 
                  </Setter.Value> 
               </Setter> 
               <Setter Property = "RenderTransformOrigin" Value = "0.5,0.5" /> 
            </Trigger> 
				
         </ControlTemplate.Triggers> 
			
      </ControlTemplate> 
   </Window.Resources> 
	
   <StackPanel> 
      <Button Content = "Round Button!"
         Template = "{StaticResource ButtonTemplate}" 
         Width = "150" Margin = "50" /> 
      <Button Content = "Default Button!" Height = "40" 
         Width = "150" Margin = "5" />
   </StackPanel> 
	
</Window> 
```
When you compile and execute the above code, it will display the following MainWindow.

### Control Template

When you move the mouse over the button with custom template, it will change its
color as shown below.

Mouse over with control template

### Data Template
A Data Template defines and specifies the appearance and structure of a
collection of data. It provides the flexibility to format and define the
presentation of the data on any UI element. It is mostly used on data related
Item controls such as ComboBox, ListBox, etc.

Example
Let’s take a simple example to understand the concept of data template. Create a
new WPF project with the name WPFDataTemplates.

In the following XAML code, we will create a Data Template as resource to hold labels and textboxes. 
There is a button and a list box as well which to display the data.
```
<Window x:Class = "WPFDataTemplates.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   xmlns:d = "http://schemas.microsoft.com/expression/blend/2008" 
   xmlns:mc = "http://schemas.openxmlformats.org/markup-compatibility/2006" 
   xmlns:local = "clr-namespace:WPFDataTemplates" 
   xmlns:loc = "clr-namespace:WPFDataTemplates" 
   mc:Ignorable = "d" Title = "MainWindow" Height = "350" Width = "525"> 
	
   <Window.Resources> 
      <DataTemplate DataType = "{x:Type loc:Person}"> 
		
         <Grid> 
            <Grid.RowDefinitions> 
               <RowDefinition Height = "Auto" /> 
               <RowDefinition Height = "Auto" /> 
            </Grid.RowDefinitions> 
				
            <Grid.ColumnDefinitions> 
               <ColumnDefinition Width = "Auto" /> 
               <ColumnDefinition Width = "200" /> 
            </Grid.ColumnDefinitions>
				
            <Label Name = "nameLabel" Margin = "10"/> 
            <TextBox Name = "nameText" Grid.Column = "1" Margin = "10" 
               Text = "{Binding Name}"/>  
            <Label Name = "ageLabel" Margin = "10" Grid.Row = "1"/> 
            <TextBox Name = "ageText" Grid.Column = "1" Grid.Row = "1" Margin = "10" 
               Text = "{Binding Age}"/> 
         </Grid> 
			
      </DataTemplate> 
   </Window.Resources> 
	
   <Grid> 
      <Grid.RowDefinitions> 
         <RowDefinition Height = "Auto" /> 
         <RowDefinition Height = "*" /> 
      </Grid.RowDefinitions> 
		
      <ListBox ItemsSource = "{Binding}" />  
      <StackPanel Grid.Row = "1" > 
         <Button Content = "_Show..." Click = "Button_Click" Width = "80" HorizontalAlignment = "Left" Margin = "10"/> 
      </StackPanel> 
		
   </Grid> 
	
</Window> 
```
Here is implementation in C# in which a list of Person objects are assigned to DataContext, implementation of Person class and button click event.
```
using System.Collections.Generic; 
using System.Windows;
  
namespace WPFDataTemplates { 

   public partial class MainWindow : Window { 
	
      Person src = new Person { Name = "Ali", Age = 27 }; 
      List<Person> people = new List<Person>(); 
		
      public MainWindow() { 
         InitializeComponent(); 
         people.Add(src); 
         people.Add(new Person { Name = "Mike", Age = 62 }); 
         people.Add(new Person { Name = "Brian", Age = 12 });  
         this.DataContext = people; 
      } 
		
      private void Button_Click(object sender, RoutedEventArgs e) { 
         string message = src.Name + " is " + src.Age; 
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
```

When you compile and execute the above code, it will produce the following
window. It contains one list and inside the list box, each list box item
contains the Person class object data which are displayed on Labels and Text
boxes.









# Resources

 
Resources are normally definitions connected with some object that you just
anticipate to use more often than once. It is the ability to store data locally
for controls or for the current window or globally for the entire applications.

Defining an object as a resource allows us to access it from another place. What
it means is that the object can be reused. Resources are defined in resource
dictionaries and any object can be defined as a resource effectively making it a
shareable asset. A unique key is specified to an XAML resource and with that
key, it can be referenced by using a StaticResource markup extension.

Resources can be of two types −

1) StaticResource 
2) DynamicResource 

A StaticResource is a onetime lookup, whereas a DynamicResource works more like
a data binding. It remembers that a property is associated with a particular
resource key. If the object associated with that key changes, dynamic resource
will update the target property.

Example Here's a simple application for the SolidColorBrush resource.

Let’s create a new WPF project with the name WPFResouces.

Drag two Rectangles and set their properties as shown in the following XAML
code.
``` 
<Window x:Class = "WPFResources.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   xmlns:d = "http://schemas.microsoft.com/expression/blend/2008" 
   xmlns:mc = "http://schemas.openxmlformats.org/markup-compatibility/2006" 
   xmlns:local = "clr-namespace:WPFResources" 
   mc:Ignorable = "d" Title = "MainWindow" Height = "350" Width = "525"> 
	
   <Window.Resources> 
      <SolidColorBrush x:Key = "brushResource" Color = "Blue" /> 
   </Window.Resources> 
	
   <StackPanel> 
      <Rectangle Height = "50" Margin = "20" Fill = "{StaticResource brushResource}" /> 
      <Rectangle Height = "50" Margin = "20" Fill = "{DynamicResource brushResource}" /> 
      <Button x:Name = "changeResourceButton"
         Content = "_Change Resource" Click = "changeResourceButton_Click" /> 
   </StackPanel> 
	
</Window> 
```

In the above XAML code, you can see that one rectangle has StaticResource and
the other one has DynamicResource and the color of brushResource is Bisque.

When you compile and execute the code, it will produce the following MainWindow.

MainWindow of Resources When you click the "Change Resource" button, you will
see that the rectangle with DynamicResource will change its color to Red.

Change Resources

Resource Scope

Resources are defined in resource dictionaries, but there are numerous places
where a resource dictionary can be defined. In the above example, a resource
dictionary is defined on Window/page level. In what dictionary a resource is
defined immediately limits the scope of that resource. So the scope, i.e. where
you can use the resource, depends on where you've defined it.

Define the resource in the resource dictionary of a grid and it's accessible by
that grid and by its child elements only.

Define it on a window/page and it's accessible by all elements on that
window/page.

The app root can be found in App.xaml resources dictionary. It's the root of our
application, so the resources defined here are scoped to the entire application.

As far as the scope of the resource is concerned, the most often are application
level, page level, and a specific element level like a Grid, StackPanel, etc.

Resource Scope

The above application has resources in its Window/page level.

Resource Dictionaries

Resource dictionaries in XAML apps imply that the resource dictionaries are kept
in separate files. It is followed in almost all XAML apps. Defining resources in
separate files can have the following advantages −

Separation between defining resources in the resource dictionary and UI related
code.

Defining all the resources in a separate file such as App.xaml would make them
available across the app.

So, how do we define our resources in a resource dictionary in a separate file?
Well, it is very easy, just add a new resource dictionary through Visual Studio
by following steps given below −

In your solution, add a new folder and name it ResourceDictionaries.

Right-click on this folder and select Resource Dictionary from Add submenu item
and name it DictionaryWithBrush.xaml

Example

Let’s now take the same example, but here, we will define the resource dictionary in app level. The XAML code for MainWindow.xaml is as follows −

``` 
<Window x:Class = "WPFResources.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   xmlns:d = "http://schemas.microsoft.com/expression/blend/2008" 
   xmlns:mc = "http://schemas.openxmlformats.org/markup-compatibility/2006" 
   xmlns:local = "clr-namespace:WPFResources" 
   mc:Ignorable = "d" Title = "MainWindow" Height = "350" Width = "525"> 
	
   <StackPanel> 
      <Rectangle Height = "50" Margin = "20" Fill = "{StaticResource brushResource}" /> 
      <Rectangle Height = "50" Margin = "20" Fill = "{DynamicResource brushResource}" /> 
      <Button x:Name = "changeResourceButton"
         Content = "_Change Resource" Click = "changeResourceButton_Click" /> 
   </StackPanel> 
	
</Window>
```
Here is the implementation in DictionaryWithBrush.xaml −

``` 
<ResourceDictionary xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml"> 
	
   <SolidColorBrush x:Key = "brushResource" Color = "Blue" /> 
</ResourceDictionary> 
Here is the implementation in app.xaml −

<Application x:Class="WPFResources.App" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   StartupUri = "MainWindow.xaml"> 
	

   <Application.Resources> 
      <ResourceDictionary Source = " XAMLResources\ResourceDictionaries\DictionaryWithBrush.xaml"/> 
   </Application.Resources> 
	
</Application> 
```

When the above code is compiled and executed, it will produce the following
output −

Resource Dictionaries Output When you click the Change Resource button, the
rectangle will change its color to Red.

Change Resource Dictionaries We recommend that you execute the above code and
try some more resources (for example, background color).




# Styles
 
The .NET framework provides several strategies to personalize and customize the
appearance of an application. Styles provide us the flexibility to set some
properties of an object and reuse these specific settings across multiple
objects for a consistent look.

In styles, you can set only the existing properties of an object such as Height,
Width, Font size, etc.

Only default behavior of a control can be specified.

Multiple properties can be added into a single style.

Styles are used to give a uniform look or appearance to a set of controls.
Implicit styles are used to apply an appearance to all the controls of a given
type and simplify the application. Imagine three buttons, all of them have to
look the same, same width and height, same font size, same foreground color,
etc. We can set all those properties on the button elements themselves and
that's still quite okay for all of the buttons. Take a look at the following
diagram.

Styles

But in a real-life applications, you'll typically have a lot more of these that
need to look exactly the same. And not only buttons of course, you'll typically
want your text blocks, text boxes, and combo boxes etc. to look the same across
your application. Surely, there must be a better way to achieve this and it is
known as styling. You can think of a style as a convenient way to apply a set of
property values to more than one element. Take a look at the following diagram.

Style is Defined
Example
Let’s take a simple example to understand this concept. Start by creating a new WPF project.

Drag three buttons from the toolbox to the design window.

The following XAML code creates three buttons and initializes them with some properties.

``` 
<Window x:Class = "WPFStyle.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   xmlns:d = "http://schemas.microsoft.com/expression/blend/2008" 
   xmlns:mc = "http://schemas.openxmlformats.org/markup-compatibility/2006" 
   xmlns:local = "clr-namespace: WPFStyle" 
   mc:Ignorable = "d" Title = "MainWindow" Height = "350" Width = "604"> 
	
   <StackPanel> 
      <Button Content = "Button1" Height = "30" Width = "80" 
         Foreground = "Blue" FontSize = "12" Margin = "10"/> 
      <Button Content = "Button2" Height = "30" Width = "80" 
         Foreground = "Blue" FontSize = "12" Margin = "10"/> 
      <Button Content = "Button3" Height = "30" Width = "80" 
         Foreground = "Blue" FontSize = "12" Margin = "10"/> 
   </StackPanel> 
	
</Window>
``` 

When you look at the above code, you will see that for all the buttons height,
width, foreground color, font size and margin properties are same. Now when the
above code is compiled and executed the following window will be displayed.

Output of three buttons
Now let’s have a look at the same example, but this time, we will be using style.

```
<Window x:Class = "XAMLStyle.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   xmlns:d = "http://schemas.microsoft.com/expression/blend/2008" 
   xmlns:mc = "http://schemas.openxmlformats.org/markup-compatibility/2006"
   xmlns:local = "clr-namespace:XAMLStyle" 
   mc:Ignorable = "d" Title = "MainWindow" Height = "350" Width = "604">
	
   <Window.Resources> 
      <Style x:Key = "myButtonStyle" TargetType = "Button"> 
         <Setter Property = "Height" Value = "30" /> 
         <Setter Property = "Width" Value = "80" /> 
         <Setter Property = "Foreground" Value = "Blue" /> 
         <Setter Property = "FontSize" Value = "12" /> 
         <Setter Property = "Margin" Value = "10" /> 
      </Style> 
   </Window.Resources> 
	
   <StackPanel> 
      <Button Content = "Button1" Style = "{StaticResource myButtonStyle}" /> 
      <Button Content = "Button2" Style = "{StaticResource myButtonStyle}" /> 
      <Button Content = "Button3" Style="{StaticResource myButtonStyle}" /> 
   </StackPanel> 
	
</Window> 
```

Styles are defined in the resource dictionary and each style has a unique key
identifier and a target type. Inside <style> you can see that multiple setter
tags are defined for each property which will be included in the style.

In the above example, all of the common properties of each button are now
defined in style and then the style are assigned to each button with a unique
key by setting the style property through the StaticResource markup extension.

When you compile and execute the above code, it will display the following
window (the same output).

Same Output The advantage of doing it like this is immediately obvious, we can
reuse that style anywhere in its scope; and if we need to change it, we simply
change it once in the style definition instead of on each element.

In what level a style is defined instantaneously limits the scope of that style.
So the scope, i.e. where you can use the style, depends on where you've defined
it. Styles can be defined on the following levels −

Sr.No Levels & Description 1 Control Level Defining a style on control level can
only be applied to that particular control. Given below is an example of a
control level where the button and TextBlock have their own style.

2 Layout Level Defining a style on any layout level will make it accessible by
that layout and its child elements only.

3 Window Level Defining a style on a window level can make it accessible by all
the elements on that window.

4 Application Level Defining a style on app level can make it accessible
throughout the entire application. Let’s take the same example, but here, we
will put the styles in app.xaml file to make it accessible throughout
application.


# Triggers
A trigger basically enables you to change property values or take actions based
on the value of a property. So, it allows you to dynamically change the
appearance and/or behavior of your control without having to create a new one.

Triggers are used to change the value of any given property, when certain
conditions are satisfied. Triggers are usually defined in a style or in the root
of a document which are applied to that specific control. There are three types
of triggers −

1) Property Triggers
2) Data Triggers
3) Event Triggers
4) Property Triggers

In property triggers, when a change occurs in one property, it will bring either
an immediate or an animated change in another property. For example, you can use
a property trigger to change the appearance of a button when the mouse hovers
over the button.

The following example code shows how to change the foreground color of a button when mouse hovers over the button.
```
<Window x:Class = "WPFPropertyTriggers.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   Title = "MainWindow" Height = "350" Width = "604"> 
	
   <Window.Resources> 
      <Style x:Key = "TriggerStyle" TargetType = "Button"> 
         <Setter Property = "Foreground" Value = "Blue" /> 
         <Style.Triggers> 
            <Trigger Property = "IsMouseOver" Value = "True"> 
               <Setter Property = "Foreground" Value = "Green" /> 
            </Trigger> 
         </Style.Triggers> 
      </Style> 
   </Window.Resources> 
	
   <Grid> 
      <Button Width = "100" Height = "70"
         Style = "{StaticResource TriggerStyle}" Content = "Trigger"/> 
   </Grid> 
	
</Window> 
```

When you compile and execute the above code, it will produce the following window −

## Property Triggers

When the mouse hovers over the button, its foreground color will change to green.

Color Change in Trigger

## Data Triggers

A data trigger performs some actions when the bound data satisfies some conditions. 
Let’s have a look at the following XAML code in which a checkbox and a text block are created with some properties. 
When the checkbox is checked, it will change its foreground color to red.

``` xaml
<Window x:Class = "WPFDataTrigger.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   Title = "Data Trigger" Height = "350" Width = "604">
	
   <StackPanel HorizontalAlignment = "Center"> 
      <CheckBox x:Name = "redColorCheckBox" 
         Content = "Set red as foreground color" Margin = "20"/> 
			
      <TextBlock Name = "txtblock" VerticalAlignment = "Center" 
         Text = "Event Trigger" FontSize = "24" Margin = "20"> 
         <TextBlock.Style> 
            <Style> 
               <Style.Triggers> 
                  <DataTrigger Binding = "{Binding ElementName = redColorCheckBox, Path = IsChecked}" 
                     Value = "true"> 
                     <Setter Property = "TextBlock.Foreground" Value = "Red"/> 
                     <Setter Property = "TextBlock.Cursor" Value = "Hand" /> 
                  </DataTrigger> 
               </Style.Triggers> 
            </Style> 
         </TextBlock.Style> 
      </TextBlock> 
		
   </StackPanel> 
	
</Window>
```

When the above code is compiled and executed, it will produce the following output −

## Data Trigger
When you tick the checkbox, the text block will change its foreground color to red.

## Color Change
## Event Triggers

An event trigger performs some actions when a specific event is fired. It is
usually used to accomplish some animation on control such DoubleAnumatio,
ColorAnimation, etc. In the following example, we will create a simple button.
When the click event is fired, it will expand the button width and height.

```

<Window x:Class = "WPFEventTrigger.MainWindow"
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   Title = "MainWindow" Height = "350" Width = "604"> 
	
   <Grid> 
      <Button Content = "Click Me" Width = "60" Height = "30">
		
         <Button.Triggers> 
            <EventTrigger RoutedEvent = "Button.Click"> 
               <EventTrigger.Actions> 
                  <BeginStoryboard> 
                     <Storyboard> 
							
                        <DoubleAnimationUsingKeyFrames Storyboard.TargetProperty = 
                           "Width" Duration = "0:0:4"> 
                           <LinearDoubleKeyFrame Value = "60" KeyTime = "0:0:0"/> 
                           <LinearDoubleKeyFrame Value = "120" KeyTime = "0:0:1"/> 
                           <LinearDoubleKeyFrame Value = "200" KeyTime = "0:0:2"/> 
                           <LinearDoubleKeyFrame Value = "300" KeyTime = "0:0:3"/> 
                        </DoubleAnimationUsingKeyFrames>
								
                        <DoubleAnimationUsingKeyFrames Storyboard.TargetProperty = "Height" 
                           Duration = "0:0:4"> 
                           <LinearDoubleKeyFrame Value = "30" KeyTime = "0:0:0"/> 
                           <LinearDoubleKeyFrame Value = "40" KeyTime = "0:0:1"/> 
                           <LinearDoubleKeyFrame Value = "80" KeyTime = "0:0:2"/> 
                           <LinearDoubleKeyFrame Value = "150" KeyTime = "0:0:3"/> 
                        </DoubleAnimationUsingKeyFrames>
								
                     </Storyboard> 
                  </BeginStoryboard> 
               </EventTrigger.Actions> 
            </EventTrigger> 
         </Button.Triggers> 
			
      </Button> 
   </Grid> 
	
</Window>
```

When you compile and execute the above code, it will produce the following window −

Event Trigger
Upon clicking the button, you will observe that it will start expanding in both dimensions.

Click Button in Event Trigger
We recommend that you compile and execute the above examples and apply the triggers to other properties as well.



# Custom Controls 

WPF applications allows to create custom controls which makes it very easy to
create feature-rich and customizable controls. Custom controls are used when all
the built-in controls provided by Microsoft are not fulfilling your criteria or
you don’t want to pay for third-party controls.

In this chapter, you will learn how to create custom controls. Before we start
taking a look at Custom Controls, let's take a quick look at a User Control
first.

## User Control

``` 
<UserControl x:Class = "WPFUserControl.MyUserControl" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   xmlns:mc = "http://schemas.openxmlformats.org/markup-compatibility/2006"  
   xmlns:d = "http://schemas.microsoft.com/expression/blend/2008"  
   mc:Ignorable = "d" d:DesignHeight = "300" d:DesignWidth = "300"> 
	
   <Grid> 
      <TextBox Height = "23"  
         HorizontalAlignment = "Left"  
         Margin = "80,49,0,0" Name = "txtBox"  
         VerticalAlignment = "Top" Width = "200" /> 
			
      <Button Content = "Click Me"  
         Height = "23" HorizontalAlignment = "Left"  
         Margin = "96,88,0,0" Name = "button"  
         VerticalAlignment = "Top" Click = "button_Click" />    
   </Grid>
	
</UserControl>

```
Given below is the C# code for button click event in MyUserControl.cs file which updates the text box.

```
using System; 
using System.Windows; 
using System.Windows.Controls; 
 
namespace WPFUserControl {
   /// <summary>
      /// Interaction logic for MyUserControl.xaml 
   /// </summary> 
	
   public partial class MyUserControl : UserControl { 
	
      public MyUserControl() { 
         InitializeComponent(); 
      }  
		
      private void button_Click(object sender, RoutedEventArgs e) { 
         txtBox.Text = "You have just clicked the button"; 
      } 
   } 
}

```
Here is the implementation in MainWindow.xaml to add the user control.


```
<Window x:Class = "XAMLUserControl.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   xmlns:control = "clr-namespace:WPFUserControl" 
   Title = "MainWindow" Height = "350" Width = "525"> 
	
   <Grid> 
      <control:MyUserControl/> 
   </Grid> 
	
</Window> 
```
When you compile and execute the above code, it will produce the following window.

Output of User Control
Upon clicking the "Click Me" button, you will notice that the text inside the textbox is updated.

Button Clicked in User Control

Custom Controls

A custom control is a class which offers its own style and template which are
normally defined in generic.xaml. Custom controls are used in the following
scenarios −

If the control doesn't exist and you have to create it from scratch.

If you want to extend or add functionality to a preexisting control by adding an extra property or an extra functionality to fit your specific scenario.

If your controls need to support theming and styling.

If you want to share your control across applications.

Example

Let’s take an example to understand how custom controls work. Create a new WPF
project and then right-click on your solution and select Add > New Item...

Custom Controls

It will open the following window. Now select Custom Control (WPF) and name it MyCustomControl.

Add New Item

Click the Add button and you will see that two new files (Themes/Generic.xaml
and MyCustomControl.cs) will be added in your solution.

Here is the XAML code in which style is set for the custom control in Generic.xaml file.
``` 
<ResourceDictionary 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   xmlns:local = "clr-namespace:WPFCustomControls">  
	
   <Style TargetType = "{x:Type local:MyCustomControl}"
      BasedOn = "{StaticResource {x:Type Button}}"> 
      <Setter Property = "Background" Value = "LightSalmon" /> 
      <Setter Property = "Foreground" Value = "Blue"/> 
   </Style> 
	
</ResourceDictionary>
```
Here is the C# code for MyCustomControl class which is inherited from the button class and in constructor it overrides the metadata.


```
using System; 
using System.Windows; 
using System.Windows.Controls; 
 
namespace WPFCustomControls { 

   public class MyCustomControl : Button { 
	
      static MyCustomControl() { 
         DefaultStyleKeyProperty.OverrideMetadata(typeof(MyCustomControl), new
            FrameworkPropertyMetadata(typeof(MyCustomControl))); 
      } 
		
   } 
} 

```
Here is the custom control click event implementation in C# which updates the text of the text block.

```
using System; 
using System.Windows; 
using System.Windows.Controls;

namespace WPFCustomControls { 
   /// <summary> 
      /// Interaction logic for MainWindow.xaml 
   /// </summary> 
	
   public partial class MainWindow : Window { 
	
      public MainWindow() { 
         InitializeComponent(); 
      }  
		
      private void customControl_Click(object sender, RoutedEventArgs e) { 
         txtBlock.Text = "You have just click your custom control"; 
      }
		
   } 
}
```
Here is implementation in MainWindow.xaml to add the custom control and a TextBlock.

```
<Window x:Class = "WPFCustomControls.MainWindow" 
   xmlns = "http://schemas.microsoft.com/winfx/2006/xaml/presentation" 
   xmlns:x = "http://schemas.microsoft.com/winfx/2006/xaml" 
   xmlns:control = "clr-namespace:WPFCustomControls" 
   Title = "MainWindow" Height = "350" Width = "604"> 
	
   <StackPanel> 
      <control:MyCustomControl x:Name = "customControl"  
         Content = "Click Me" Width = "70" 
         Margin = "10" Click = "customControl_Click"/> 
			
      <TextBlock Name = "txtBlock"  
         Width = "250" Height = "30"/> 
   </StackPanel>
	
</Window> 
```
When you compile and execute the above code, it will produce the following window with a custom control which is a customized button.

Output of the Code
Upon clicking the customized button, you will see that the text inside text block is updated.


# Chinese WPF



## WPF快速入门系列(2)——深入解析依赖属性
一、引言
　　感觉最近都颓废了，好久没有学习写博文了，出于负罪感，今天强烈逼迫自己开始更新WPF系列。尽管最近看到一篇WPF技术是否老矣的文章，但是还是不能阻止我系统学习WPF。今天继续分享WPF中一个最重要的知识点——依赖属性。

二、依赖属性的全面解析
　　听到依赖属性，自然联想到C#中属性的概念。C#中属性是抽象模型的核心部分，而依赖
属性是专门基于WPF创建的。在WPF库实现中，依赖属性使用普通的C#属性进行了包装，使得
我们可以通过和以前一样的方式来使用依赖属性，但我们必须明确，在WPF中我们大多数都
在使用依赖属性，而不是使用属性。依赖属性重要性在于，在WPF核心特性，如动画、数据
绑定以及样式中都需要使用到依赖属性。既然WPF引入了依赖属性，也自然有其引入的道理。
WPF中的依赖属性主要有以下三个优点：

依赖属性加入了属性变化通知、限制、验证等功能。这样可以使我们更方便地实现应用，同
时大大减少了代码量。许多之前需要写很多代码才能实现的功能，在WPF中可以轻松实现。
节约内存：在WinForm中，每个UI控件的属性都赋予了初始值，这样每个相同的控件在内存中都会保存一份初始值。而WPF依赖属性很好地解决了这个问题，它内部实现使用哈希表存储机制，对多个相同控件的相同属性的值都只保存一份。关于依赖属性如何节约内存的更多内容参考：WPF的依赖属性是怎么节约内存的

支持多种提供对象：可以通过多种方式来设置依赖属性的值。可以配合表达式、样式和绑定来对依赖属性设置值。
2.1 依赖属性的定义

　　上面介绍了依赖属性所带来的好处，这时候，问题又来了，怎样自己定义一个依赖属性
呢？C#属性的定义大家再熟悉不过了。下面通过把C#属性进行改写成依赖属性的方式来介绍
依赖属性的定义。下面是一个属性的定义：

```
1 public class Person
2    {
3         public string Name { get; set; }
6     }
```

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
 　　WPF允许在多个地方设置依赖属性的值，则自然就涉及到依赖属性获取值的优先级问题。例如下面XMAL代码，我们在三个地方设置了按钮的背景颜色，那最终按钮会读取那个设置的值呢？是Green、Yellow还是Red？

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

　　上面按钮的背景颜色是Green。之所以背景色是Green，是因为WPF每访问一个依赖属性，它都会按照下面的顺序由高到底处理该值。具体优先级如下图所示：

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

　　在上面XAML代码中。Window.FontSize设置会影响所有内部子元素字体大小，这就是依赖属性的继承。如第一个Label没有定义FontSize，所以它继承了Window.FontSize值。但一旦子元素提供了显式设置，这种继承就会被打断，所以Window.FontSize值对于第二个Label不再起作用。
　　这时，你可能已经发现了问题：StatusBar没有显式设置FontSize值，但它的字体大小没有继承Window.FontSize的值，而是保持了系统的默认值。那这是什么原因呢？其实导致这样的问题：并不是所有元素都支持属性值继承的，如StatusBar、Tooptip和Menu控件。另外，StatusBar等控件截获了从父元素继承来的属性，并且该属性也不会影响StatusBar控件的子元素。例如，如果我们在StatusBar中添加一个Button。那么这个Button的FontSize属性也不会发生改变，其值为默认值。

　　前面介绍了依赖属性的继承，那我们如何把自定义的依赖属性设置为可被其他控件继承
呢？通过AddOwer方法可以依赖属性的继承。具体的实现代码如下所示：

```
 1  public class CustomStackPanel : StackPanel
 2    {
 3         public static readonly DependencyProperty MinDateProperty;
 4 
 5         static CustomStackPanel()
 6        {
 7             MinDateProperty = DependencyProperty.Register("MinDate", typeof(DateTime), typeof(CustomStackPanel), new FrameworkPropertyMetadata(DateTime.MinValue, FrameworkPropertyMetadataOptions.Inherits));
 8        }
 9 
10         public DateTime MinDate
11        {
12             get { return (DateTime)GetValue(MinDateProperty); }
13             set { SetValue(MinDateProperty, value); }
14        }
15    }
16 
17     public class CustomButton :Button
18    {
19         private static readonly DependencyProperty MinDateProperty;
20 
21         static CustomButton()
22        {
23             // AddOwner方法指定依赖属性的所有者，从而实现依赖属性的继承，即CustomStackPanel的MinDate属性被CustomButton控件继承。
24             // 注意FrameworkPropertyMetadataOptions的值为Inherits
25             MinDateProperty = CustomStackPanel.MinDateProperty.AddOwner(typeof(CustomButton), new FrameworkPropertyMetadata(DateTime.MinValue, FrameworkPropertyMetadataOptions.Inherits));
26        }
27 
28         public DateTime MinDate
29        {
30             get { return (DateTime)GetValue(MinDateProperty); }
31             set { SetValue(MinDateProperty, value); }
32        }
33     }
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

2.4 只读依赖属性

 　　在C#属性中，我们可以通过设置只读属性来防止外界恶意更改该属性值，同样，在WPF
 中也可以设置只读依赖属性。如IsMouseOver就是一个只读依赖属性。那我们如何创建一个
 只读依赖属性呢？其实只读的依赖属性的定义方式与一般依赖属性的定义方式基本一样。
 只读依赖属性仅仅是用DependencyProperty.RegisterReadonly替换了
 DependencyProperty.Register而已。下面代码实现了一个只读依赖属性。

```
1 public partial class MainWindow : Window
 2    {
 3         public MainWindow()
 4        {
 5            InitializeComponent();
 6 
 7             // 内部使用SetValue来设置值
 8             SetValue(counterKey, 8);
 9        }
10 
11         // 属性包装器，只提供GetValue，你也可以设置一个private的SetValue进行限制。
12         public int Counter
13        {
14             get { return (int)GetValue(counterKey.DependencyProperty); }
15        }
16 
17         // 使用RegisterReadOnly来代替Register来注册一个只读的依赖属性
18         private static readonly DependencyPropertyKey counterKey =
19             DependencyProperty.RegisterReadOnly("Counter",
20             typeof(int),
21             typeof(MainWindow),
22             new PropertyMetadata(0));
23     }
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

　　此时Counter包装的counterKey就是一个只读依赖属性，因为其定义为private的，所以
在类外也不能使用DependencyObject.SetValue方法来对其值，而包装的Counter属性又只提
供了GetValue方法，所以类外部只能对该依赖属性进行读取，而不能对其赋值。此时运行效
果如下图所示。

2.5 附加属性

　　WPF中还有一类特殊的属性——附加属性。附加是一种特殊的依赖属性。它允许给一个对
象添加一个值，而该对象可能对这个值一无所知。附加属性最常见的例子就是布局容器中
DockPanel类中的Dock附加属性和Grid类中Row和Column附加属性。那问题又来了，我们怎样
在自己的类中定义一个附加属性呢？其实定义附加属性和定义一般的依赖属性一样没什么区
别，只是用RegisterAttached方法代替了Register方法罢了。下面代码演示了附加属性的定
义。

```
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
```



　　在上面代码中，IsAttached就是一个附加属性，附加属性没有采用CLR属性进行封装，
而是使用静态SetIsAttached方法和GetIsAttached方法来存取IsAttached值。这两个静态方
法内部一样是调用SetValue和GetValue来对附加属性读写的。

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
 1 class Program
 2    {
 3         static void Main(string[] args)
 4        {
 5             SimpleDPClass sDPClass = new SimpleDPClass();
 6             sDPClass.SimpleDP = 2;
 7            Console.ReadLine();
 8        }
 9    }
10 
11     public class SimpleDPClass : DependencyObject
12    {
13         public static readonly DependencyProperty SimpleDPProperty =
14             DependencyProperty.Register("SimpleDP", typeof(double), typeof(SimpleDPClass),
15                 new FrameworkPropertyMetadata((double)0.0,
16                    FrameworkPropertyMetadataOptions.None,
17                     new PropertyChangedCallback(OnValueChanged),
18                     new CoerceValueCallback(CoerceValue)),
19                     new ValidateValueCallback(IsValidValue));
20 
21         public double SimpleDP
22        {
23             get { return (double)GetValue(SimpleDPProperty); }
24             set { SetValue(SimpleDPProperty, value); }
25        }
26 
27         private static void OnValueChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
28        {
29             Console.WriteLine("当值改变时，我们可以做的一些操作，具体可以在这里定义： {0}", e.NewValue);
30        }
31 
32         private static object CoerceValue(DependencyObject d, object value)
33        {
34             Console.WriteLine("对值进行限定，强制值： {0}", value);
35             return value;
36        }
37 
38         private static bool IsValidValue(object value)
39        {
40             Console.WriteLine("验证值是否通过，返回bool值，如果返回True表示验证通过，否则会以异常的形式暴露： {0}", value);
41             return true;
42        }
43     }
```

　　其运行结果如下图所示：

　　从运行结果可以看出，此时并没有按照上面的流程先Coerce后Validate的顺序执行，这可能是WPF内部做了一些特殊的处理。当属性被改变时，首先会调用Validate来判断传入的value是否有效，如果无效就不继续后续操作。并且CoerceValue后面并没有运行ValidateValue，而是直接调用PropertyChanged。这是因为CoerceValue操作并没有强制改变属性的值，而前面对这个值已经验证过了，所以也就没有必要再运行Valudate方法来进行验证了。但是如果在Coerce中改变了Value的值，那么还会再次调用Valudate操作来验证值是否合法。
2.7  依赖属性的监听
　　我们可以用两种方法对依赖属性的改变进行监听。这两种方法是：
使用DependencyPropertyDescriptor类
使用OverrideMetadata的方式。
　　下面分别使用这两种方式来实现下对依赖属性的监听。
　　第一种方式：定义一个派生于依赖属性所在的类，然后重写依赖属性的元数据并传递一个PropertyChangedCallback参数即可，具体的实现如下代码所示：

```
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
```

　　第二种方法：这个方法更加简单，获取DependencyPropertyDescriptor并调用AddValueChange方法为其绑定一个回调函数。具体实现代码如下所示：

```
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
```

三、总结
 　　到这里，依赖属性的介绍就结束了。WPF中的依赖属性通过一个静态只读字段进行定义，
 并且在静态构造函数中进行注册，最后通过.NET传统属性进行包装，使其使用与传统的.NET属
并无两样。在后面一篇文章将分享WPF中新的事件机制——路由事件。


WPF - Dependency Property 深入探討
一直以來，我都認為Flex和WPF ( Silverlight ) 的架構、模式都差不多，反正就是利用XML進行視覺的排版，然後後面有邏輯程式進行處理，然後一堆類似的容器、Control、和事件傳遞模式。

沒錯，後來深深的發現，我錯了QQ，WPF的架構比Flex的架構深的多，並不是說Flex不好，而是深入地去瞭解WPF後，發現兩者的差異其實很大的，其中一個就是Dependency Property。

Property
談Dependency Property之前，我們先談談Property，中文稱之為屬性，其實簡單的理解，就例如TextBlock的FontSize，裡面存放著字型的大小，而這種程式碼在XAML裡面可能會這樣寫。

<TextBlock FontSize="12"/>
簡單易了解吧，那如果是用Code的方式，可能就會是這樣。

TextBlock textBlock = new TextBlock();
textBlock.FontSize = 12;
也滿簡單的，而且，我相信大家一定也都很清楚，但真的是這樣子嗎?讓我們繼續看下去。

Property的延續
下面是一個WPF的Tree，反正就是簡單的Window下面有DockPanel、StackPanel容器，然後下面又有Button。

image

這時候，如果只有在Window下設定FontSize = 12，其他的元件都沒設定FontSize = 12，各位猜，字型會多大多小?

答案當然是全部都是12，可想而知，下面的元件會延續根的設定，除非元件自己有設定FontSize。

解析XML
最近在處理一個案子，內容是將XML格式的內容，視覺化出來，其實並沒有想像中的那麼簡單，如上面的那個例子，如果XML最外圈有設定FontSize，內圈都沒有設定FontSize，但是內圈的FontSize若沒有設定，就要沿用外圈的FontSiz，這種程式碼要怎麼寫!?

好吧，愚蠢的我，當然就是用迴圈的方式，去裡面一個一個比對，然後再針對每個內容進行if的判斷處理。

如果只顯示一次那還好，但如果要在Run Time時，動態改變字型大小，然後又要調整每個元件的大小，呵呵呵…想翻桌了= =。

WPF Dependency Property
當然，弄出WPF的團隊，都是神人，自然不會用我這種愚蠢的方法，所以他們用了一個Dependency Property ( 相依屬性 )的架構來解決這種問題，在看Dependency Property之前，我們先看看，以前的Property是怎樣寫的。

private double fntsize;
public double FontSize
{
    get { return fntsize; }
    set { fntsize = value; }
}
老實說，我也是這樣寫的，然後如果FontSize改變的話，可能就去呼叫FontSizeChanged事件…然後…然後…反正就是很麻煩。

所以WPF使用了Dependency Property，Dependency Property允許以一般的方式進行大部分的通知；那Dependency Property怎樣寫呢?

第一步就是先用靜態類別定義一個DependencyProperty型態的欄位( C#裡面有欄位這個名詞，不清楚的話可以參考這裡，但其實就是定義一個變數，但沒有提供存取的方法，而在C#裡面，屬性這個名詞，是有提供存取的方法，這裡特別強調欄位的原因，是因為MSDN裡面，類別的成員，會區分屬性和欄位這兩個名詞，為了方便查找和避免錯亂，所以這裡我就稱為欄位。 )，此外，要注意的一點，這邊設定FontSize這個Dependency Property，那就必須在後面加上Property，所以加上後的欄位名稱就稱為FontSizeProperty。

public class Control : FrameworkElement
{
...
    public static readonly DependencyProperty FontSizeProperty;
...
}
當然，並非這樣就結束了，這可是readonly耶，而且目前FontSizeProperty裡面也沒任何東西，所以我們必須要在靜態建構子中，給FontSizeProperty參照一個物件；我們使用DependencyProperty的靜態方法Register來參照一個物件，而裡面需要帶一些參數，第一個參數是和此DependencyProperty關聯的Property名稱，第二個是型別，第三個是誰註冊，其實還有第四個參數，這部分後面再講。

static Control()
{
    FontSizeProperty = DependencyProperty.Register("FontSize", typeof(double), typeof(Control));
}
到這邊，並沒有結束，雖然我們有這個欄位，但我們並沒有可以存取的方法，所以接下來我們要寫方法來存取；這裡的set和get大家應該都清楚了，但是SetValue和GetValue又是啥?其實在WPF裡面，UIElement是繼承DependencyObject這個物件而來，而DependencyObject又是繼承DispatcherObject(抽象)而來，而SetValue和GetValue就是從DispatcherObject而來的，所以我們可以直接呼叫使用。( 換言之，如果要實作Dependency Property，就必須繼承於DispatcherObject之下，不過這樣也很合理，畢竟，這是WPF的一個機制 )。

public string FontSize
{
    set { SetValue(FontSizeProperty, value ); }
    get { return (double) GetValue(FontSizeProperty); }
}
SetValue有兩個參數，第一個就是剛剛定的欄位( FontSizeProperty )，第二個就是要存進去的值，而GetValue，其實就是取出來，這樣就完成了Dependency Property程式碼撰寫。

其實，WPF裡面幾乎都是使用Dependency Property機制來處理，最前面講到的TextBlock的FontSize，其實也是使用Dependency Property來處理的。

Dependency Property機制
說到這裡，我相信應該還有人有一堆問題，例如說，他們是怎樣傳遞的，以此圖來說，如果除了Window以外，都沒有給FontSize大小，後面的元件要怎樣知道Window所設定的FontSize?

image

這邊，小弟我取用許薰尹老師文章的其中一個圖，如右邊所示，沒錯，WPF的屬性系統 ( 也就是Dependency Property機制 )會自動的延續 ( 繼承 ) 最上方的節點元件。

image

那這代表甚麼?其實WPF的Dependency Property會資訊存到某個Collection裡面，並自動進行處理，所以我們只要確定底下的節點，
都有定義Dependency Property，那Dependency Property就會自動地去處理這些細節，我們完全可以不用管。

Dependency Property的設定!?
前面有談到，在Register時，還有第四個參數和第五個參數，其實第四個參數是用來設定一些Dependency Property的細節，例如是否要延續父層的屬性、是否會影響尺寸、預設值等等；而第五個參數是當值改變的時候，要呼叫的方法。

FrameworkPropertyMetadata metadata = new FrameworkPropertyMetadata();
metadata.AffectsMeasure = true;//是否會影響Element Size大小
metadata.Inherits = true;//是否延續上層
FontSizeProperty = DependencyProperty.Register("FontSize", typeof(double), 
    typeof(Control), metadata, ValidateFontSize);
然後這是值改變時，呼叫方法的寫法。

static void ValidateFontSize(DependencyObject obj,DependencyPropertyChangedEventArgs args)
{...}

基本上，這就是整個Dependency Property的架構，利用Dependency Property，WPF就變得更簡單，也更容易去處理。

下一篇，我們來談談附加屬性，也就是一開始接觸WPF，讓人匪夷所思的DockPanel.Dock(xxx,Dock.Right);這種寫法。



## WPF快速入门系列(3)——深入解析WPF事件机制
一、引言
 　　WPF除了创建了一个新的依赖属性系统之外，还用更高级的路由事件功能替换了普通
 的.NET事件。

　　路由事件是具有更强传播能力的事件——它可以在元素树上向上冒泡和向下隧道传播，并
且沿着传播路径被事件处理程序处理。与依赖属性一样，可以使用传统的事件方式使用路由
事件。尽管路由事件的使用方式与传统的事件一样，但是理解其工作原理还是相当重要的。

二、路由事件的详细介绍
　　对于.NET中的事件，大家应该在熟悉不过了。事件指的在某个事情发生时，由对象发送
用于通知代码的消息。WPF中的路由事件允许事件可以被传递。例如，路由事件允许一个来
自工具栏按钮的单击事件，在被处理之前可以传递到工具栏，然后再传递到包含工具栏的窗
口。那么现在问题来了，我怎样在WPF中去定义一个路由事件呢？

2.1 如何定义路由事件
　　既然有了问题，自然就要去解决了。在自己定义一个依赖属性之前，首先，我们得学习
下WPF框架中是怎么去定义的，然后按照WPF框架中定义的方式去试着自己定义一个依赖属性。
下面通过Reflector工具来查看下WPF中Button按钮的Click事件的定义方式。

　　由于Button按钮的Click事件是继承于ButtonBase基类的，所以我们直接来查看ButtonBase中Click事件的定义。具体的定义代码如下所示：

```
[Localizability(LocalizationCategory.Button), DefaultEvent("Click")]
public abstract class ButtonBase : ContentControl, ICommandSource
{
    // 事件定义
    public static readonly RoutedEvent ClickEvent;
   
    // 事件注册
    static ButtonBase()
    {
       ClickEvent = EventManager.RegisterRoutedEvent("Click", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(ButtonBase));
        CommandProperty = DependencyProperty.Register("Command", typeof(ICommand), typeof(ButtonBase), new FrameworkPropertyMetadata(null, new PropertyChangedCallback(ButtonBase.OnCommandChanged)));
      .......
    }

    // 传统事件包装
   public event RoutedEventHandler Click
    {
        add
        {
            base.AddHandler(ClickEvent, value);
        }
        remove
        {
            base.RemoveHandler(ClickEvent, value);
        }
    }
    .......
}
```


　　从上面代码可知，路由事件的定义与依赖属性的定义类似，路由事件由只读的静态字段表示，在一个静态构造函数通过EventManager.RegisterRoutedEvent函数注册，并且通过一个.NET事件定义进行包装。

　　现在已经知道了路由事件是如何在WPF框架中定义和实现的了，那要想自己定义一个路由事件也自然不在话下了。

2.2 共享路由事件

　　与依赖属性一样，可以在类之间共享路由事件的定义。即实现路由事件的继承。例如
UIElement类和ContentElement类都使用了MouseUp事件，但MouseUp事件是由
System.Windows.Input.Mouse类定义的。UIElement类和ContentElement类只是通过
RouteEvent.AddOwner方法重用了MouseUp事件。你可以在UIElement类的静态构造函数找到
下面的代码：

```
static UIElement()
{
    _typeofThis = typeof(UIElement);
    
     PreviewMouseUpEvent =  Mouse.PreviewMouseUpEvent.AddOwner(_typeofThis);
    MouseUpEvent = Mouse.MouseUpEvent.AddOwner(_typeofThis);
}
```

2.3 引发和处理路由事件
　　尽管路由事件通过传统的.NET事件进行包装，但路由事件并不是通过.NET事件触发的，而是使用RaiseEvent方法触发事件，所有元素都从UIElement类继承了该方法。下面代码是具体ButtonBase类中触发路由事件的代码：

```
1  protected virtual void OnClick()
2 {
3        RoutedEventArgs e = new RoutedEventArgs(ClickEvent, this);
4       base.RaiseEvent(e);// 通过RaiseEvent方法触发路由事件
5        CommandHelpers.ExecuteCommandSource(this);
6 }
```
　　而在WinForm中，Button的Click事件是通过调用委托进行触发的，具体的实现代码如下所示：

```
1  protected virtual void OnClick(EventArgs e)
2        {
3             EventHandler handler = (EventHandler)base.Events[EventClick];
4             if (handler != null)
5            {
6                 handler(this, e); // 直接调用委托进行触发事件
7            }
8         }
```

　　对于路由事件的处理，与原来WinForm方式一样，你可以在XAML中直接连接一个事件处理程序，具体实现代码如下所示：


```
<TextBlock Margin="3" MouseUp="SomethingClick" Name="tbxTest">
    text label
</TextBlock>
// 后台cs代码
private void SomethingClick(object sender, MouseButtonEventArgs e)
{
}



　　同时还可以通过后台代码的方式连接事件处理程序，具体的实现代码如下所示：
   tbxTest.MouseUp += new MouseButtonEventHandler(SomethingClick);
    // 或者省略委托类型
    tbxTest.MouseUp += SomethingClick;

```

三、路由事件其特殊性
　　路由事件的特殊性在于其传递性，WPF中的路由事件分为三种。

(Direct event):它源自一个元素，并且不传递给其他元素。例如，MouseEnter事件(当鼠标移动到一个元素上面时触发)就是一个直接路由事件。
(Bubbling event):例如，MouseDown事件就是一个冒泡路由事件。它首先被单击的元素触发，接下来就是该元素的父元素触发，依此类推，直到WPF到达元素树的顶部为止。
(Tunneling event):例如PreviewKeyDown就是一个隧道路由事件。在一个窗口上按下某个键，首先是窗口，然后是更具体的容器，直到到达按下键时具有焦点的元素。
　　既然，路由事件有三种表现形式，那我们怎么去区别具体的路由事件是属于哪种呢？辨别的方法在于路由事件的注册方法上，当使用EventManager.RegisterEvent方法注册一个路由事件时，需要传递一个RoutingStrategy枚举值来标识希望应用于事件的事件行为。
3.1 冒泡路由事件
　　下面代码演示了事件冒泡过程：

```
<Window x:Class="BubbleLabelClick.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="MainWindow" Height="350" Width="525" MouseUp="SomethingClick">
    <Grid Margin="3" MouseUp="SomethingClick">
        <Grid.RowDefinitions>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="*"/>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="Auto"/>
        </Grid.RowDefinitions>
        <Label Margin="5" Grid.Row="0" HorizontalAlignment="Left" Background="AliceBlue"
               BorderBrush="Black" BorderThickness="2" MouseUp="SomethingClick">
            <StackPanel MouseUp="SomethingClick">
                <TextBlock Margin="3" MouseUp="SomethingClick" Name="tbxTest">
                    Image and text label
                </TextBlock>
                <Image Source="pack://application:,,,/BubbleLabelClick;component/face.png" Stretch="None"  MouseUp="SomethingClick"/>
                <TextBlock Margin="3" MouseUp="SomethingClick">
                    Courtest for the StackPanel
                </TextBlock>            
            </StackPanel>
        </Label>
        
        <ListBox Grid.Row="1" Margin="3" Name="lstMessage">     
        </ListBox>
        <CheckBox Margin="5" Grid.Row="2" Name="chkHandle">Handle first event</CheckBox>
        <Button Click="cmdClear_Click"  Grid.Row="3" HorizontalAlignment="Right" Margin="5" Padding="3">Clear List</Button>
    </Grid>
</Window>
```

　　其后台代码为：

```
public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();

    }

    private int eventCounter = 0;

    private void SomethingClick(object sender, RoutedEventArgs e)
    {
        eventCounter++;
        string message = "#" + eventCounter.ToString() + ":\r\n" + "Sender: " + sender.ToString() + "\r\n" +
            "Source: " + e.Source + "\r\n" +
            "Original Source: " + e.OriginalSource;
        lstMessage.Items.Add(message);
        e.Handled = (bool)chkHandle.IsChecked;
    }

    private void cmdClear_Click(object sender, RoutedEventArgs e)
    {
        eventCounter = 0;
        lstMessage.Items.Clear();
    }
}
```

　　运行之后的效果图如下所示：

　　单击窗口中的笑脸图像之后，程序的运行结果如下图所示。

　　从上图结果可以发现，MouseUp事件由下向上传递了5级，直到窗口级别结束。另外，如
果选择了Handle first event复选框的话，SomethingClicked方法会将
RoutedEventArgs.Handled属性设置为true，表示事件已被处理，且该事件将终止向上冒泡。
因此，此时列表中只能看到Image的事件，具体运行结果如下图所示：

　　并且在列表框或窗口空白处进行单击，此时也一样只会出现一次MouseUp事件。但单击
一个地方例外。当单击Clear List按钮，此时不会引发MouseUp事件。这是因为按钮包含一
些特殊的处理代码，这些代码会挂起MouseUp事件（即不会触发MouseUp事件，则相应的事件
处理程序也不会被调用），并引发一个更高级的Click事件，同时，Handled标记被设置为
true(这里指的在触发Click事件时会把Handled设置为true)，从而阻止MouseUp事件继续向
上传递。

　　通过博友yiifans指出，上面有一点说错了，在设置Handled = true的时候，不管是冒
泡还是隧道事件，它还是会继续传播的，只是对应的事件不会再处理了。这里之所以没有删
除上面错误解释而是在这里另行说明，是为了强调，因为WPF编程宝典上也是说会阻止传播。
如果想继续响应相应事件的话，可以通过AddHandler方法进行注册。此时你可以去掉
XAMLStackPanel中MouseUp的注册，而是通过后台代码的方式进行注册MouseUp事件，具体的
实现代码如下：
``` 
   // stackpanel1是StackPanel的名称
   stackpanel1.AddHandler(UIElement.MouseUpEvent, new
   RoutedEventHandler(SomethingClick), true);
```

　　之所以还是会继续上传，其实通过在SomethingClick事件处理程序中设置一个断点就可
以发现其调用堆栈，具体的堆栈调用截图如下所示：

　　从上图可以知道SomethingClick调用前都执行了哪些操作，其中RoutedEventHandleInfo.InvokeHandler方法的实现代码就是这个问题的关键所在，下面通过Reflector查看下这个方法的源码，具体查看的源码如下所示：

```
internal void InvokeHandler(object target, RoutedEventArgs routedEventArgs)
{
    if (!routedEventArgs.Handled || this._handledEventsToo)
    {
        if (this._handler is RoutedEventHandler)
        {
            ((RoutedEventHandler) this._handler)(target, routedEventArgs);
        }
        else
        {
            routedEventArgs.InvokeHandler(this._handler, target);
        }
    }
}
```

　　在上面代码中，红色标记的就是解释这个问题的关键代码，每当触发事件处理程序之前，
都会检查RoutedEventArgs的Handled属性和handleEventsToo字段。这样我们就彻底明白了，
当Handle=true时，其实路由事件一样还是会传递，只是传递到对应事件处理程序中时，只
是因为Handle为true和_handleEventsToo为false，从而导致事件处理程序没有运行罢了，
如果通过AddHandler（RoutedEvent, Delegate, Boolean）注册事件处理程序的话，此时
把_handleEventToo显式设置为true了，所以即使Handle为true，该元素的事件处理程序照
样会执行，因为此时if条件一样为true的。

3.2 隧道路由事件

 　　隧道路由事件与冒泡路由事件的工作方式一样，只是方向相反。即如果上面的例子中，
 触发的是一个隧道路由事件的话，如果在图像上单击，则首先窗口触发该隧道路由事件，
 然后才是Grid控件，接下来是StackPanel面板，以此类推，直到到达实际源头，即标签中
 的图像为止。

　　看了上面的介绍。隧道路由事件想必是相当好理解吧。它与冒泡路由事件的传递方式相
反。但是我们怎样去区别隧道路由事件呢？隧道路由事件的识别相当容易，因为隧道路由事
件都是以单词Preview开头。并且，WPF一般都成对地定义冒泡路由事件和隧道路由事件。这
意味着如果发现一个冒泡的MouseUp事件，则对应的PreviewMouseUp就是一个隧道路由事件。
另外，隧道路由事件总是在冒泡路由事件之前被触发。

　　另外需要注意的一点是：如果将隧道路由事件标记为已处理的，那么冒泡路由事件就不
会发生。这是因为这两个事件共享同一个RoutedEventArgs类的实例。隧道路由事件对于来
执行一些预处理操作非常有用，例如，根据键盘上特定的键执行特定操作，或过滤掉特定的
鼠标操作等这样的场景都可以在隧道路由事件处理程序中进行处理。下面的示例演示了
PreviewKeyDown事件的隧道过程。XAML代码如下所示。

```
<Window x:Class="TunneleEvent.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="MainWindow" Height="350" Width="525" PreviewKeyDown="SomeKeyPressed">
    <Grid Margin="3" PreviewKeyDown="SomeKeyPressed">
        <Grid.RowDefinitions>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="*"/>
            <RowDefinition Height="Auto"/>
            <RowDefinition Height="Auto"/>
        </Grid.RowDefinitions>
        <Label Margin="5" Grid.Row="0" HorizontalAlignment="Left" Background="AliceBlue"
               BorderBrush="Black" BorderThickness="2" PreviewKeyDown="SomeKeyPressed">
            <StackPanel>
                <TextBlock Margin="3" PreviewKeyDown="SomeKeyPressed">
                    Image and text label
                </TextBlock>
                <Image Source="face.png" Stretch="None" PreviewMouseUp="SomeKeyPressed"/>
                <DockPanel Margin="0,5,0,0"  PreviewKeyDown="SomeKeyPressed">
                    <TextBlock Margin="3" 
                     PreviewKeyDown="SomeKeyPressed">
                        Type here:
                    </TextBlock>
                    <TextBox PreviewKeyDown="SomeKeyPressed" KeyDown="SomeKeyPressed"></TextBox>
                </DockPanel>
            </StackPanel>
        </Label>

        <ListBox Grid.Row="1" Margin="3" Name="lstMessage">
        </ListBox>
        <CheckBox Margin="5" Grid.Row="2" Name="chkHandle">Handle first event</CheckBox>
        <Button Click="cmdClear_Click"  Grid.Row="3" HorizontalAlignment="Right" Margin="5" Padding="3">Clear List</Button>
    </Grid>
</Window>
```

　　其对应的后台cs代码实现如下所示：

``` cs 
1 public partial class MainWindow : Window
 2    {
 3         public MainWindow()
 4        {
 5            InitializeComponent();
 6        }
 7 
 8         private int eventCounter = 0;
 9 
10         private void SomeKeyPressed(object sender, RoutedEventArgs e)
11        {
12             eventCounter++;
13             string message = "#" + eventCounter.ToString() + ":\r\n" +
14                 " Sender: " + sender.ToString() + "\r\n" +
15                 " Source: " + e.Source + "\r\n" +
16                 " Original Source: " + e.OriginalSource + "\r\n" +
17                 " Event: " + e.RoutedEvent;
18            lstMessage.Items.Add(message);
19             e.Handled = (bool)chkHandle.IsChecked;
20        }
21 
22         private void cmdClear_Click(object sender, RoutedEventArgs e)
23        {
24             eventCounter = 0;
25            lstMessage.Items.Clear();
26        }
27     }
```

　　程序运行后的效果图如下所示：

　　在文本框中按下一个键时，事件首先在窗口触发，然后在整个层次结构中向下传递。具体的运行结果如下图所示：

　　如果在任何位置将PreviewKeyDown事件标记为已处理，则冒泡的KeyDown事件也就不会触发。当勾选了Handle first event 复选框时，当在输入框中按下一个键时，listbox中显示的记录只有1条记录，因为窗口触发的PrevieKeyDown事件处理已经把隧道路由事件标识为已处理，所以PreviewKeyDown事件将不会向下传递，所以此时只会显示一条MainWindow触发的记录。并且，此时，你可以注意到，我们按下的键上对应的字符并没有在输入框中显示，因为此时并没有触发Textbox中的KeyDown事件，因为改变文本框内容的处理是在KeyDown事件中处理的。具体的运行结果如下图所示：

3.3 附加事件
　　在上面例子中，因为所有元素都支持MouseUp和PreviewKeyDown事件。然而，许多控件都有它们自己特殊的事件。例如按钮的的Click事件，其他任何类都有定义该事件。假设有这样一个场景，StackPanel面板中包含了一堆按钮，并且希望在一个事件处理程序中处理所有这些按钮的单击事件。首先想到的办法就是将每个按钮的Click事件关联到同一个事件处理程序。但是Click事件支持事件冒泡，从而有一种更好的解决办法。可以在更高层次元素来关联Click事件来处理所有按钮的单击事件，具体的XAML代码实现如下所示：

```
<Window x:Class="AttachClickEvent.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="MainWindow" Height="350" Width="525">
    <StackPanel Margin="3" Button.Click="DoSomething">
        <Button Name="btn1">Button 1</Button>
        <Button Name="btn2">Button 2</Button>
        <Button Name="btn3">Button 3</Button>
    </StackPanel>
</Window>
```

　　也可以在代码中关联附加事件，但是需要使用UIElement.AddHandle方法，而不能使用+=运算符的方式。具体实现代码如下所示：
// StackPanel面板命名为ButtonsPanel
 ButtonsPanel.AddHandler(Button.ClickEvent, new RoutedEventHandler(DoSomething));
四、WPF事件生命周期
 　　WPF事件生命周期起始和WinForm中类似。下面详细解释下WPF中事件的生命周期。
　　FrameworkElement类实现了ISupportInitialize接口，该接口提供了两个用于控制初始化过程的方法。第一个是BeginInit方法，在实例化元素后立即调用该方法。BeginInit方法被调用之后，XAML解析器设置所有元素的属性并添加内容。第二个是EndInit方法，当初始化完成后，该方法被调用。此时引发Initialized事件。更准确地说，XAML解析器负责调用BeginInit方法和EndInit方法。
　　当创建窗口时，每个元素分支都以自下而上的方式被初始化。这意味着位于深层的嵌套元素在它们容器之前先被初始化。当引发初始化事件时，可以确保元素树中当前元素以下的元素已经全部完成了初始化。但是，包含当前元素的容器还没有初始化，而且也不能假设窗口的其他部分也已经完成初始化了。在每个元素都完成初始化之后，还需要在它们的容器中进行布局、应用样式，如果需要的话还会进行数据绑定。
　　一旦初始化过程完成后，就会引发Loaded事件。Loaded事件和Initialized事件的发生过程相反。意思就是说，包含所有元素的窗口首先引发Loaded事件，然后才是更深层次的嵌套元素。当所有元素都引发了Loaded事件之后，窗口就变得可见了，并且元素都已被呈现。下图列出了部分生命周期事件。

五、小结
　　到这里，WPF路由事件的内容就介绍结束了，本文首先介绍了路由事件的定义，接着介绍了三种路由事件，WPF包括直接路由事件、冒泡路由事件和隧道路由事件，最后介绍了WPF事件的生命周期。在后面一篇文章将介绍WPF中的元素绑定。


## WPF快速入门系列(4)——深入解析WPF绑定
一、引言
　　WPF绑定使得原本需要多行代码实现的功能，现在只需要简单的XAML代码就可以完成之前多行后台代码实现的功能。WPF绑定可以理解为一种关系，该关系告诉WPF从一个源对象提取一些信息，并将这些信息来设置目标对象的属性。目标属性总是依赖属性。然而，源对象可以是任何内容，可以是一个WPF元素、或ADO.NET数据对象或自定义的数据对象等。下面详细介绍了WPF绑定中的相关知识点。
二、绑定元素对象
2.1 如何实现绑定元素对象
　　这里首先介绍绑定最简单的情况——绑定元素对象，即数据源是一个WPF元素对象并且源属性是依赖属性。由于依赖属性具有内置的更改通知支持，因此，当在源对象中改变依赖属性的值时，会立即更新目标对象中的绑定属性。下面通过一个简单的例子来演示下如何绑定元素对象。具体的XAML代码(这里不需要后台代码)如下所示：
```
<StackPanel>
        <Slider Name="sliderFontSize" Margin="3"
            Minimum="1" Maximum="40" Value="10" TickFrequency="1" TickPlacement="TopLeft"/>
        <TextBlock Margin="10" Text="LearningHard" Name="lbtext"
                   FontSize="{Binding ElementName=sliderFontSize, Path=Value}"></TextBlock>
    </StackPanel>
```

　　在上面XAML代码中，TextBlock控件的FontSize属性绑定了Slider控件的Value属性，感觉说绑定有点拗口，你可以直接理解为TextBlock的FontSize属性的值来自与Slider控件的Value值，由于源属性Value是依赖属性，具体内置的更改通知功能，所以Slider控件Value值的改变，直接影响TextBlock控件FontSize的值。正如我们分析的那样，实际运行结果也是如此，运行结果如下图所示：

　　当移动上图中Slider控件上的游标时，下面的文本字体大小也会跟着一起改变。具体效果这里就不贴图了，大家可以自行尝试。从中可以看到WPF绑定的强大了吧，如果放到以前WinForm开发中，你需要监听Slider的ValueChanged事件，然后在事件处理程序中去动态改变文本的字体大小。
　　这里Path除了可以直接绑定属性之外，还可以绑定属性的属性，如FontFamily.Source，也可以指向属性使用的索引器，如Content.Children[0]。当然你也可以执行多层次的路径，如指向属性的属性的属性等。
　　另外，如果绑定失败时，WPF不会引发异常来告知绑定失败的原因。例如，指定的元素或属性不存在，此时不会收到任何提示，只是在目标属性不能显示数据罢了。然而在调试模式下，你可以在输出窗口来查看绑定失败的信息，例如，在上面XAML代码，我们绑定Slider控件一个不存在的属性，如Text属性，此时在Output窗口中就会看到如下信息：

2.2 绑定模式
　　绑定的一个最大的特点就是源属性改变时，目标属性会自动地更新。然而上面的示例有一个问题，即目标对象的改变不会自动更新源对象的属性。通过下面的例子可以看出这个问题所在。此时XAML代码修改为：

```
<Window x:Class="WPFBindingDemo.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="MainWindow" Height="350" Width="400">
    <StackPanel>
        <Slider Name="sliderFontSize" Margin="3"
            Minimum="1" Maximum="40" Value="10" TickFrequency="1" TickPlacement="TopLeft"/>
        <TextBlock Margin="10" Text="LearningHard" Name="lbtext"
                   FontSize="{Binding ElementName=sliderFontSize, Path=Value}"></TextBlock>
        
        <!--在按钮的Click事件处理程序中去改变目标对象的FontSize的值-->
        <StackPanel Orientation="Horizontal">
        <Button Margin="10" Padding="5" Click="cmd_SetSmall">Set to Small</Button>
        <Button Margin="10" Padding="5" Click="cmd_SetNormal">Set to Normal</Button>
        <Button Margin="10" Padding="5" Click="cmd_SetLarge">Set to Large</Button>
        </StackPanel>
    </StackPanel>
</Window>
```

　　此时后台C#代码如下所示：
```
       private void cmd_SetSmall(object sender, RoutedEventArgs e)
        {
            // 仅仅在双向模式下工作
            lbtext.FontSize = 5;
        }

        private void cmd_SetNormal(object sender, RoutedEventArgs e)
        {
            sliderFontSize.Value = 20;
        }

        private void cmd_SetLarge(object sender, RoutedEventArgs e)
        {
            // 仅仅在双向模式下工作
            lbtext.FontSize = 40;
        }
```

　　具体的运行效果如下图所示：

　　从上图可以看到，当在后台更改TextBlock的FontSize属性值，而Slider的Value值却没有进行更新。此时，你肯定会想问，能不能实现目标属性的更变也会自动改变绑定中源属性的机制呢？因为这样就不会显得那样呆板了，然而，你想到的了WPF团队肯定也想到了，WPF支持双向绑定，即从源到目标以及目标到源，要支持双向绑定，只需要设置Binding对象的Mode属性为TwoWay即可，修改后的XAML代码为：

```
<StackPanel>
        <Slider Name="sliderFontSize" Margin="3"
            Minimum="1" Maximum="40" Value="10" TickFrequency="1" TickPlacement="TopLeft"/>
        <TextBlock Margin="10" Text="LearningHard" Name="lbtext"
                   FontSize="{Binding ElementName=sliderFontSize, Path=Value, Mode=TwoWay}"></TextBlock>
        
        <!--在按钮的Click事件处理程序中去改变目标对象的FontSize的值-->
        <StackPanel Orientation="Horizontal">
        <Button Margin="10" Padding="5" Click="cmd_SetSmall">Set to Small</Button>
        <Button Margin="10" Padding="5" Click="cmd_SetNormal">Set to Normal</Button>
        <Button Margin="10" Padding="5" Click="cmd_SetLarge">Set to Large</Button>
        </StackPanel>
    </StackPanel>
   ```


　　Mode属性除了可以设置OneWay，TwoWay值外，还可以设置Default、OneTime和OneWayToSource，关于这些值更详细的介绍请自行参考MSDN：http://msdn.microsoft.com/zh-cn/library/system.windows.data.bindingmode(v=vs.110).aspx。
　　另外，除了可以在XAML中通过Binding标记地方式声明绑定外，还可以使用代码方式动态创建绑定。如上面的例子中代码创建绑定的实现代码如下所示：

```
1  Binding binding = new Binding();
2  binding.Source = sliderFontSize;
3  binding.Path = new PropertyPath("Value");
4  binding.Mode = BindingMode.TwoWay;
5  lbtext.SetBinding(TextBlock.FontSizeProperty, binding);
```

　　还可以通过使用BindingOperations类的ClearBinding方法来移除数据绑定。还可以使用ClearAllBindings移除一个元素的所有数据绑定。
2.3 绑定更新
　　在上面的例子中，还存在另一个问题，当通过在文本框中输入内容来改变显示的字体尺寸时，此时什么事情都不会发生，知道使用tab键将焦点转移到另外一个控件时，才会应用对应的改变。此时XAML代码如下所示：

```
<Window x:Class="WPFBindingDemo.MainWindow"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="MainWindow" Height="350" Width="400">
    <StackPanel>
        <Slider Name="sliderFontSize" Margin="3"
            Minimum="1" Maximum="40" Value="10" TickFrequency="1" TickPlacement="TopLeft"/>
        <TextBlock Margin="10" Text="LearningHard" Name="lbtext"
                   FontSize="{Binding ElementName=sliderFontSize, Path=Value, Mode=TwoWay}"></TextBlock>
        
        <!--在按钮的Click事件处理程序中去改变目标对象的FontSize的值-->
        <StackPanel Orientation="Horizontal">
        <Button Margin="10" Padding="5" Click="cmd_SetSmall">Set to Small</Button>
        <Button Margin="10" Padding="5" Click="cmd_SetNormal">Set to Normal</Button>
        <Button Margin="10" Padding="5" Click="cmd_SetLarge">Set to Large</Button>
        </StackPanel>
        
        <!--添加一个输入文本框来设置文本字体大小进行测试问题-->
        <StackPanel Orientation="Horizontal" Margin="5">
            <TextBlock VerticalAlignment="Center">Set FontSize:</TextBlock>
            <TextBox Text="{Binding ElementName=lbtext, Path=FontSize, Mode=TwoWay}" Width="100"/>
        </StackPanel>
    </StackPanel>
</Window>
```

　　后台代码实现与前面的一样，此时运行的效果如下图所示：

　　为了明白导致这个问题的原因，这里需要深入分析下绑定表达式。当使用OneWay或TwoWay绑定时，改变后的值会立即从源传播到目标。对于滑动条，然而，从目标到源传播未必会立即发生。因为，它们的行为是由Binding.UpdateSourceTrigger属性控制，该属性可以使用下图列出的某个值。注意，UpdateSourceTrigger属性值并不影响目标的更新方式，它仅仅控制TwoWay模式或OneWayToSource模式的绑定更新源的方式。而文本框正是使用LostFocus方式从目标向源进行更新的。

　　既然，找出了导致原因，此时可以对XAML代码进行修改，使得当用于在文本框中输入内容时将变化应用于字体尺寸，具体改变部分的XAML代码为：
<!--添加一个输入文本框来设置文本字体大小进行测试问题-->

```
        <StackPanel Orientation="Horizontal" Margin="5">
            <TextBlock VerticalAlignment="Center">Set FontSize:</TextBlock>
            <TextBox Text="{Binding ElementName=lbtext, Path=FontSize, Mode=TwoWay, UpdateSourceTrigger=PropertyChanged}" Width="100"/>
        </StackPanel>
```

　　另外，需要注意的是，TextBox的Text属性的默认行为是LostFocus，这是因为当用于输入内容时，文本框中文本会不断变化，从而引起多次更新。所以PropertyChanged模式可能会使应用程序运行更缓慢，所以LostFocus默认行为可以说是合理的。
　　要完全控制源对象的更新时机，也可以选择UpdateSourceTrigger.Explicit模式。此时就需要额外编写代码手动触发更新，此时可以添加一个Apply按钮，并在按钮的Click事件处理程序中调用BindingExpression.UpdateSource方法触发立即刷新并更新字体大小的操作。具体的实现代码如下所示：
// 获得应用于文本框上的绑定
BindingExpression be = txtFontSize.GetBindingExpression(TextBox.TextProperty);
// 调用UpdateSource更新源对象
be.UpdateSource();
三、绑定非元素对象
 　　上面都是介绍如何链接两个元素的绑定，但是在数据驱动的应用程序中，更常见的情况是创建从一个对象中提起数据的绑定表达式。不过希望绑定的信息必须存储在一个公有属性中。因为WPF绑定不能获取私有信息或公有字段。
　　当绑定一个非元素对象时，不能使用Binding.ElementName属性，但可以使用以下属性中的一个：
Source——该属性是指向源对象的引用，即提供数据的对象。
RelativeSource——该属性使用RelativeSource对象指定绑定源的相对位置，默认值为null。
DataContext属性——如果没有使用Source或RelativeSource属性指定一个数据源，WPF会从当前元素开始在元素树中向上查找。检查每个元素的DataContext属性，并使用第一个非空的DataContext属性。当然你也可以自己设置DataContext属性。
　　下面通过一个例子来演示下如何绑定到非元素对象。下面的演示如何使用DataContext属性来绑定一个自定义对象的属性。首先自定义一个实现了INotifyPropertyChanged接口的类。这个接口是为了发出属性更改的通知，即实现了这个接口将会实现当源对象的公共属性发生改变时，该属性的值会立即响应到界面上显式。当然不实现这个接口的对象也可以绑定控件中，只要被绑定是公有属性就可以。具体的实现代码如下所示：

```
1 using System.ComponentModel;
 2 
 3 namespace WPFBindingDemo
 4 {
 5     public class Student:INotifyPropertyChanged
 6    {
 7         private int m_ID;
 8         private string m_StudentName;
 9         private double m_Score;
10        
11         public int ID
12        {
13             get { return m_ID; }
14             set 
15            {
16                 if (value != m_ID)
17                {
18                     m_ID = value;
19                     Notify("ID");
20                }
21            }
22        }
23 
24         public string StudentName
25        {
26             get { return m_StudentName; }
27             set
28            {
29                 if (value != m_StudentName)
30                {
31                     m_StudentName = value;
32                     Notify("StudentName");
33                }
34            }
35        }
36 
37         public double Score
38        {
39             get { return m_Score; }
40             set 
41            {
42                 if (value != m_Score)
43                {
44                     m_Score = value;
45                     Notify("Score");
46                }
47            }
48        }
49 
50         public event PropertyChangedEventHandler PropertyChanged;
51         private void Notify(string propertyName)
52        {
53             if (PropertyChanged != null)
54            {
55                 this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
56            }
57        }
58    }
59 }
```


　　既然源数据对象以准备好了，自然接下来就是去设计WPF界面来让控件来绑定这个源对象了，具体的XAML代码如下所示：
```
<Window x:Class="WPFBindingDemo.BindingToCollection"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="BindingToCollection" Height="300" Width="300">
    <StackPanel Margin="50">
        <StackPanel Orientation="Horizontal" Margin="10">
            <TextBlock Text="学号:"  />
            <TextBlock Text="{Binding Path=ID}" Width="100"/>
        </StackPanel>
        <StackPanel Orientation="Horizontal" Margin="10">
            <TextBlock Text="姓名:"  />
            <TextBlock Text="{Binding Path=StudentName}" Width="100"/>
        </StackPanel>
        <StackPanel Orientation="Horizontal" Margin="10">
            <TextBlock Text="分数:"  />
            <TextBlock Text="{Binding Path=Score}" Width="100"/>
        </StackPanel>

        <StackPanel Orientation="Horizontal" Margin="10">
            <Button Content="改变姓名" Name="changeName" Click="changeName_Click_1"/>
            <Button Content="改变分数" Name="changeScore" Margin="20,0,0,0" Click="ChangeScore_Click"/>
        </StackPanel>
    </StackPanel>
</Window>
```

　　对应的后台代码逻辑如下所示：

```
public partial class BindingToCollection : Window
    {
        private Student m_student;
        public BindingToCollection()
        {
            InitializeComponent();
            m_student = new Student() { ID = 1, StudentName = "LearningHard", Score = 60 };
            // 设置Window对象的DataContext属性
            this.DataContext = m_student ;
        }

        private void ChangeScore_Click(object sender, RoutedEventArgs e)
        {
            m_student.Score = 90;
        }

        private void changeName_Click_1(object sender, RoutedEventArgs e)
        {
            m_student.StudentName = "Learning";
        }
    }
```

　　完成了示例所有代码的编写之后，下面具体看看示例的运行效果，看看是否可以成功完成绑定并源对象的属性的更改会立即反应到界面中，具体的效果图如下所示：

　　从上图示例的演示动画效果可以看出，上面的代码确实实现我们预期的功能。从上面代码可以看出，我们并没有对每个控件单独设置它的Source属性，而是直接设置了Window对象的DataContext属性。这样绑定的控件发现没有设置source属性或RelativeSource属性，就会从元素树中查找DataContex属性不为null的值来作为自己的DataContext。通过这样的方式可以省去重复在多个控件中设置相同的DataContext属性。
　　这里只是演示了绑定单个数据对象的情况，就如之前所说的，数据源还可以是XAML文件，ADO.NET数据对象、集合等，这里就不一一实现了，只要了解具体思路，具体问题具体搜索解决就好了。这里给出两个非常的好例子。
Simple Demo of Binding to a Database in WPF using LINQ-SQL
How to Perform WPF Data Binding Using LINQ to XML
四、提高大列表的性能
 　　如果绑定的数据源具有大量记录时，此时就需要考虑性能的问题了。然而，幸运的是，WPF很多列表控件都已经帮我们做好了相应的支持，这里只是提出来让大家知道这点。
　　对于大列表显示性能问题，WPF做了以下几种支持：
UI虚拟化——UI虚拟化是列表仅为当前显示项创建容器对象的一种技术，例如，如果有一个具有5万条记录的列表，但是可见区域只能包含30条记录，ListBox控件只创建30个ListBoxItem对象。如果ListBox控件不支持UI虚拟化的话，它将需要生成全部5万个ListBoxItem对象，这显然需要占用更多的内存。并且分配这些对象的时间用户明显可以感觉到，这就带来了非常不好的用户体验。WPF中UI虚拟化是通过VirtualizingStackPanel容器实现的。像ListBox、ListView和DataGrid都自动使用VirtualizingStackPanel面板布局它们的子元素，所以，这些控件都默认支持虚拟化功能。然而，ComboBox需要支持虚拟化支持，必须明确提供新的ItemPanelTemplate添加虚拟化支持，具体实现如下所示：

```
<ComboBox>
   <ComboBox.ItemsPanel>
       <ItemsPanelTemplate>
          <VirtualizingStackPanel></VirtualizingStackPanel>
       </ItemsPanelTemplate>
   </ComboBox.ItemsPanel>
</ComboBox>
```

　　TreeView控件也支持虚拟化，但它在默认情况下，关闭了该支持，你需要显式启用该特性，具体使用的启用代码如下所示：
<TreeView VirtualizingPanel.IsVirtualizing="True" />
项目容器再循环——WPF 3.5 SP1使用项目容器再循环改进了虚拟化。通常支持虚拟化的列表在滚动时，控件不断地创建新的项目容器对象来保存新的可见项。例如，当具有5万个项的ListBox控件，在滚动时，ListBox需要重新生成新的ListBoxItem对象。但是如果启用了项目容器再循环，ListBox控件会保存少量ListBoxItem对象存活，当滚动时，将新数据加到这些之前的ListBoxItem对象，从而重复使用它们。具体支持代码如下所示
<ListBox VirtualizingPanel.VirtualizationMode="Recycling"/>
　　项目容器再循环提供了滚动性能，并降低了内存消耗量，因为垃圾回收器不需要查找旧对象进行回收。为了确保向后兼容，除了DataGrid之后的所有列表控件默认都禁用该特性，如需支持，需要显式启用。
延迟滚动——为了进一步提供滚动性能，可以开启延迟滚动功能。使用延迟滚动，当用户在滚动条上拖动滚动滑块时不更新列表显示，只有用户释放了滚动滑块时才刷新。当使用常规滚动时，在拖动的同时会刷新列表，使列表显示正在改变的位置。这个特性也需要显式启用，启用代码如下：
<ListBox ScrollViewer.IsDeferredScrollingEnabled="True"/>
　　显然，需要在响应性和易用性之间平衡。如果有一个复杂的模板和大量数据，对于提高速度可能会选择使用延迟滚动特性，但当用户需要在滚动时查看目前滚动位置，则就可以不启用该特性。
　　上面介绍了这么多，其实提供列表控件的性能主要在两方面：UI虚拟化提高了列表项初始化的时间，因为UI虚拟化支持一次性不初始化所有项，而在滚动是自动创建新的项。项目容器再循环和延迟滚动提高了滚动性能。
　　另外WPF绑定还有两个知识点：数据验证和数据转换，对于数据验证与Asp.net中验证类似，都是为了保证输入数据的合法性，而数据转换指的是在源数据绑定到目标依赖属性之前要做对应的转换，例如WPF显示人民币都需要显示一个￥符号，但是如果数据源的内容只是“120”这样的字符串怎么办呢？这时候就可以通过数据转换在绑定之前，把数据源的值转换成显示所需要的格式。对于这两个知识点，我觉得在遇到问题时再去学就好了，因为我们已经明白了解决问题的思路了。所以，在快速入门系列中不想太深入的介绍这两个知识点，以使大家可以快速掌握WPF要领。这里给出几个学习链接：
      数据绑定概述
      WPF Data Binding - Part 1
      WPF Simple Data Converter Example
　　如何：实现绑定验证
五、小结
 　  到这里，这篇博文的内容就介绍结束了，时间不知不觉的已经2点多了。下面一篇博文将分享WPF命令的内容。




## WPF快速入门系列(5)——深入解析WPF命令
一、引言
　　WPF命令相对来说是一个崭新的概念，因为命令对于之前的WinForm根本没有实现这个概念，但是这并不影响我们学习WPF命令，因为设计模式中有命令模式，关于命令模式可以参考我设计模式的博文：http://www.cnblogs.com/zhili/p/CommandPattern.html。命令模式的要旨在于把命令的发送者与命令的执行者之间的依赖关系分割开了。对此，WPF中的命令也是一样的，WPF命令使得命令源(即命令发送者，也称调用程序)和命令目标（即命令执行者，也称处理程序）分离。现在是不是感觉命令是不是亲切了点了呢？下面就详细分享下我对WPF命令的理解。
 二、命令是什么呢？
 　　上面通过命令模式引出了WPF命令的要旨，那在WPF中，命令是什么呢？对于程序来说，命令就是一个个任务，例如保存，复制，剪切这些操作都可以理解为一个个命令。即当我们点击一个复杂按钮时，此时就相当于发出了一个复制的命令，即告诉文本框执行一个复杂选中内容的操作，然后由文本框控件去完成复制的操作。在这里，复杂按钮就相当于一个命令发送者，而文本框就是命令的执行者。它们之间通过命令对象分割开了。如果采用事件处理机制的话，此时调用程序与处理程序就相互引用了。
　　所以对于命令只是从不同角度理解问题的一个词汇，之前理解点击一个按钮，触发了一个点击事件，在WPF编程中也可以理解为触发了一个命令。说到这里，问题又来了，WPF中既然有了命令了？那为什么还需要路由事件呢？对于这个问题，我的理解是，事件和命令是处理问题的两种方式，它们之间根本不存在冲突的，并且WPF命令中使用了路由事件。所以准确地说WPF命令应该是路由命令。那为什么说WPF命令是路由的呢？这个疑惑将会在WPF命令模型介绍中为大家解答。
　　另外，WPF命令除了使命令源和命令目标分割的优点外，它还具有另一个优点：
使得控件的启用状态和相应的命令状态保持同步，即命令被禁用时，此时绑定命令的控件也会被禁用。
三、WPF命令模型
 　　经过前面的介绍，大家应该已经命令了WPF命令吧。即命令就是一个操作，任务。接下来就要详细介绍了WPF命令模型了。
　　WPF命令模型具有4个重要元素：
命令——命令表示一个程序任务，并且可跟踪该任务是否能被执行。然而，命令实际上不包含执行应用程序的代码，真正处理程序在命令目标中。
命令源——命令源触发命令，即命令的发送者。例如Button、MenuItem等控件都是命令源，单击它们都会执行绑定的命令。
命令目标——命令目标是在其中执行命令的元素。如Copy命令可以在TextBox控件中复制文本。
命令绑定——前面说过，命令是不包含执行程序的代码的，真正处理程序存在于命令目标中。那命令是怎样映射到处理程序中的呢？这个过程就是通过命令绑定来完成的，命令绑定完成的就是红娘牵线的作用。
　　WPF命令模型的核心就在于ICommand接口了，该接口定义命令的工作原理。该接口的定义如下所示：

```
public interface ICommand
{
    // Events
    event EventHandler CanExecuteChanged;

    // Methods
    bool CanExecute(object parameter);
    
    void Execute(object parameter);
}
```

　　该接口包括2个方法和一个事件。CanExecute方法返回命令的状态——指示命令是否可执行，例如，文本框中没有选择任何文本，此时Copy命令是不用的，CanExecute则返回为false。
　　Execute方法就是命令执行的方法，即处理程序。当命令状态改变时，会触发CanExecuteChanged事件。
　　当自定义命令时，不会直接去实现ICommand接口。而是使用RoutedCommand类，该类实是WPF中唯一现了ICommand接口的类。所有WPF命令都是RoutedCommand类或其派生类的实例。然而程序中处理的大部分命令不是RoutedCommand对象，而是RoutedUICommand对象。RoutedUICommand类派生与RoutedCommand类。
　　接下来介绍下为什么说WPF命令是路由的呢？实际上，RoutedCommand上Execute和CanExecute方法并没有包含命令的处理逻辑，而是将触发遍历元素树的事件来查找具有CommandBinding的对象。而真正命令的处理程序包含在CommandBinding的事件处理程序中。所以说WPF命令是路由命令。该事件会在元素树上查找CommandBinding对象，然后去调用CommandBinding的CanExecute和Execute来判断是否可执行命令和如何执行命令。那这个查找方向是怎样的呢？对于位于工具栏、菜单栏或元素的FocusManager.IsFocusScope设置为”true“是从元素树上根元素(一般指窗口元素)向元素方向向下查找，对于其他元素是验证元素树根方向向上查找。
　　WPF中提供了一组已定义命令，命令包括以下类：ApplicationCommands、NavigationCommands、MediaCommands、EditingCommands 以及ComponentCommands。 这些类提供诸如 Cut、BrowseBack、BrowseForward、Play、Stop 和 Pause 等命令。
四、使用命令
 　　前面都是介绍了一些命令的理论知识，下面介绍了如何使用WPF命令来完成任务。XAML具体实现代码如下所示：


```
1 <Window x:Class="WPFCommand.MainWindow"
 2        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
 3        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
 4        Title="MainWindow" Height="200" Width="300">
 5     <!--定义窗口命令绑定，绑定的命令是New命令，处理程序是NewCommand-->
 6     <Window.CommandBindings>
 7         <CommandBinding Command="ApplicationCommands.New" Executed="NewCommand"/>
 8     </Window.CommandBindings>
 9     
10     <StackPanel>
11         <Menu>
12             <MenuItem Header="File">
13                 <!--WPF内置命令都可以采用其缩写形式-->
14                 <MenuItem Command="New"></MenuItem>
15             </MenuItem>
16         </Menu>
17         
18         <!--获得命令文本的两种方式-->
19         <!--直接从静态的命令对象中提取文本-->
20         <Button Margin="5" Padding="5" Command="ApplicationCommands.New" ToolTip="{x:Static ApplicationCommands.New}">New</Button>
21 
22         <!--使用数据绑定，获得正在使用的Command对象，并提取其Text属性-->
23         <Button Margin="5" Padding="5" Command="ApplicationCommands.New" Content="{Binding RelativeSource={RelativeSource Self},Path=Command.Text}"/>
24         <Button Margin="5" Padding="5" Visibility="Visible" Click="cmdDoCommand_Click" >DoCommand</Button>
25     </StackPanel>
26 </Window>
```


　　其对应的后台代码实现如下所示：

```
public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            //// 后台代码创建命令绑定
            //CommandBinding bindingNew = new CommandBinding(ApplicationCommands.New);
            //bindingNew.Executed += NewCommand;
            //// 将创建的命令绑定添加到窗口的CommandBindings集合中
            //this.CommandBindings.Add(bindingNew);
        }

        private void NewCommand(object sender, ExecutedRoutedEventArgs e)
        {
            MessageBox.Show("New 命令被触发了，命令源是:" + e.Source.ToString());
        }

        private void cmdDoCommand_Click(object sender, RoutedEventArgs e)
        {
            // 直接调用命令的两种方式
            ApplicationCommands.New.Execute(null, (Button)sender);

            //this.CommandBindings[0].Command.Execute(null);
        }

    }
```


　　上面程序的运行结果如下图所示：

五、自定义命令
 　　在开发过程中，自然少不了自定义命令来完成内置命令所没有提供的任务。下面通过一个例子来演示如何创建一个自定义命令。
　　首先，定义一个Requery命令，具体的实现如下所示：

```
public class DataCommands
    {
        private static RoutedUICommand requery;
        static DataCommands()
        {
            InputGestureCollection inputs = new InputGestureCollection();
            inputs.Add(new KeyGesture(Key.R, ModifierKeys.Control, "Ctrl+R"));
            requery = new RoutedUICommand(
              "Requery", "Requery", typeof(DataCommands), inputs);
        }
         
        public static RoutedUICommand Requery
        {
            get { return requery; }
        }
    }
```


　　上面代码实现了一个Requery命令，为了演示效果，我们需要把该命令应用到XAML标签上，具体的XAML代码如下所示：

```
<!--要使用自定义命令，首先需要将.NET命名空间映射为XAML名称空间,这里映射的命名空间为local-->
    <Window x:Class="WPFCommand.CustomCommand"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml" 
       
        xmlns:local="clr-namespace:WPFCommand" 
        Title="CustomCommand" Height="300" Width="300" >
       
    <Window.CommandBindings>
        <!--定义命令绑定-->
        <CommandBinding Command="local:CustomCommands.Requery" Executed="RequeryCommand_Execute"/>
    </Window.CommandBindings>
    <StackPanel>
        <!--应用命令-->
        <Button Margin="5" Command="local:CustomCommands.Requery" Content="{Binding RelativeSource={RelativeSource Self}, Path=Command.Text}"></Button>
    </StackPanel>
</Window>
```

　　接下来，看看程序的运行效果，具体的运行结果如下图所示：

六、实现可撤销的命令程序
　　WPF命令模型缺少的一个特征就是Undo命令，尽管提供了一个ApplicationCommands.Undo命令，但是该命令通常被用于编辑控件，如TextBox控件。如果希望支持应用程序范围内的Undo操作，就需要在内部跟踪以前的命令，并且触发Undo操作时还原该命令。这个实现原理就是保持用一个集合对象保存之前所有执行过的命令，当触发Undo操作时，还要上一个命令的状态。这里除了需要保存执行过的命令外，还需要保存触发命令的控件以及状态，所以我们需要抽象出一个类来保存这些属性，我们取名这个类为CommandHistoryItem。为了保存命令和命令的状态，自然就需要在完成命令之前进行保存，所以自然联想到是否有Preview之类的事件呢？实际上确实有，这个事件就是PreviewExecutedEvent，所以我们需要在窗口加载完成后把这个事件注册到窗口上，这里在触发这个事件的时候就可以保存即将要执行的命令、命令源和命令源的内容。另外，之前的命令自然需要保存到一个列表中，这里使用ListBox控件作为这个列表，如果不希望用户在界面上看到之前的命令列表的话，也可以使用List等集合容器。
　　上面讲解完了主要实现思路之后，下面我们梳理下实现思路：
抽象一个CommandHistoryItem来保存命令相关的属性。
注册PreviewExecutedEvent事件，为了在命令执行完之前保存命令、命令源以及命令源当前的状态。
在PreviewExecutedEvent事件处理程序中，把命令相关属性添加到ListBox列表中。
当执行撤销操作时，可以从ListBox.Items列表中取出上一个执行的命令进行恢复之前命令的状态。
　　有了上面的实现思路之后，实现这个可撤销的命令程序也就是码代码的过程了。具体的后台代码实现如下所示：

```
 1  public partial class CommandsMonitor : Window
  2    {
  3         private static RoutedUICommand undo;
  4         public static RoutedUICommand Undo
  5        {
  6             get { return CommandsMonitor.undo; }
  7        }
  8 
  9         static CommandsMonitor()
 10        {
 11             undo = new RoutedUICommand("Undo", "Undo", typeof(CommandsMonitor));
 12        }
 13 
 14         public CommandsMonitor()
 15        {
 16            InitializeComponent();
 17             // 按下菜单栏按钮时，PreviewExecutedEvent事件会被触发2次，即CommandExecuted事件处理程序被触发了2次
 18             // 一次是菜单栏按钮本身，一次是目标源触发命令的执行，所以在CommandExecuted要过滤掉不关心的命令源
 19             this.AddHandler(CommandManager.PreviewExecutedEvent, new ExecutedRoutedEventHandler(CommandExecuted));
 20        }
 21 
 22         public void CommandExecuted(object sender, ExecutedRoutedEventArgs e)
 23        {
 24             // 过滤掉命令源是菜单按钮的，因为我们只关心Textbox触发的命令
 25             if (e.Source is ICommandSource)
 26                 return;
 27             // 过滤掉Undo命令
 28             if (e.Command == CommandsMonitor.Undo)
 29                 return;
 30 
 31             TextBox txt = e.Source as TextBox;
 32             if (txt != null)
 33            {
 34                 RoutedCommand cmd = e.Command as RoutedCommand;
 35                 if (cmd != null)
 36                {
 37                     CommandHistoryItem historyItem = new CommandHistoryItem()
 38                    {
 39                         CommandName = cmd.Name,
 40                         ElementActedOn = txt,
 41                         PropertyActedOn = "Text",
 42                         PreviousState = txt.Text
 43                    };
 44 
 45                     ListBoxItem item = new ListBoxItem();
 46                     item.Content = historyItem;
 47                    lstHistory.Items.Add(item);
 48                }
 49 
 50            }
 51        }
 52 
 53         private void window_Unloaded(object sender, RoutedEventArgs e)
 54        {
 55             this.RemoveHandler(CommandManager.PreviewExecutedEvent, new ExecutedRoutedEventHandler(CommandExecuted));
 56        }
 57 
 58         private void UndoCommand_Executed(object sender, RoutedEventArgs e)
 59        {
 60             ListBoxItem item = lstHistory.Items[lstHistory.Items.Count - 1] as ListBoxItem;
 61 
 62             CommandHistoryItem historyItem = item.Content as CommandHistoryItem;
 63             if (historyItem == null)
 64            {
 65                 return;
 66            }
 67                 
 68             if (historyItem.CanUndo)
 69            {
 70                historyItem.Undo();
 71            }
 72            lstHistory.Items.Remove(item);
 73        }
 74 
 75         private void UndoCommand_CanExecuted(object sender, CanExecuteRoutedEventArgs e)
 76        {
 77             if (lstHistory == null || lstHistory.Items.Count == 0)
 78            {
 79                 e.CanExecute = false;
 80            }
 81             else
 82            {
 83                 e.CanExecute = true;
 84            }
 85        }
 86    }
 87 
 88     public class CommandHistoryItem
 89    {
 90         public String CommandName { get; set; }
 91         public UIElement ElementActedOn { get; set; }
 92 
 93         public string PropertyActedOn { get; set; }
 94 
 95         public object PreviousState { get; set; }
 96 
 97         public bool CanUndo
 98        {
 99             get { return (ElementActedOn != null && PropertyActedOn != ""); }
100        }
101 
102         public void Undo()
103        {
104             Type elementType = ElementActedOn.GetType();
105             PropertyInfo property = elementType.GetProperty(PropertyActedOn);
106             property.SetValue(ElementActedOn, PreviousState, null);
107        }
108    }
109 }
```


　　其对应的XAML界面设计代码如下所示：

```
<Window x:Class="WPFCommand.CommandsMonitor"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="CommandsMonitor" Height="300" Width="350"
        xmlns:local="clr-namespace:WPFCommand"
        Unloaded="window_Unloaded">
    <Window.CommandBindings>
        <CommandBinding Command="local:CommandsMonitor.Undo"
                        Executed="UndoCommand_Executed"
                        CanExecute="UndoCommand_CanExecuted"/>
    </Window.CommandBindings>
    <Grid>
        <Grid.RowDefinitions>
            <RowDefinition Height="Auto"></RowDefinition>
            <RowDefinition></RowDefinition>
            <RowDefinition></RowDefinition>
            <RowDefinition></RowDefinition>
        </Grid.RowDefinitions>
        <ToolBarTray Grid.Row="0">
            <ToolBar>
                <Button Command="ApplicationCommands.Cut">Cut</Button>
                <Button Command="ApplicationCommands.Copy">Copy</Button>
                <Button Command="ApplicationCommands.Paste">Paste</Button>
            </ToolBar>
            <ToolBar>
                <Button Command="local:CommandsMonitor.Undo">Reverse Last Command</Button>
            </ToolBar>
        </ToolBarTray>

        <TextBox Margin="5" Grid.Row="1"
             TextWrapping="Wrap" AcceptsReturn="True">
        </TextBox>
        <TextBox Margin="5" Grid.Row="2"
             TextWrapping="Wrap" AcceptsReturn="True">
        </TextBox>

        <ListBox Grid.Row="3" Name="lstHistory" Margin="5" DisplayMemberPath="CommandName"></ListBox>
    </Grid>
</Window>
```

　　上面程序的运行效果如下图所示：

七、小结
 　　到这里，WPF命令的内容就介绍结束了，关于命令主要记住命令模型四要素——命令、命令绑定、命令源和命令目标。后面继续为大家分享WPF的资源和样式的内容。


## WPF快速入门系列(6)——WPF资源和样式
一、引言
 　　WPF资源系统可以用来保存一些公有对象和样式，从而实现重用这些对象和样式的作用。而WPF样式是重用元素的格式的重要手段，可以理解样式就如CSS一样，尽管我们可以在每个控件中定义格式，但是如果多个控件都应用了多个格式的时候，我们就可以把这些格式封装成格式，然后在资源中定义这个格式，之前如果用到这个格式就可以直接使用这个样式，从而达到重用格式的手段。从中可以发现，WPF资源和WPF样式是相关的，我们经常把样式定义在资源中。
二、WPF资源详解
2.1 资源基础介绍
　　尽管可以在代码中创建和操作资源，但是通常都是以XAML标签的形式定义资源的。下面具体看看如何去定义一个资源，具体的XAML代码如下所示：
```
<Window x:Class="ResourceDemo.ResourceUse"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="REsource" Height="100" Width="350"
        xmlns:sys="clr-namespace:System;assembly=mscorlib">
   <Window.Resources>
        <!--定义一个字符串资源-->
        <sys:String x:Key="nameStr">
            LearningHard博客：http://www.cnblogs.com/zhili/
        </sys:String>
    </Window.Resources>
    <StackPanel>
        <!--通过资源key来对资源进行使用-->
        <TextBlock Text="{StaticResource nameStr}" Margin="10"/>
    </StackPanel>
</Window>
```

　　每一个元素都有一个Resources属性，该属性存储了一个资源字典集合。关于资源字典将会在下面部分介绍。尽管每个元素都提供了Resources属性，但通常在窗口级别上定义资源，就如上面XAML代码所示的那样。因为每个元素都可以访问它自己的资源集合中的资源，也可以访问所有父元素的资源集合中的资源。
2.2 静态资源和动态资源区别
 　　为了使用XAML标记中的资源，需要一种引用资源的方法，可以通过两个标记来进行引用资源：一个用于静态资源，另一个用于动态资源。在上面的XAML中，我们引用的方式就是静态资源的引用方式，因为我们指定了StaticResource。那静态资源和动态资源有什么区别呢？
　　对于静态资源在第一次创建窗口时，一次性地设置完毕；而对于动态资源，如果发生了改变，则会重新应用资源。下面通过一个示例来演示下他们之间的区别。具体的XAML代码如下所示：
```
<Window x:Class="ResourceDemo.DynamicResource"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="DynamicResource" Height="300" Width="300">
    <Window.Resources>
        <SolidColorBrush x:Key="RedBrush" Color="Red"></SolidColorBrush>
    </Window.Resources>
    <StackPanel Margin="5">
    　　<Button Background="{StaticResource RedBrush}" Margin="5" FontSize="14" Content="Use a Static Resource"/>
        <Button Background="{DynamicResource RedBrush}" Margin="5" FontSize="14" Content="Use a Dynamic Resource"/>
        <Button Margin="5" FontSize="14" Content="Change the RedBrush to Yellow" Click="ChangeBrushToYellow_Click"/>
    </StackPanel>
</Window>
```

　　对应改变资源按钮的后台代码如下所示：
```
private void ChangeBrushToYellow_Click(object sender, RoutedEventArgs e)
        {
            // 改变资源
            this.Resources["RedBrush"] = new SolidColorBrush(Colors.Yellow);
        }
　　运行上面程序，你将发现，当点击Change按钮之后，只改变了动态引用资源按钮的背景色，而静态引用按钮的背景却没有发生改变，具体效果图如下所示：
```

2.3 资源字典
　　在前面中讲到，每个Resources属性存储着一个资源字典集合。如果希望在多个项目之间共享资源的话，就可以创建一个资源字典。资源字段是一个简单的XAML文档，该文档就是用于存储资源的，可以通过右键项目->添加资源字典的方式来添加一个资源字典文件。下面具体看下如何去创建一个资源字典。具体的XAML代码如下：
```
<ResourceDictionary xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
                    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml">
    <SolidColorBrush x:Key="blueBrush" Color="Blue"/>
    <FontWeight x:Key="fontWeight">Bold</FontWeight>
</ResourceDictionary>
```

　　为了使用资源字典，需要将其合并到应用程序中资源集合位置，当然你也可以合并到窗口资源集合中，但是通常是合并到应用程序资源集合中，因为资源字典的目的就是在于多个窗体中共享，具体的XAML代码如下所示：
```
<Application x:Class="ResourceDemo.App"
             xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
             xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
             StartupUri="DynamicResource.xaml">
    <Application.Resources>
        <!--合并资源字典到Application.Resources中-->
        <ResourceDictionary>
            <ResourceDictionary.MergedDictionaries>
                <ResourceDictionary Source="Generic.xaml"/>
            </ResourceDictionary.MergedDictionaries>
        </ResourceDictionary>
    </Application.Resources>
```
 

　　那怎样使用资源字典中定义的资源呢？其使用方式和引用资源的方式是一样的，一样是通过资源的Key属性来进行引用的，具体使用代码如下所示：
```
<Window x:Class="ResourceDemo.ResourceUse"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="REsource" Height="100" Width="350"
        xmlns:sys="clr-namespace:System;assembly=mscorlib">
    <Window.Resources>
        <!--定义一个字符串资源-->
        <sys:String x:Key="nameStr">
            LearningHard博客：http://www.cnblogs.com/zhili/
        </sys:String>
    </Window.Resources>
    <StackPanel>
       <!--使用资源字典中定义的资源-->
        <Button  Margin="10" Background="{StaticResource blueBrush}" Content="Blue Button" FontWeight="{StaticResource fontWeight}"/>
        <!--通过资源key来对资源进行使用-->
        <TextBlock Text="{StaticResource nameStr}" Margin="10"/>
    </StackPanel>
</Window>
```

　　此时的运行效果如下图所示：

　　前面只是介绍在当前应用程序下共享资源可以把资源字典合并到应用程序资源集合中，如果想在多个应用程序共享资源怎么办呢？最简单的方法就是在每个应用程序中拷贝一份资源字典的XAML文件，但是这样不能对版本进行控制，显然这不是一个好的办法。更好的办法是将资源字典编译到一个单独的类库程序集中，应用程序可以通过引用程序集的方式来共享资源。这样就达到了在多个应用程序中共享资源的目的。
　　使用这种方式面临着另一个问题，即如何获得所需要的资源并在应用程序中使用资源。对此，可以采用两种方法。第一种办法是通过代码创建一个ResourceDictionary对象，再通过指定其Source属性来定位程序中资源字典文件，一旦创建了ResourceDictionary对象，就可以通过key来检索对应的资源，具体的实现代码如下：
 ResourceDictionary resourceDic = new ResourceDictionary();
            // ReusableDictionary.xaml是资源字典文件
            resourceDic.Source = new Uri("ResourceLibrary;component/ReusableDictionary.xaml", UriKind.Relative);
            SolidColorBrush blueBrush =(SolidColorBrush)resourceDic["BlueBrush"];
　　这种方式不需要手动指定资源，当加载一个新的资源字典时，窗口中所有的DynamicResource引用都会自动引用新的资源，这样的方式可以用来构建动态的皮肤功能。
　　另外一种办法可以使用ComponentResourceKey标记，使用ComponentResourceKey为资源创建键名。具体使用例子请参看博文：Defining and Using Shared Resources in a Custom Control Library。
三、WPF样式详解
　　在前面介绍了WPF资源，使用资源可以在一个地方定义对象而在整个应用程序中重用它们，除了在资源中可以定义各种对象外，还可以定义样式，从而达到样式的重用。
　　样式可以理解为元素的属性集合。与Web中的CSS类似。WPF可以指定具体的元素类型为目标，并且WPF样式还支持触发器，即当一个属性发生变化的时，触发器中的样式才会被应用。
3.1 WPF样式使用
　　之前WPF资源其实完全可以完成WPF样式的功能，只是WPF样式对资源中定义的对象进行了封装，使其存在于样式中，利于管理和应用，我们可以把一些公共的属性定义放在样式中进行定义，然后需要引用这些属性的控件只需要引用具体的样式即可，而不需要对这多个属性进行分别设置。下面XAML代码就是一个样式的使用示例：

```
<Window x:Class="StyleDemo.StyleDefineAndUse"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="MainWindow" Height="300" Width="400">
    <Window.Resources>
        <!--定义样式-->
        <Style TargetType="Button">
            <Setter Property="FontFamily" Value="Times New Roman" />
            <Setter Property="FontSize" Value="18" />
            <Setter Property="FontWeight" Value="Bold" />
        </Style>
    </Window.Resources>
    <StackPanel Margin="5">
        <!--由于前面定义的样式没有定义key标记,如果没有显示指定Style为null，这按钮将指定引用事先定义的样式-->
        <Button Padding="5" Margin="5">Customized Button</Button>
        <TextBlock Margin="5">Normal Content.</TextBlock>
        <!--使其不引用事先定义的样式-->
        <Button Padding="5" Margin="5" Style="{x:Null}">A Normal Button</Button>
    </StackPanel>
</Window>
```

　　具体的运行效果如下图所示：

　　当样式中没有定义key标记时，则对应的样式会指定应用到目标对象上，上面XAML代码就是这种情况，如果显式为样式定义了key标记的话，则必须显式指定样式Key的方式，对应的样式才会被应用到目标对象上，下面具体看看这种情况。此时XAML代码如下所示：


```
<Window x:Class="StyleDemo.ReuseFontWithStyles"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="ReuseFontWithStyles" Height="300" Width="300">
    <Window.Resources>
        <!--带有key标签的样式-->
        <Style TargetType="Button" x:Key="BigButtonStyle">
            <Setter Property="FontFamily" Value="Times New Roman" />
            <Setter Property="FontSize" Value="18" />
            <Setter Property="FontWeight" Value="Bold" />
        </Style>
    </Window.Resources>
    <StackPanel Margin="5">
        <!--如果不显式指定样式key将不会应用样式-->
        <Button Padding="5" Margin="5">Normal Button</Button>
        <Button Padding="5" Margin="5" Style="{StaticResource BigButtonStyle}">Big Button</Button>
        <TextBlock Margin="5">Normal Content.</TextBlock>
        <!--使其不引用事先定义的样式-->
        <Button Padding="5" Margin="5" Style="{x:Null}">A Normal Button</Button>
    </StackPanel>
</Window>
```

　　此时运行效果如下图所示：

3.2 样式触发器
　　WPF样式还支持触发器，在样式中定义的触发器，只有在该属性或事件发生时才会被触发，下面具体看看简单的样式触发器是如何定义和使用的，具体的XAML代码如下所示：

```
<Window x:Class="StyleDemo.SimpleTriggers"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="SimpleTriggers" Height="300" Width="300">
    <Window.Resources>
        <Style x:Key="BigFontButton">
            <Style.Setters>
                <Setter Property="Control.FontFamily" Value="Times New Roman" />
                <Setter Property="Control.FontSize" Value="18" />

            </Style.Setters>
            <!--样式触发器-->
            <Style.Triggers>
                <!--获得焦点时触发-->
                <Trigger Property="Control.IsFocused" Value="True">
                    <Setter Property="Control.Foreground" Value="Red" />
                </Trigger>
                <!--鼠标移过时触发-->
                <Trigger Property="Control.IsMouseOver" Value="True">
                    <Setter Property="Control.Foreground" Value="Yellow" />
                    <Setter Property="Control.FontWeight" Value="Bold" />
                </Trigger>
                <!--按钮按下时触发-->
                <Trigger Property="Button.IsPressed" Value="True">
                    <Setter Property="Control.Foreground" Value="Blue" />
                </Trigger>
            </Style.Triggers>
        </Style>
    </Window.Resources>

    <StackPanel Margin="5">
        <Button Padding="5" Margin="5"
            Style="{StaticResource BigFontButton}" 
              >A Big Button</Button>
        <TextBlock Margin="5">Normal Content.</TextBlock>
        <Button Padding="5" Margin="5"
            >A Normal Button</Button>
    </StackPanel>
</Window>
```

　　此时的运行效果如下图所示：

　　上面定义的触发器都是在某个属性发生变化时触发的，也可以定义当某个事件激活时的触发器，我们也把这样的触发器称为事件触发器，下面示例定义的事件触发器是等待MouseEnter事件，一旦触发MouseEnter事件，则动态改变按钮的FontSize属性来形成动画效果，具体的XAML代码如下所示：

```
<Window x:Class="StyleDemo.EventTrigger"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="EventTrigger" Height="300" Width="300">
    <Window.Resources>
        <Style x:Key="BigFontButton">
            <Style.Setters>
                <Setter Property="Control.FontFamily" Value="Times New Roman" />
                <Setter Property="Control.FontSize" Value="18" />
                <Setter Property="Control.FontWeight" Value="Bold" />
            </Style.Setters>
            <Style.Triggers>
                <!--定义事件触发器-->
                <EventTrigger RoutedEvent="Mouse.MouseEnter">
                    <!--事件触发时只需的操作-->
                    <EventTrigger.Actions>
                        <!--把动画放在动画面板中-->
                        <BeginStoryboard>
                            <!--在0.2秒的时间内将字体放大到22单位-->
                            <Storyboard>
                                <DoubleAnimation
                  Duration="0:0:0.2"
                  Storyboard.TargetProperty="FontSize"
                  To="22"  />
                            </Storyboard>
                        </BeginStoryboard>
                    </EventTrigger.Actions>
                </EventTrigger>
                <!--鼠标移开触发的事件-->
                <EventTrigger RoutedEvent="Mouse.MouseLeave">
                    <EventTrigger.Actions>
                        <BeginStoryboard>
                            <!--在1秒的时间内将字体尺寸缩小到原来的大小-->
                            <!--如果目标字体尺寸没有明确指定，则WPF将默认使用第一次动画之前按钮的字体尺寸-->
                            <Storyboard>
                                <DoubleAnimation
                  Duration="0:0:1"
                  Storyboard.TargetProperty="FontSize"  />
                            </Storyboard>
                        </BeginStoryboard>
                    </EventTrigger.Actions>
                </EventTrigger>
            </Style.Triggers>
        </Style>     
    </Window.Resources>
    <StackPanel Margin="5">
        <Button Padding="5" Margin="5"
            Style="{StaticResource BigFontButton}" 
              >A Big Button</Button>
        <TextBlock Margin="5">Normal Content.</TextBlock>
        <Button Padding="5" Margin="5"
            >A Normal Button</Button>
    </StackPanel>
</Window>
```


　　此时的运行效果如下图所示：



## WPF快速入门系列(7)——深入解析WPF模板
一、引言
 　　模板从字面意思理解是“具有一定规格的样板"。在现实生活中，砖块都是方方正正的，那是因为制作砖块的模板是方方正正的，如果我们使模板为圆形的话，则制作出来的砖块就是圆形的，此时我们并不能说圆形的”砖块“不是砖块吧。因为形状只是它们的外观，其制作材料还是一样的。所以，模板可以理解为表现形式。WPF中的模板同样是表现形式的意思。
　　在WPF中包括三种模板：控件模板、数据模版和面板模板。它们都继承于FrameworkTemplate基类，其继承层次结果如下图所示：

　　从上图可以发现，FrameworkTemplate确实有三个子类，它们正是WPF中支持的三种模板。对于控件模板，即控件外观外衣，可以通过修改控件模板来自定义控件的外观表现，例如，可以通过修改按钮的控件模板使按钮表现为圆形；数据模板，即数据的外衣。用于从一个对象中提取数据，并在内容控件或列表控件的各个项中显示数据。面板模板即面板的外衣，而面板又用于进行布局的，所以面板的外衣也就是布局的外衣，通过修改面板模板可以自定义控件的布局。例如，ListBox默认是自从向下地显示每一项的，此时可以通过修改面板模板使其自左向右地显示每一项。
　　WPF模板其实都是外观的表现形式，不管是控件模板、数据模板还是面板模板，其都是改变控件的表现形式。只不过这三种控件的作用点不一样罢了。控件模板是针对于控件本身，修改它可以改变控件本身表现的样子；数据模板针对控件的数据，修改它可以改变控件绑定的数据表现样子。既然是决定数据的表现，从而决定其一般应用于数据绑定控件，如ListBox、ListView等控件。面板模板则针对于控件的布局，修改它可以影响控件的布局方式。
二、控件模板
　　在分别介绍这三种控件模板之前，我觉得你有必要先了解WPF的逻辑树和可视化树的内容，因为你要修改控件模板，则首先需要了解控件的组成。
2.1 WPF的逻辑树和可视化树
　　在许多技术中，元素和组件都是按树结构的形式进行组织的。使用这样的结构，开发人员可以直接操作树中的对象节点来程序对象，从而通过操作该对象来修改程序的表现和行为（这是了解逻辑树和可视化树的主要原因）。在WPF中，同样使用了树结构来组织元素之间的关系。WPF中支持逻辑树和可视化树的概念，并且WPF公开了两个提供树形视图帮助器类：LogicalTreeHelper 和 VisualTreeHelper。逻辑树指的是UI界面的组成元素的结构。先看下面的XAML代码的例子：
```
<Window x:Class="TemplateDemo.VisualTree"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="MainWindow" Height="200" Width="300">
    <StackPanel Margin="5">
        <Button Padding="5" Margin="10">First Button</Button>
        <Button Padding="5" Margin="10">Second Button</Button>
    </StackPanel>
</Window>
```
　　上面XAML的逻辑树如下图所示：

　　可视化树是逻辑树的扩展版本，它将元素分成更小的部分。上面XAML代码对应的可视化树如下图所示：

　　从上面可视化树可以看出，Button由多个可视化元素组成——使按钮具有阴影背景特征的边框(由ButtonChrome类表示)、内部的容器(一个ContentPresenter对象)以及存储按钮文本的文本块控件(由TextBlock表示)。上面的可视化树和逻辑树结构并不是我凭空想象出来的，而是有事实依据的，我们可以通过VisualTreeHelper类和LogicTreeHelper类提供的方法来查看窗口的可视化树和逻辑树，下面的例子实现了这个需求，具体的XAML实现如下所示：
```
<Window x:Class="TemplateDemo.Window1"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="MainWindow" Height="380" Width="400">
    <StackPanel Margin="5">
        <Button Padding="5" Margin="5" Click="ShowLogicTree">Show Logic Tree Button</Button>
        <Button Padding="5" Margin="5" Click="ShowVisualTree">Show Visual Tree Button</Button>
        <!--TreeView控件用来显示窗口的逻辑树和可视化树-->
        <TreeView Name="treeElements" Margin="5"></TreeView>
    </StackPanel>
</Window>
```
　　对应的后台代码实现入下所示：
```
public partial class Window1 : Window
    {
        public Window1()
        {
            InitializeComponent();
        }

        // 把公共代码抽象出一个方法，从而使代码重用
        public void ProcessElement(object obj, TreeViewItem item, TreeViewItem previousItem)
        {         
            item.Header = obj.GetType().Name;
            item.IsExpanded = true;

            // 如果当前元素是第一个元素就添加到树集合上
            // 如果是内嵌元素，则添加到它的父节点上
            if (previousItem == null)
            {
                treeElements.Items.Add(item);
            }
            else
            {
                previousItem.Items.Add(item);
            }
        }

        private void PrintLogicTree(object obj, TreeViewItem previousItem)
        {
            TreeViewItem item = new TreeViewItem();
            ProcessElement(obj, item, previousItem);

            // 如果不是DependencyObject，则返回
            if (!(obj is DependencyObject))
                return;

            // 递归打印逻辑树
            foreach(object child in LogicalTreeHelper.GetChildren(obj as DependencyObject))
            {
                // 这里为了避免死循环，因为TreeView的子元素包含Window1、StackPanel等控件
                // 如果不加这个条件，控件会一直反复循环
                if (child is TreeView)
                    return;
                PrintLogicTree(child, item);
            }
        }

        private void PrintVisualTree(DependencyObject obj, TreeViewItem previousItem)
        {
            TreeViewItem item = new TreeViewItem();
            ProcessElement(obj, item, previousItem);

            //  递归输出视觉树
            for (int i = 0; i < VisualTreeHelper.GetChildrenCount(obj); i++)
            {
                if (obj is TreeView)
                    return;

                PrintVisualTree(VisualTreeHelper.GetChild(obj, i), item);
            }
        }

        private void ShowLogicTree(object sender, RoutedEventArgs e)
        {
            treeElements.Items.Clear();
            PrintLogicTree(this, null);
        }

        private void ShowVisualTree(object sender, RoutedEventArgs e)
        {
            treeElements.Items.Clear();
            PrintVisualTree(this, null);
        }

    }
```
　　程序的运行效果如下图所示：

2.2 通过控件模板自定义控件外观
　　控件模板既然是控件的外衣，自然我们可以创建的新的控件模板，然后把新的控件模板应用到需要应用的控件中，这时候应用了新控件模板的控件，将会使用新的控件模板来渲染自身，从而改变控件的外观。这也是自定义控件外观的要旨。在WPF中按钮的默认控件是长方形的，我们可以通过创建一个新的控件模板来改变按钮的外观，下面的例子就实现了通过控件模板的方式自定义了一个圆形的按钮。具体的XAML代码如下所示：
```
<Window x:Class="TemplateDemo.ControlTemplate"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="ControlTemplate" Height="300" Width="300">
    <Window.Resources>
        <!--定义控件模板，并使用key标记-->
        <ControlTemplate x:Key="roundButtonTemplate" TargetType="Button">
            <Grid>
                <Ellipse Name="ell" Fill="Orange" Width="100" Height="100"></Ellipse>
                <!--使用模板绑定来绑定按钮的内容-->
                <ContentPresenter Content="{TemplateBinding Button.Content}" VerticalAlignment="Center" HorizontalAlignment="Center"></ContentPresenter>
            </Grid> 
            <!--定义模板触发器-->
            <ControlTemplate.Triggers>
                <Trigger Property="IsMouseOver" Value="True">
                    <Setter TargetName="ell"  Property="Fill" Value="Yellow"/>
                </Trigger>
            </ControlTemplate.Triggers>
        </ControlTemplate>
    </Window.Resources>
    <StackPanel Margin="10">
        <Button Content="Round Button" Template="{StaticResource roundButtonTemplate}"></Button>
    </StackPanel>
</Window>
```
　　此时，你就可以看到按钮是一个圆形的了，并且当鼠标移动到按钮上时，会触发模板触发器来改变Ellipse的填充色，具体的运行效果如下图所示：

　　从上面的控件模板的使用可知，它和创建自定义控件不同，在很多情况下，你不需要编写自己的控件，你只是希望更改控件的外观。使用控件面板非常简单：
首先在资源集合中创建一个ControlTemplate，并指定key标记
然后赋值到控件的Template属性中。　　
三、数据模板
　　数据模板是数据的外衣，数据模板是一段定义如何绑定数据对象的XAML标记，有两种类型的控件支持数据模板：
内容控件通过ContentTemplate属性支持数据模板。内容模板用于显示任何放在Content属性中的内容。
列表控件，即继承自ItemsControl类的控件，通过ItemPlate属性支持数据模板。该模板用于显示由ItemSource提供集合中的每一项。
　　基于列表的模板实际上是以内容控件模板为基础的，因为列表中的每一项由一个内容控件包装的。如ListBox控件的ListBoxItem元素。下面让我们具体看看如何去创建一个数据模板吧。
3.1 如何定义数据模板
　　具体的XAML代码如下所示：
```
<Window x:Class="TemplateDemo.DataTemplate"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:local ="clr-namespace:TemplateDemo;assembly=TemplateDemo"
        Title="DataTemplate" Height="300" Width="300">
    <Window.Resources>
        <!--创建数据模板-->
        <DataTemplate x:Key="personDataTem">
            <Border Name="blueBorder" Margin="3" BorderThickness="3" BorderBrush="Blue"
              CornerRadius="5">
                <Grid Margin="3">
                    <Grid.RowDefinitions>
                        <RowDefinition></RowDefinition>
                        <RowDefinition></RowDefinition>
                    </Grid.RowDefinitions>
                    <TextBlock Name="nametxt" FontWeight="Bold" Text="{Binding Path=Name}"></TextBlock>
                    <TextBlock Grid.Row="1" Text="{Binding Path=Age}"></TextBlock>
                </Grid>
            </Border>
            <!--定义数据模板触发器-->
            <DataTemplate.Triggers>
                <Trigger SourceName="blueBorder" Property="IsMouseOver" Value="True">
                    <Setter TargetName="blueBorder" Property="Background" Value="LightGray"/>
                    <Setter TargetName="nametxt" Property="FontSize" Value="20"/>
                </Trigger>
            </DataTemplate.Triggers>
        </DataTemplate>
    </Window.Resources>
    <StackPanel Margin="5">
        <ListBox Name="lstPerson" HorizontalContentAlignment="Stretch" ItemTemplate="{StaticResource personDataTem}"></ListBox>
    </StackPanel>
</Window>
```
　　其对应的后台代码如下所示：

```
public partial class DataTemplate : Window
    {
        ObservableCollection<Student> persons = new ObservableCollection<Student>() 
        { 
            new Student() { Name ="LearningHard", Age=25},
            new Student() { Name ="HelloWorld", Age=22}
        };
        public DataTemplate()
        {
            InitializeComponent();

            lstPerson.ItemsSource = persons;
        }
    }

public class Student : INotifyPropertyChanged
    {
        public string ID { get { return Guid.NewGuid().ToString(); } }

        public string Name { get; set; }

        public int Age { get; set; }


        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged(PropertyChangedEventArgs e)
        {
            if (PropertyChanged != null)
                PropertyChanged(this, e);
        }
    }
```
　　其运行效果如下图所示：

　　从上面数据模板的创建可知，使用DataTemplate很简单：
首先在资源集合中创建一个数据模板，并设置key标签。
然后将key赋值到控件的CellTemplate或ContentTemplate或ItemTemplate属性上即可。
3. 2 数据模板与控件模板的关系
　　从上面的介绍可知，控件只是数据和行为的载体，至于它本身长什么样子和数据长什么样子都是靠Template决定的。决定控件外观的是ControlTemplate，决定数据外观的是DataTemplate，它们正是Control类的Template和ContentTemplate两个属性的值。
　　一般来说，ControlTemplate内都有一个ContentPresenter，这个ContentPresenter的ContentTemplate就是DataTemplate类型。所以数据模板和控件模板的关系如下图所示：

四、创建面板模板
　　ItemsPanelTemplate用于指定项的布局。 ItemsControl 类型具有一个类型为ItemsPanelTemplate 的 ItemsPanel 属性。
　　每种ItemsControl都有其默认的ItemsPanelTemplate。对于 ListBox，默认值使用 VirtualizingStackPanel。 对于 MenuItem，默认值使用 WrapPanel。 对于 StatusBar，默认值使用 DockPanel。
　　自定义面板模板与自定义数据面板和数据面板一样简单，一样只需要首先定义一个面板模板在资源集合中，然后将其Key指定给ItemsPanel属性即可。具体的XAML实现如下所示：
```
<Window x:Class="TemplateDemo.ItemsPanelTemplate"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        Title="ItemsPanelTemplate" Height="300" Width="300">
    <Window.Resources>
        <!--定义DataTemplate-->
        <DataTemplate x:Key="personDataTem">
            <Border Name="blueBorder" Margin="3" BorderThickness="3" BorderBrush="Blue"
              CornerRadius="5">
                <Grid Margin="3">
                    <Grid.RowDefinitions>
                        <RowDefinition></RowDefinition>
                        <RowDefinition></RowDefinition>
                    </Grid.RowDefinitions>
                    <TextBlock Name="nametxt" FontWeight="Bold" Text="{Binding Path=Name}"></TextBlock>
                    <TextBlock Grid.Row="1" Text="{Binding Path=Age}"></TextBlock>
                </Grid>
            </Border>
        </DataTemplate>
        <!--定义ItemsPanelTemplate-->
        <ItemsPanelTemplate x:Key="listItemsPanelTem">
            <StackPanel Orientation="Horizontal"
                    VerticalAlignment="Center"
                    HorizontalAlignment="Left"/>
        </ItemsPanelTemplate>
    </Window.Resources>
    
    <!--使用ItemsPanelTemplate只需要赋值给ItemsPanel属性即可-->
    <ListBox Name="lstPerson" ItemsPanel="{StaticResource listItemsPanelTem}" ItemTemplate="{StaticResource personDataTem}" />
</Window>
```
　　其后台代码和数据模板的后台代码一样，其实现代码为：
```
public partial class ItemsPanelTemplate : Window
    {
        ObservableCollection<Student> persons = new ObservableCollection<Student>() 
        { 
            new Student() { Name ="LearningHard", Age=25},
            new Student() { Name ="HelloWorld", Age=22}
        };
        public ItemsPanelTemplate()
        {
            InitializeComponent();
            lstPerson.ItemsSource = persons;
        }
    }
```
　　此时程序运行的效果如下图所示，从下图结果可以看出，此时ListBox中的项不再是自上而下排列了，而是从左向右排列的。

五、总结
　　到这里，WPF模板的内容就介绍结束了，本文主要介绍了WPF中支持的三种模板：控件模板、数据模板和面板模板，然后各自定义并使用了自定义的模板，最后介绍了这三个模板之间的联系。使用这三个模板的方式都非常简单，都是先定义一个模板，然后在把对应的key应用到控件对应的属性中，对于控件模板，应用的是控件的Template，对于数据模板，应用的是控件的ItemTemplate属性，对于面板模板，应用的是控件的ItemsPanel属性。在下面的一篇博文将介绍如何实现一个MVVM的实例程序。



## WPF快速入门系列(8)——MVVM快速入门
一、引言
　　在前面介绍了WPF一些核心的内容，其中包括WPF布局、依赖属性、路由事件、绑定、命令、资源样式和模板。然而，在WPF还衍生出了一种很好的编程框架，即WVVM，在Web端开发有MVC，在WPF客户端开发中有MVVM，其中VM就相当于MVC中C(Control)。在Web端，微软开发了Asp.net MVC这样的MVC框架，同样在WPF领域，微软也开发了Prism这样的MVVM框架。Prism项目地址是：http://compositewpf.codeplex.com/SourceControl/latest。大家有兴趣的可以下载源码研究下。
　　本文所有源码下载：FristMVVMProject.zip
二、MVVM模式是什么？
　　既然讲到MVVM模式，自然第一个问题就是MVVM的含义。MVVM是Model-View-ViewModel的缩写形式，它通常被用于WPF或Silverlight开发。这三者之间的关系如下图所示：

　　下面我们分别来介绍下这三部分。
模型(Model)
　　Model——可以理解为带有字段，属性的类。
视图(View)
　　View——可以理解为我们所看到的UI。
视图模型(View Model)
View Model在View和Model之间，起到连接的作用，并且使得View和Model层分离。View Model不仅仅是Model的包装，它还包含了程序逻辑，以及Model扩展，例如，如果Model中有一个公开属性不需要在UI上显示，此时我们可以不再View Model中去定义它。
在MVVM模式下，WPF程序的运行流程如下图所示：

 
　　在MVVM中，VM的地位可以说是举足轻重。使用MVVM模式具有以下几个特点：
视图的cs文件包括极少的代码，其核心逻辑都被放在View Model类中，从而使得程序逻辑与视图耦合度降低。
ViewModel类作为View的DataContext。
在MVVM下，所有的事件和动作都被当成命令，如按钮的点击操作，此时不是触发点击事件，而是绑定到一个点击命令，再由命令去执行对应的逻辑。
三、使用MVVM模式来实现WPF程序
　　前面介绍了MVVM一些基础知识，下面通过一个实例来说明下如何在WPF程序中应用MVVM模式。在之前实现WPF程序时，我们可能会把所有的后台逻辑都放在视图的后台文件中，这样的实现方式的好处更直观，方便，对于一些小的应用程序这样做当然没什么问题，但是对于复杂的应用程序这样写的话，可能会导致后台代码显得非常臃肿，到最好变得难以维护。此时想到的解决方案就是职责分离，使后台的逻辑分离到其他类中，MVVM其实我理解就是达到这个目的。下面我们按照MVVM的组成部分来实现下这个MVVM程序。
　　第一步：自然是数据部分了，即Model层的实现。在这里定义了一个Person类，其中包含了2个基本的属性。
```
public class Person
    {
        public string Name { get; set; }
        public int Age { get; set; }
    }
```
　　为了进行测试，下面创建一个静态方法来获得测试数据。
```
public class PersonDataHelper
    {
        public static ObservableCollection<Person> GetPersons()
        {
            ObservableCollection<Person> samplePersons = new ObservableCollection<Person>();
            samplePersons.Add(new Person() {Name = "张三", Age = 33});
            samplePersons.Add(new Person() { Name ="王五", Age= 22 });
            samplePersons.Add(new Person() { Name = "李四", Age = 35 });
            samplePersons.Add(new Person() { Name = "LearningHard", Age = 27 });
            return samplePersons;
        }
    }
```
　　第二步：实现ViewModel层，实现数据和界面之间的逻辑。在视图模型类中，包含了属性和命令，因为在MVVM中，事件都当成命令来进行处理，其中命令只能与具有Command属性的控件进行绑定。既然要包含命令，首先就需要实现一个命令，这里自定义的命令需要实现ICommand接口。这里我们定义了一个QueryCommand。具体的实现代码如下所示：
```
public class QueryCommand :ICommand
    {
        #region Fields
        private Action _execute;
        private Func<bool> _canExecute;
        #endregion 

        public QueryCommand(Action execute)
            : this(execute, null)
        { 
        }
        public QueryCommand(Action execute, Func<bool> canExecute)
        {
            if (execute == null)
                throw new ArgumentNullException("execute");
            _execute = execute;
            _canExecute = canExecute;
        }

        #region ICommand Member

        public event EventHandler CanExecuteChanged
        {
            add
            {
                if (_canExecute != null)
                {
                    CommandManager.RequerySuggested += value;

                }
            }
            remove
            {
                if (_canExecute != null)
                {
                    CommandManager.RequerySuggested -= value;

                }
            }
        }

        public bool CanExecute(object parameter)
        {
            return _canExecute == null ? true : _canExecute();
        }

        public void Execute(object parameter)
        {
            _execute();
        }
        #endregion
    }
```
　　接下来就是定义我们的ViewModel类了，具体的实现代码如下所示：
```
1 public class PersonListViewModel : INotifyPropertyChanged
 2    {
 3         #region Fields
 4         private string _searchText;
 5         private ObservableCollection<Person> _resultList;
 6         #endregion 
 7 
 8         #region Properties
 9 
10         public ObservableCollection<Person> PersonList { get; private set; }
11 
12         // 查询关键字
13         public string SearchText
14        {
15             get { return _searchText; }
16             set
17            {
18                 _searchText = value;
19                 RaisePropertyChanged("SearchText");
20            }
21        }
22 
23         // 查询结果
24         public ObservableCollection<Person> ResultList
25        {
26             get { return _resultList; }
27             set
28            {
29                 _resultList = value;
30                 RaisePropertyChanged("ResultList");
31            }
32        }
33 
34         public ICommand QueryCommand 
35        { 
36             get { return new QueryCommand(Searching, CanSearching); } 
37        }
38 
39         #endregion 
40 
41         #region Construction
42         public PersonListViewModel()
43        {
44             PersonList = PersonDataHelper.GetPersons();
45             _resultList = PersonList;
46        }
47 
48         #endregion
49         
50         #region Command Handler
51         public void Searching()
52        {
53             ObservableCollection<Person> personList = null;
54             if (string.IsNullOrWhiteSpace(SearchText))
55            {
56                 ResultList = PersonList;
57            }
58             else
59            {
60                 personList = new ObservableCollection<Person>();
61                 foreach (Person p in PersonList)
62                {
63                     if (p.Name.Contains(SearchText))
64                    {
65                        personList.Add(p);
66                    }
67                }
68                 if (personList != null)
69                {
70                     ResultList = personList;
71                }
72            }
73        }
74 
75         public bool CanSearching()
76        {
77             return true;
78        }
79 
80         #endregion 
81 
82         #region INotifyPropertyChanged Members
83 
84         public event PropertyChangedEventHandler PropertyChanged;
85 
86         #endregion
87 
88         #region Methods
89         private void RaisePropertyChanged(string propertyName)
90        {
91             // take a copy to prevent thread issues
92             PropertyChangedEventHandler handler = PropertyChanged;
93             if (handler != null)
94            {
95                 handler(this, new PropertyChangedEventArgs(propertyName));
96            }
97        }
98         #endregion 
99     }
```
　　第三步：实现View层，设计我们的视图，设置它的DataContext属性为ViewModel类。具体的XAML代码如下所示：
```
<Window x:Class="MVVMDemo.View.PersonsView"
        xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
        xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
        xmlns:local="clr-namespace:MVVMDemo.ViewModel"
        Title="PersonsView" Height="350" Width="400">
    <!--设置DataContex是ViewModel类，当然你也可以使用后台代码设置-->
    <Window.DataContext>
        <local:PersonListViewModel />
    </Window.DataContext>
    <Grid>
        <Grid.RowDefinitions>
            <RowDefinition Height="50"/>
            <RowDefinition Height="*"/>
        </Grid.RowDefinitions>
        <TextBox Grid.Row="0" Name="searchtxt" Text="{Binding  Path=SearchText, Mode=TwoWay}" HorizontalAlignment="Left" Height="30" Width="280" Margin="10,0,0,0"></TextBox>
        <Button Grid.Row="0" Name="searchBtn" Content="Search" Command="{Binding Path=QueryCommand}" Width="80" Height="30" HorizontalAlignment="Right" Margin="0,0,10,0"></Button>
        <DataGrid Grid.Row="1" Name="datGrid" 
                  HorizontalAlignment="Center"
                  VerticalAlignment="Top" ItemsSource="{Binding Path=ResultList}" Width="300"></DataGrid>
        
    </Grid>
</Window>
```
　　到此，我们的MVVM的WPF程序就已经完成了，下面就是要看看程序是否达到我们预期的目的。具体的运行结果如下图所示：

四、总结
　　到这里，本文的内容就分享完了，并且本文也是WPF系列的最后一篇了，希望这个系列可以使得初学者快速上手WPF编程。在接下来的时间里，我打算写一些具有实战性的内容，因为我之前都是分享一些初级的入门系列，接下来打算分享一些实际的项目实现，以及领域驱动设计方面的内容，希望得到大家的督促和支持。
