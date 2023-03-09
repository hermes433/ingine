#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    printf("\033[0d\033[2J"); 
    int r, end;
    const float p = 45;
    const float t = 20;
    float t_o, t_p;
    time_t now; // time_t - тип переменной
    time(&now);
    int hours, minutes, seconds;
    long time_1st = time(NULL);

    for(;(p - ((time(NULL) - time_1st)*0.068)) > 0;){
        printf ("wrr...wrr...wrr...");
        sleep(3);
        printf("\033[0d\033[2J"); // замена system clear
        printf ("\nSilnik wlaczony\n");

        time(&now);
    	struct tm *local = localtime(&now); // tm - тип переменной, 

	        hours = local->tm_hour;
	        minutes = local->tm_min;
	        seconds = local->tm_sec;

        printf ("|| %02d:%02d:%02d ||\n", hours, minutes, seconds);

        printf ("Stan paliwa: %.03f l.\n", p - ((time(NULL) - time_1st)*0.068));
        
            t_o = t + ((time(NULL) - time_1st)*0.91);
        if (t_o <= 90){
        printf ("Temperatura oleju: %.02f C\n", t_o);
        }else printf ("Temperatura oleju : 90 C\n"); 
        
            t_p = t + ((time(NULL) - time_1st)*1.25);
        if (t_p <= 115){
        printf ("Temperatura plynu chlodzacego: %.02f C\n", t_p);
        }else printf ("Temperatura plynu chlodzacego: 115 C\n");

        sleep(1);
        }
    printf ("\033[0d\033[2J");
    printf ("Benzyna sie skonczyla! :( \nCzas jazdy: %.02d", (time(NULL) - time_1st));
}