/*	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION
    INGENIERA DE SOFTWARE
                
	AUTORES:    Luca Manuel de Veintemilla - lmde2@espe.edu.ec
				Kevin Alexander Vargas - kavargas7@espe.edu.ec
				Anthony Bladimir Sinchiguano Almache - absinchiguano@espe.edu.ec
				Christian Mateo Román Quiroz- cmroman1@espe.edu.ec
				Camila Alejandra Rivera Medina - carivera14@espe.edu.ec
				Michelle Estefanía Yánez Gutierrez  - meyanez5@espe.edu.ec
				Susana Camila Morales Noroña - scmorales1@espe.edu.ec
				Erick Patricio Ramírez Ortiz - epramirez2@espe.edu.ec 

					
	FECHA DE CREACION:  6-07-2022      
	FECHA DE MODIFICACION:    19-07-2022
	Grupo #12, #8, #13, #9
*/

#include <iostream>
#include "Cola.hpp"

template <typename T>
class Node {
public:
	bool is_leaf;
	std::size_t degree; // numero maximo de hijos
	std::size_t size; // longitud inicial
	T* item;
	Node<T>** children;
	Node<T>* parent;

	/**
	 * Esta función crea un nuevo nodo con el grado dado y establece el tamaño en 0, el padre en nullptr y
	 * is_leaf en falso
	 * 
	 * @param _degree El grado del nodo.
	 */
	Node(std::size_t _degree) {// Constructor
		
		this->is_leaf = false;
		this->degree = _degree;
		this->size = 0;

		/* Creando una nueva matriz de tipo T con un tamaño de grado - 1. */
		T* _item = new T[degree - 1];
		for (int i = 0; i < degree - 1; i++) {
			_item[i] = 0;
		}
		this->item = _item;

		/* Creación de una matriz de punteros a nodos. */
		Node<T>** _children = new Node<T>*[degree];
		for (int i = 0; i < degree; i++) {
			_children[i] = nullptr;
		}
		this->children = _children;

		this->parent = nullptr;

	}
};

template <typename T>
class BPlusTree {
	Node<T>* root;
	std::size_t degree;

public:
	BPlusTree(std::size_t _degree) {// Constructor
		this->root = nullptr;
		this->degree = _degree;
	}
	~BPlusTree() { // Destructor
		clear(this->root);
	}

	Node<T>* getroot() {
		return this->root;
	}

	/**
	 * Si la raíz es nula, devuelve nullptr. De lo contrario, comience en la raíz y busque la clave en el
	 * nodo hoja
	 * 
	 * @param node el nodo raíz del árbol
	 * @param key la clave para buscar
	 * 
	 * @return el nodo que contiene la clave.
	 */
	Node<T>* BPlusTreeSearch(Node<T>* node, T key) {
		if (node == nullptr) { // Si la raiz es negativa, regresa el vacio
			return nullptr;
		}
		else {
			Node<T>* cursor = node; // iterador

			while (!cursor->is_leaf) { // Hasta llegar a la hoja
				for (int i = 0; i < cursor->size; i++) { 
					if (key < cursor->item[i]) { 
						cursor = cursor->children[i];
						break;
					}
					if (i == (cursor->size) - 1) {
						cursor = cursor->children[i + 1];
						break;
					}
				}
			}

			//BUscar por la clave si el nodo existe
			for (int i = 0; i < cursor->size; i++) {
				if (cursor->item[i] == key) {
					return cursor;
				}
			}

			return nullptr;
		}
	}

	/**
	 * La función toma un nodo y una clave como entrada y devuelve el nodo hoja que contiene la clave
	 * 
	 * @param node la raiz del arbol
	 * @param key la clave que desea buscar
	 * 
	 * @return un puntero a un nodo.
	 */
	Node<T>* BPlusTreeRangeSearch(Node<T>* node, T key) {
		if (node == nullptr) { // if root is null, return nullptr
			return nullptr;
		}
		else {
			Node<T>* cursor = node; // cursor finding key

			while (!cursor->is_leaf) { // until cusor pointer arrive leaf
				for (int i = 0; i < cursor->size; i++) { //in this index node, find what we want key
					if (key < cursor->item[i]) { //find some range, and let find their child also.
						cursor = cursor->children[i];
						break;
					}
					if (i == (cursor->size) - 1) {
						cursor = cursor->children[i + 1];
						break;
					}
				}
			}
			return cursor;
		}
	}


	/**
	 * La función comienza en el nodo que contiene el primer elemento del rango y luego atraviesa el árbol
	 * hasta llegar al final del rango.
	 * 
	 * @param start el comienzo de la gama
	 * @param end el final del rango
	 * @param result_data la matriz que contendrá los resultados de la búsqueda de rango
	 * @param arr_length la longitud de la matriz en la que desea almacenar los resultados
	 * 
	 * @return El número de artículos en el rango.
	 */
	int range_search(T start, T end, T* result_data, int arr_length) {
		int index = 0;

		Node<T>* start_node = BPlusTreeRangeSearch(this->root, start);
		Node<T>* cursor = start_node;
		T temp = cursor->item[0];

		while (temp <= end) {
			if (cursor == nullptr) {
				break;
			}
			for (int i = 0; i < cursor->size; i++) {
				temp = cursor->item[i];
				if ((temp >= start) && (temp <= end)) {
					result_data[index] = temp;
					index++;
				}
			}
			cursor = cursor->children[cursor->size];
		}
		return index;
	}

	/**
	 * Busca un dato dado en el árbol.
	 * 
	 * @param data Los datos a buscar.
	 * 
	 * @return verdadero si el item existe, falso, si no.
	 */
	bool search(T data) {  
		return BPlusTreeSearch(this->root, data) != nullptr;
	}

	/**
	 * Encuentra el índice del primer elemento en la matriz que es mayor que los datos
	 * 
	 * @param arr La matriz a ordenar
	 * @param data los datos a insertar
	 * @param len la longitud de la matriz
	 * 
	 * @return El índice de la matriz donde se deben insertar los datos.
	 */
	int find_index(T* arr, T data, int len) {
		int index = 0;
		for (int i = 0; i < len; i++) {
			if (data < arr[i]) {
				index = i;
				break;
			}
			if (i == len - 1) {
				index = len;
				break;
			}
		}
		return index;
	}

	/**
	 * Toma una matriz, un valor y la longitud de la matriz, y devuelve la matriz con el valor insertado
	 * en la posición correcta
	 * 
	 * @param arr La matriz en la que insertar los datos.
	 * @param data Los datos que se insertarán en la matriz.
	 * @param len la longitud de la matriz
	 * 
	 * @return La matriz con los nuevos datos insertados.
	 */
	T* item_insert(T* arr, T data, int len) {
		int index = 0;
		for (int i = 0; i < len; i++) {
			if (data < arr[i]) {
				index = i;
				break;
			}
			if (i == len - 1) {
				index = len;
				break;
			}
		}

		for (int i = len; i > index; i--) {
			arr[i] = arr[i - 1];
		}

		arr[index] = data;

		return arr;
	}

	/**
	 * Inserta un nodo secundario en la matriz secundaria de un nodo.
	 * 
	 * @param child_arr la variedad de niños
	 * @param child el nodo secundario que se va a insertar
	 * @param len la longitud de la matriz
	 * @param index el índice de la matriz secundaria donde se insertará el elemento secundario
	 * 
	 * @return El child_arr está siendo devuelto.
	 */
	Node<T>** child_insert(Node<T>** child_arr, Node<T>* child, int len, int index) {
		for (int i = len; i > index; i--) {
			child_arr[i] = child_arr[i - 1];
		}
		child_arr[index] = child;
		return child_arr;
	}

	/**
	 * Inserta un nuevo elemento en un nodo y desplaza los elementos y los elementos secundarios hacia la
	 * derecha para dejar espacio para el nuevo elemento.
	 * 
	 * @param node el nodo para insertar los datos en
	 * @param data los datos a insertar
	 * @param child el nodo secundario que se insertará
	 * 
	 * @return El nodo que se pasó.
	 */
	Node<T>* child_item_insert(Node<T>* node, T data, Node<T>* child) {
		int item_index = 0;
		int child_index = 0;
		for (int i = 0; i < node->size; i++) {
			if (data < node->item[i]) {
				item_index = i;
				child_index = i + 1;
				break;
			}
			if (i == node->size - 1) {
				item_index = node->size;
				child_index = node->size + 1;
				break;
			}
		}
		for (int i = node->size; i > item_index; i--) {
			node->item[i] = node->item[i - 1];
		}
		for (int i = node->size + 1; i > child_index; i--) {
			node->children[i] = node->children[i - 1];
		}

		node->item[item_index] = data;
		node->children[child_index] = child;

		return node;
	}

/**
 * Inserta un nuevo elemento en el nodo principal y, si el nodo principal está lleno, divide el nodo
 * principal e inserta el nuevo elemento en el nodo principal.
 * 
 * @param par el nodo padre
 * @param child el nodo secundario en el que se insertan los datos
 * @param data los datos a insertar
 */
	void InsertPar(Node<T>* par, Node<T>* child, T data) {
		//overflow check
		Node<T>* cursor = par;
		if (cursor->size < this->degree - 1) {
			cursor = child_item_insert(cursor, data, child);
			cursor->size++;
		}
		else {//overflow
			//creo nuevo nodo
			auto* Newnode = new Node<T>(this->degree);
			Newnode->parent = cursor->parent;

			//copio el item
			T* item_copy = new T[cursor->size + 1];
			for (int i = 0; i < cursor->size; i++) {
				item_copy[i] = cursor->item[i];
			}
			item_copy = item_insert(item_copy, data, cursor->size);

			auto** child_copy = new Node<T>*[cursor->size + 2];
			for (int i = 0; i < cursor->size + 1; i++) {
				child_copy[i] = cursor->children[i];
			}
			child_copy[cursor->size + 1] = nullptr;
			child_copy = child_insert(child_copy, child, cursor->size + 1, find_index(item_copy, data, cursor->size + 1));

			//separo nodos
			cursor->size = (this->degree) / 2;
			if ((this->degree) % 2 == 0) {
				Newnode->size = (this->degree) / 2 - 1;
			}
			else {
				Newnode->size = (this->degree) / 2;
			}

			for (int i = 0; i < cursor->size; i++) {
				cursor->item[i] = item_copy[i];
				cursor->children[i] = child_copy[i];
			}
			cursor->children[cursor->size] = child_copy[cursor->size];

			for (int i = 0; i < Newnode->size; i++) {
				Newnode->item[i] = item_copy[cursor->size + i + 1];
				Newnode->children[i] = child_copy[cursor->size + i + 1];
				Newnode->children[i]->parent = Newnode;
			}
			Newnode->children[Newnode->size] = child_copy[cursor->size + Newnode->size + 1];
			Newnode->children[Newnode->size]->parent = Newnode;

			T paritem = item_copy[this->degree / 2];

			delete[] item_copy;
			delete[] child_copy;

			//Checkeo de padre
			if (cursor->parent == nullptr) {
				auto* Newparent = new Node<T>(this->degree);
				cursor->parent = Newparent;
				Newnode->parent = Newparent;

				Newparent->item[0] = paritem;
				Newparent->size++;

				Newparent->children[0] = cursor;
				Newparent->children[1] = Newnode;

				this->root = Newparent;

	
			}
			else { //Si ya hay un padre
				InsertPar(cursor->parent, Newnode, paritem);
			}
		}
	}

	/**
	 * Si el árbol está vacío, cree un nuevo nodo raíz e inserte los datos. Si el árbol no está vacío,
	 * busque el nodo de hoja en el que se deben insertar los datos e inserte los datos en el nodo de
	 * hoja. Si el nodo hoja está lleno, divida el nodo hoja e inserte los datos en el nuevo nodo hoja. Si
	 * el nodo principal está lleno, divida el nodo principal e inserte los datos en el nuevo nodo
	 * principal
	 * 
	 * @param data los datos a insertar
	 */
	void insert(T data) {
		if (this->root == nullptr) { //Si esta vacio
			this->root = new Node<T>(this->degree);
			this->root->is_leaf = true;
			this->root->item[0] = data;
			this->root->size = 1; //
		}
		else { //Si se tiene al menos un nodo
			Node<T>* cursor = this->root;

			//mueve el nodo hoja
			cursor = BPlusTreeRangeSearch(cursor, data);

			// chequeo de overflow
			if (cursor->size < (this->degree - 1)) { // no hay overflow, solo se coloca en la posicion
				cursor->item = item_insert(cursor->item, data, cursor->size);
				cursor->size++;
				cursor->children[cursor->size] = cursor->children[cursor->size - 1];
				cursor->children[cursor->size - 1] = nullptr;
			}
			else {//overflow c
				//hago nuevo nodo
				auto* Newnode = new Node<T>(this->degree);
				Newnode->is_leaf = true;
				Newnode->parent = cursor->parent;

				//copio item
				T* item_copy = new T[cursor->size + 1];
				for (int i = 0; i < cursor->size; i++) {
					item_copy[i] = cursor->item[i];
				}

				//inserto y rearreglo
				item_copy = item_insert(item_copy, data, cursor->size);

				//separo los nodos
				cursor->size = (this->degree) / 2;
				if ((this->degree) % 2 == 0) {
					Newnode->size = (this->degree) / 2;
				}
				else {
					Newnode->size = (this->degree) / 2 + 1;
				}

				for (int i = 0; i < cursor->size; i++) {
					cursor->item[i] = item_copy[i];
				}
				for (int i = 0; i < Newnode->size; i++) {
					Newnode->item[i] = item_copy[cursor->size + i];
				}

				cursor->children[cursor->size] = Newnode;
				Newnode->children[Newnode->size] = cursor->children[this->degree - 1];
				cursor->children[this->degree - 1] = nullptr;

				delete[] item_copy;

				//checkeo del apdre
				T paritem = Newnode->item[0];

				if (cursor->parent == nullptr) {//Si no hay padre (nodo raiz)
					auto* Newparent = new Node<T>(this->degree);
					cursor->parent = Newparent;
					Newnode->parent = Newparent;

					Newparent->item[0] = paritem;
					Newparent->size++;

					Newparent->children[0] = cursor;
					Newparent->children[1] = Newnode;

					this->root = Newparent;
				}
				else {//Si hay un padre.
					InsertPar(cursor->parent, Newnode, paritem);
				}
			}
		}
	}

	/**
	 * Si el nodo es la raíz y está vacío, elimine la raíz. De lo contrario, si el nodo no es la raíz y no
	 * está lleno, intente tomarlo prestado de un hermano. Si eso no funciona, fusionarse con un hermano
	 * 
	 * @param data Los datos que se eliminarán del árbol.
	 */
	void remove(T data) { // Remove an item from the tree.

		Node<T>* cursor = this->root;

	
		cursor = BPlusTreeRangeSearch(cursor, data);


		/* Encontrar el índice del cursor en la matriz de hijos de su padre. */
		int sib_index = -1;
		for (int i = 0; i < cursor->parent->size + 1; i++) {
			if (cursor == cursor->parent->children[i]) {
				sib_index = i;
			}
		}
		int left = sib_index - 1;
		int right = sib_index + 1;


	
		/* Búsqueda del índice de los datos a borrar. */
		int del_index = -1;
		for (int i = 0; i < cursor->size; i++) {
			if (cursor->item[i] == data) {
				del_index = i;
				break;
			}
		}

		if (del_index == -1) {
			return; 
		}


		/* Eliminación del elemento en el índice del cursor. */
		for (int i = del_index; i < cursor->size - 1; i++) {
			cursor->item[i] = cursor->item[i + 1];
		}
		cursor->item[cursor->size - 1] = 0;
		cursor->size--;

		/* Eliminar el nodo raíz si es el único nodo en el árbol. */
		if (cursor == this->root && cursor->size == 0) {//root case
			clear(this->root);
			this->root = nullptr;
			return;
		}
		cursor->children[cursor->size] = cursor->children[cursor->size + 1];
		cursor->children[cursor->size + 1] = nullptr;



		/* Comprobando si el cursor está en la raíz. Si es así, vuelve. */
		if (cursor == this->root) {
			return;
		}

		if (cursor->size < degree / 2) {

			if (left >= 0) {
				Node<T>* leftsibling = cursor->parent->children[left];

				if (leftsibling->size > degree / 2) { 
					T* temp = new T[cursor->size + 1];

				
				/* Copiar el contenido de la matriz de cursores en la matriz temporal. */
					for (int i = 0; i < cursor->size; i++) {
						temp[i] = cursor->item[i];
					}

					
					/* Insertar el elemento del hermano izquierdo en el nodo actual. */
					item_insert(temp, leftsibling->item[leftsibling->size - 1], cursor->size);
					for (int i = 0; i < cursor->size + 1; i++) {
						cursor->item[i] = temp[i];
					}
					cursor->size++;
					delete[] temp;

				
					cursor->children[cursor->size] = cursor->children[cursor->size - 1];
					cursor->children[cursor->size - 1] = nullptr;

					leftsibling->item[leftsibling->size - 1] = 0;
					leftsibling->size--;
					leftsibling->children[leftsibling->size] = leftsibling->children[leftsibling->size + 1]; //cursor
					leftsibling->children[leftsibling->size + 1] = nullptr;

					cursor->parent->item[left] = cursor->item[0];

					return;
				}
			}
			if (right <= cursor->parent->size) {//hijo derecho existe
				Node<T>* rightsibling = cursor->parent->children[right];

				if (rightsibling->size > degree / 2) {//if data number is enough to use this node
					T* temp = new T[cursor->size + 1];

		
					/* Copiando el contenido del cursor en la matriz temporal. */
					for (int i = 0; i < cursor->size; i++) {
						temp[i] = cursor->item[i];
					}
			
					/* Insertar el elemento en el nodo. */
					item_insert(temp, rightsibling->item[0], cursor->size);
					for (int i = 0; i < cursor->size + 1; i++) {
						cursor->item[i] = temp[i];
					}
					cursor->size++;
					delete[] temp;

		
					cursor->children[cursor->size] = cursor->children[cursor->size - 1];
					cursor->children[cursor->size - 1] = nullptr;

				
					/* Desplazamiento de los elementos del hermano derecho a la izquierda una posición. */
					for (int i = 0; i < rightsibling->size - 1; i++) {
						rightsibling->item[i] = rightsibling->item[i + 1];
					}
					rightsibling->item[rightsibling->size - 1] = 0;
					rightsibling->size--;
					rightsibling->children[rightsibling->size] = rightsibling->children[rightsibling->size + 1]; //cursor
					rightsibling->children[rightsibling->size + 1] = nullptr;

					cursor->parent->item[right - 1] = rightsibling->item[0];

					return;
				}
			}

			//Si se encuentra un underflow, se tendra que unir los nodos

			if (left >= 0) { 
				Node<T>* leftsibling = cursor->parent->children[left];

				for (int i = 0; i < cursor->size; i++) {
					leftsibling->item[leftsibling->size + i] = cursor->item[i];
				}
		
				leftsibling->children[leftsibling->size] = nullptr;
				leftsibling->size = leftsibling->size + cursor->size;
				leftsibling->children[leftsibling->size] = cursor->children[cursor->size];

		
				Removepar(cursor, left, cursor->parent);
				for (int i = 0; i < cursor->size; i++) {
					cursor->item[i] = 0;
					cursor->children[i] = nullptr;
				}
				cursor->children[cursor->size] = nullptr;

				delete[] cursor->item;
				delete[] cursor->children;
				delete cursor;

				return;

			}
			if (right <= cursor->parent->size) { 
				Node<T>* rightsibling = cursor->parent->children[right];

				// Unos lo nodos
				for (int i = 0; i < rightsibling->size; i++) {
					cursor->item[i + cursor->size] = rightsibling->item[i];
				}
		
				cursor->children[cursor->size] = nullptr;
				cursor->size = rightsibling->size + cursor->size;
				cursor->children[cursor->size] = rightsibling->children[rightsibling->size];

	
				Removepar(rightsibling, right - 1, cursor->parent);

				for (int i = 0; i < rightsibling->size; i++) {
					rightsibling->item[i] = 0;
					rightsibling->children[i] = nullptr;
				}
				rightsibling->children[rightsibling->size] = nullptr;

				delete[] rightsibling->item;
				delete[] rightsibling->children;
				delete rightsibling;
				return;

			}

		}
		else {
			return;
		}
	}

	/**
	 * Elimina un nodo del árbol, y si el nodo es una hoja, verifica si el nodo se ha desbordado, y si es
	 * así, verifica si los hermanos del nodo se han desbordado, y si es así, toma prestado del hermano, y
	 * si no lo han hecho, se fusiona con el hermano
	 * 
	 * @param node el nodo que contiene los datos que se eliminarán
	 * @param index el índice del elemento que se va a eliminar
	 * @param par el nodo principal del nodo que contiene los datos que se eliminarán
	 */
	void Removepar(Node<T>* node, int index, Node<T>* par) {
		Node<T>* remover = node;
		Node<T>* cursor = par;
		T target = cursor->item[index];

		//if cursor is root, and there are no more data -> child node is to be root!
		if (cursor == this->root && cursor->size == 1) {//root case
			if (remover == cursor->children[0]) {
				delete[] remover->item;
				delete[] remover->children;
				delete remover;
				this->root = cursor->children[1];
				delete[] cursor->item;
				delete[] cursor->children;
				delete cursor;
				return;
			}
			if (remover == cursor->children[1]) {
				delete[] remover->item;
				delete[] remover->children;
				delete remover;
				this->root = cursor->children[0];
				delete[] cursor->item;
				delete[] cursor->children;
				delete cursor;
				return;
			}
		}

		//remove data
		for (int i = index; i < cursor->size - 1; i++) {
			cursor->item[i] = cursor->item[i + 1];
		}
		cursor->item[cursor->size - 1] = 0;

		//remove pointer
		int rem_index = -1;
		for (int i = 0; i < cursor->size + 1; i++) {
			if (cursor->children[i] == remover) {
				rem_index = i;
			}
		}
		if (rem_index == -1) {
			return;
		}
		for (int i = rem_index; i < cursor->size; i++) {
			cursor->children[i] = cursor->children[i + 1];
		}
		cursor->children[cursor->size] = nullptr;
		cursor->size--;

		//underflow check
		if (cursor == this->root) {
			return;
		}
		if (cursor->size < degree / 2) {//underflow case

			int sib_index = -1;
			for (int i = 0; i < cursor->parent->size + 1; i++) {
				if (cursor == cursor->parent->children[i]) {
					sib_index = i;
				}
			}
			int left = sib_index - 1;
			int right = sib_index + 1;

			if (left >= 0) {// left_sibiling exists
				Node<T>* leftsibling = cursor->parent->children[left];

				if (leftsibling->size > degree / 2) { //if data number is enough to use this node
					T* temp = new T[cursor->size + 1];

					//copy item
					for (int i = 0; i < cursor->size; i++) {
						temp[i] = cursor->item[i];
					}

					//insert and rearrange at cursor
					item_insert(temp, cursor->parent->item[left], cursor->size);
					for (int i = 0; i < cursor->size + 1; i++) {
						cursor->item[i] = temp[i];
					}
					cursor->parent->item[left] = leftsibling->item[leftsibling->size - 1];
					delete[] temp;

					Node<T>** child_temp = new Node<T>*[cursor->size + 2];
					//copy child node
					for (int i = 0; i < cursor->size + 1; i++) {
						child_temp[i] = cursor->children[i];
					}
					//insert and rearrange at child
					child_insert(child_temp, leftsibling->children[leftsibling->size], cursor->size, 0);

					for (int i = 0; i < cursor->size + 2; i++) {
						cursor->children[i] = child_temp[i];
					}
					delete[] child_temp;

					//size edit
					cursor->size++;
					leftsibling->size--;
					return;

				}
			}

			if (right <= cursor->parent->size) {// right_sibiling exists
				Node<T>* rightsibling = cursor->parent->children[right];

				if (rightsibling->size > degree / 2) {//if data number is enough to use this node
					T* temp = new T[cursor->size + 1];

					//copy item
					for (int i = 0; i < cursor->size; i++) {
						temp[i] = cursor->item[i];
					}
					//insert and rearrange at cursor
					item_insert(temp, cursor->parent->item[sib_index], cursor->size);
					for (int i = 0; i < cursor->size + 1; i++) {
						cursor->item[i] = temp[i];
					}
					cursor->parent->item[sib_index] = rightsibling->item[0];
					delete[] temp;

					//insert and reaarange at child

					cursor->children[cursor->size + 1] = rightsibling->children[0];
					for (int i = 0; i < rightsibling->size; i++) {
						rightsibling->children[i] = rightsibling->children[i + 1];
					}
					rightsibling->children[rightsibling->size] = nullptr;

					cursor->size++;
					rightsibling->size--;
					return;

				}
			}

			//if sibling is not enought to use their data
			//we have to merge step
			if (left >= 0) { // left_sibling exists
				Node<T>* leftsibling = cursor->parent->children[left];

				leftsibling->item[leftsibling->size] = cursor->parent->item[left];
				//merge two leaf node
				for (int i = 0; i < cursor->size; i++) {
					leftsibling->item[leftsibling->size + i + 1] = cursor->item[i];
				}
				for (int i = 0; i < cursor->size + 1; i++) {
					leftsibling->children[leftsibling->size + i + 1] = cursor->children[i];
					cursor->children[i]->parent = leftsibling;
				}
				for (int i = 0; i < cursor->size + 1; i++) {
					cursor->children[i] = nullptr;
				}
				leftsibling->size = leftsibling->size + cursor->size + 1;
				//delete recursion
				Removepar(cursor, left, cursor->parent);
				return;

			}
			if (right <= cursor->parent->size) { // right_sibiling exists
				Node<T>* rightsibling = cursor->parent->children[right];

				cursor->item[cursor->size] = cursor->parent->item[right - 1];
				//merge two leaf node
				for (int i = 0; i < rightsibling->size; i++) {
					cursor->item[cursor->size + 1 + i] = rightsibling->item[i];
				}
				for (int i = 0; i < rightsibling->size + 1; i++) {
					cursor->children[cursor->size + i + 1] = rightsibling->children[i];
					rightsibling->children[i]->parent = rightsibling;
				}
				for (int i = 0; i < rightsibling->size + 1; i++) {
					rightsibling->children[i] = nullptr;
				}
				//edit pointer
				rightsibling->size = rightsibling->size + cursor->size + 1;
				//parent property edit
				Removepar(rightsibling, right - 1, cursor->parent);
				return;
			}
		}
		else {
			return;
		}
	}

	/**
	 * Elimina todos los nodos del árbol.
	 * 
	 * @param cursor el nodo a borrar
	 */
	void clear(Node<T>* cursor) {
		if (cursor != nullptr) {
			if (!cursor->is_leaf) {
				for (int i = 0; i <= cursor->size; i++) {
					clear(cursor->children[i]);
				}
			}
			delete[] cursor->item;
			delete[] cursor->children;
			delete cursor;
		}
	}

	/**
	 * Imprime el árbol B+.
	 */
	void bpt_print() {
		print(this->root);
	}

	/**
	 * Si el cursor no es nulo, imprime los elementos en el cursor, luego, si el cursor no es una hoja,
	 * imprime los elementos secundarios del cursor
	 * 
	 * @param cursor el nodo para imprimir
	 */
	void print(Node<T>* cursor) {
		if (cursor != NULL) {
			for (int i = 0; i < cursor->size; ++i) {
				std::cout << "|" << cursor->item[i] << "|" << " ";
			}
			std::cout << "\n";

			if (!cursor->is_leaf) {
				for (int i = 0; i < cursor->size + 1; ++i) {
					print(cursor->children[i]);
				}
			}
		}
	}

	bool esPrimo(int numero) {
		// Casos especiales
		if (numero == 0 || numero == 1 || numero == 4) return false;
		for (int x = 2; x < numero / 2; x++) {
			if (numero % x == 0) return false;
		}
		// Si no se pudo dividir por ninguno de los de arriba, sí es primo
		return true;
	}

	void primos() {

		int suma = 0;

		if (this->root != NULL) {
			for (int i = 0; i < this->root->size; ++i) {
				
				if (esPrimo(this->root->item[i])) {

					suma = suma + this->root->item[i];

				}
			}

			if (!this->root->is_leaf) {
				for (int i = 0; i < this->root->size + 1; ++i) {
					print(this->root->children[i]);
				}
			}
		}

		cout << suma << endl;
	}

	/**
	 * Imprime el árbol en orden de nivel.
	 */
	void impresion() {
		
		if (root != nullptr) {
			Cola<Node<T>*> cola;
			cola.pushLast(this->root);
			cola.pushLast(nullptr);

			while (!(cola.estaVacia())) {
				Node<T>* aux{ cola.poll() };

				if (aux != nullptr) {

					std::cout << " [ ";
					for (int i = 0; i < aux->size; ++i) {
						std::cout << "|" << aux->item[i] << "|" << " ";
					}
					std::cout << " ] ";

					//std::cout << cola.estaVacia() << std::endl;

					if (!aux->is_leaf) {
						for (int i = 0; i < aux->size + 1; ++i) {
							cola.pushLast(aux->children[i]);
						}
					}

				}
				else if (!(cola.estaVacia())) {
					cola.pushLast(nullptr);
					std::cout << std::endl;
				}


			}
		}

	}

	/**
	 * Abre un archivo, comprueba si está abierto y, si lo está, escribe una nueva línea y el número en el
	 * archivo.
	 * 
	 * @param file El nombre del archivo en el que desea guardar.
	 * @param num El número a guardar
	 */
	void guardar(std::string file, int  num) {
		std::ofstream out;
		out.open(file.c_str(), std::ofstream::app);
		if (!out.is_open()) {
			std::cout << "No se puede guardar el archivo " << std::endl;
		}
		else {
			out << "\n";
			out << num;

		}
		out.close();
	}

	/**
	 * Abre un archivo, lo lee línea por línea e inserta cada línea en un árbol
	 * 
	 * @param file El nombre del archivo a leer.
	 */
	void cargar(std::string file) {
		T line;
		std::ifstream in;
		in.open(file.c_str());
		if (!in.is_open()) {
			std::cout << "No se puede abrir el archivo: " << file << std::endl << std::endl;
		}
		else {
			while (in >> line) {
				insert(line);
			}
		}
		in.close();
	}
};

