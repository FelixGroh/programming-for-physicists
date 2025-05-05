/* Mittels der Leibniz-Reihe 
 * (Gottfried Wilhelm Leibniz, Zeitschrift Acta Eruditorum, 1682)
 * wird die Kreiszahl Pi approximiert 
 * (Anzahl der Summanden = N) 
 * Ausgabe zum Plotten (Gnuplot oder Python) mittels: "./a.out >> While_2.dat" */
 #include <iostream>
 #include <cmath>
 #include <numbers>
 
 int main(){
     const unsigned int N = 100;
     double Pi_Approx = 0;
     
     printf("# 0: Summenindex k \n# 1: Approximierter Wert von Pi \n");
     
     for(int k = 0; k <= N; k++) {
         Pi_Approx = Pi_Approx + pow(-1,k)/(2*k + 1);
         printf("%4i %20.15f \n",k, 4*Pi_Approx);
         ++k;
     }
     
     Pi_Approx = Pi_Approx*4;
     
     printf("# Approximierter Wert von Pi:     %20.15f \n", Pi_Approx);
     printf("# Wirklicher Wert von Pi:         %20.15f \n", std::numbers::pi);

    return 0;
}