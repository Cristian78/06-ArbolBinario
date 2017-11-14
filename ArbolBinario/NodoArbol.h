#ifndef HASHENTRY_H
#define HASHENTRY_H

using namespace std;
template<class T>
class NodoArbol {
private:

    NodoArbol *izq, *der;
    T dato;
public:

    NodoArbol(T dato);

    T getDato() const;

    void setDato(T dato);

    void put(T d);

    void put(NodoArbol *nodo);

    T search(T d);

    NodoArbol *remover(T param);

    void preorder();

    void inorder();

    void postorder();

    int contarporNivel(unsigned int);

    void espejo();

    bool compara(NodoArbol *);

    void print(bool esDerecho, string identacion) {
        if (der != NULL) {
            der->print(true, identacion + (esDerecho ? "     " : "|    "));
        }
        cout << identacion;
        if (esDerecho) {
            cout << " /";
        } else {
            cout << " \\";
        }
        cout << "-- ";
        cout << dato << endl;
        if (izq != NULL) {
            izq->print(false, identacion + (esDerecho ? "|    " : "     "));
        }
    }
};


template<class T>
NodoArbol<T>::NodoArbol(T dato) : dato(dato) {
    izq = NULL;
    der = NULL;
}


template<class T>
void NodoArbol<T>::put(T d) {

    if (d == dato)
        throw 1;
    else if (d < dato) { // va a la izq
        if (izq == NULL)
            izq = new NodoArbol<T>(d);
        else
            izq->put(d);
    } else { // va a la der
        if (der == NULL)
            der = new NodoArbol<T>(d);
        else
            der->put(d);
    }
}

template<class T>
void NodoArbol<T>::put(NodoArbol<T> *nodo) {

    if (nodo->getDato() == dato)
        throw 1;
    else if (nodo->getDato() < dato) { // va a la izq
        if (izq == NULL)
            izq = nodo;
        else
            izq->put(nodo);
    } else { // va a la der
        if (der == NULL)
            der = nodo;
        else
            der->put(nodo);
    }
}

template<class T>
T NodoArbol<T>::search(T d) {
    if (d == dato) {
        return dato;
    } else if (d < dato) {
        if (izq == NULL)
            throw 3;
        else
            return izq->search(d);
    } else {
        if (der == NULL)
            throw 3;
        else
            return der->search(d);
    }
}

template<class T>
NodoArbol<T> *NodoArbol<T>::remover(T d) {
    NodoArbol<T> *aux;
    if (d == dato) {
        if (der != NULL) {
            der->put(izq);
            return der;
        }
        return izq;
    } else if (d < dato) {
        if (izq == NULL)
            throw 3;
        else {
            aux = izq;
            izq = izq->remover(d);
            if (izq != aux)
                delete aux;
        }
    } else {
        if (der == NULL)
            throw 3;
        else {
            aux = der;
            der = der->remover(d);
            if (der != aux)
                delete aux;
        }
    }
    return this;
}

template<class T>
T NodoArbol<T>::getDato() const {
    return dato;
}

template<class T>
void NodoArbol<T>::setDato(T dato) {
    NodoArbol::dato = dato;
}

template<class T>
void NodoArbol<T>::preorder() {
    cout << dato << ", ";
    if (izq != NULL) izq->preorder();
    if (der != NULL) der->preorder();
}

template<class T>
void NodoArbol<T>::inorder() {
    if (izq != NULL) izq->inorder();
    cout << dato << ", ";
    if (der != NULL) der->inorder();
}

template<class T>
void NodoArbol<T>::postorder() {
    if (izq != NULL) izq->postorder();
    if (der != NULL) der->postorder();
    cout << dato << ", ";
}

template <class T>
void NodoArbol<T>::espejo(){
    NodoArbol *aux = izq;
    izq = der;
    der = aux;

    if (izq != NULL)
        izq->espejo();
    if (der != NULL)
        der->espejo();
}

template <class T>
bool NodoArbol<T>::compara(NodoArbol *a) {
    if (this->dato != a->getDato())
        return false;
    if (izq == NULL ^ a->izq == NULL)
        return false;
    if (der == NULL ^ a->der == NULL)
        return false;

    bool estizq = true, estder = true;

    if (izq != NULL)
        estizq = izq->compara(a->izq);
    if (der != NULL)
        estder = der->compara(a->der);

    return estizq == estder;
}

#endif //HASHENTRY_H