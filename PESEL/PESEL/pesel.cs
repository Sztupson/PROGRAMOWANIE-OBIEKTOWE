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
        private Char Ona_On;
        private String Dzien;
        private String Msc;
        private String Miesiac;
        private String Rok;
        
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
        public Char _Ona_On
        {
            get { return Ona_On; }
            set { Ona_On = ' '; }
        }
        public String _Dzien
        {
            get { return Dzien; }
            set { Dzien = Text; }
        }
        public String _Msc
        {
            get { return Msc; }
            set { Msc = Text; }
        }
        public String _Miesiac
        {
            get { return Miesiac; }
            set { Miesiac = Text; }
        }
        public String _Rok
        {
            get { return Rok; }
            set { Rok = Text; }
        }
        public enum formatdaty
        {
            rrrr_mmm_dddd,
            rrrr_mm_dd,
            dd_mmmm
        }
        private formatdaty FormatDaty;

        public formatdaty _FormatDaty
        {
            get { return FormatDaty; }
            set { FormatDaty = value; }
        }

        private String Data;
        public String _Data
        {
            get { return Data; }
            set { Data = value; }
        }
        private void pesel_Validating(object sender, CancelEventArgs e)
        {
            int[] pp;
            pp = this.Text.ToCharArray().Select(s => int.Parse(s.ToString())).ToArray();

            if (this.Text.Length < 11)
            {

                this.BackColor = KolorBledu;
                this.Poprawny = false;
                MessageBox.Show("Zbyt mało cyfr w numerze PESEL");
            }
            else
            {
                if (pp[9] % 2 == 0)
                    Plec = "Kobieta";
                else
                    Plec = "Mężczyzna";
                this.Poprawny = true;

                Ona_On = System.Convert.ToChar(Plec.Substring(0, 1));

                // dzien urodzenia
                Dzien = System.Convert.ToString(pp[4] * 10 + pp[5]);

                //Miesiac urodzenia
                int ms;
                if (pp[2] > 2)
                    ms = pp[2] - 1;
                else
                    ms = pp[2];

                Msc = System.Convert.ToString((pp[2] - ms) * 10 + pp[3]);

                string[] miesiac = { "styczeń", "luty", "marzec", "kwiecień", "maj", "czerwiec", "lipiec", "sierpień", "wrzesień", "październik", "listopad", "grudzień" };
                Miesiac = miesiac[System.Convert.ToInt32(Msc) - 1];

                //Rok urodzenia
                if (pp[2] == 8 || pp[2] == 9)
                    Rok = System.Convert.ToString(1800 + ms * 50 + pp[0] * 10 + pp[1]);
                else if (pp[2] == 0 || pp[2] == 1)
                    Rok = System.Convert.ToString(1900 + ms * 50 + pp[0] * 10 + pp[1]);
                else if (pp[2] == 2 || pp[2] == 3)
                    Rok = System.Convert.ToString(2000 + ms * 50 + pp[0] * 10 + pp[1]);
                else if (pp[2] == 4 || pp[2] == 5)
                    Rok = System.Convert.ToString(2100 + ms * 50 + pp[0] * 10 + pp[1]);
                else if (pp[2] == 6 || pp[2] == 7)
                    Rok = System.Convert.ToString(2200 + ms * 50 + pp[0] * 10 + pp[1]);

                switch(FormatDaty)
                {
                    case formatdaty.dd_mmmm:
                        {
                            _Data = Dzien + ":" + Miesiac;
                            return;
                        }
                    case formatdaty.rrrr_mmm_dddd:
                        {
                            _Data = "dataaa";
                            return;
                        }
                }
            }   
        }


        private void pesel_TextChanged(object sender, EventArgs e)
        {
            this.BackColor = Color.White;

        }
    }
}
