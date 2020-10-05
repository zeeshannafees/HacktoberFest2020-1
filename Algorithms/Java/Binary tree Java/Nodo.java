/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package arbolb;

/**
 *
 * @author Gmmonsalve
 *///
public class Nodo {
    
    private int info;
    private Nodo derecho;
    private Nodo Izquierdo;

    public Nodo(Integer info) {
        this.info = info;
    }

    public Integer getInfo() {
        return info;
    }

    public void setInfo(Integer info) {
        this.info = info;
    }

    public Nodo getDerecho() {
        return derecho;
    }

    public void setDerecho(Nodo derecho) {
        this.derecho = derecho;
    }

    public Nodo getIzquierdo() {
        return Izquierdo;
    }

    public void setIzquierdo(Nodo Izquierdo) {
        this.Izquierdo = Izquierdo;
    }
    
}
