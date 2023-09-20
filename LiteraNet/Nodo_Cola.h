template<class T>
class Nodo_Cola
{
public:
	T dato;
	Nodo_Cola<T>* siguiente;

	Nodo_Cola(T v, Nodo_Cola<T>* sig = NULL)
	{
		dato = v;
		siguiente = sig;
	}
};
