using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;
using System.Xml.Linq;
using Newtonsoft.Json.Linq;


namespace PROJEKT_NA_ZALICZENIE
{
    public partial class Form1 : Form
    {
        private static readonly HttpClient client = new HttpClient();
        private const string ApiKey = "4V8TQN6GW183NNG7";
        private const string BaseUrl = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY";

        public Form1()
        {
            InitializeComponent();
            lblStatus.Text = "Wpisz symbol akcji i kliknij Załaduj";

            
        }


        private async void btnLoadDataToolStrip_Click(object sender, EventArgs e)
        {
            string symbol = txtSymbol.Text.Trim().ToUpper();
            if (string.IsNullOrEmpty(symbol))
            {
                MessageBox.Show("Wpisz symbol akcji (np. AAPL, TSLA)");
                return;
            }

            lblStatus.Text = $"Pobieranie danych dla {symbol}...";
            await LoadStockDataAsync(symbol);
        }
        private async Task LoadStockDataAsync(string symbol)
        {
            try
            {
                string url = $"{BaseUrl}&symbol={symbol}&apikey={ApiKey}";
                string response = await client.GetStringAsync(url);
                JObject jsonData = JObject.Parse(response);
                var timeSeries = jsonData["Time Series (Daily)"];

                if (timeSeries != null)
                {
                    chart1.Series[0].Points.Clear();
                    foreach (var item in timeSeries as JObject)
                    {
                        string date = item.Key;
                        double closePrice = Convert.ToDouble(item.Value["4. close"]);
                        chart1.Series[0].Points.AddXY(date, closePrice);
                    }

                    lblStatus.Text = $"Załadowano dane dla {symbol}";
                }
                else
                {
                    lblStatus.Text = "Brak danych lub błędny symbol!";
                }
            }
            catch (Exception ex)
            {
                lblStatus.Text = "Błąd pobierania danych!";
                MessageBox.Show("Błąd: " + ex.Message);
            }
        }


        private double saldo = 0;
        private void btnAddSaldo_Click(object sender, EventArgs e)
        {

            saldo += 100;
            lblSaldoNumbers.Text = saldo.ToString();
        }

        

        private void rozszerzToolStripMenuItem_Click(object sender, EventArgs e)
        {
            chart1.Width *= 2;
        }

        private void pomniejszToolStripMenuItem_Click(object sender, EventArgs e)
        {
            chart1.Width /= 2;
        }

        private void otwórzToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFileDialog1.ShowDialog();
        }

        private void zapiszToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveFileDialog1.ShowDialog();
        }
        private void wybierzKolorToolStripMenuItem_Click(object sender, EventArgs e)
        {
            colorDialog1.ShowDialog();
            chart1.BackColor = colorDialog1.Color;
            zielonyToolStripMenuItem.Checked = false;
            niebieskiToolStripMenuItem.Checked = false;
            wybierzKolorToolStripMenuItem.Checked = true;
        }

        private void niebieskiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            chart1.BackColor = Color.Blue;
            zielonyToolStripMenuItem.Checked = false;
            niebieskiToolStripMenuItem.Checked = true;
            wybierzKolorToolStripMenuItem.Checked = false;
        }

        private void zielonyToolStripMenuItem_Click(object sender, EventArgs e)
        {
            chart1.BackColor = Color.Green;
            zielonyToolStripMenuItem.Checked = true;
            niebieskiToolStripMenuItem.Checked = false;
            wybierzKolorToolStripMenuItem.Checked = false;
        }

        private void zmieńZdjęcieToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openFileDialog2.ShowDialog();
            BackgroundImage = Image.FromFile(openFileDialog2.FileName);
            BackgroundImageLayout = ImageLayout.Stretch;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
        