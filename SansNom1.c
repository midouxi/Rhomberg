#include <stdlib.h>
#include <gtk/gtk.h>
#include <math.h>
float romberg(float f(float),float a,float b,int n);
float F(float x);
GtkWidget *fenetre;
GtkWidget *vc;
GtkWidget *hc1;
GtkWidget *hc2;
GtkWidget *hc3;
GtkWidget *hc4;
GtkWidget *hca;
GtkWidget *hcb;
GtkWidget *txt1; 
GtkWidget *txt2;
GtkWidget *txt3;
GtkWidget *txta;
GtkWidget *txtb;
GtkWidget *lbl1;
GtkWidget *lbl2;
GtkWidget *lbl3;
GtkWidget *lbl4;
GtkWidget *label=NULL;
GtkWidget *btn;
GtkWidget *menubar;
  GtkWidget *filemenu;
  GtkWidget *file;
  GtkWidget *quit;
  GtkWidget *about;

  //About
  void show_about(GtkWidget *widget, gpointer data)
{

  GtkWidget *dialog = gtk_about_dialog_new();
  gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog), "Romberg :)");
  gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "Beta Version"); 
  gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog),  //Ces fonctions appellent le nom ,la version et le Copyright.
      "Agouzal Mehdi\n
Interface GTK+ de la methode de romberg\n\ ");
  gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), 
     "Encadree Par : Mme Allaoui");
  gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), 
      "Copyright (c) ENSA Khouribga 2012 .");
  gtk_dialog_run(GTK_DIALOG (dialog));
  gtk_widget_destroy(dialog);

}
/*programme libghina */
void calculer(void)
{
     
     gint ta,tb;
     gfloat F(float),somme,t1,t2;
     gchar temp[40];
   t1=atoi(gtk_entry_get_text(GTK_ENTRY(txt1))); //c comme scanf en GTK
   t2=atoi(gtk_entry_get_text(GTK_ENTRY(txt2)));
   ta=atoi(gtk_entry_get_text(GTK_ENTRY(txta)));
   tb=atoi(gtk_entry_get_text(GTK_ENTRY(txtb)));
   somme = romberg(F,t1,t2,ta);
   sprintf (temp,"%f",somme);
   gtk_entry_set_text(txt3,temp);  
} 

int main(int argc, char **argv)
{
gtk_init(&argc, &argv);

/* Création de la fenetre */
fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);//insertion de l'interface principal
gtk_window_set_title(GTK_WINDOW(fenetre), "Programme_ROMBERG-Mme.Allaoui");//le titre du programme 
gtk_window_set_default_size(GTK_WINDOW(fenetre), 320, 300);//les mesures de cette interface
g_signal_connect(G_OBJECT(fenetre), "destroy", G_CALLBACK(gtk_main_quit),NULL);
gtk_container_set_border_width(GTK_CONTAINER(fenetre), 20);//les mesures de l ABOUT
  gtk_widget_add_events(fenetre, GDK_BUTTON_PRESS_MASK);//insertion du widget 

  

  g_signal_connect(G_OBJECT(fenetre), "button-press-event", 
        G_CALLBACK(show_about), (gpointer) fenetre); 


vc = gtk_vbox_new(FALSE, 0); //pour créer une boite verticale
hc1=gtk_hbox_new(TRUE,5);//pour créer une boite horizontale
hc2=gtk_hbox_new(TRUE,5);
hca=gtk_hbox_new(TRUE,5);
hcb=gtk_hbox_new(TRUE,5);
hc3=gtk_hbox_new(TRUE,5);
hc4=gtk_hbox_new(TRUE,5);
hca=gtk_hbox_new(TRUE,5);
hcb=gtk_hbox_new(TRUE,5);
 menubar = gtk_menu_bar_new();//la grande barre outil 
 filemenu = gtk_menu_new();//sous-onglet de la grande barre ! 

  file = gtk_menu_item_new_with_label("File");//la fct gtk_menu... crée un nouveau onglet dans le toolbar
  quit = gtk_menu_item_new_with_label("Quit");

  gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu); //nous créons une barre de menus et un menu.
  gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);//sous-shell
  gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
  gtk_box_pack_start(GTK_BOX(vc), menubar, FALSE, FALSE, 3);

gtk_container_add(GTK_CONTAINER(fenetre), vc);//insérer l

gtk_box_pack_start(vc,hc1,TRUE,TRUE,5); //placer les objets au sein de container
gtk_box_pack_start(vc,hc2,TRUE,TRUE,5);
gtk_box_pack_start(vc,hca,TRUE,TRUE,5);
gtk_box_pack_start(vc,hcb,TRUE,TRUE,5);
gtk_box_pack_start(vc,hc3,TRUE,TRUE,5);
gtk_box_pack_start(vc,hc4,TRUE,TRUE,5);


lbl1=gtk_label_new("Entrer la 1 ere borne de l'intervalle :");//printf
lbl2=gtk_label_new("Entrer la 2 eme borne de l'intervalle :");
lbl3=gtk_label_new("Entrer le nombre de subdivision :");
lbl4=gtk_label_new("Entrer  le nombre d'acceleration :");

txt1=gtk_entry_new();//créer les cases de saisie
txt2=gtk_entry_new();
txt3=gtk_entry_new();
txta=gtk_entry_new();
txtb=gtk_entry_new();

btn=gtk_button_new_with_label("Integrer");//créer un bouton son nom integrer et si cliqué on le relie à la procédure calculer
g_signal_connect(G_OBJECT(btn), "clicked", calculer,NULL);

gtk_box_pack_start(hc1,lbl1,TRUE,TRUE,5);//servent à placer les objets à l'intérieur de ces containers
gtk_box_pack_start(hc1,txt1,TRUE,TRUE,5);

gtk_box_pack_start(hc2,lbl2,TRUE,TRUE,5);
gtk_box_pack_start(hc2,txt2,TRUE,TRUE,5);

gtk_box_pack_start(hca,lbl3,TRUE,TRUE,5);
gtk_box_pack_start(hca,txta,TRUE,TRUE,5);


gtk_box_pack_start(hcb,lbl4,TRUE,TRUE,5);
gtk_box_pack_start(hcb,txtb,TRUE,TRUE,5);

gtk_box_pack_start(hc3,btn,TRUE,TRUE,100);
gtk_box_pack_start(hc4,txt3,TRUE,TRUE,50);



/*stoonate flekher*/
 g_signal_connect_swapped(G_OBJECT(fenetre), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);//gtk_main_quit=fonction de GTK pour quitter une App

  g_signal_connect(G_OBJECT(quit), "activate",
        G_CALLBACK(gtk_main_quit), NULL);//si on selectionne quit on sort de l'app 


gtk_widget_show_all(fenetre);//affichage complet 
gtk_main();
return EXIT_SUCCESS; 
}




float romberg(float f(float), float a, float b, int n)//la déclaration de la fonction romberg
{
  int i, j, k;
  float h, sum,R[100][100],aire;


  h = b - a;//initialisation du pas de la méthode de trapézes
  R[0][0] = 0.5 * h * (f(a) + f(b));
  //printf(" R[0][0] = %f\n", R[0][0]);

  for (i = 1; i <= n; i++)             /////////////////////////////////////////////////
  {                                    //                                             //
     h *= 0.5;                         //                                             //
     sum = 0;                          //             Méthode de trapézes             //
     for (k = 1; k <= pow(2,i)-1; k+=2)//                                             //
     {                                 //                                             //
       sum =sum +  f(a + k * h);       //                                             //
     }                                 /////////////////////////////////////////////////
     R[i][0] = 0.5 * R[i-1][0] + sum * h;
     printf(" R[%d][0] = %f\n", i, R[i][0]);
     for (j = 1; j <= i; j++)
     {
       R[i][j] = R[i][j-1] + (R[i][j-1] - R[i-1][j-1]) / (pow(4,j)-1);//interpolation de redsharson
      printf(" R[%d][%d] = %f\n", i,j, R[i][j]);
       aire=R[i][j];
     }
   }
   return aire;// la valeur de  l'integrale a retourner par la fonction romberg
}



float F(float x)
{
    return x*x;// definition de la fontion a integrer
}
