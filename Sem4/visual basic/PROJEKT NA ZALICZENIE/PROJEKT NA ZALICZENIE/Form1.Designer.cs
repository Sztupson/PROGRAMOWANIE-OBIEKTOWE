namespace PROJEKT_NA_ZALICZENIE
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.plikToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.otwórzToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.zapiszToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.kupnoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.kategorieToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.sortowanieToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.zamknijToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.sprzedażToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.wystawiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.koszykToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.profilToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.wykresContextToolStrip = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.kolorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.wybierzKolorToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.zielonyToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.niebieskiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rozmiarToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.rozszerzToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pomniejszToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.txtSymbol = new System.Windows.Forms.TextBox();
            this.lblStatus = new System.Windows.Forms.Label();
            this.lblSaldo = new System.Windows.Forms.Label();
            this.lblSaldoNumbers = new System.Windows.Forms.Label();
            this.btnAddSaldo = new System.Windows.Forms.Button();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.appContextMenuStrip = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.zmieńZdjęcieToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openFileDialog2 = new System.Windows.Forms.OpenFileDialog();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.btnLoadDataToolStrip = new System.Windows.Forms.ToolStripButton();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            this.wykresContextToolStrip.SuspendLayout();
            this.appContextMenuStrip.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.plikToolStripMenuItem,
            this.kupnoToolStripMenuItem,
            this.sprzedażToolStripMenuItem,
            this.wystawiToolStripMenuItem,
            this.koszykToolStripMenuItem,
            this.profilToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(800, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // plikToolStripMenuItem
            // 
            this.plikToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.otwórzToolStripMenuItem,
            this.zapiszToolStripMenuItem});
            this.plikToolStripMenuItem.Name = "plikToolStripMenuItem";
            this.plikToolStripMenuItem.Size = new System.Drawing.Size(38, 20);
            this.plikToolStripMenuItem.Text = "Plik";
            // 
            // otwórzToolStripMenuItem
            // 
            this.otwórzToolStripMenuItem.Name = "otwórzToolStripMenuItem";
            this.otwórzToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.otwórzToolStripMenuItem.Text = "Otwórz";
            this.otwórzToolStripMenuItem.Click += new System.EventHandler(this.otwórzToolStripMenuItem_Click);
            // 
            // zapiszToolStripMenuItem
            // 
            this.zapiszToolStripMenuItem.Name = "zapiszToolStripMenuItem";
            this.zapiszToolStripMenuItem.Size = new System.Drawing.Size(112, 22);
            this.zapiszToolStripMenuItem.Text = "Zapisz";
            this.zapiszToolStripMenuItem.Click += new System.EventHandler(this.zapiszToolStripMenuItem_Click);
            // 
            // kupnoToolStripMenuItem
            // 
            this.kupnoToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.kategorieToolStripMenuItem,
            this.sortowanieToolStripMenuItem,
            this.zamknijToolStripMenuItem});
            this.kupnoToolStripMenuItem.Name = "kupnoToolStripMenuItem";
            this.kupnoToolStripMenuItem.Size = new System.Drawing.Size(54, 20);
            this.kupnoToolStripMenuItem.Text = "Kupno";
            // 
            // kategorieToolStripMenuItem
            // 
            this.kategorieToolStripMenuItem.Name = "kategorieToolStripMenuItem";
            this.kategorieToolStripMenuItem.Size = new System.Drawing.Size(133, 22);
            this.kategorieToolStripMenuItem.Text = "Kategorie";
            this.kategorieToolStripMenuItem.ToolTipText = "Wybierz sektor akcji które chcesz kupić";
            // 
            // sortowanieToolStripMenuItem
            // 
            this.sortowanieToolStripMenuItem.Name = "sortowanieToolStripMenuItem";
            this.sortowanieToolStripMenuItem.Size = new System.Drawing.Size(133, 22);
            this.sortowanieToolStripMenuItem.Text = "Sortowanie";
            this.sortowanieToolStripMenuItem.ToolTipText = "Sortuj według";
            // 
            // zamknijToolStripMenuItem
            // 
            this.zamknijToolStripMenuItem.Enabled = false;
            this.zamknijToolStripMenuItem.Name = "zamknijToolStripMenuItem";
            this.zamknijToolStripMenuItem.Size = new System.Drawing.Size(133, 22);
            this.zamknijToolStripMenuItem.Text = "Zamknij";
            this.zamknijToolStripMenuItem.ToolTipText = "Zamykanie aplikacji";
            // 
            // sprzedażToolStripMenuItem
            // 
            this.sprzedażToolStripMenuItem.Name = "sprzedażToolStripMenuItem";
            this.sprzedażToolStripMenuItem.Size = new System.Drawing.Size(65, 20);
            this.sprzedażToolStripMenuItem.Text = "Sprzedaż";
            // 
            // wystawiToolStripMenuItem
            // 
            this.wystawiToolStripMenuItem.Name = "wystawiToolStripMenuItem";
            this.wystawiToolStripMenuItem.Size = new System.Drawing.Size(60, 20);
            this.wystawiToolStripMenuItem.Text = "Wystaw";
            // 
            // koszykToolStripMenuItem
            // 
            this.koszykToolStripMenuItem.Name = "koszykToolStripMenuItem";
            this.koszykToolStripMenuItem.Size = new System.Drawing.Size(55, 20);
            this.koszykToolStripMenuItem.Text = "Koszyk";
            // 
            // profilToolStripMenuItem
            // 
            this.profilToolStripMenuItem.Name = "profilToolStripMenuItem";
            this.profilToolStripMenuItem.Size = new System.Drawing.Size(47, 20);
            this.profilToolStripMenuItem.Text = "Profil";
            // 
            // chart1
            // 
            chartArea1.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea1);
            this.chart1.ContextMenuStrip = this.wykresContextToolStrip;
            legend1.Name = "Legend1";
            this.chart1.Legends.Add(legend1);
            this.chart1.Location = new System.Drawing.Point(12, 121);
            this.chart1.Name = "chart1";
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            series1.Legend = "Legend1";
            series1.Name = "Series1";
            this.chart1.Series.Add(series1);
            this.chart1.Size = new System.Drawing.Size(312, 300);
            this.chart1.TabIndex = 2;
            this.chart1.Text = "Wykres";
            // 
            // wykresContextToolStrip
            // 
            this.wykresContextToolStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.kolorToolStripMenuItem,
            this.rozmiarToolStripMenuItem});
            this.wykresContextToolStrip.Name = "wykresContextToolStrip";
            this.wykresContextToolStrip.Size = new System.Drawing.Size(118, 48);
            // 
            // kolorToolStripMenuItem
            // 
            this.kolorToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.wybierzKolorToolStripMenuItem,
            this.zielonyToolStripMenuItem,
            this.niebieskiToolStripMenuItem});
            this.kolorToolStripMenuItem.Name = "kolorToolStripMenuItem";
            this.kolorToolStripMenuItem.Size = new System.Drawing.Size(117, 22);
            this.kolorToolStripMenuItem.Text = "Kolor";
            // 
            // wybierzKolorToolStripMenuItem
            // 
            this.wybierzKolorToolStripMenuItem.Name = "wybierzKolorToolStripMenuItem";
            this.wybierzKolorToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.wybierzKolorToolStripMenuItem.Text = "Wybierz kolor";
            this.wybierzKolorToolStripMenuItem.Click += new System.EventHandler(this.wybierzKolorToolStripMenuItem_Click);
            // 
            // zielonyToolStripMenuItem
            // 
            this.zielonyToolStripMenuItem.Name = "zielonyToolStripMenuItem";
            this.zielonyToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.zielonyToolStripMenuItem.Text = "Zielony";
            this.zielonyToolStripMenuItem.Click += new System.EventHandler(this.zielonyToolStripMenuItem_Click);
            // 
            // niebieskiToolStripMenuItem
            // 
            this.niebieskiToolStripMenuItem.Name = "niebieskiToolStripMenuItem";
            this.niebieskiToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.niebieskiToolStripMenuItem.Text = "Niebieski";
            this.niebieskiToolStripMenuItem.Click += new System.EventHandler(this.niebieskiToolStripMenuItem_Click);
            // 
            // rozmiarToolStripMenuItem
            // 
            this.rozmiarToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.rozszerzToolStripMenuItem,
            this.pomniejszToolStripMenuItem});
            this.rozmiarToolStripMenuItem.Name = "rozmiarToolStripMenuItem";
            this.rozmiarToolStripMenuItem.Size = new System.Drawing.Size(117, 22);
            this.rozmiarToolStripMenuItem.Text = "Rozmiar";
            // 
            // rozszerzToolStripMenuItem
            // 
            this.rozszerzToolStripMenuItem.Name = "rozszerzToolStripMenuItem";
            this.rozszerzToolStripMenuItem.Size = new System.Drawing.Size(128, 22);
            this.rozszerzToolStripMenuItem.Text = "Rozszerz";
            this.rozszerzToolStripMenuItem.Click += new System.EventHandler(this.rozszerzToolStripMenuItem_Click);
            // 
            // pomniejszToolStripMenuItem
            // 
            this.pomniejszToolStripMenuItem.Name = "pomniejszToolStripMenuItem";
            this.pomniejszToolStripMenuItem.Size = new System.Drawing.Size(128, 22);
            this.pomniejszToolStripMenuItem.Text = "Pomniejsz";
            this.pomniejszToolStripMenuItem.Click += new System.EventHandler(this.pomniejszToolStripMenuItem_Click);
            // 
            // txtSymbol
            // 
            this.txtSymbol.Location = new System.Drawing.Point(319, 95);
            this.txtSymbol.Name = "txtSymbol";
            this.txtSymbol.Size = new System.Drawing.Size(100, 20);
            this.txtSymbol.TabIndex = 5;
            this.txtSymbol.Text = "BTC";
            // 
            // lblStatus
            // 
            this.lblStatus.AutoSize = true;
            this.lblStatus.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lblStatus.Location = new System.Drawing.Point(315, 69);
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(173, 20);
            this.lblStatus.TabIndex = 6;
            this.lblStatus.Text = "Wprowadź nazwę akcji:";
            // 
            // lblSaldo
            // 
            this.lblSaldo.AutoSize = true;
            this.lblSaldo.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lblSaldo.Location = new System.Drawing.Point(681, 66);
            this.lblSaldo.Name = "lblSaldo";
            this.lblSaldo.Size = new System.Drawing.Size(54, 20);
            this.lblSaldo.TabIndex = 7;
            this.lblSaldo.Text = "Saldo:";
            // 
            // lblSaldoNumbers
            // 
            this.lblSaldoNumbers.AutoSize = true;
            this.lblSaldoNumbers.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lblSaldoNumbers.ForeColor = System.Drawing.SystemColors.ActiveBorder;
            this.lblSaldoNumbers.Location = new System.Drawing.Point(684, 93);
            this.lblSaldoNumbers.Name = "lblSaldoNumbers";
            this.lblSaldoNumbers.Size = new System.Drawing.Size(51, 20);
            this.lblSaldoNumbers.TabIndex = 8;
            this.lblSaldoNumbers.Text = "saldo:";
            // 
            // btnAddSaldo
            // 
            this.btnAddSaldo.Location = new System.Drawing.Point(685, 130);
            this.btnAddSaldo.Name = "btnAddSaldo";
            this.btnAddSaldo.Size = new System.Drawing.Size(75, 23);
            this.btnAddSaldo.TabIndex = 9;
            this.btnAddSaldo.Text = "Dodaj saldo";
            this.btnAddSaldo.UseVisualStyleBackColor = true;
            this.btnAddSaldo.Click += new System.EventHandler(this.btnAddSaldo_Click);
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // appContextMenuStrip
            // 
            this.appContextMenuStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.zmieńZdjęcieToolStripMenuItem});
            this.appContextMenuStrip.Name = "appContextMenuStrip";
            this.appContextMenuStrip.Size = new System.Drawing.Size(148, 26);
            // 
            // zmieńZdjęcieToolStripMenuItem
            // 
            this.zmieńZdjęcieToolStripMenuItem.Name = "zmieńZdjęcieToolStripMenuItem";
            this.zmieńZdjęcieToolStripMenuItem.Size = new System.Drawing.Size(147, 22);
            this.zmieńZdjęcieToolStripMenuItem.Text = "Zmień zdjęcie";
            this.zmieńZdjęcieToolStripMenuItem.ToolTipText = "Zmień zdjęcie tła aplikacji";
            this.zmieńZdjęcieToolStripMenuItem.Click += new System.EventHandler(this.zmieńZdjęcieToolStripMenuItem_Click);
            // 
            // openFileDialog2
            // 
            this.openFileDialog2.FileName = "openFileDialog2";
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Location = new System.Drawing.Point(608, 430);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(192, 20);
            this.dateTimePicker1.TabIndex = 12;
            // 
            // toolStrip1
            // 
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.btnLoadDataToolStrip});
            this.toolStrip1.Location = new System.Drawing.Point(0, 24);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.Size = new System.Drawing.Size(800, 25);
            this.toolStrip1.TabIndex = 13;
            this.toolStrip1.Text = "toolStrip1";
            // 
            // btnLoadDataToolStrip
            // 
            this.btnLoadDataToolStrip.Image = ((System.Drawing.Image)(resources.GetObject("btnLoadDataToolStrip.Image")));
            this.btnLoadDataToolStrip.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.btnLoadDataToolStrip.Name = "btnLoadDataToolStrip";
            this.btnLoadDataToolStrip.Size = new System.Drawing.Size(105, 22);
            this.btnLoadDataToolStrip.Text = "Załaduj wykres";
            this.btnLoadDataToolStrip.Click += new System.EventHandler(this.btnLoadDataToolStrip_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.ContextMenuStrip = this.appContextMenuStrip;
            this.Controls.Add(this.toolStrip1);
            this.Controls.Add(this.dateTimePicker1);
            this.Controls.Add(this.btnAddSaldo);
            this.Controls.Add(this.lblSaldoNumbers);
            this.Controls.Add(this.lblSaldo);
            this.Controls.Add(this.lblStatus);
            this.Controls.Add(this.txtSymbol);
            this.Controls.Add(this.chart1);
            this.Controls.Add(this.menuStrip1);
            this.HelpButton = true;
            this.MainMenuStrip = this.menuStrip1;
            this.MinimizeBox = false;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            this.wykresContextToolStrip.ResumeLayout(false);
            this.appContextMenuStrip.ResumeLayout(false);
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem kupnoToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem sprzedażToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem wystawiToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem kategorieToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem sortowanieToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem koszykToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem profilToolStripMenuItem;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
        private System.Windows.Forms.TextBox txtSymbol;
        private System.Windows.Forms.Label lblStatus;
        private System.Windows.Forms.Label lblSaldo;
        private System.Windows.Forms.Label lblSaldoNumbers;
        private System.Windows.Forms.Button btnAddSaldo;
        private System.Windows.Forms.ContextMenuStrip wykresContextToolStrip;
        private System.Windows.Forms.ToolStripMenuItem kolorToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem rozmiarToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem wybierzKolorToolStripMenuItem;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.ToolStripMenuItem zamknijToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem rozszerzToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pomniejszToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem plikToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem otwórzToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem zapiszToolStripMenuItem;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.ToolStripMenuItem zielonyToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem niebieskiToolStripMenuItem;
        private System.Windows.Forms.ContextMenuStrip appContextMenuStrip;
        private System.Windows.Forms.ToolStripMenuItem zmieńZdjęcieToolStripMenuItem;
        private System.Windows.Forms.OpenFileDialog openFileDialog2;
        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton btnLoadDataToolStrip;
    }
}

