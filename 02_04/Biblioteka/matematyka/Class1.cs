using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace matematyka
{
    public class Class1
    {
        public int sumaa(int a, int b) { return a + b; }
        public int iloczyn(int a, int b) { return a * b; }
        public int silnia(int a) {
            int s = 1;
            for (int i = 1; i <= a; i++)
                { s = s * i; }
            return s;
        }
        public int n_po_k(int n, int k) { 
            return silnia(n) / silnia(k) * silnia(n - k); 
        }
        
    }
}
