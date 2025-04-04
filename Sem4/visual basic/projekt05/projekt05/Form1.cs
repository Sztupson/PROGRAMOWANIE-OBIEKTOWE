using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace projekt05
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        int x,y,z;
        char dzialanie;
        

        private void btnMinus_Click(object sender, EventArgs e)
        {
            dzialanie = '-';
            x = System.Convert.ToInt32(lblWynik.Text);
            lblWynik.Text = "";
        }

        private void btnDivision_Click(object sender, EventArgs e)
        {
            dzialanie = '/';
            x = System.Convert.ToInt32(lblWynik.Text);
            lblWynik.Text = "";
        }

        private void btnMultiply_Click(object sender, EventArgs e)
        {
            dzialanie = '*';
            x = System.Convert.ToInt32(lblWynik.Text);
            lblWynik.Text = "";
        }
        private void btn1_Click(object sender, EventArgs e)
        {
            if (lblWynik.Text == "0,0")
                lblWynik.Text = "1";
            else
                lblWynik.Text += 1;
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            if (lblWynik.Text == "0,0")
                lblWynik.Text = "2";
            else
                lblWynik.Text += 2;
        }

        private void btn3_Click(object sender, EventArgs e)
        {
            if (lblWynik.Text == "0,0")
                lblWynik.Text = "3";
            else
                lblWynik.Text += 3;
        }
        private void btn4_Click(object sender, EventArgs e)
        {
            if (lblWynik.Text == "0,0")
                lblWynik.Text = "4";
            else
                lblWynik.Text += 4;
        }

        private void btn5_Click(object sender, EventArgs e)
        {
            if (lblWynik.Text == "0,0")
                lblWynik.Text = "5";
            else
                lblWynik.Text += 5;
        }

        private void btn6_Click(object sender, EventArgs e)
        {
            if (lblWynik.Text == "0,0")
                lblWynik.Text = "6";
            else
                lblWynik.Text += 6;
        }

        private void btn7_Click(object sender, EventArgs e)
        {
            if (lblWynik.Text == "0,0")
                lblWynik.Text = "7";
            else
                lblWynik.Text += 7;
        }

        private void btn8_Click(object sender, EventArgs e)
        {
            if (lblWynik.Text == "0,0")
                lblWynik.Text = "8";
            else
                lblWynik.Text += 8;
        }

        private void btn9_Click(object sender, EventArgs e)
        {
            if (lblWynik.Text == "0,0")
                lblWynik.Text = "9";
            else
                lblWynik.Text += 9;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            dzialanie = '+';
            x = System.Convert.ToInt32(label1.Text);
            label1.Text = "";
            lblWynik.Text += " + ";
        }

        private void button11_Click(object sender, EventArgs e)
        {
            if (lblWynik.Text == "0,0")
                lblWynik.Text = "1";
            else
                lblWynik.Text += 1;
            label1.Text += 1;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            if (lblWynik.Text == "0,0")
                lblWynik.Text = "2";
            else
                lblWynik.Text += 2;
            label1.Text += 2;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            y = System.Convert.ToInt32(label1.Text);
            label1.Text = "";
            if (dzialanie == '+')
                z = x + y;
            else if (dzialanie == '-')
                z = x - y;
            else if (dzialanie == '/')
            {
                if (y == 0)
                    lblWynik.Text = "Undefined";
                else
                    z = x / y;
            }
            else if (dzialanie == '*')
                z = x * y;

            lblWynik.Text += " = " + z.ToString();
        }

        private void btnPlus_Click(object sender, EventArgs e)
        {
            dzialanie = '+';
            x = System.Convert.ToInt32(lblWynik.Text);
            lblWynik.Text = "";
        }

        private void btnWynik_Click(object sender, EventArgs e)
        {
            y = System.Convert.ToInt32(lblWynik.Text);
            if (dzialanie == '+')
                z = x + y;
            else if (dzialanie == '-')
                z = x - y;
            else if (dzialanie == '/')
            {
                if (y == 0)
                    lblWynik.Text = "Undefined";
                else
                    z = x / y;
            }
            else if (dzialanie == '*')
                z = x * y;

            lblWynik.Text = z.ToString();

        }
    }
}
