/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arbolb;

import java.util.Scanner;

/**
 *
 * @author Gmmonsalve
 */
public class ArbolB {

    public static Integer[] vector_a() { //Método de generación de vector con números aleatorios
        int num;
        Integer rand[] = new Integer[5];
        for (int i = 0; i < 5; i++) {
            num = (int) (Math.random() * 100) + 1;
            rand[i] = num;
        }
        return rand;
    }

    public static void Preorden(Nodo raiz) { //Método de ordenamiendo, PreOrden
        if (raiz != null) {
            System.out.println("" + raiz.getInfo());
            Preorden(raiz.getIzquierdo());
            Preorden(raiz.getDerecho());
        }
    }

    public static void InOrden(Nodo raiz) {
        if (raiz != null) {
            InOrden(raiz.getIzquierdo());
            System.out.println("!" + raiz.getInfo() + ")");
            InOrden(raiz.getDerecho());
        }
    }

    public static void PosOrden(Nodo raiz) {
        if (raiz != null) {
            PosOrden(raiz.getIzquierdo());
            PosOrden(raiz.getDerecho());
            System.out.println("!" + raiz.getInfo() + ")");
        }
    }

    public static void InsertarBinario(Nodo raiz, int valor) { //Inserta nodos de forma Árbol Binario de Búsqueda (ABB)
        if (valor > raiz.getInfo()) {
            if (raiz.getDerecho() == null) {
                raiz.setDerecho(new Nodo(valor));
                System.out.println("acabo de crear el nodo" + valor + " a la derecha de " + raiz.getInfo());
            } else {
                InsertarBinario(raiz.getDerecho(), valor);
            }

        } else {
            if (valor < raiz.getInfo()) {
                if (raiz.getIzquierdo() == null) {
                    raiz.setIzquierdo(new Nodo(valor));
                    System.out.println("acabo de crear el nodo" + valor + " a la izquierda de " + raiz.getInfo());
                } else {
                    InsertarBinario(raiz.getIzquierdo(), valor);
                }

            }
        }
    }

    public static void busqueda(Nodo raiz, int valor) {
        if (valor == raiz.getInfo()) {
            System.out.println("¡Encontrado!");
        } else {
            if (valor > raiz.getInfo()) {
                busqueda(raiz.getDerecho(), valor);
            } else {
                if (valor < raiz.getInfo()) {
                    busqueda(raiz.getIzquierdo(), valor);

                }
            }

        }

    }

    public static void main(String[] args) {

        Integer vecto[] = vector_a();
        Nodo raiz = new Nodo(vecto[0]); //Se crea la raíz con un valor aleatorio

        for (int i = 1; i < 5; i++) {
            InsertarBinario(raiz, vecto[i]);
        }

        System.out.println("Preorden");
        Preorden(raiz);
        System.out.println("PostOrden");
        PosOrden(raiz);
        System.out.println("InOrden");
        InOrden(raiz);
        System.out.println("**********************");
        System.out.println("Escriba el elemento que desee buscar");
        Scanner leer = new Scanner(System.in);
        int c;
        c = leer.nextInt();
        busqueda(raiz, c);
    }
  
}
