#include<iostream>
using namespace std;
class vehicule{
  protected:
	float vitesse_lim;
	float cx;
	int nbrRoue;
  public :
	vehicule(){
	   vitesse_lim =  200;
	   cx=0.5;
	   nbrRoue=4;}
	vehicule(float v,float c,int n ){
	   vitesse_lim = v;
	   cx=c;
	   nbrRoue=n;}  
	~vehicule(){
		}
	void affiche(){
		cout<<"La vitesse limite est : "<<vitesse_lim<<endl;
		cout<<"Coefficient aerodynamique : "<<cx<<endl;
		cout<<"Nombre de roue : "<<nbrRoue<<endl;}
		
};
class voiture :	public vehicule{
	public :
	voiture(){
	   vitesse_lim = 200;
	   cx=0.5;
	   nbrRoue=4;}
	voiture(float v,float c,int n ):vehicule(v,c,n){}  
	void affiche(){vehicule::affiche();}
	float calculV(){
		return ((1-cx)*vitesse_lim / nbrRoue);}
	
};
class camion : public vehicule{
	protected :
		int carg;
	public:
	camion():vehicule(){
	   carg=0;}
	camion(float v,float c,int n ,int car):vehicule(v,c,n){
	   carg = car;}  
	float calculV(){
		return ((1-cx)*vitesse_lim / nbrRoue * carg );}
void affiche() {
        vehicule::affiche();
        cout << "Capacite de chargement : " << carg << endl;
    }
		
};
main()
{
	voiture v(200,0.7,4);
	v.affiche();
	float c = v.calculV();
	cout<<"la vitesse est : "<<c<<endl;
	camion ca(200,0.7,12,8);
	ca.affiche();
    c=ca.calculV();
	cout<<"la vitesse est : "<<c;
}
