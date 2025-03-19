using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Nauczyciel_Tabliczki_Mnozenia
{
    public partial class Form1 : Form
    {

        int x, y;
        public Form1()
        {
            InitializeComponent();
        }

        private void koniecToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void lblEqualSign_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void toolStripMenuItem5_Click(object sender, EventArgs e)
        {
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void btnCheckAnswers_Click(object sender, EventArgs e)
        {
            if (x + y == System.Convert.ToInt32(textBox1.Text))
                lblRightAnswersAnswer.Text = System.Convert.ToString(System.Convert.ToInt32(lblRightAnswersAnswer.Text) + 1);
            else
                lblWrongAnswersAnswer.Text = System.Convert.ToString(System.Convert.ToInt32(lblWrongAnswersAnswer.Text) + 1);
        }

        private void btnRandomizeNumbers_Click(object sender, EventArgs e)
        {
            Random r = new Random();

            
            x = r.Next(1, 10);
            y = r.Next(1, 10);

            lblX.Text = x.ToString();
            lblY.Text = y.ToString();

            textBox1.Select();
        }
    }
}
