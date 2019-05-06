
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
