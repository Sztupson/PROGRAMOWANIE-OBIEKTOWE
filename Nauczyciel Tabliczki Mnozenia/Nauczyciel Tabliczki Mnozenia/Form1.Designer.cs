namespace Nauczyciel_Tabliczki_Mnozenia
{
    partial class Form1
    {
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Wyczyść wszystkie używane zasoby.
        /// </summary>
        /// <param name="disposing">prawda, jeżeli zarządzane zasoby powinny zostać zlikwidowane; Fałsz w przeciwnym wypadku.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Kod generowany przez Projektanta formularzy systemu Windows

        /// <summary>
        /// Metoda wymagana do obsługi projektanta — nie należy modyfikować
        /// jej zawartości w edytorze kodu.
        /// </summary>
        private void InitializeComponent()
        {
            this.lblX = new System.Windows.Forms.Label();
            this.lblDzialania = new System.Windows.Forms.Label();
            this.lblY = new System.Windows.Forms.Label();
            this.lblEqualSign = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.zakresyLiczbToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.działaniaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.koniecToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.lblRightAnswers = new System.Windows.Forms.Label();
            this.lblWrongAnswers = new System.Windows.Forms.Label();
            this.lblRightAnswersAnswer = new System.Windows.Forms.Label();
            this.lblWrongAnswersAnswer = new System.Windows.Forms.Label();
            this.toolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem4 = new System.Windows.Forms.ToolStripMenuItem();
            this.dodawanieToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.mnożenieToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.odejmowanieToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dzielenieToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.btnRandomizeNumbers = new System.Windows.Forms.Button();
            this.btnCheckAnswers = new System.Windows.Forms.Button();
            this.toolStripMenuItem5 = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // lblX
            // 
            this.lblX.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblX.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lblX.Location = new System.Drawing.Point(234, 134);
            this.lblX.Name = "lblX";
            this.lblX.Size = new System.Drawing.Size(60, 60);
            this.lblX.TabIndex = 0;
            this.lblX.Text = "0";
            this.lblX.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblDzialania
            // 
            this.lblDzialania.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lblDzialania.Location = new System.Drawing.Point(333, 153);
            this.lblDzialania.Name = "lblDzialania";
            this.lblDzialania.Size = new System.Drawing.Size(35, 23);
            this.lblDzialania.TabIndex = 1;
            this.lblDzialania.Text = "+";
            // 
            // lblY
            // 
            this.lblY.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblY.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lblY.Location = new System.Drawing.Point(392, 134);
            this.lblY.Name = "lblY";
            this.lblY.Size = new System.Drawing.Size(60, 60);
            this.lblY.TabIndex = 2;
            this.lblY.Text = "0";
            this.lblY.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblEqualSign
            // 
            this.lblEqualSign.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lblEqualSign.Location = new System.Drawing.Point(458, 152);
            this.lblEqualSign.Name = "lblEqualSign";
            this.lblEqualSign.Size = new System.Drawing.Size(50, 30);
            this.lblEqualSign.TabIndex = 3;
            this.lblEqualSign.Text = "=";
            this.lblEqualSign.Click += new System.EventHandler(this.lblEqualSign_Click);
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.textBox1.Location = new System.Drawing.Point(499, 150);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(70, 29);
            this.textBox1.TabIndex = 4;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.zakresyLiczbToolStripMenuItem,
            this.działaniaToolStripMenuItem,
            this.koniecToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 24);
            this.menuStrip1.TabIndex = 5;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // zakresyLiczbToolStripMenuItem
            // 
            this.zakresyLiczbToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItem5,
            this.toolStripMenuItem2,
            this.toolStripMenuItem3,
            this.toolStripMenuItem4});
            this.zakresyLiczbToolStripMenuItem.Name = "zakresyLiczbToolStripMenuItem";
            this.zakresyLiczbToolStripMenuItem.Size = new System.Drawing.Size(86, 20);
            this.zakresyLiczbToolStripMenuItem.Text = "Zakresy liczb";
            // 
            // działaniaToolStripMenuItem
            // 
            this.działaniaToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.dodawanieToolStripMenuItem,
            this.odejmowanieToolStripMenuItem,
            this.mnożenieToolStripMenuItem,
            this.dzielenieToolStripMenuItem});
            this.działaniaToolStripMenuItem.Name = "działaniaToolStripMenuItem";
            this.działaniaToolStripMenuItem.Size = new System.Drawing.Size(66, 20);
            this.działaniaToolStripMenuItem.Text = "Działania";
            // 
            // koniecToolStripMenuItem
            // 
            this.koniecToolStripMenuItem.Name = "koniecToolStripMenuItem";
            this.koniecToolStripMenuItem.Size = new System.Drawing.Size(55, 20);
            this.koniecToolStripMenuItem.Text = "Koniec";
            this.koniecToolStripMenuItem.Click += new System.EventHandler(this.koniecToolStripMenuItem_Click);
            // 
            // lblRightAnswers
            // 
            this.lblRightAnswers.AutoSize = true;
            this.lblRightAnswers.Location = new System.Drawing.Point(182, 328);
            this.lblRightAnswers.Name = "lblRightAnswers";
            this.lblRightAnswers.Size = new System.Drawing.Size(114, 13);
            this.lblRightAnswers.TabIndex = 9;
            this.lblRightAnswers.Text = "Poprawne odpowiedzi:";
            // 
            // lblWrongAnswers
            // 
            this.lblWrongAnswers.AutoSize = true;
            this.lblWrongAnswers.Location = new System.Drawing.Point(182, 355);
            this.lblWrongAnswers.Name = "lblWrongAnswers";
            this.lblWrongAnswers.Size = new System.Drawing.Size(129, 13);
            this.lblWrongAnswers.TabIndex = 8;
            this.lblWrongAnswers.Text = "Niepoprawne odpowiedzi:";
            // 
            // lblRightAnswersAnswer
            // 
            this.lblRightAnswersAnswer.AutoSize = true;
            this.lblRightAnswersAnswer.Location = new System.Drawing.Point(317, 328);
            this.lblRightAnswersAnswer.Name = "lblRightAnswersAnswer";
            this.lblRightAnswersAnswer.Size = new System.Drawing.Size(13, 13);
            this.lblRightAnswersAnswer.TabIndex = 7;
            this.lblRightAnswersAnswer.Text = "0";
            this.lblRightAnswersAnswer.Click += new System.EventHandler(this.label7_Click);
            // 
            // lblWrongAnswersAnswer
            // 
            this.lblWrongAnswersAnswer.AutoSize = true;
            this.lblWrongAnswersAnswer.Location = new System.Drawing.Point(317, 355);
            this.lblWrongAnswersAnswer.Name = "lblWrongAnswersAnswer";
            this.lblWrongAnswersAnswer.Size = new System.Drawing.Size(13, 13);
            this.lblWrongAnswersAnswer.TabIndex = 6;
            this.lblWrongAnswersAnswer.Text = "0";
            // 
            // toolStripMenuItem2
            // 
            this.toolStripMenuItem2.Name = "toolStripMenuItem2";
            this.toolStripMenuItem2.Size = new System.Drawing.Size(180, 22);
            this.toolStripMenuItem2.Text = "1-20";
            // 
            // toolStripMenuItem3
            // 
            this.toolStripMenuItem3.Name = "toolStripMenuItem3";
            this.toolStripMenuItem3.Size = new System.Drawing.Size(180, 22);
            this.toolStripMenuItem3.Text = "1-50";
            // 
            // toolStripMenuItem4
            // 
            this.toolStripMenuItem4.Name = "toolStripMenuItem4";
            this.toolStripMenuItem4.Size = new System.Drawing.Size(180, 22);
            this.toolStripMenuItem4.Text = "1-100";
            // 
            // dodawanieToolStripMenuItem
            // 
            this.dodawanieToolStripMenuItem.Name = "dodawanieToolStripMenuItem";
            this.dodawanieToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.dodawanieToolStripMenuItem.Text = "Dodawanie";
            // 
            // mnożenieToolStripMenuItem
            // 
            this.mnożenieToolStripMenuItem.Name = "mnożenieToolStripMenuItem";
            this.mnożenieToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.mnożenieToolStripMenuItem.Text = "Mnożenie";
            // 
            // odejmowanieToolStripMenuItem
            // 
            this.odejmowanieToolStripMenuItem.Name = "odejmowanieToolStripMenuItem";
            this.odejmowanieToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.odejmowanieToolStripMenuItem.Text = "Odejmowanie";
            // 
            // dzielenieToolStripMenuItem
            // 
            this.dzielenieToolStripMenuItem.Name = "dzielenieToolStripMenuItem";
            this.dzielenieToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.dzielenieToolStripMenuItem.Text = "Dzielenie";
            // 
            // btnRandomizeNumbers
            // 
            this.btnRandomizeNumbers.Location = new System.Drawing.Point(234, 228);
            this.btnRandomizeNumbers.Name = "btnRandomizeNumbers";
            this.btnRandomizeNumbers.Size = new System.Drawing.Size(96, 39);
            this.btnRandomizeNumbers.TabIndex = 10;
            this.btnRandomizeNumbers.Text = "Losuj";
            this.btnRandomizeNumbers.UseVisualStyleBackColor = true;
            this.btnRandomizeNumbers.Click += new System.EventHandler(this.btnRandomizeNumbers_Click);
            // 
            // btnCheckAnswers
            // 
            this.btnCheckAnswers.Location = new System.Drawing.Point(355, 228);
            this.btnCheckAnswers.Name = "btnCheckAnswers";
            this.btnCheckAnswers.Size = new System.Drawing.Size(97, 39);
            this.btnCheckAnswers.TabIndex = 11;
            this.btnCheckAnswers.Text = "Sprawdź";
            this.btnCheckAnswers.UseVisualStyleBackColor = true;
            this.btnCheckAnswers.Click += new System.EventHandler(this.btnCheckAnswers_Click);
            // 
            // toolStripMenuItem5
            // 
            this.toolStripMenuItem5.Name = "toolStripMenuItem5";
            this.toolStripMenuItem5.Size = new System.Drawing.Size(180, 22);
            this.toolStripMenuItem5.Text = "1-10";
            this.toolStripMenuItem5.Click += new System.EventHandler(this.toolStripMenuItem5_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnCheckAnswers);
            this.Controls.Add(this.btnRandomizeNumbers);
            this.Controls.Add(this.lblRightAnswers);
            this.Controls.Add(this.lblWrongAnswers);
            this.Controls.Add(this.lblRightAnswersAnswer);
            this.Controls.Add(this.lblWrongAnswersAnswer);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.lblEqualSign);
            this.Controls.Add(this.lblY);
            this.Controls.Add(this.lblDzialania);
            this.Controls.Add(this.lblX);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblX;
        private System.Windows.Forms.Label lblDzialania;
        private System.Windows.Forms.Label lblY;
        private System.Windows.Forms.Label lblEqualSign;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem zakresyLiczbToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem działaniaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem koniecToolStripMenuItem;
        private System.Windows.Forms.Label lblRightAnswers;
        private System.Windows.Forms.Label lblWrongAnswers;
        private System.Windows.Forms.Label lblRightAnswersAnswer;
        private System.Windows.Forms.Label lblWrongAnswersAnswer;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem3;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem4;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem5;
        private System.Windows.Forms.ToolStripMenuItem dodawanieToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem odejmowanieToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem mnożenieToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dzielenieToolStripMenuItem;
        private System.Windows.Forms.Button btnRandomizeNumbers;
        private System.Windows.Forms.Button btnCheckAnswers;
    }
}

