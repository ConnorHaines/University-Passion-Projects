namespace coursework
{
    partial class Form1
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.lst_Numbers = new System.Windows.Forms.ListBox();
            this.rad_Sort = new System.Windows.Forms.RadioButton();
            this.rad_Unsort = new System.Windows.Forms.RadioButton();
            this.rad_Linear = new System.Windows.Forms.RadioButton();
            this.rad_Binary = new System.Windows.Forms.RadioButton();
            this.btn_Initialise = new System.Windows.Forms.Button();
            this.btn_Clear = new System.Windows.Forms.Button();
            this.btn_Shuffle = new System.Windows.Forms.Button();
            this.btn_Delete = new System.Windows.Forms.Button();
            this.tb_Insert = new System.Windows.Forms.TextBox();
            this.btn_Insert = new System.Windows.Forms.Button();
            this.tb_Search = new System.Windows.Forms.TextBox();
            this.btn_Search = new System.Windows.Forms.Button();
            this.btn_Exit = new System.Windows.Forms.Button();
            this.lbl_NumberEntries = new System.Windows.Forms.Label();
            this.lbl_First = new System.Windows.Forms.Label();
            this.lbl_Last = new System.Windows.Forms.Label();
            this.lbl_Min = new System.Windows.Forms.Label();
            this.lbl_Max = new System.Windows.Forms.Label();
            this.gb_Stats = new System.Windows.Forms.GroupBox();
            this.gb_Insert_Sort = new System.Windows.Forms.GroupBox();
            this.gb_Search = new System.Windows.Forms.GroupBox();
            this.gb_Controls = new System.Windows.Forms.GroupBox();
            this.gb_Drag_N_Drop = new System.Windows.Forms.GroupBox();
            this.pb_Bin = new System.Windows.Forms.PictureBox();
            this.gb_Stats.SuspendLayout();
            this.gb_Insert_Sort.SuspendLayout();
            this.gb_Search.SuspendLayout();
            this.gb_Controls.SuspendLayout();
            this.gb_Drag_N_Drop.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pb_Bin)).BeginInit();
            this.SuspendLayout();
            // 
            // lst_Numbers
            // 
            this.lst_Numbers.FormattingEnabled = true;
            this.lst_Numbers.HorizontalScrollbar = true;
            this.lst_Numbers.Location = new System.Drawing.Point(12, 13);
            this.lst_Numbers.Name = "lst_Numbers";
            this.lst_Numbers.Size = new System.Drawing.Size(166, 121);
            this.lst_Numbers.TabIndex = 0;
            this.lst_Numbers.MouseDown += new System.Windows.Forms.MouseEventHandler(this.lst_Numbers_MouseDown_1);
            // 
            // rad_Sort
            // 
            this.rad_Sort.AutoSize = true;
            this.rad_Sort.Location = new System.Drawing.Point(88, 53);
            this.rad_Sort.Name = "rad_Sort";
            this.rad_Sort.Size = new System.Drawing.Size(56, 17);
            this.rad_Sort.TabIndex = 1;
            this.rad_Sort.Text = "Sorted";
            this.rad_Sort.UseVisualStyleBackColor = true;
            this.rad_Sort.CheckedChanged += new System.EventHandler(this.btn_Sort_CheckedChanged);
            // 
            // rad_Unsort
            // 
            this.rad_Unsort.AutoSize = true;
            this.rad_Unsort.Checked = true;
            this.rad_Unsort.Location = new System.Drawing.Point(88, 77);
            this.rad_Unsort.Name = "rad_Unsort";
            this.rad_Unsort.Size = new System.Drawing.Size(68, 17);
            this.rad_Unsort.TabIndex = 2;
            this.rad_Unsort.TabStop = true;
            this.rad_Unsort.Text = "Unsorted";
            this.rad_Unsort.UseVisualStyleBackColor = true;
            this.rad_Unsort.CheckedChanged += new System.EventHandler(this.btn_Unsort_CheckedChanged);
            // 
            // rad_Linear
            // 
            this.rad_Linear.AutoSize = true;
            this.rad_Linear.Checked = true;
            this.rad_Linear.Location = new System.Drawing.Point(6, 84);
            this.rad_Linear.Name = "rad_Linear";
            this.rad_Linear.Size = new System.Drawing.Size(54, 17);
            this.rad_Linear.TabIndex = 3;
            this.rad_Linear.TabStop = true;
            this.rad_Linear.Text = "Linear";
            this.rad_Linear.UseVisualStyleBackColor = true;
            // 
            // rad_Binary
            // 
            this.rad_Binary.AutoSize = true;
            this.rad_Binary.Location = new System.Drawing.Point(60, 84);
            this.rad_Binary.Name = "rad_Binary";
            this.rad_Binary.Size = new System.Drawing.Size(54, 17);
            this.rad_Binary.TabIndex = 3;
            this.rad_Binary.Text = "Binary";
            this.rad_Binary.UseVisualStyleBackColor = true;
            // 
            // btn_Initialise
            // 
            this.btn_Initialise.Location = new System.Drawing.Point(9, 71);
            this.btn_Initialise.Name = "btn_Initialise";
            this.btn_Initialise.Size = new System.Drawing.Size(75, 23);
            this.btn_Initialise.TabIndex = 4;
            this.btn_Initialise.Text = "Initialise";
            this.btn_Initialise.UseVisualStyleBackColor = true;
            this.btn_Initialise.Click += new System.EventHandler(this.btn_Initialise_Click);
            // 
            // btn_Clear
            // 
            this.btn_Clear.Location = new System.Drawing.Point(6, 76);
            this.btn_Clear.Name = "btn_Clear";
            this.btn_Clear.Size = new System.Drawing.Size(108, 23);
            this.btn_Clear.TabIndex = 5;
            this.btn_Clear.Text = "Clear";
            this.btn_Clear.UseVisualStyleBackColor = true;
            this.btn_Clear.Click += new System.EventHandler(this.btn_Clear_Click);
            // 
            // btn_Shuffle
            // 
            this.btn_Shuffle.Location = new System.Drawing.Point(6, 47);
            this.btn_Shuffle.Name = "btn_Shuffle";
            this.btn_Shuffle.Size = new System.Drawing.Size(108, 23);
            this.btn_Shuffle.TabIndex = 6;
            this.btn_Shuffle.Text = "Shuffle";
            this.btn_Shuffle.UseVisualStyleBackColor = true;
            this.btn_Shuffle.Click += new System.EventHandler(this.btn_Shuffle_Click);
            // 
            // btn_Delete
            // 
            this.btn_Delete.Location = new System.Drawing.Point(6, 19);
            this.btn_Delete.Name = "btn_Delete";
            this.btn_Delete.Size = new System.Drawing.Size(108, 23);
            this.btn_Delete.TabIndex = 7;
            this.btn_Delete.Text = "Delete";
            this.btn_Delete.UseVisualStyleBackColor = true;
            this.btn_Delete.Click += new System.EventHandler(this.btn_Delete_Click);
            // 
            // tb_Insert
            // 
            this.tb_Insert.Location = new System.Drawing.Point(9, 22);
            this.tb_Insert.Name = "tb_Insert";
            this.tb_Insert.Size = new System.Drawing.Size(147, 20);
            this.tb_Insert.TabIndex = 8;
            // 
            // btn_Insert
            // 
            this.btn_Insert.Location = new System.Drawing.Point(9, 47);
            this.btn_Insert.Name = "btn_Insert";
            this.btn_Insert.Size = new System.Drawing.Size(75, 23);
            this.btn_Insert.TabIndex = 9;
            this.btn_Insert.Text = "Insert";
            this.btn_Insert.UseVisualStyleBackColor = true;
            this.btn_Insert.Click += new System.EventHandler(this.btn_Insert_Click);
            // 
            // tb_Search
            // 
            this.tb_Search.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.tb_Search.Location = new System.Drawing.Point(6, 26);
            this.tb_Search.Name = "tb_Search";
            this.tb_Search.Size = new System.Drawing.Size(108, 20);
            this.tb_Search.TabIndex = 10;
            // 
            // btn_Search
            // 
            this.btn_Search.Location = new System.Drawing.Point(6, 55);
            this.btn_Search.Name = "btn_Search";
            this.btn_Search.Size = new System.Drawing.Size(108, 23);
            this.btn_Search.TabIndex = 9;
            this.btn_Search.Text = "Search";
            this.btn_Search.UseVisualStyleBackColor = true;
            this.btn_Search.Click += new System.EventHandler(this.btn_Search_Click);
            // 
            // btn_Exit
            // 
            this.btn_Exit.Location = new System.Drawing.Point(6, 105);
            this.btn_Exit.Name = "btn_Exit";
            this.btn_Exit.Size = new System.Drawing.Size(108, 23);
            this.btn_Exit.TabIndex = 11;
            this.btn_Exit.Text = "Exit";
            this.btn_Exit.UseVisualStyleBackColor = true;
            this.btn_Exit.Click += new System.EventHandler(this.btn_Exit_Click);
            // 
            // lbl_NumberEntries
            // 
            this.lbl_NumberEntries.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.lbl_NumberEntries.Location = new System.Drawing.Point(6, 17);
            this.lbl_NumberEntries.Name = "lbl_NumberEntries";
            this.lbl_NumberEntries.Size = new System.Drawing.Size(138, 20);
            this.lbl_NumberEntries.TabIndex = 12;
            this.lbl_NumberEntries.Text = "Number of Entries: ";
            // 
            // lbl_First
            // 
            this.lbl_First.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.lbl_First.Location = new System.Drawing.Point(6, 37);
            this.lbl_First.Name = "lbl_First";
            this.lbl_First.Size = new System.Drawing.Size(103, 20);
            this.lbl_First.TabIndex = 12;
            this.lbl_First.Text = "First Value: ";
            // 
            // lbl_Last
            // 
            this.lbl_Last.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.lbl_Last.Location = new System.Drawing.Point(6, 57);
            this.lbl_Last.Name = "lbl_Last";
            this.lbl_Last.Size = new System.Drawing.Size(103, 20);
            this.lbl_Last.TabIndex = 12;
            this.lbl_Last.Text = "Last Value: ";
            // 
            // lbl_Min
            // 
            this.lbl_Min.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.lbl_Min.Location = new System.Drawing.Point(6, 77);
            this.lbl_Min.Name = "lbl_Min";
            this.lbl_Min.Size = new System.Drawing.Size(103, 20);
            this.lbl_Min.TabIndex = 12;
            this.lbl_Min.Text = "Minimum: ";
            // 
            // lbl_Max
            // 
            this.lbl_Max.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.lbl_Max.Location = new System.Drawing.Point(6, 97);
            this.lbl_Max.Name = "lbl_Max";
            this.lbl_Max.Size = new System.Drawing.Size(103, 20);
            this.lbl_Max.TabIndex = 12;
            this.lbl_Max.Text = "Maximum: ";
            // 
            // gb_Stats
            // 
            this.gb_Stats.Controls.Add(this.lbl_Min);
            this.gb_Stats.Controls.Add(this.lbl_Max);
            this.gb_Stats.Controls.Add(this.lbl_NumberEntries);
            this.gb_Stats.Controls.Add(this.lbl_First);
            this.gb_Stats.Controls.Add(this.lbl_Last);
            this.gb_Stats.Location = new System.Drawing.Point(12, 258);
            this.gb_Stats.Name = "gb_Stats";
            this.gb_Stats.Size = new System.Drawing.Size(166, 122);
            this.gb_Stats.TabIndex = 13;
            this.gb_Stats.TabStop = false;
            this.gb_Stats.Text = "Statistics";
            // 
            // gb_Insert_Sort
            // 
            this.gb_Insert_Sort.Controls.Add(this.rad_Sort);
            this.gb_Insert_Sort.Controls.Add(this.rad_Unsort);
            this.gb_Insert_Sort.Controls.Add(this.tb_Insert);
            this.gb_Insert_Sort.Controls.Add(this.btn_Insert);
            this.gb_Insert_Sort.Controls.Add(this.btn_Initialise);
            this.gb_Insert_Sort.Location = new System.Drawing.Point(12, 147);
            this.gb_Insert_Sort.Name = "gb_Insert_Sort";
            this.gb_Insert_Sort.Size = new System.Drawing.Size(166, 103);
            this.gb_Insert_Sort.TabIndex = 14;
            this.gb_Insert_Sort.TabStop = false;
            this.gb_Insert_Sort.Text = "Insert";
            // 
            // gb_Search
            // 
            this.gb_Search.Controls.Add(this.rad_Linear);
            this.gb_Search.Controls.Add(this.rad_Binary);
            this.gb_Search.Controls.Add(this.tb_Search);
            this.gb_Search.Controls.Add(this.btn_Search);
            this.gb_Search.Location = new System.Drawing.Point(198, 13);
            this.gb_Search.Name = "gb_Search";
            this.gb_Search.Size = new System.Drawing.Size(120, 107);
            this.gb_Search.TabIndex = 15;
            this.gb_Search.TabStop = false;
            this.gb_Search.Text = "Search";
            // 
            // gb_Controls
            // 
            this.gb_Controls.Controls.Add(this.btn_Exit);
            this.gb_Controls.Controls.Add(this.btn_Delete);
            this.gb_Controls.Controls.Add(this.btn_Clear);
            this.gb_Controls.Controls.Add(this.btn_Shuffle);
            this.gb_Controls.Location = new System.Drawing.Point(198, 245);
            this.gb_Controls.Name = "gb_Controls";
            this.gb_Controls.Size = new System.Drawing.Size(120, 135);
            this.gb_Controls.TabIndex = 16;
            this.gb_Controls.TabStop = false;
            this.gb_Controls.Text = "Controls";
            // 
            // gb_Drag_N_Drop
            // 
            this.gb_Drag_N_Drop.Controls.Add(this.pb_Bin);
            this.gb_Drag_N_Drop.Location = new System.Drawing.Point(198, 126);
            this.gb_Drag_N_Drop.Name = "gb_Drag_N_Drop";
            this.gb_Drag_N_Drop.Size = new System.Drawing.Size(120, 115);
            this.gb_Drag_N_Drop.TabIndex = 17;
            this.gb_Drag_N_Drop.TabStop = false;
            this.gb_Drag_N_Drop.Text = "Drag N\' Drop Bin";
            // 
            // pb_Bin
            // 
            this.pb_Bin.Cursor = System.Windows.Forms.Cursors.Default;
            this.pb_Bin.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pb_Bin.Image = global::coursework.Properties.Resources.Recycle_Bin_Full1;
            this.pb_Bin.Location = new System.Drawing.Point(3, 16);
            this.pb_Bin.Name = "pb_Bin";
            this.pb_Bin.Size = new System.Drawing.Size(114, 96);
            this.pb_Bin.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pb_Bin.TabIndex = 0;
            this.pb_Bin.TabStop = false;
            this.pb_Bin.DragDrop += new System.Windows.Forms.DragEventHandler(this.pb_Bin_DragDrop);
            this.pb_Bin.DragEnter += new System.Windows.Forms.DragEventHandler(this.pb_Bin_DragEnter_1);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.ClientSize = new System.Drawing.Size(331, 402);
            this.Controls.Add(this.gb_Drag_N_Drop);
            this.Controls.Add(this.gb_Controls);
            this.Controls.Add(this.gb_Search);
            this.Controls.Add(this.gb_Insert_Sort);
            this.Controls.Add(this.gb_Stats);
            this.Controls.Add(this.lst_Numbers);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximumSize = new System.Drawing.Size(347, 441);
            this.MinimumSize = new System.Drawing.Size(347, 441);
            this.Name = "Form1";
            this.Text = "Number Generator & Sorter";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.gb_Stats.ResumeLayout(false);
            this.gb_Insert_Sort.ResumeLayout(false);
            this.gb_Insert_Sort.PerformLayout();
            this.gb_Search.ResumeLayout(false);
            this.gb_Search.PerformLayout();
            this.gb_Controls.ResumeLayout(false);
            this.gb_Drag_N_Drop.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pb_Bin)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox lst_Numbers;
        private System.Windows.Forms.RadioButton rad_Sort;
        private System.Windows.Forms.RadioButton rad_Unsort;
        private System.Windows.Forms.RadioButton rad_Linear;
        private System.Windows.Forms.RadioButton rad_Binary;
        private System.Windows.Forms.Button btn_Initialise;
        private System.Windows.Forms.Button btn_Clear;
        private System.Windows.Forms.Button btn_Shuffle;
        private System.Windows.Forms.Button btn_Delete;
        private System.Windows.Forms.TextBox tb_Insert;
        private System.Windows.Forms.Button btn_Insert;
        private System.Windows.Forms.TextBox tb_Search;
        private System.Windows.Forms.Button btn_Search;
        private System.Windows.Forms.Button btn_Exit;
        private System.Windows.Forms.Label lbl_NumberEntries;
        private System.Windows.Forms.Label lbl_First;
        private System.Windows.Forms.Label lbl_Last;
        private System.Windows.Forms.Label lbl_Min;
        private System.Windows.Forms.Label lbl_Max;
        private System.Windows.Forms.GroupBox gb_Stats;
        private System.Windows.Forms.GroupBox gb_Insert_Sort;
        private System.Windows.Forms.GroupBox gb_Search;
        private System.Windows.Forms.GroupBox gb_Controls;
        private System.Windows.Forms.GroupBox gb_Drag_N_Drop;
        private System.Windows.Forms.PictureBox pb_Bin;
    }
}
