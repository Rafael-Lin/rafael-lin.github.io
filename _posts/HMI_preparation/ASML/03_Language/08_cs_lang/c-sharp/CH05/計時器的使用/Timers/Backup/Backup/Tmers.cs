using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Timers
{
    public partial class Timers : Form
    {
        private const int INTERVAL = 1000;      //1秒
        private System.Timers.Timer TimersTimer = new System.Timers.Timer(INTERVAL);
        private System.Threading.Timer ThreadTimer = null;
        //这个委托用来在工作者线程中访问UI线程中创建的控件
        private delegate void OutputDelegate(DateTime time);
        public Timers()
        {
            InitializeComponent();
        }
        /// <summary>
        /// 启动定时器
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void START_Click(object sender, EventArgs e)
        {
            //先保证所有定时器停止
            WinformTimerStop();
            TimersTimerStop();
            ThreadTimerStop();
            if (TIMERSTIMER.Checked)
                TimersTimerStart();
            else if (FORMTIMER.Checked)
                WinformTimerStart();
            else
                ThreadTimerStart();
        }
        /// <summary>
        /// 使当前线程休眠一段时间
        /// </summary>
        private void SLEEP_Click(object sender, EventArgs e)
        {
            //睡眠5秒 
            OUTPUT.Text += "现在开始休眠5秒\r\n";
            System.Threading.Thread.Sleep(5 * 1000);
        }
        /// <summary>
        /// 停止所有定时器
        /// </summary>
        private void STOP_Click(object sender, EventArgs e)
        {
            //证所有定时器停止
            WinformTimerStop();
            TimersTimerStop();
            ThreadTimerStop();
        }
        /// <summary>
        /// 清空输出
        /// </summary>
        private void RESET_Click(object sender, EventArgs e)
        {
            OUTPUT.Text = "";
        }
    }
    /// <summary>
    /// Window.Form.Timer定时器的操作
    /// </summary>
    public partial class Timers : Form
    {
        /// <summary>
        /// 启动Windows.Form.Timer定时器
        /// </summary>
        private void WinformTimerStart()
        {
            WINDOWFORMTIMER.Interval = INTERVAL;
            WINDOWFORMTIMER.Tick += TimerHandler;
            WINDOWFORMTIMER.Start();
        }
        /// <summary>
        /// 停止Windows.Form.Timer定时器
        /// </summary>
        private void WinformTimerStop()
        {
            WINDOWFORMTIMER.Stop();
        }
        /// <summary>
        /// 回调方法
        /// </summary>
        /// <param name="sender">事件发送者</param>
        /// <param name="args">事件参数</param>
        private void TimerHandler(object sender, EventArgs args)
        {
            OUTPUT.Text += DateTime.Now.ToString() + sender.ToString() + "到时了\r\n";
        }
    }
    /// <summary>
    /// Timers.Timer定时器的操作
    /// </summary>
    public partial class Timers : Form
    {
        /// <summary>
        /// 启动Timers.Timer定时器
        /// </summary>
        private void TimersTimerStart()
        {
            TimersTimer.Elapsed += TimerHandler;
            //把当前窗体控件赋给Timers.Timer的同步对象属性，
            //以保证其回调方法能访问当前UI线程的控件
            TimersTimer.SynchronizingObject = this;
            TimersTimer.Start();
        }
        /// <summary>
        /// 停止Timers.Timer定时器
        /// </summary>
        private void TimersTimerStop()
        {
            TimersTimer.Stop();
        }
    }
    /// <summary>
    /// Threading.Timer定时器的操作
    /// </summary>
    public partial class Timers : Form
    {
        /// <summary>
        /// 启动Threading.Timer成员
        /// 当初始化结束后该定时器就立即启动
        /// </summary>
        private void ThreadTimerStart()
        {
            ThreadTimer = new System.Threading.Timer(
                new System.Threading.TimerCallback(ThreadTimerHandler),
            null, System.Threading.Timeout.Infinite,
            System.Threading.Timeout.Infinite);
            ThreadTimer.Change(INTERVAL, INTERVAL);
        }
        /// <summary>
        /// 如果Theading.Timer没有停止，则停止
        /// 这里停止使用的是把间隔时间设置为无限大
        /// Threading.Timer接口和其他两个定时器类型略有不同
        /// </summary>
        private void ThreadTimerStop()
        {
            if (ThreadTimer != null)
                ThreadTimer.Change(System.Threading.Timeout.Infinite,
                    System.Threading.Timeout.Infinite);
        }
        /// <summary>
        /// 实际执行Threading.Timer的方法
        /// </summary>
        /// <param name="time"></param>
        private void ThreadTimerHandlerUI(DateTime time)
        {
            OUTPUT.Text += time.ToString() +
                "System.Threading.Timer到时了\r\n";
        }
        /// <summary>
        /// Threading.Timer的回调方法，需要使用BeginInvoke方法来访问UI线程中的控件
        /// </summary>
        /// <param name="state">状态参数</param>
        private void ThreadTimerHandler(object state)
        {
            BeginInvoke(new OutputDelegate(ThreadTimerHandlerUI),
                DateTime.Now);
        }
    }
}