using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace aplikacja_z_biblioteka
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            matematyka.Class1 funkcja = new matematyka.Class1();
            lblSilnia.Text = funkcja.silnia(Convert.ToInt32(numericUpDown1.Value)).ToString();
        }

        private void numericUpDown2_ValueChanged(object sender, EventArgs e)
        {
            matematyka.Class1 funkcja = new matematyka.Class1();
            lblN_Po_K.Text = funkcja.n_po_k(Convert.ToInt32(numericUpDown2.Value), Convert.ToInt32(numericUpDown3.Value)).ToString();
        }

        private void numericUpDown3_ValueChanged(object sender, EventArgs e)
        {
            matematyka.Class1 funkcja = new matematyka.Class1();
            lblN_Po_K.Text = funkcja.n_po_k(Convert.ToInt32(numericUpDown2.Value), Convert.ToInt32(numericUpDown3.Value)).ToString();
        }
    }
}
