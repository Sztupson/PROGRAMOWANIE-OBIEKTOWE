using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AplikacjaPeselTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label3.Text = pesel1._Poprawny.ToString();
            label4.Text = pesel1._Płeć.ToString();
        }

        private void pesel1_TextChanged(object sender, EventArgs e)
        {
            this.BackColor = Color.White;
        }
    }
}
