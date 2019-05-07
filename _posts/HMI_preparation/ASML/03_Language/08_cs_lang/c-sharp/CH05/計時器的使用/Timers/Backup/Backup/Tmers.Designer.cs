namespace Timers
{
    partial class Timers
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.START = new System.Windows.Forms.Button();
            this.SLEEP = new System.Windows.Forms.Button();
            this.STOP = new System.Windows.Forms.Button();
            this.GROUP = new System.Windows.Forms.GroupBox();
            this.THREADTIMER = new System.Windows.Forms.RadioButton();
            this.TIMERSTIMER = new System.Windows.Forms.RadioButton();
            this.FORMTIMER = new System.Windows.Forms.RadioButton();
            this.OUTPUT = new System.Windows.Forms.TextBox();
            this.WINDOWFORMTIMER = new System.Windows.Forms.Timer(this.components);
            this.RESET = new System.Windows.Forms.Button();
            this.GROUP.SuspendLayout();
            this.SuspendLayout();
            // 
            // START
            // 
            this.START.Location = new System.Drawing.Point(25, 19);
            this.START.Name = "START";
            this.START.Size = new System.Drawing.Size(75, 23);
            this.START.TabIndex = 0;
            this.START.Text = "启动";
            this.START.UseVisualStyleBackColor = true;
            this.START.Click += new System.EventHandler(this.START_Click);
            // 
            // SLEEP
            // 
            this.SLEEP.Location = new System.Drawing.Point(25, 48);
            this.SLEEP.Name = "SLEEP";
            this.SLEEP.Size = new System.Drawing.Size(75, 23);
            this.SLEEP.TabIndex = 1;
            this.SLEEP.Text = "休眠";
            this.SLEEP.UseVisualStyleBackColor = true;
            this.SLEEP.Click += new System.EventHandler(this.SLEEP_Click);
            // 
            // STOP
            // 
            this.STOP.Location = new System.Drawing.Point(25, 77);
            this.STOP.Name = "STOP";
            this.STOP.Size = new System.Drawing.Size(75, 23);
            this.STOP.TabIndex = 2;
            this.STOP.Text = "中止";
            this.STOP.UseVisualStyleBackColor = true;
            this.STOP.Click += new System.EventHandler(this.STOP_Click);
            // 
            // GROUP
            // 
            this.GROUP.Controls.Add(this.THREADTIMER);
            this.GROUP.Controls.Add(this.TIMERSTIMER);
            this.GROUP.Controls.Add(this.FORMTIMER);
            this.GROUP.Location = new System.Drawing.Point(115, 12);
            this.GROUP.Name = "GROUP";
            this.GROUP.Size = new System.Drawing.Size(180, 117);
            this.GROUP.TabIndex = 3;
            this.GROUP.TabStop = false;
            this.GROUP.Text = "定时器类型";
            // 
            // THREADTIMER
            // 
            this.THREADTIMER.AutoSize = true;
            this.THREADTIMER.Location = new System.Drawing.Point(6, 74);
            this.THREADTIMER.Name = "THREADTIMER";
            this.THREADTIMER.Size = new System.Drawing.Size(139, 17);
            this.THREADTIMER.TabIndex = 2;
            this.THREADTIMER.Text = "System.Threading.Timer";
            this.THREADTIMER.UseVisualStyleBackColor = true;
            // 
            // TIMERSTIMER
            // 
            this.TIMERSTIMER.AutoSize = true;
            this.TIMERSTIMER.Location = new System.Drawing.Point(6, 51);
            this.TIMERSTIMER.Name = "TIMERSTIMER";
            this.TIMERSTIMER.Size = new System.Drawing.Size(122, 17);
            this.TIMERSTIMER.TabIndex = 1;
            this.TIMERSTIMER.Text = "System.Timers.Timer";
            this.TIMERSTIMER.UseVisualStyleBackColor = true;
            // 
            // FORMTIMER
            // 
            this.FORMTIMER.AutoSize = true;
            this.FORMTIMER.Checked = true;
            this.FORMTIMER.Cursor = System.Windows.Forms.Cursors.Default;
            this.FORMTIMER.Location = new System.Drawing.Point(6, 28);
            this.FORMTIMER.Name = "FORMTIMER";
            this.FORMTIMER.Size = new System.Drawing.Size(166, 17);
            this.FORMTIMER.TabIndex = 0;
            this.FORMTIMER.TabStop = true;
            this.FORMTIMER.Text = "System.Windows.Forms.Timer";
            this.FORMTIMER.UseVisualStyleBackColor = true;
            // 
            // OUTPUT
            // 
            this.OUTPUT.Location = new System.Drawing.Point(25, 146);
            this.OUTPUT.Multiline = true;
            this.OUTPUT.Name = "OUTPUT";
            this.OUTPUT.ReadOnly = true;
            this.OUTPUT.Size = new System.Drawing.Size(270, 217);
            this.OUTPUT.TabIndex = 4;
            // 
            // RESET
            // 
            this.RESET.Location = new System.Drawing.Point(25, 106);
            this.RESET.Name = "RESET";
            this.RESET.Size = new System.Drawing.Size(75, 23);
            this.RESET.TabIndex = 5;
            this.RESET.Text = "重置输出";
            this.RESET.UseVisualStyleBackColor = true;
            this.RESET.Click += new System.EventHandler(this.RESET_Click);
            // 
            // Timers
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(320, 395);
            this.Controls.Add(this.RESET);
            this.Controls.Add(this.OUTPUT);
            this.Controls.Add(this.GROUP);
            this.Controls.Add(this.STOP);
            this.Controls.Add(this.SLEEP);
            this.Controls.Add(this.START);
            this.Name = "Timers";
            this.Text = "Timers";
            this.GROUP.ResumeLayout(false);
            this.GROUP.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button START;
        private System.Windows.Forms.Button SLEEP;
        private System.Windows.Forms.Button STOP;
        private System.Windows.Forms.GroupBox GROUP;
        private System.Windows.Forms.RadioButton THREADTIMER;
        private System.Windows.Forms.RadioButton TIMERSTIMER;
        private System.Windows.Forms.RadioButton FORMTIMER;
        private System.Windows.Forms.TextBox OUTPUT;
        private System.Windows.Forms.Timer WINDOWFORMTIMER;
        private System.Windows.Forms.Button RESET;
    }
}

