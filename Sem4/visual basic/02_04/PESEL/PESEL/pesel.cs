using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PESEL
{
    public partial class pesel: TextBox
    {
        public pesel()
        {
            InitializeComponent();
        }
        private Color KolorBledu;
        private Boolean Poprawny;
        private String Plec;


        public Color _KolorBłędu
        {
            get { return KolorBledu; }
            set { KolorBledu = value; }
        }
        public Boolean _Poprawny
        {
            get { return Poprawny; }
            set { Poprawny = value; }
        }
        public String _Płeć
        {
            get { return Plec; }
            set { Plec = Text; }

        }
        private void pesel_Validating(object sender, CancelEventArgs e)
        {
            int[] pp;
            pp = this.Text.ToCharArray().Select(s => int.Parse(s.ToString())).ToArray();

            if (this.Text.Length < 11 || this.Text.Length > 11) 
            {
                this.BackColor = KolorBledu;
                this.Poprawny = false;
                MessageBox.Show("Niepoprawna ilość cyfr w numerze PESEL.");
            } 
            else
            {
                if (pp[9] % 2 == 0)
                { Plec = "Kobieta"; }
                else
                { Plec = "Mężczyzna"; }
                this.Poprawny = true;
            }
        }
    }
}
