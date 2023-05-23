#include <iostream>
#include <string>
using namespace std;
class Producto {
    public:
        Producto(){}
        Producto(string n, string d, double p)
        {
            this->nombre = n;
            this->descripcion =d;
            this->precio =p;
        }
        string nombre;
        string descripcion;
        double precio;
};
class ProductoBase : virtual public Producto 
{
    public:
        ProductoBase() { }
        ProductoBase(string n, string d, double p) : Producto(n,d,p)
        {
            this->nombre = n;
            this->descripcion = d;
            this->precio = p;
        }
};
class ProductoFisico : virtual public ProductoBase {
    public:
        double peso;
        double tamano;
        ProductoFisico(){}
        ProductoFisico(string n, string d, double p, double w ,double _s) : ProductoBase(n,d,p), peso(w), tamano(_s) {};

};
class ProductoDigital : virtual public ProductoBase {
    public:
        string link;
        ProductoDigital(string n, string d, double p, string l) : ProductoBase(n,d,p), link(l) {};
        ProductoDigital(){}
};
class ProVenta : virtual public ProductoDigital, virtual public ProductoFisico
{
public:
    ProVenta(){}
    ProVenta(string n, string d, double p, string l, double w, double t): ProductoDigital(n,d,p,l), ProductoFisico(n,d,p,w,t)
    {
        this->nombre = n;
        this->descripcion = d;
        this->precio = p;
        this->link = l;
        this->peso = w;
        this->tamano = t;
    }
};
int main()
{ 
    ProductoFisico libro("Cien años de soledad", "Libro de Gabriel Garcia Marquez",12.99, 1.2, 10.5);
    ProductoDigital cancion("Bohemian Rhapsody", "Cancion de Queen", 0.99, "https://www.youtbe.com/watch?v=fJ9rUzIMcZQ");
    ProVenta prod001( "Nat King cole",  "FRANK SINATRA", 0.99,"https://www.youtube.com/watch?v=JErVP6xLZwg",3.0, 2.0);
    
    cout<<"Producto Fisico: "<<libro.nombre<<endl;
    cout<<"Descripcion: "<<libro.descripcion<<endl;
    cout<<"Precio: $"<<libro.precio<<endl;
    cout<<"Peso: "<<libro.peso<<" KG"<<endl;
    cout<<"Tamoño: "<<libro.tamano<<" cm"<<endl; cout<<endl;

    cout<<"Producto Digital: "<<cancion.nombre<<endl;
    cout<<"Descripcion: "<<cancion.descripcion<<endl;
    cout<<"Precio: $"<<cancion.precio<<endl;
    cout<<"Link de descarga: "<<cancion.link<<endl;

    cout<<endl<<"Descripcion PRODVENTA: "<<prod001.descripcion<<endl;
    cout<<"Precio: PRODVENTAS$"<<prod001.precio<<endl;
    cout<<"Link de descarga: PRODVENTA"<<prod001.link<<endl;
    cout<<"Peso: "<<prod001.peso<<" KG"<<endl;
    cout<<"Tamaño: "<<prod001.tamano<<" cm"<<endl; cout<<endl;

}